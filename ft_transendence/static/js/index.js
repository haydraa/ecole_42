import { RegisterForm, LoginForm } from "./forms/logs.js";
import { AddFriendForm } from "./forms/friends.js";
import { addAliasForm, returnButton } from "./forms/tournament.js";
import { UpdateInfoForm } from "./forms/setting.js";
import { PongStart } from "./game/pong.js";
import { PongStartTournament } from "./game/tournament_pong.js"
import { Lougout, DeleteAccount } from "./logout_destroy.js"

export const navigateTo = url => {
    history.pushState(null, null, url);
    router(url);
};

const router = async (url) => {
    const path = url || window.location.pathname;
    fetch(path)
        .then(response => response.text())
        .then(data => {
            const parser = new DOMParser();
            const doc = parser.parseFromString(data, 'text/html');
            const newBody = doc.body;
            const newHeader = doc.head;
            document.body.innerHTML = newBody.innerHTML;
            document.head.innerHTML = newHeader.innerHTML;

            switch (location.pathname) {
                case "/register/":
                    RegisterForm();
                    break;
                case "/login/":
                    LoginForm();
                    break;
                case "/setting/":
                    UpdateInfoForm();
                    DeleteAccount();
                    break;
                case "/game/pong/":
                    PongStart();
                    break;
                case "/game/tournament-lobby/":
                    addAliasForm();
                    returnButton();
                    break;
                case "/game/start-tournament/":
                    returnButton();
                    break;
                case "/game/tournament/":
                    returnButton();
                    break;
                case "/game/start-match/":
                    PongStartTournament();
                    returnButton();
                    break;
                case "/game/end-of-tournament/":
                    returnButton();
                    break;
                case "/friends-list/":
                    AddFriendForm();
                    break;
                default:
                    Lougout();
                    break;
            }
        });
};

window.addEventListener("popstate", () => {
    router(window.location.pathname);
});

document.addEventListener("DOMContentLoaded", () => {
    document.body.addEventListener("click", e => {
        if (e.target.matches("[data-link]")) {
            e.preventDefault();
            navigateTo(e.target.href);
        }
    });
    router(window.location.pathname);
});
