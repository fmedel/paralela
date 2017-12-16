#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "blowfish.h"
#include <mpi.h>

using namespace std;

void cuakear(int total_nodos, int nodo)
{


    char palabra[5];
    char *char_decifrado;
    bool es_alfabeto=false;

    char encriptado[]="4751d8439293cedbfb4a29d2048ba636acf91fac192b6c1e8a84ba62fa524186b0277ed6cf0d07d642c0f40cdf2e74e67e2a7d66ed337a16b8cecb99648489f12faed18c9f80656802fadf99ecf1cac4a71cf732edcc79216e44fcfc8b26fb1feb8b95d9d66bcf3ed5ef89efdb9843787273dee9b52ef166bc9bf9b53a205019";


    int i,j,k,l,m;

    int inicio;
    int fin;

    inicio= ((95/total_nodos)*nodo)+32;
    fin=(95/total_nodos)*(nodo+1)+32;


    try
    {

        for (i=inicio; i<fin; i++)
        {
            palabra[0]=(char)i;

            for (j=65; j<127; j++)
            {
                palabra[1]=(char)j;

                for (k=65; k<127; k++)
                {
                    palabra[2]=(char)k;

                    for (l=97; l<127; l++)
                    {
                        palabra[3]=(char)l;

                        for (m=65; m<127; m++)
                        {

                            palabra[4]=(char)m;

                            //printf("%s\n", palabra );

                            char_decifrado= descifrar(palabra, encriptado );


                            for (int g=0; g<strlen(char_decifrado); g++){

                                if ((int(char_decifrado[g])>=65) && (int(char_decifrado[g])<=122))
                                {
                                     es_alfabeto=true;

                                }
                                else
                                {
                                    //printf("NO\n" );
                                    es_alfabeto=false;
                                    break;
                                }

                            }

                            if (es_alfabeto==true)
                            {
                                //printf("%s------%s\n",char_decifrado, palabra );
                                if(strlen(char_decifrado)>5)
                                {
                                    printf("%s------%s\n",char_decifrado, palabra );
                                }
                            }

                        }
                    }
                }
            }
        }


        //fprintf(stdout, "\n%s\n", texto_texto);
    }
    catch(int err_code)
    {
        printf("ERROR BYE!!!! %d", err_code);
    }


}



int main(int argc, char** argv)
{
    int total_equipos;
    int nodo;
    MPI_Status estatus;


    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &total_equipos);
    MPI_Comm_rank(MPI_COMM_WORLD, &nodo);

    MPI_Barrier(MPI_COMM_WORLD);




    cuakear(total_equipos,nodo);


    MPI_Finalize();
    return 0;
}
