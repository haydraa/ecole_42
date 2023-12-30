FROM debian:buster

RUN apt-get update
RUN apt-get install -y mariadb-server \
    mariadb-client \
    vim \
    && rm -rf /var/lib/apt/lists/*




RUN mkdir -p /var/run/mysqld && chown -R mysql:mysql /var/run/mysqld && chmod 777 /var/run/mysqld

EXPOSE 3306

COPY ./tools/mariadb.sh /usr/local/bin

RUN chmod +x /usr/local/bin/mariadb.sh

ENTRYPOINT [ "/usr/local/bin/mariadb.sh" ]

CMD [ "mysqld", "--bin-address=0.0.0.0" ]
