docker stop nginx wordpress mariadb
docker container prune
docker rmi -f $(docker images -a -q)
