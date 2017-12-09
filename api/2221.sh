# Parar todos los contenedores
docker stop $(docker ps -a -q)

# Eliminar todos los contenedores
docker rm $(docker ps -a -q)

##Build an image from the Dockerfile assign it a name.
docker build -t api_app .

docker run  -ti -p 8082:80 --name pg_test_sw api_app  /bin/bash
