// Add to cart click interactions control karne ke liye
document.addEventListener("DOMContentLoaded", () => {
    const cartButtons = document.querySelectorAll(".add-to-cart-btn");

    cartButtons.forEach((btn, index) => {
        btn.addEventListener("click", (e) => {
            e.preventDefault();
            alert(`Item ${index + 1} added to your shopping cart!`);
        });
    });
});