export function AddFriendForm() {
    const form = document.querySelector('#formAddFriend');
    if (form) {
        form.addEventListener('submit', function (event) {
            event.preventDefault();
            const username = document.querySelector('#usernameSearched').value;

            // Envoyer le nom d'utilisateur au serveur
            fetch('/addFriend/', {
                method: 'POST',
                headers: {
                    'Content-Type': 'application/json',
                },
                body: JSON.stringify({ formAddFriend: "formAddFriend", username: username }),
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
                        AddFriendForm();
                    }
                })
                .catch((error) => { });
        });
    } else {
        console.error('Form id "formAddFriend" not found.');
    }
}