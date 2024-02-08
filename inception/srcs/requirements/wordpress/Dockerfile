FROM  debian:buster

RUN apt-get update && apt-get upgrade -y

RUN apt-get -y install wget \
        curl \ 
        php7.3 \
        netcat \
        php-cgi \
        php-mysqli \
        php-fpm \
        mariadb-client \
        sendmail \
        php-pdo \
        php-gd php-cli \
        php-mbstring \
        redis \
        php-redis


#RUN chmod +x ./tools/wait-for-it.sh


COPY ./conf/www.conf  /etc/php/7.3/fpm/pool.daemon
COPY ./conf /var/www/
#COPY ./tools/wait-for-it.sh /usr/local/bin/wait-for-it.sh


EXPOSE 9000

CMD [ "bash", "/var/www/setup.sh" ]

 


