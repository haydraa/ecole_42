FROM debian:buster

RUN apt-get update
RUN apt-get install -y nginx && apt install openssl -y 


RUN mkdir /etc/nginx/ssl

RUN openssl req -newkey rsa:4096 -x509 -sha256 -days 365 -nodes \
 -out $CRETS_ \
 -keyout /etc/ssl/private/ngnix-selfsigned.key \ 
-subj "/C=FR/L=AN/O=42 ANGOULEME/CN=jghribi.42.fr"

COPY conf/nginx.conf  /etc/nginx.conf

RUN mkdir -p /run/nginx

EXPOSE 443

CMD ["ngnix", "-g", "daemon off;"]


