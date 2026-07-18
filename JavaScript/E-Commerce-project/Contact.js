document.addEventListener('DOMContentLoaded', () => {
    const contactForm = document.getElementById('contactForm');

    contactForm.addEventListener('submit', (event) => {
        // Form submit hone par page redirect hone se rokne ke liye
        event.preventDefault();

        // Inputs se value pull karna
        const firstName = document.getElementById('firstName').value;
        const lastName = document.getElementById('lastName').value;
        const subject = document.getElementById('subject').value;
        const message = document.getElementById('message').value;

        // Aapka local data console par safe-keeping ke liye
        const formData = {
            firstName: firstName,
            lastName: lastName,
            subject: subject,
            message: message
        };

        console.log("Form Submitted Successfully!", formData);

        // Alert prompt (Customise kar sakte hain)
        alert(`Thank you, ${firstName}! Your message has been sent successfully.`);

        // Form reset karne ke liye submission ke baad
        contactForm.reset();
    });
});