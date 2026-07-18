document.addEventListener('DOMContentLoaded', () => {
    // DOM Elements Selector
    const addToCartBtn = document.getElementById('addToCartBtn');
    const toast = document.getElementById('toast');
    const cartTrigger = document.getElementById('cartTrigger');
    const cartDrawer = document.getElementById('cartDrawer');
    const cartOverlay = document.getElementById('cartOverlay');
    const closeCartBtn = document.getElementById('closeCartBtn');
    
    const cartCountBadge = document.getElementById('cartCountBadge');
    const emptyCartState = document.getElementById('emptyCartState');
    const cartItemsWrapper = document.getElementById('cartItemsWrapper');
    const cartFooter = document.getElementById('cartFooter');
    
    // Qty and Price Elements
    const qtyVal = document.getElementById('qtyVal');
    const qtyMinus = document.getElementById('qtyMinus');
    const qtyPlus = document.getElementById('qtyPlus');
    const cartTotalPrice = document.getElementById('cartTotalPrice');
    const removeItemBtn = document.getElementById('removeItemBtn');

    let itemPrice = 1540.00;
    let quantity = 1;
    let isCartEmpty = true;

    // --- Helper function: UI ko item existence ke anusaar change karne ke liye ---
    function updateCartUI() {
        if (isCartEmpty) {
            emptyCartState.style.display = 'block';
            cartItemsWrapper.style.display = 'none';
            cartFooter.style.display = 'none';
            cartCountBadge.textContent = "0";
        } else {
            emptyCartState.style.display = 'none';
            cartItemsWrapper.style.display = 'block';
            cartFooter.style.display = 'block';
            
            // Total price aur quantity label sync
            qtyVal.textContent = quantity;
            cartCountBadge.textContent = quantity;
            
            let finalPrice = itemPrice * quantity;
            cartTotalPrice.textContent = `$${finalPrice.toFixed(2)}`;
        }
    }

    // --- Add to Cart click Action ---
    addToCartBtn.addEventListener('click', () => {
        // Step 1: Toast notification show karein
        toast.classList.add('show');
        
        // Dynamic item activation logic
        isCartEmpty = false;
        updateCartUI();

        // Step 2: 2 seconds ke baad Toast gayab hoga aur Sidebar automatic trigger hoga
        setTimeout(() => {
            toast.classList.remove('show');
            openCartSidebar();
        }, 2000);
    });

    // --- Quantity Plus Action ---
    qtyPlus.addEventListener('click', () => {
        quantity++;
        updateCartUI();
    });

    // --- Quantity Minus Action ---
    qtyMinus.addEventListener('click', () => {
        if (quantity > 1) {
            quantity--;
            updateCartUI();
        }
    });

    // --- Remove Item (Video Empty cart status trigger ke liye) ---
    removeItemBtn.addEventListener('click', () => {
        isCartEmpty = true;
        quantity = 1; // Reset
        updateCartUI();
    });

    // --- Sidebar Open / Close Logics ---
    function openCartSidebar() {
        cartDrawer.classList.add('open');
        cartOverlay.style.display = 'block';
    }

    function closeCartSidebar() {
        cartDrawer.classList.remove('open');
        cartOverlay.style.display = 'none';
    }

    cartTrigger.addEventListener('click', openCartSidebar);
    closeCartBtn.addEventListener('click', closeCartSidebar);
    cartOverlay.addEventListener('click', closeCartSidebar);
});