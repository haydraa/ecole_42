#!bin/sh

mysql_install_db

/etc/init.d/mysql start

if [ -d "/var/lib/mysql/$MYSQL_DATABASE" ]
then
    echo "DATA BASE EXISTE"

else
    mysql_secure_installation << _EOF_

    Y
    root1234
    root1234
    Y
    n
    Y
    Y
    _EOF_

    echo "GRANT ALL ON *.* 'root'@'%' IDENTFIED BY '$MYSQL_ROOT_PASSWORFD'; FLUSH PRIVILEGES;" | mysql -uroot

    echo "GRAMT ALL ON *.* TO 'root'@'%' IDENTIFIED BY '$MYSQL_ROOT_PASSWORD'; FLUSH PRIVILEGES;" | mysqls -uroot


fi
/etc/init.d/musql stop

exec "$@"
