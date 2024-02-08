<?php

define('DB_NAME', 'wordpress');
define('DB_USER', 'jghribi');
define('DB_PASSWORD', '1234');
define('DB_HOST', 'mariadb');
define('DB_CHARSET', 'utf8');
define('DB_COLLATE', '');

$table_prefix = 'wp_';

define('AUTH_KEY',         'qvQz(eqh}5~;S5TR#R:T&C?V;`9^SKZj.Z^]z?i`mhO?E-g0jA(3|T:<q?uBK#36');
define('SECURE_AUTH_KEY',  'I]Lar9Kn_+|>6Yn>QuxXX~~H<vwZW=J!|_O06B-b_-M_{iPd^`S~O#rL8[k#_3Qx');
define('LOGGED_IN_KEY',    'B,,slhS>=QaZ4a,[$3d}w@3G>t=-rVn|af;e^Y1N)|P De0]PJ-AoG6I]Oa;`}hA');
define('NONCE_KEY',        '$-1g>/*G+^W3NusCW3<+li GS%jG#emQ_c!kpUd@`hvLt@9Mr2,<2E)+@sFT@&_f');
define('AUTH_SALT',        'G(cJz*p)_fBbi:}Sb&gF+Kx{#w-MVHM?J.>jm.H=l)L~dqFaQ|-AN3/-/M DD@pg');
define('SECURE_AUTH_SALT', '6&W-;`Q4wz{m|o`Az/ZS9:~f5H0*45C[w95U[S|N+v%39`x~l};fSjlY4C[Ept2G');
define('LOGGED_IN_SALT',   '+qr-6C[G>uB=+>uWrU>XsV} fEosQvMNPoVED==+QW]}C{J [:p-ko%&@Et_!b$@');
define('NONCE_SALT',       'Q!G2)qR(Gdzy(7>m,+M+]Geac%R9+VAIW0EoslA+C)<> w=d9`pygGtn4+.U~?1=');

$table_prefix = 'wp_';

define('WP_DEBUG', false);

if (!defined('ABSPATH')) {
    define('ABSPATH', __DIR__ . '/');
}

require_once ABSPATH . 'wp-settings.php';
