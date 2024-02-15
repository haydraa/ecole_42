FROM debian:bullseye

RUN apt update \
    && apt upgrade \
    && apt install -y wget sed php7.4 php-fpm php-mysql php

RUN mkdir -p /var/www/html \
    && chown -R www-data:www-data /var/www/html

RUN if [ -d "/var/html/wordpress" ]; then \
        echo "wordpress already downloaded"; \
    else \
        wget https://fr.wordpress.org/wordpress-6.0-fr_FR.tar.gz -P /var/ && \
	    tar -xf /var/wordpress-6.0-fr_FR.tar.gz -C /var/www/html; \
    fi

COPY ./conf/wordpress.conf /etc/php/7.4/fpm/pool.d/www.conf

COPY ./conf/wp-config.sh /tmp/wp-config.sh
RUN chmod +x /tmp/wp-config.sh

ENTRYPOINT ["sh", "/tmp/wp-config.sh"]

 


