FROM nginx:1.25

# Remove default configuration file
RUN rm /etc/nginx/conf.d/default.conf

RUN mkdir -p /etc/nginx/ssl
RUN apt install -y nginx openssl
RUN openssl req -x509 -nodes \
    -out /etc/nginx/ssl/nginx.crt \
    -keyout /etc/nginx/ssl/nginx.key \
    -subj "/C=FR/ST=IDF/L=Paris/O=42/OU=42/CN=transandance.42.fr/UID=*"

# Copy your custom Nginx configuration file
COPY nginx.conf /etc/nginx/conf.d
