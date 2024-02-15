FROM debian:bullseye

RUN apt update -y\
    && apt upgrade -y

RUN mkdir -p /etc/nginx/ssl
RUN apt install -y nginx openssl
RUN openssl req -x509 -nodes \
    -out /etc/nginx/ssl/nginx.crt \
    -keyout /etc/nginx/ssl/nginx.key \
    -subj "/C=FR/ST=IDF/L=Paris/O=42/OU=42/CN=jghribi.42.fr/UID=jghribi"

RUN mkdir -p /var/run/nginx
COPY ./conf/nginx.conf /etc/nginx/sites-available/default
 
EXPOSE 443

RUN mkdir -p /var/www/html
# RUN chmod 755 /var/www/wordpress
RUN chown -R www-data:www-data /var/www/html

CMD ["nginx", "-g", "daemon off;"]

