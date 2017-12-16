#ifndef BLOWFISH_H
#define BLOWFISH_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <openssl/bio.h>
#include <openssl/blowfish.h>
#include <openssl/rand.h>
#include <openssl/evp.h>
#include <openssl/buffer.h>
#include <openssl/err.h>

    /**
     * @typede typedef unsigned char byte
     * Definición por comodidad de un unsigned char byte 
     */
    typedef unsigned char byte;

    /**
     * Función que calcula el tamaño de bloque en función de la potencia de 
     * 2 inmediatamente superior al parámetro dado.
     * @param len tamaño a estimar
     * @return la potencia de 2 inmmediamente superior al largo pasado.
     */
    unsigned long estimate_block_size(unsigned int len);

    /**
     * @fn char* hex2str(byte *hex, unsigned int len)
     * @param hex representación hexadecimal.
     * @param len largo del mensaje hexadecimal.
     * @return una representación string del mensaje hexadecimal.
     * @retval char*
     */
    char* hex2str(byte *hex, unsigned int len);

    /**
     * 
     * @param texto texto con la representación hexadecimal de la memoria
     * @param len largo del texto
     * @return un arreglo de bytes
     */
    byte* str2hex(char *texto, unsigned int len);

    /**
     * 
     * @param llave palabra en texto claro.
     * @param mensaje Mensaje a cifrar.
     * @return El mensaje cifrado represendo hexadecimalmente en minúsculas.
     */
    char* cifrar(char* llave, char* mensaje);

    /**
     * 
     * @param llave palabra en texto claro.
     * @param mensaje Mensaje representado hexadecimalmente a descifrar.
     * @return El mensaje descifrado (si la llave es correcta) o basura en 
     * cualquier otro caso.
     */
    char* descifrar(char* llave, char* mensaje);

#ifdef __cplusplus
}
#endif

#endif /* BLOWFISH_H */

