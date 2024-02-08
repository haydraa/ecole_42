FROM debian:buster

RUN apt-get update
RUN apt-get install -y nginx openssl 


RUN mkdir /etc/nginx/ssl
RUN chmod 777 /etc/nginx/ssl
#RUN chmod 777 /etc/ssl/certs/

RUN openssl req \
    -x509 \
    -nodes \
    -days 365 \
    -newkey rsa:2048 \
    -keyout /etc/nginx/ssl/nginx.key \ 
    -out /etc/nginx/ssl/nginx.crt \
    -subj "/C=FR/L=AN/O=42 ANGOULEME/CN=jghribi.42.fr"

COPY ./conf/default  /etc/nginx/sites-enabled/nginx.conf

EXPOSE 443

CMD ["nginx", "-g", "daemon off;"]


