document.getElementById("login-form").addEventListener("submit", function(event) {
    const emailInput = document.getElementsByName("email")[0];
    const emailValue = emailInput.value;

    if (!validateEmail(emailValue)) {
        event.preventDefault();
        alert("Please enter a valid MITWPU email address.");
    }
});

function validateEmail(email) {
    const pattern = /^[a-zA-Z0-9._%+-]+@mitwpu\.edu\.in$/;
    return pattern.test(email);
}
