export function addAliasForm() {
    const nav = document.querySelector('#tournament');
    if (nav) {
        nav.addEventListener('submit', function (event) {
            event.preventDefault();
            const alias = document.querySelector('#alias').value;

            // Envoyer le nom d'utilisateur au serveur
            fetch('/game/tournament-add-alias/', {
                method: 'POST',
                headers: {
                    'Content-Type': 'application/json',
                },
                body: JSON.stringify({ formAddAlias: "formAddAlias", alias: alias }),
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
                        addAliasForm();
                        returnButton();
                    }
                })
                .catch((error) => { });
        });

    }
}

export function returnButton() {

    const nav = document.querySelector('#tournament');
    if (nav) {
        nav.addEventListener('click', function (event) {
            // Check if the clicked element is the button you're interested in
            if (event.target.id === 'returnTournament') {
                event.preventDefault();
                fetch('/game/delTournament/', {
                    method: 'POST',
                    headers: {
                        'Content-Type': 'application/json',
                    },
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
                            history.pushState(null, null, '/game_menu/');
                            returnButton();
                        }
                    })
                    .catch((error) => { });
            }
        });
    }
}