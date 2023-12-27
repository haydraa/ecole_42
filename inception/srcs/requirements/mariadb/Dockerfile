FROM debian:buster

RUN apt-get update
RUN apt-get install -y mariadb-server \
    mariadb-client \
    vim \
    && rm -rf /var/lib/apt/lists/*

RUN mkdir -p /var/run/mysqld && chown -R mysqld:mysql /var/run/mysqld && chmod 777 /var/run/mysql

EXPOSE 3306

