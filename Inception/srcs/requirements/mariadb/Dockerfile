FROM		debian:buster

RUN			apt-get update -y && \
			apt-get upgrade -y && \
			apt-get -y install mariadb-server \
			mariadb-client \
			vim

CMD			echo "\ndaemon off;" >> /etc/mysql/mariadb.cnf
COPY		./sets/mariadb_setup.sh		/tmp/mariadb_setup.sh
COPY		./conf/50-server.cnf		/etc/mysql/mariadb.conf.d/

ENTRYPOINT	["sh", "/tmp/mariadb_setup.sh"]

EXPOSE 		3306
