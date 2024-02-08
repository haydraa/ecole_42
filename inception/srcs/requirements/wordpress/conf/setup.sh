#!/bin/bash

sed -i "s/listen = \/run\/php\/php7.3-fpm.sock/listen = 9000/" "/etc/php/7.3/fpm/pool.d/www.conf";
mkdir -p /var/www/wordpress;
chown -R www-data:www-data /var/www/*;
chmod -R 775 /var/www/*;

mkdir -p /run/php/;
touch /run/php/php7.3-fpm.pid;

if [ ! -f /var/www/html/wp-config.php ]; then
  mkdir -p /var/www/html
  wget https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar;
  chmod +x wp-cli.phar;
  mv wp-cli.phar /usr/local/bin/wp;

  cd /var/www/html;

  wp core download --allow-root;

  mv /var/www/wp-config.php /var/www/html

  wp core install --allow-root --url=${DOMAIN_NAME} --title=${WP_NAME} --admin_user=${WP_ROOT_LOGIN} --admin_password=${MYSQL_ROOT_PASSWORD} --admin_email=${WP_ROOT_EMAIL};
  wp user create  --allow-rot ${MYSQL_USER} ${WP_USER_EMAIL} --user_pass=${MYSQL_PASSWORD};
fi

/usr/sbin/php-fpm7.3 -F
