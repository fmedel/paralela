##Build an image from the Dockerfile assign it a name.
docker build -t ubuntu_prueba .
docker run -it  ubuntu_prueba /bin/bash
