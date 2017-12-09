#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "blowfish.h"
#include <mpi.h>


char diccionario[]="! #$%&'()*+,-./:;<=>?@[]\^_`{}|~0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";



void error(char* programa);
int verificar(char*);



int main(int argc, char** argv)
{

    int nodo, total_cpus;;

    MPI_Init(&argc, &argv);

    MPI_Comm_size(MPI_COMM_WORLD, &total_cpus);

    MPI_Comm_rank(MPI_COMM_WORLD, &nodo);

    int inicio = (94/total_cpus)*nodo;
    int fin = (94/total_cpus)*(nodo+1);

    int largo_desencriptado;
    int i,j,k,l,m,t;

    int es_entendible;


    char* mensaje = NULL;
    char *texto = NULL;
    int salida = EXIT_SUCCESS;

    mensaje = "08fd193b1771a99ac34474e745f4ad521a1ba438f3c63892a860d0e8bd55cbb93b45113aa4954da6019e440a928ad02b65c895eb94d91225ef5ec177c095de0d110ac76a67fe56aa45a7595da9514d23b454e109ec4a2dbbc40f32befe39214e2a304bb3f2477511e909a20e80bf02c07b01c833589031ec7dc22c8b1311bbfa";





    char palabra[6];


    for(i=inicio; i<fin; i++)
    {

        for(j=0; j<94; j++)
        {

            for(k=0; k<94; k++)
            {

                for(l=0; l<94; l++)
                {

                    for(m=0; m<94; m++)
                    {
                      for (t = 0; t < 94; t++) {
                        free(texto);
                        palabra[0]= diccionario[i];
                        palabra[1]= diccionario[j];
                        palabra[2]= diccionario[k];
                        palabra[3]= diccionario[l];
                        palabra[4]= diccionario[m];
                        palabra[5]= diccionario[t];
                        texto=descifrar(palabra, mensaje);
                        largo_desencriptado=strlen(texto);
                        es_entendible= verificar(texto);
                        if(es_entendible==1)
                        {

                            if(largo_desencriptado>8)
                            {
                                fprintf(stdout, "Clave: %s         CPU: %d     Mensaje: %s \n", palabra, nodo, texto);
                            }
                        }
                      }
                    }
                }
            }
        }
    }



    printf("Termine\n");
    MPI_Finalize();
    return 0;
}


int verificar(char mensaje[])
{
    int i;
    int largo;
    int caracter;
    int ver;

    largo=strlen(mensaje);

    for(i=0; i<largo; i++)
    {
        caracter= (int)mensaje[i];
        if ((  caracter>= 65) && (caracter <= 122))
        {
            ver=1;
        }
        else
        {

            return 0;
        }
    }
    return 1;
}
