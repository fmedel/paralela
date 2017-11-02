/*
archivo modificado de
https://github.com/glennrp/libpng/blob/libpng16/contrib/examples/pngpixel.c

*/
#include <stdlib.h>
#include <stdio.h>
#include <setjmp.h> /* necesario para el manejo de errores */
#include <png.h>


#if defined(PNG_READ_SUPPORTED) && defined(PNG_SEQUENTIAL_READ_SUPPORTED)

/* Devuelve el componente 'c' del píxel 'x' de la fila dada. */
static unsigned int component(png_const_bytep row, png_uint_32 x, unsigned int c, unsigned int bit_depth, unsigned int channels){
  /* Las imágenes PNG pueden tener hasta 2 ^ 31 píxeles de ancho, pero esto significa que pueden llegar hasta
      * 2 ^ 37 bits de ancho (para un píxel de 64 bits - el más grande posible) y por lo tanto 2 ^ 34
      * bytes de ancho. Dado que la fila instalada en la memoria, sin embargo, los siguientes deben
      * trabajo:
  */
   png_uint_32 bit_offset_hi = bit_depth * ((x >> 6) * channels);
   png_uint_32 bit_offset_lo = bit_depth * ((x & 0x3f) * channels + c);
   row = (png_const_bytep)(((PNG_CONST png_byte (*)[8])row) + bit_offset_hi);
   row += bit_offset_lo >> 3;
   bit_offset_lo &= 0x07;

   /* PNG píxeles se empaquetan en bytes para poner el primer píxel en el más alto
     * bits derl byte y en dos bytes para valores de 16 bits con los 8 bits altos
     * primero, así que:
   */
   switch (bit_depth){
      case 1: return (row[0] >> (7-bit_offset_lo)) & 0x01;
      case 2: return (row[0] >> (6-bit_offset_lo)) & 0x03;
      case 4: return (row[0] >> (4-bit_offset_lo)) & 0x0f;
      case 8: return row[0];
      case 16: return (row[0] << 8) + row[1];
      default:
      /* Esto nunca debe suceder; indica un error en este programa o en
        * libpng en sí:
      */
         fprintf(stderr, "pngpixel: profundidad de bits no válida %u\n", bit_depth);
         exit(1);
   }
}

/*Imprime un píxel de una fila devuelta por libpng; determinar el formato de la fila, buscar
 * el píxel, e imprimir la información relevante a stdout.
 */
static void print_pixel(png_structp png_ptr, png_infop info_ptr, png_const_bytep row,png_uint_32 x) {
   PNG_CONST unsigned int bit_depth = png_get_bit_depth(png_ptr, info_ptr);
   FILE *fp;
   char buffer[100];
    int c1a;
    int c2a;
    int c3a;
   fp = fopen ( "monica_original.txt", "a" );/* imprimir  los pixcel */
   switch (png_get_color_type(png_ptr, info_ptr)){
     case PNG_COLOR_TYPE_GRAY:
       if ( component(row, x, 0, bit_depth, 1) == 0) {
           fprintf(fp, "%d %d %d\n",0,0,0 );
       }else{
           fprintf(fp, "%d %d %d\n",255,255,255 );
       }
        //printf("GRAY %u\n", component(row, x, 0, bit_depth, 1));
        fclose ( fp );
        return;
      case PNG_COLOR_TYPE_RGB: /** para RGB **/
          /*  printf("%u %u %u\n", component(row, x, 0, bit_depth, 3), component(row, x, 1, bit_depth, 3),component(row, x, 2, bit_depth, 3));*/
            c1a=component(row, x, 0, bit_depth, 3);
            c2a =component(row, x, 1, bit_depth, 3);
            c3a=component(row, x, 2, bit_depth, 3);
            fprintf(fp, "%d %d %d\n",c1a,c2a,c3a );
          fclose ( fp );
         return;

      default:
         png_error(png_ptr, "pngpixel: invalido tipo de color");
   }
}

