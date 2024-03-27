export function UpdateInfoForm() {
    const form = document.querySelector('#formUpdateInfo');
    if (form) {
        form.addEventListener('submit', function (event) {
            event.preventDefault();
            const username = document.querySelector('#newUsername').value;
            const battleTag = document.querySelector('#newBattleTag').value;
            const password = document.querySelector('#newpassword').value;
            const avatar = document.querySelector('#newAvatar').files[0];

            const formData = new FormData();
            formData.append('formUpdateInfo', 'formUpdateInfo');
            formData.append('username', username);
            formData.append('battleTag', battleTag);
            formData.append('password', password);
            formData.append('avatar', avatar);

            // Envoyer le nom d'utilisateur au serveur
            fetch('/update-info/', {
                method: 'POST',
                body: formData,
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
                    }
                })
                .catch((error) => { });
        });
    } else {
        console.error('Form id "formUpdateInfo" not found.');
    }
}