FROM debian:buster

RUN apt-get update
RUN apt-get install -y nginx && apt install openssl -y 


COPY ./tools/scripts.sh /

CMD ["/script.sh"]

