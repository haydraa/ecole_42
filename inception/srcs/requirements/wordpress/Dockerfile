FROM  debian:buster

RUN apt-get update && apt-get upgrade

RUN apt-get -y install wget \
        wget\
        curl\ 
        bash\
        php\
        php-cgi\
        php-mysql\
        php-fpm\
        php-pdo\
        php-gd php-cli\
        php-mbstring\
        redis\
        php-redis && rm-rf /var/lib/apt/lists/*


RUN curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar/ \
 && chmod +x wp-cli.phar && mv wp-cli.phar /usr/local/bin/wp


 


