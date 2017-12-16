#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "blowfish.h"
#include <mpi.h>
using namespace std;

int cuakear(){
    string string_opcion;
    string string_llave;
    string string_mensajes;
    string string_texto;

    char palabra[5];


    char opcion_opcion[3];
    char llave_llave[5];
    char mensaje_mensaje[256];
    char *texto_texto;
    char *texto_texto_texto;

    cout<<"Ingrese opcion"<<endl;
    cin>> string_opcion;

    cout<<"Ingrese llave"<<endl;
    cin>>string_llave;

    cout<<"Ingrese mensajes"<<endl;
    cin>>string_mensajes;

    //llave_llave=string_llave.c_str();
    //mensaje_mensaje= string_mensajes.c_srt();

    strcpy(llave_llave, string_llave.c_str());
    strcpy(mensaje_mensaje, string_mensajes.c_str());


    int i,j,k,l,m;



    /*opcion = (char *) calloc(strlen(argv[1]) + 2, sizeof (byte));
    snprintf(opcion, strlen(argv[1]) + 1, "%s", argv[1]);

    llave = (char *) calloc(strlen(argv[2]) + 2, sizeof (byte));
    snprintf(llave, strlen(argv[2]) + 1, "%s", argv[2]);

    mensaje = (char *) calloc(strlen(argv[3]) + 2, sizeof (byte));
    snprintf(mensaje, strlen(argv[3]) + 1, "%s", argv[3]);*/
    if (string_opcion=="enc") 
    {
        fprintf(stdout, "\nLlave         : %s", llave_llave);
        fprintf(stdout, "\nMensaje       : %s", mensaje_mensaje);

        texto_texto = cifrar(llave_llave, mensaje_mensaje);
        fprintf(stdout, "\nTexto cifrado : %s\n", texto_texto);
    } 

    else if(string_opcion=="dec") 
    {

        
       
        int inicio=32,fin=127, p=0;

        
        for (i=inicio; i<fin; i++)
        {
            palabra[0]=(char)i;

            for (j=32; j<127; j++)
            {
                palabra[1]=(char)j;

                for (k=32; k<127; k++)
                {
                    palabra[2]=(char)k;

                    for (l=32; l<127; l++)
                    {
                        palabra[3]=(char)l;

                        for (m=32; m<127; m++)
                        {
                            palabra[4]=(char)m;

                            texto_texto= descifrar(palabra, "6c57efd83d7492f3");
                            texto_texto_texto = cifrar(palabra, texto_texto);
                            printf("%s-----%s-----%d\n", texto_texto,palabra, strlen(texto_texto));
                            //cout<<palabra<<endl;
                            
                            if (strcmp("6c57efd83d7492f3", texto_texto_texto)==1)
                            {
                                
                                
                                printf("HAS S1DO HACK3AD0 \n BYE!!!!");
                                printf("%s-----%s-----%d\n", texto_texto,palabra, strlen(texto_texto));
                                scanf("%d", p);
                            }

                        }
                    }
                }
            }
        }

        
        fprintf(stdout, "\n%s\n", texto_texto);
    }
}


int main(int argc, char** argv) 
{
    int total_equipos;
    int nodo;
    MPI_Status status;


    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &total_equipos);
    MPI_Comm_rank(MPI_COMM_WORLD, &nodo);

    MPI_Barrier(MPI_COMM_WORLD);
    

    if (nodo==0){
        cuakear();

    }else{
        cout<<"soy el nodo"<<nodo<<endl;
    }


    // Libero la memoria
    /*free(llave_llave);
    free(mensaje_mensaje);*/
    
   
    MPI_Finalize();

    return 0;

}

