FROM		debian:buster

RUN			apt-get update -y && \
			apt-get upgrade -y && \
			apt-get -y install php7.3-fpm \
			wget \
			tar \
			vim \
			curl \
			php-cli \
			php-mysql \
			sudo \
			mariadb-client

COPY		./conf/www.conf /etc/php/7.3/fpm/pool.d/www.conf
COPY		./sets/wordpress_setup.sh /tmp/wordpress_setup.sh

RUN			wget https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar && \
			chmod +x wp-cli.phar && mv wp-cli.phar /usr/bin/wp

WORKDIR		/var/www/html/wordpress
RUN			mkdir -p /run/php

EXPOSE		9000

ENTRYPOINT	["sh", "/tmp/wordpress_setup.sh"]
