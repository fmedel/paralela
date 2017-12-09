# CryptoApp

## Introducción

Es el programa base para cifrar usando el algoritmo **blowfish** es necesario tener instalado openssl (sudo apt-get install libssl-dev).

## Compilación

Para compilar es necesario disponer del programa make (sudo apt-get install make) y ejecutar:

make

## Ejecución

./dist/cryptoapp [opcion] [llave] [mensaje] 

**[opcion]** puede ser [enc] => cifrar y [dec] => descifrar 
**[llave]** es una secuencia de caracteres usadas como llave simetrica 
**[mensaje]** texto a cifrar/descifrar 

 === Ejemplo para cifrar CIFRADO === 
./dist/cryptoapp enc asdf "Hola curso..." 

 === Ejemplo para cifrar CIFRADO === 
./dist/cryptoapp dec asdf "37727ac53c8dea90d386ebd2b763eb0b"





