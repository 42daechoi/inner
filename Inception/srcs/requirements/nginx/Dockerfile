FROM 		debian:buster

RUN 		apt-get update -y && \
			apt-get upgrade -y && \
			apt-get install nginx -y && \
			apt-get install openssl -y && \
			apt-get install vim -y

COPY 		conf/nginx.conf /etc/nginx/sites-available/default

RUN 		openssl req -newkey rsa:4096 -days 365 -nodes -x509 \
			-subj "/C=KR/ST=Seoul/L=Seoul/O=42Seoul/OU=Gam/CN=localhost" \
			-out /etc/ssl/certs/daechoi.42.fr.crt \
			-keyout /etc/ssl/private/daechoi.42.fr.key

ENTRYPOINT	["nginx", "-g", "daemon off;"]

EXPOSE 		443
