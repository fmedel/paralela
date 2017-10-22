		echo "compilación de los programas"
		gcc  PngaPixcel.c -o PngaPixcel -lpng
		echo "compilación completa PngaPixcel"
		#g++ 1024a4068.cpp -o pasar
		echo "compilación completa 1024a4068"
		echo "ejecutando PngaPixcel"
		./PngaPixcel Monica-Bellucci.png
		echo "finalizo PngaPixcel"
		echo "ejecutando 1024a4068"
		#./pasar
		echo "finalizo 1024a4068"
		echo "eliminacion archivo extras"
		#rm monica_original.txt PngaPixcel pasar
		echo " pasar pnm a png"
		#pnmtopng monica.pmm > monica.png
		echo "finalizo el paso de pn a png"
		#rm monica.pmm
		echo "eliminacion de archivo pmm"
