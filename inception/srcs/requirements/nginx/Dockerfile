FROM debian:buster

RUN apt-get update
RUN apt-get install -y nginx && apt install openssl -y 


RUN mkdir /etc/nginx/ssl

openssl req -x509 -nodes -days 365 -newkey rsa:2048 -keyout \
/etc/ssl/private/ngnix-selfsigned.key -out $CRETS_ \
-subj "/C=FR/L=AN/O=42 ANGOULEME/CN=jghribi.42,fr"


COPY conf/nginx.conf  /etc/nginx.conf

CMD ["/script.sh"]

