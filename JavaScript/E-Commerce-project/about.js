// JavaScript interactiveness add karne ke liye
document.addEventListener("DOMContentLoaded", () => {
    const galleryItems = document.querySelectorAll(".gallery-item");

    galleryItems.forEach(item => {
        item.addEventListener("click", () => {
            const id = item.getAttribute("data-id");
            console.log(`Furniture Image ${id} clicked!`);
            // Aap yahan par lightbox image popup ya koi preview open kar sakte hain
        });
    });
});