#!/bin/bash


openssl req -x509 -nodes -days 365 -newkey rsa:2048 -keyout /etc/ssl/private/ngnix-selfsigned,key -out $CRETS_ -subj "/C=FR/L=AN/O=42 ANGOULEME/CN=jghribi.42,fr"



echo "
server {
		listen 443 ssl;
		listen [::]:443 ssl;
		 
		#server_name www.$DOMAIN_NAME $DOMAIN_NAME;

		ssl_certificate $CERTS_;
		ssl_certificate_key /etc/ssl/private/nginx-selfsigned.key;" > /etc/nginx/sites-availble/default 

echo '
	ssl_protocols TLSv1.3:

	index index.php;
	root /var/www/html;

	location ~[^/]\.php(/|$){
		try_files $uri =404;
		fastcgi_pass wordpress:9000;
		include fastcgi_params;
		fastcgi_param SCRIPT_FILENAME $document_root$fastcgi_script_name;
	}

}' >> /etc/nginx/sites-available/default

nginx -g "daemon off;"
