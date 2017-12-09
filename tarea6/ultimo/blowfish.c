#include "blowfish.h"

unsigned long estimate_block_size(unsigned int len) {
    unsigned long largo = 0;
    if (len > 0) {
        largo = 1;
        while (len > largo) {
            largo *= 2;
        }
    }
    return largo;
}

char* hex2str(byte* hex, unsigned int len) {
    int i;
    unsigned long largo = len * 2;
    char *app;
    char *buf;
    app = (char *) calloc(1, sizeof (byte));
    buf = (char *) calloc(largo + 1, sizeof (byte));
    strcpy(buf, "");
    for (i = 0; i < largo; i++) {
        sprintf(app, "%02x", (byte) hex[i]);
        strcat(buf, app);
    }
    buf[largo] = '\0';
    free(app);

    return buf;
}

byte* str2hex(char *texto, unsigned int len) {
    byte* result = (byte *) calloc((len / 2) + 1, sizeof (byte));
    unsigned int i = 0;

    for (i = 0; i < (len / 2); i++) {
        sscanf(texto + 2 * i, "%02x", (unsigned int *) &result[i]);
        //printf("bytearray %d: %02x\n", i, bytearray[i]);
    }

    return result;
}

char* cifrar(char* llave, char* mensaje) {
    // long largo = ((strlen(mensaje) / 8) + 1) * 8;
    unsigned long largo = estimate_block_size(strlen(mensaje));
    byte iv[8] = {8, 8, 8, 8, 8, 8, 8, 8};
    //byte* cifrado = (byte *) mensaje;

    BF_KEY clave;
    BF_set_key(&clave, strlen(llave), (byte *) llave);
    byte *texto = (byte *) calloc(largo, sizeof (byte));

    BF_cbc_encrypt((byte *) mensaje, texto, largo, &clave, iv, BF_ENCRYPT);

    return hex2str(texto, largo);
}

char* descifrar(char* llave, char* mensaje) {
    char* texto;
    long largo = (strlen(mensaje) * 2);
    byte iv[8] = {8, 8, 8, 8, 8, 8, 8, 8};
    byte* cifrado = str2hex(mensaje, strlen(mensaje));

    BF_KEY clave;
    BF_set_key(&clave, strlen(llave), (byte *) llave);
    texto = (char *) calloc(largo + 1, sizeof (char));

    BF_cbc_encrypt(cifrado, (byte *) texto, largo, &clave, iv, BF_DECRYPT);
    free(cifrado);
    return texto;
}
