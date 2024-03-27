import { navigateTo } from "./index.js"

export function Lougout() {
    const lougout = document.getElementById('lougout');
    if (lougout) {
        lougout.addEventListener('click', function (event) {
            event.preventDefault();

            fetch('/logout/', {
                method: 'POST',
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
                .catch((error) => { });
        });
    } else {
        console.error('Lougout has been defused');
    }
}

export function DeleteAccount() {
    const del = document.getElementById('delete');
    if (del) {
        del.addEventListener('click', function (event) {
            event.preventDefault();

            fetch('/delete-account/', {
                method: 'POST',
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
                .catch((error) => { });
        });
    } else {
        console.error('Delete has been defused');
    }
}