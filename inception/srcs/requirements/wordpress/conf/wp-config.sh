#!/bin/sh

mkdir -p /run/php 
chmod 777 /var/www/html/wordpress
chown -R root:root /var/www/html/wordpress

if [ -f "/var/www/html/wordpress/wp-config.php" ]; then \
    echo "wordpress configuration file already set"; \
else \
    sleep 10
    wget https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar -P /var/
    chmod +777 /var/wp-cli.phar
    mv /var/wp-cli.phar /usr/local/bin/wp
    chown -R root:root /usr/local/bin/wp

    sed -i "s/votre_nom_de_bdd/$SQL_DATABASE/g" /var/www/html/wordpress/wp-config-sample.php
    sed -i "s/votre_utilisateur_de_bdd/$SQL_USER/g" /var/www/html/wordpress/wp-config-sample.php
    sed -i "s/votre_mdp_de_bdd/$SQL_PASSWORD/g" /var/www/html/wordpress/wp-config-sample.php
    sed -i "s/localhost/$SQL_HOST/g" /var/www/html/wordpress/wp-config-sample.php

    cp /var/www/html/wordpress/wp-config-sample.php /var/www/html/wordpress/wp-config.php
    wp core install --skip-plugins --allow-root --path=/var/www/html/wordpress --url=$WP_URL --title=$WP_TITLE --admin_name=$WP_ADMIN --admin_password=$WP_ADMIN_PW --admin_email=$WP_ADMIN_EMAIL

    wp user create --path=/var/www/html/wordpress $WP_USR $WP_USR_MAIL --role=editor --user_pass=$WP_USR_PW --allow-root;
fi

php-fpm7.4 -R -F