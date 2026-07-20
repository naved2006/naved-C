
    (function() {
      // ---------- STATE ----------
      let products = [];               // array of product objects
      let currentEditId = null;       // if editing, store id
      let sortOrder = 'none';         // 'low-high', 'high-low'
      let searchTerm = '';
      let categoryFilter = '';

      // DOM references
      const form = document.getElementById('productForm');
      const titleInput = document.getElementById('titleInput');
      const priceInput = document.getElementById('priceInput');
      const imageInput = document.getElementById('imageInput');
      const categoryInput = document.getElementById('categoryInput');
      const addBtn = document.getElementById('addBtn');
      const productGrid = document.getElementById('productGrid');
      const searchInput = document.getElementById('searchInput');
      const categoryFilterSelect = document.getElementById('categoryFilter');
      const sortLowHigh = document.getElementById('sortLowHigh');
      const sortHighLow = document.getElementById('sortHighLow');
      const resetFiltersBtn = document.getElementById('resetFilters');

      // ---------- HELPERS ----------
      function generateId() {
        return Date.now().toString(36) + Math.random().toString(36).substring(2, 8);
      }

      // ---------- LOCAL STORAGE ----------
      function loadFromStorage() {
        const stored = localStorage.getItem('productManager_products');
        if (stored) {
          try {
            products = JSON.parse(stored);
          } catch(e) { products = []; }
        } else {
          // seed with demo products
          products = [
            { id: generateId(), title: 'Wireless Mouse', price: 29.99, image: 'https://placehold.co/200x150/EEE/2a7de1?text=Mouse', category: 'Electronics' },
            { id: generateId(), title: 'Mechanical Keyboard', price: 89.50, image: 'https://placehold.co/200x150/EEE/2a7de1?text=Keyboard', category: 'Electronics' },
            { id: generateId(), title: 'USB-C Hub', price: 45.00, image: 'https://placehold.co/200x150/EEE/2a7de1?text=Hub', category: 'Accessories' },
            { id: generateId(), title: 'Desk Lamp', price: 24.99, image: 'https://placehold.co/200x150/EEE/2a7de1?text=Lamp', category: 'Home' },
          ];
          saveToStorage();
        }
        // update category filter options
        populateCategoryFilter();
      }

      function saveToStorage() {
        localStorage.setItem('productManager_products', JSON.stringify(products));
      }

      // ---------- POPULATE CATEGORY DROPDOWN ----------
      function populateCategoryFilter() {
        const categories = products.map(p => p.category).filter(Boolean);
        const unique = [...new Set(categories)];
        const currentVal = categoryFilterSelect.value;
        categoryFilterSelect.innerHTML = '<option value="">All categories</option>';
        unique.forEach(cat => {
          const option = document.createElement('option');
          option.value = cat;
          option.textContent = cat;
          categoryFilterSelect.appendChild(option);
        });
        // restore selected value if still valid
        if ([...categoryFilterSelect.options].some(o => o.value === currentVal)) {
          categoryFilterSelect.value = currentVal;
        } else {
          categoryFilterSelect.value = '';
        }
        categoryFilter = categoryFilterSelect.value;
      }

      // ---------- RENDER (with filters, sort, search) ----------
      function renderProducts() {
        let filtered = [...products];

        // search
        if (searchTerm.trim() !== '') {
          const term = searchTerm.trim().toLowerCase();
          filtered = filtered.filter(p => p.title.toLowerCase().includes(term));
        }

        // category filter
        if (categoryFilter) {
          filtered = filtered.filter(p => p.category === categoryFilter);
        }

        // sort
        if (sortOrder === 'low-high') {
          filtered.sort((a, b) => a.price - b.price);
        } else if (sortOrder === 'high-low') {
          filtered.sort((a, b) => b.price - a.price);
        }

        // render grid
        if (filtered.length === 0) {
          productGrid.innerHTML = `<div class="empty-message"><i class="fas fa-box-open" style="font-size:2rem; display:block; margin-bottom:0.5rem;"></i> No products found</div>`;
          return;
        }

        let html = '';
        filtered.forEach(product => {
          const imageSrc = product.image && product.image.trim() !== '' ? product.image : 'https://placehold.co/200x150/EEE/2a7de1?text=No+Image';
          html += `
            <div class="product-card" data-id="${product.id}">
              <div class="img-wrap">
                <img src="${imageSrc}" alt="${product.title}" loading="lazy" onerror="this.src='https://placehold.co/200x150/EEE/2a7de1?text=Error'">
              </div>
              <div class="card-body">
                <div class="title">${escapeHtml(product.title)}</div>
                <span class="category">${escapeHtml(product.category || 'Uncategorized')}</span>
                <div class="price">₹ ${Number(product.price).toFixed(2)}</div>
                <div class="card-actions">
                  <button class="edit-btn" data-id="${product.id}"><i class="fas fa-pen"></i> Edit</button>
                  <button class="delete-btn" data-id="${product.id}"><i class="fas fa-trash-alt"></i> Delete</button>
                </div>
              </div>
            </div>
          `;
        });
        productGrid.innerHTML = html;

        // attach event listeners to edit/delete buttons
        document.querySelectorAll('.edit-btn').forEach(btn => {
          btn.addEventListener('click', function(e) {
            const id = this.dataset.id;
            editProduct(id);
          });
        });

        document.querySelectorAll('.delete-btn').forEach(btn => {
          btn.addEventListener('click', function(e) {
            const id = this.dataset.id;
            deleteProduct(id);
          });
        });
      }

      // simple escape to prevent XSS
      function escapeHtml(text) {
        if (!text) return '';
        const map = { '&': '&amp;', '<': '&lt;', '>': '&gt;', '"': '&quot;', "'": '&#039;' };
        return String(text).replace(/[&<>"']/g, function(m) { return map[m]; });
      }

      // ---------- CRUD ----------
      function addProduct(event) {
        event.preventDefault();
        const title = titleInput.value.trim();
        const price = parseFloat(priceInput.value);
        const image = imageInput.value.trim();
        const category = categoryInput.value.trim();

        if (!title || isNaN(price) || price < 0) {
          alert('Please enter a valid title and price (positive number).');
          return;
        }

        // if editing mode
        if (currentEditId) {
          // update existing
          const index = products.findIndex(p => p.id === currentEditId);
          if (index !== -1) {
            products[index] = { 
              ...products[index], 
              title, 
              price, 
              image: image || products[index].image, 
              category: category || products[index].category 
            };
            currentEditId = null;
            addBtn.innerHTML = '<i class="fas fa-plus-circle"></i> Add Product';
          } else {
            // fallback
            currentEditId = null;
            addBtn.innerHTML = '<i class="fas fa-plus-circle"></i> Add Product';
          }
        } else {
          // create new
          const newProduct = {
            id: generateId(),
            title,
            price,
            image: image || '',
            category: category || 'Uncategorized'
          };
          products.push(newProduct);
        }

        saveToStorage();
        clearForm();
        populateCategoryFilter();
        renderProducts();
        // reset filters/ sort state? we keep them
      }

      function editProduct(id) {
        const product = products.find(p => p.id === id);
        if (!product) return;

        // fill form
        titleInput.value = product.title;
        priceInput.value = product.price;
        imageInput.value = product.image || '';
        categoryInput.value = product.category || '';

        currentEditId = id;
        addBtn.innerHTML = '<i class="fas fa-save"></i> Update Product';
        // scroll to form
        form.scrollIntoView({ behavior: 'smooth', block: 'center' });
        titleInput.focus();
      }

      function deleteProduct(id) {
        if (!confirm('Delete this product?')) return;
        products = products.filter(p => p.id !== id);
        saveToStorage();
        if (currentEditId === id) {
          currentEditId = null;
          addBtn.innerHTML = '<i class="fas fa-plus-circle"></i> Add Product';
          clearForm();
        }
        populateCategoryFilter();
        renderProducts();
      }

      function clearForm() {
        titleInput.value = '';
        priceInput.value = '';
        imageInput.value = '';
        categoryInput.value = '';
        currentEditId = null;
        addBtn.innerHTML = '<i class="fas fa-plus-circle"></i> Add Product';
      }

      // ---------- FILTER / SORT HANDLERS ----------
      function applyFiltersAndRender() {
        searchTerm = searchInput.value;
        categoryFilter = categoryFilterSelect.value;
        renderProducts();
      }

      // ---------- INIT ----------
      function init() {
        loadFromStorage();
        renderProducts();

        // form submit
        form.addEventListener('submit', addProduct);

        // search
        searchInput.addEventListener('input', function() {
          searchTerm = this.value;
          renderProducts();
        });

        // category filter
        categoryFilterSelect.addEventListener('change', function() {
          categoryFilter = this.value;
          renderProducts();
        });

        // sort buttons
        sortLowHigh.addEventListener('click', function() {
          sortOrder = (sortOrder === 'low-high') ? 'none' : 'low-high';
          renderProducts();
          // toggle active style
          sortLowHigh.classList.toggle('active', sortOrder === 'low-high');
          sortHighLow.classList.remove('active');
        });

        sortHighLow.addEventListener('click', function() {
          sortOrder = (sortOrder === 'high-low') ? 'none' : 'high-low';
          renderProducts();
          sortHighLow.classList.toggle('active', sortOrder === 'high-low');
          sortLowHigh.classList.remove('active');
        });

        // reset filters
        resetFiltersBtn.addEventListener('click', function() {
          searchInput.value = '';
          searchTerm = '';
          categoryFilterSelect.value = '';
          categoryFilter = '';
          sortOrder = 'none';
          sortLowHigh.classList.remove('active');
          sortHighLow.classList.remove('active');
          renderProducts();
        });
      }

      // start
      init();
    })();