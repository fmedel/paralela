##Build an image from the Dockerfile assign it a name.
docker build -t ubuntu_prueba .
docker run  --net=host -it  ubuntu_prueba /bin/bash
