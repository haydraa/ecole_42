FROM debian:buster

RUN apt-get update && \
    apt-get install -y mariadb-server && \
    apt-get clean && \
    rm -rf /var/lib/apt/lists/*

COPY ./conf/mysqld.conf /etc/mysqld/mariadb.conf.d/
COPY ./tools/createdb.sql /docker-entrypoint-initdb.d/

# RUN service mysql start && \
   # mysql < createdb.sql && \
   # rm -f createdb.sql

EXPOSE 3306

CMD [ "mysqld_safe" ] 