int main(int argc, const char **argv){
FILE *fp;
fp = fopen ( "monica_original.txt", "a" );/* imprimir  los pixcel */
fprintf(fp, "P3\n");
fprintf(fp, "25600\n");
fprintf(fp, "25600\n");
fprintf(fp, "255\n");
fclose ( fp );
  int bloque =1;
  /* Este programa utiliza el predeterminado, <setjmp.h> basado, manipulación de errores libpng
   * mecanismo, por lo tanto cualquier variable local que existe antes de la llamada a
   * setjmp y se cambia después de que la llamada a setjmp devuelve satisfactoriamente debe
   * ser declarado con 'volátil' para asegurar que sus valores no
   * destruido por longjmp:
   */
   volatile int result = 1 /*caida*/;
   if (argc == 2){
      /*long x = atol(argv[1]);//1024 --> ancho
      long y = atol(argv[2]); //768 --->alto*/
      FILE *f = fopen(argv[1], "rb"); // ---> nombre
      volatile png_bytep row = NULL;
      if (f != NULL){
        /* libpng requiere una función de devolución de llamada para manejar errores; esta
         * la devolución de llamada no debe devolverse. La función de devolución de llamada predeterminada utiliza una
         * jmp_buf almacenado <setjmp.h> que se mantiene en un png_struct y
         * escribe mensajes de error en stderr. Crear el png_struct es un
         * poco complicado; simplemente copie el siguiente código.
         */
         png_structp png_ptr = png_create_read_struct(PNG_LIBPNG_VER_STRING,NULL, NULL, NULL);
         if (png_ptr != NULL){
            png_infop info_ptr = png_create_info_struct(png_ptr);
            if (info_ptr != NULL){
               // Declara las variables de pila para mantener punteros asignados localmente datos.
               //Inicializar el búfer de control de errores:
               if (setjmp(png_jmpbuf(png_ptr)) == 0){
                  png_uint_32 width, height;
                  int bit_depth, color_type, interlace_method,compression_method, filter_method;
                  png_bytep row_tmp;
                  /* Ahora asociar el recientemente abierto (FILE *) con el valor predeterminado
                   * libpng funciones de inicialización. A veces libpng es
                   * compilado sin soporte de stdio (puede ser difícil de hacer
                   * en algunos ambientes); en ese caso usted tendrá que escribir
                   * su propia lectura de devolución de llamada para leer los datos de (FILE *).
                   */
                  png_init_io(png_ptr, f);
                  /* Y lee la primera parte del archivo PNG - el encabezado y
                   * toda la información hasta el primer píxel.
                   */
                  png_read_info(png_ptr, info_ptr);
                  /* Esto rellena suficiente información para decirnos el ancho de
                   * cada fila en bytes, asignar la cantidad apropiada de
                   * espacio. En este caso png_malloc se utiliza - no se
                   * devuelve si la memoria no está disponible.
                   */
                  row = png_malloc(png_ptr, png_get_rowbytes(png_ptr,info_ptr));
                  /* Para evitar la sobrecarga de utilizar una copia automática volátil row_tmp
                   * a un local aquí - sólo use la fila para el png_free a continuación.
                   */
                  row_tmp = row;
                  /* Toda la información que necesitamos está en el encabezado es devuelta por
                   * png_get_IHDR, si esto falla, ahora podemos usar 'png_error' para
                   * Señalar el error y el control de retorno al setjmp anterior.
                   */
                  if (png_get_IHDR(png_ptr, info_ptr, &width, &height,&bit_depth, &color_type, &interlace_method, &compression_method, &filter_method)){
                     int passes, pass;
                     /* png_set_interlace_handling devuelve el número de
                      * pases requeridos, así como activar libpng's
                      * manipulación, pero como lo hacemos nosotros mismos esto es
                      * necesario:
                      */
                     switch (interlace_method){
                        case PNG_INTERLACE_NONE:
                           passes = 1;
                           break;
                        case PNG_INTERLACE_ADAM7:
                           passes = PNG_INTERLACE_ADAM7_PASSES;
                           break;
                        default:
                           png_error(png_ptr, "pngpixel: desconocido entrelazado");
                     }
                     /* Ahora lea los píxeles, paso por paso, fila por fila: */
                     png_start_read_image(png_ptr);
                     for (pass=0; pass<passes; ++pass){
                        png_uint_32 ystart, xstart, ystep, xstep;
                        png_uint_32 py;
                        if (interlace_method == PNG_INTERLACE_ADAM7){
                          /* A veces el pase entero está vacío porque el
                            * la imagen es demasiado estrecha o demasiado corta. libpng
                            * espera ser llamado para cada fila que es
                            * presente en el pase, por lo que puede ser necesario
                            * omita el ciclo debajo (sobre py) si la imagen es
                            * demasiado estrecho.
                            */
                           if (PNG_PASS_COLS(width, pass) == 0)
                              continue;

                              /* Necesitamos el pixel inicial y el offset
                               * entre cada píxel en este paso; utilizar las macros
                               * en png.h:
                               */
                           xstart = PNG_PASS_START_COL(pass);
                           ystart = PNG_PASS_START_ROW(pass);
                           xstep = PNG_PASS_COL_OFFSET(pass);
                           ystep = PNG_PASS_ROW_OFFSET(pass);
                        }
                        else{
                           ystart = xstart = 0;
                           ystep = xstep = 1;
                        }
                        /* Para encontrar el píxel, bucle sobre 'py' para cada pase
                         * leyendo una fila y luego comprobando para ver si
                         * contiene el píxel.
                         */
                         int h=0;
                         int n=0;
                         int m=0;
                        for (py = ystart; py < height; py += ystep){
                           png_uint_32 px, ppx;
                           /* png_read_row toma dos punteros. Cuando libpng
                            * maneja el entrelazado el primero se rellena
                            * pixel por pixel, y el segundo recibe el mismo
                            * píxeles, pero se replican en todos los
                            * píxeles no escritos hasta ahora para cada paso. Cuando nosotros
                            * hacer el entrelazado, sin embargo, sólo contienen
                            * los píxeles de los pases entrelazados
                            * Ambos son inútiles y sin sentido, por lo que pasamos un
                            * Puntero nulo.
                            */
                           png_read_row(png_ptr, row_tmp, NULL);
                           /* Ahora encuentre el píxel si está en esta fila; ahí
                             * son, por supuesto, maneras mucho mejores de hacer esto
                             * que usar un bucle for:
                             */
                           /** modificación por fmedel*/
                          for (px = xstart, ppx = 0; px < width; px += xstep, ++ppx){
                            /* 'ppx' es el índice del píxel en la fila buffer. */
                              if (h>25599) {//800
                                printf("salio\n" );
                                return 0;
                              }
                              if ((h*25600*bloque<=m)&&(((h*25600*bloque)+(25600))>m)&&(h<(25600))) { //800
                                print_pixel(png_ptr, info_ptr, row_tmp, ppx);
                                n++;
                                //printf("fila-->%d\n",n );
                                if (n>(25599)) {
                                  n=0;
                                  h++;
                                  printf("columna -> %d\n",h );
                                }
                              }else
                              {/*printf("h->%d n->%d m->%d\n",h,n,m );*/}
                                m++;
                              /* Ahora termina los bucles temprano - tenemos encontró y manejó los datos requeridos.*/
                           } /* x loop */
                        } /* y loop */
                     } /* pass loop */
                     /* Finalmente liberar el buffer temporal: */
                  pass_loop_end:
                     row = NULL;
                     png_free(png_ptr, row_tmp);
                  }
                  else
                     png_error(png_ptr, "pngpixel: png_get_IHDR fallo");
               }
               else{
                 /* Else libpng ha generado un error. Se ha producido un mensaje de error.
                    * ya se ha emitido, por lo que sólo es necesario limpiar
                    * datos asignados localmente:
                    */
                  if (row != NULL){
                    /* La implementación por defecto de png_free nunca produce errores
                        * (sólo se bloquea si algo sale mal), pero la caja fuerte
                        * La manera de usarlo es todavía borrar 'fila' antes de llamar
                        * png_free:
                        */
                     png_bytep row_tmp = row;
                     row = NULL;
                     png_free(png_ptr, row_tmp);
                  }
               }

               png_destroy_info_struct(png_ptr, &info_ptr);
            }

            else
               fprintf(stderr, "pngpixel: sin memoria asignando png_info\n");

            png_destroy_read_struct(&png_ptr, NULL, NULL);
         }

         else
            fprintf(stderr, "pngpixel: sin memoria asignando png_struct\n");
      }

      else
         fprintf(stderr, "pngpixel: %s: no se pudo abrir el archivo\n", argv[2]);


}   else
    /* Número incorrecto de argumentos */
      fprintf(stderr, "pngpixel: use:png-file\n");

   return result;
}
#endif /* READ && SEQUENTIAL_READ */
