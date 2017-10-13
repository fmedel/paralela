# tarea2-paralela
paralela
<br>
para pasar a pmm <br>
poner en la linea 1 P3<br>
poner en la linea 2 1024<br>
poner en la linea 3 768<br>
poner en la linea 4 255<br>
<br>
guardar
<br>
linea 1 --> formato<br>
linea 2 --> pixcel ancho<br>
linea 3 -->pixcel alto<br>
linea 4 --> color <br>
<br>
cada linea es un pixcel  tiene RGA(255 255 255)<br>
cada 1024  lineas es un fila de pixcel de la imagen<br>
<hr>
PngaPixcel.c --> pasa png a pixcel <br>
gcc  pngaPixcel.c -o PngaPixcel -lpng <br>
./pngaPixcel [imagen] ---> entrega todos los pixcel del  png a  un archvi de txt <br>
<hr>
1024a4068.cpp ---> pasa solo el ancho de la imagen a 4k falta el ancho
<br>
<hr>
<hr>
libreria
<br>
sudo apt-get install libpng-dev
<br>
For zlib, run:
<br>
sudo apt-get install zlib1g-dev
<br>
sudo apt-get install libpng16-dev

<hr>
Ubuntu
<br>
paquete de Package: netpbm  --> sudo apt-get install netpbm
<br>
pnmtopng [archivo en pnm] > [archivo final]
