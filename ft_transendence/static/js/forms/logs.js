// import checkLoginStatus from "./checkLogin.js";
import { navigateTo } from "../index.js";

export function RegisterForm() {
    const form = document.querySelector('#formRegister');
    if (form) {
        form.addEventListener('submit', function (event) {
            event.preventDefault();
            const username = document.querySelector('#usernameRegister').value;
            const email = document.querySelector('#emailRegister').value;
            const password = document.querySelector('#passwordRegister').value;

            // Envoyer le nom d'utilisateur au serveur
            fetch('/register/', {
                method: 'POST',
                headers: {
                    'Content-Type': 'application/json',
                },
                body: JSON.stringify({ RegisterForm: "RegisterForm", username: username, email: email, password: password }),
            })
            .then(response => {
                const contentType = response.headers.get("content-type");

                if (contentType && contentType.includes("application/json")) {
                    return response.json();
                }
                else if (contentType && contentType.includes("text/html")) {
                    return response.text();
                }
            })
            .then(data => {
                if (typeof data === 'object') {
                    console.log('JSON data : ', data);
                }
                else {
                    const parser = new DOMParser();
                    const doc = parser.parseFromString(data, 'text/html');
                    const newBody = doc.body;
                    const newHeader = doc.head;
                    document.body.innerHTML = newBody.innerHTML;
                    document.head.innerHTML = newHeader.innerHTML;
                    navigateTo('/');
                }
            })
            .catch((error) => {});
        });
    } else {
        console.error('Form id "formRegister" not found.');
    }
}

export function LoginForm() {
    const form = document.querySelector('#formLogin');
    if (form) {
        form.addEventListener('submit', function (event) {
            event.preventDefault();
            const username = document.querySelector('#usernameLogin').value;
            const password = document.querySelector('#passwordLogin').value;

            // Envoyer le nom d'utilisateur au serveur
            fetch('/login/', {
                method: 'POST',
                headers: {
                    'Content-Type': 'application/json',
                },
                body: JSON.stringify({ LoginForm: "LoginForm", username: username, password: password }),
            })
                .then(response => {
                    const contentType = response.headers.get("content-type");

                    if (contentType && contentType.includes("application/json")) {
                        return response.json();
                    }
                    else if (contentType && contentType.includes("text/html")) {
                        return response.text();
                    }
                })
                .then(data => {
                    if (typeof data === 'object') {
                        console.log('JSON data : ', data);
                    }
                    else {
                        const parser = new DOMParser();
                        const doc = parser.parseFromString(data, 'text/html');
                        const newBody = doc.body;
                        const newHeader = doc.head;
                        document.body.innerHTML = newBody.innerHTML;
                        document.head.innerHTML = newHeader.innerHTML;
                        navigateTo('/');
                    }
                })
                .catch((error) => {});
        });
    } else {
        console.error('Form id "LoginForm" not found.');
    }
}

setTimeout(() => {
    const logoutButton = document.querySelector('.button-logout');
    if (logoutButton) {
        logoutButton.addEventListener('click', e => {
            e.preventDefault();
            Logout();
        });
    }
}, 0);

export function Logout() {
    // if (checkLoginStatus()) {
    fetch('logout/', {
        method: 'POST',
        headers: {
            'Content-Type': 'application/json'
        },
        body: JSON.stringify({})
    })
        .then(response => {
            if (!response.ok) {
                throw new Error('Network response was not ok');
            }
        })
        .catch(error => {
            console.error('There has been a problem with your fetch operation:', error);
        });
}
// }