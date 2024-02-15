FROM debian:bullseye

ARG SQL_DATABASE
ARG SQL_HOST
ARG SQL_USER
ARG SQL_PASSWORD
ARG SQL_ROOT_PASSWORD

RUN apt update -y &&\
    apt upgrade -y &&\
    apt install -y mariadb-server && \
    service mariadb start && \
    sleep 5 &&\
    mysql -u root -e "CREATE USER IF NOT EXISTS '$SQL_USER'@'%' IDENTIFIED BY '$SQL_PASSWORD';\ 
                      CREATE DATABASE IF NOT EXISTS $SQL_DATABASE; \
                      GRANT ALL PRIVILEGES ON $SQL_DATABASE.* TO '$SQL_USER'@'%'; \
                      ALTER USER 'root'@'localhost' IDENTIFIED BY '$SQL_ROOT_PASSWORD'; "
                     

COPY ./conf/50-server.cnf ./etc/mysql/mariadb.conf.d/50-server.cnf

ENTRYPOINT [ "mysqld_safe" ]