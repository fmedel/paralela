
using namespace std;
void unir_archivo(int archivo,int procesos){
  FILE *fp;
  char str[20];
  char str2[20];
  char str3[20];
  sprintf(str2,"%d",archivo);
  strcpy(str3,str2);
  strcat(str3,".csv");
  long m=0;
  FILE *fp2=fopen(str3,"w");
  if (fp2==NULL){std::cout << "error en archivo"<< '\n';exit(0);}
  for (int i = 0; i < procesos; i++) {
    sprintf(str, "%d", i);
    strcat(str,"/t");
    strcat(str,str2);
    strcat(str,".csv");
    fp=fopen(str, "r");
    if (fp==NULL){std::cout << "error en archivo"<< '\n';exit(0);}
    char line[200];
    while (fgets(line, sizeof(line),fp)) {
      m=atoi(line);
      fprintf(fp2, "%s",line );
    }
    fclose(fp);
  }
  fclose(fp2);
}

long menor(long dato1 ,long dato2){
  if (dato2>dato1) {
    return dato1;
  }
  else{
    return dato2;
  }
}

long mayor(long dato1, long dato2){
  if (dato2<dato1) {
    return dato2;
  }
  else{
    return dato1;
  }
}

void union_arreglos(long areglo[4],long arregloA[10],long arregloMenor[9],long arreglomayor[9]){
  long total=0;
  long minimo=999999999999999999;
  long maximo=0;

  for (int i = 0; i <10 ; i++) {
    total+=arregloA[i];
  }

  for (int  z = 0; z < 9; z++) {
    if(minimo>arregloMenor[z]){
      minimo=arregloMenor[z];
    }
  }

  for (int  x = 0; x < 9; x++) {
    if(maximo<arregloMenor[x]){
      maximo=arregloMenor[x];
    }
  }
  areglo[0]=total;
  areglo[2]=minimo;
  areglo[3]=maximo;

}

void separ_archivo(long areglo[4], long datos_int, int archivo_tem, long arregloA[10],long arregloMenor[9],long arreglomayor[9],int numprocs,int myid){
  long m=0,n=0;
  FILE *fp;
  char str[20];
  char str2[20];
  sprintf(str, "%d", myid);
  sprintf(str2, "%d", myid);
  if (archivo_tem == 0) {
    fp=fopen("datos.csv", "r");
  }else if (archivo_tem == 1) {
    strcat(str,"/t1.csv");
    strcat(str2,"/1.csv");
    rename(str,str2);
    fp=fopen(str2, "r");
  }else if (archivo_tem == 2) {
    strcat(str,"/t2.csv");
    strcat(str2,"/2.csv");
    rename(str,str2);
    fp=fopen(str2, "r");
  }else if (archivo_tem == 3) {
    strcat(str,"/t3.csv");
    strcat(str2,"/3.csv");
    rename(str,str2);
    fp=fopen(str2, "r");
  }else if (archivo_tem == 4) {
    strcat(str,"/t4.csv");
    strcat(str2,"/4.csv");
    rename(str,str2);
    fp=fopen(str2, "r");
  }else if (archivo_tem == 5) {
    strcat(str,"/t5.csv");
    strcat(str2,"/5.csv");
    rename(str,str2);
    fp=fopen(str2, "r");
  }else if (archivo_tem == 6) {
    strcat(str,"/t6.csv");
    strcat(str2,"/6.csv");
    rename(str,str2);
    fp=fopen(str2, "r");
  }else if (archivo_tem == 7) {
    strcat(str,"/t7.csv");
    strcat(str2,"/7.csv");
    rename(str,str2);
    fp=fopen(str2, "r");
  }else if (archivo_tem == 8) {
    strcat(str,"/t8.csv");
    strcat(str2,"/8.csv");
    rename(str,str2);
    fp=fopen(str2, "r");
  }else if (archivo_tem == 9) {
    strcat(str,"/t9.csv");
    strcat(str2,"/9.csv");
    rename(str,str2);
    fp=fopen(str2, "r");
  }
  sprintf(str, "%d", myid);
  strcat(str,"/t1.csv");
  FILE *archivo1=fopen(str, "w");
  sprintf(str, "%d", myid);
  strcat(str,"/t2.csv");
  FILE *archivo2=fopen(str, "w");
  sprintf(str, "%d", myid);
  strcat(str,"/t3.csv");
  FILE *archivo3=fopen(str, "w");
  sprintf(str, "%d", myid);
  strcat(str,"/t4.csv");
  FILE *archivo4=fopen(str, "w");
  sprintf(str, "%d", myid);
  strcat(str,"/t5.csv");
  FILE *archivo5=fopen(str, "w");
  sprintf(str, "%d", myid);
  strcat(str,"/t6.csv");
  FILE *archivo6=fopen(str, "w");
  sprintf(str, "%d", myid);
  strcat(str,"/t7.csv");
  FILE *archivo7=fopen(str, "w");
  sprintf(str, "%d", myid);
  strcat(str,"/t8.csv");
  FILE *archivo8=fopen(str, "w");
  sprintf(str, "%d", myid);
  strcat(str,"/t9.csv");
  FILE *archivo9=fopen(str, "w");
  if (fp==NULL){std::cout << "error en archivo"<< '\n';exit(0);}
  if (archivo1==NULL){std::cout << "error en archivo t1"<< '\n'; exit(0);}
  if (archivo2==NULL){std::cout << "error en archivo t2"<< '\n';exit(0);}
  if (archivo3==NULL){std::cout << "error en archivo t3"<< '\n';exit(0);}
  if (archivo4==NULL){std::cout << "error en archivo t4"<< '\n';exit(0);}
  if (archivo5==NULL){std::cout << "error en archivo t5"<< '\n';exit(0);}
  if (archivo6==NULL){std::cout << "error en archivo t6"<< '\n';exit(0);}
  if (archivo7==NULL){std::cout << "error en archivo t7"<< '\n';exit(0);}
  if (archivo8==NULL){std::cout << "error en archivo t8"<< '\n';exit(0);}
  if (archivo9==NULL){std::cout << "error en archivo t9"<< '\n';exit(0);}
  long A1=0,A2=0,A3=0,A4=0,A5=0;
  long A6=0,A7=0,A8=0,A9=0,A10=0;
  long menorA1=areglo[3];
  long menorA2=areglo[3];
  long menorA3=areglo[3];
  long menorA4=areglo[3];
  long menorA5=areglo[3];
  long menorA6=areglo[3];
  long menorA7=areglo[3];
  long menorA8=areglo[3];
  long menorA9=areglo[3];
  long mayorA1=0,mayorA2=0,mayorA3=0,mayorA4=0,mayorA5=0;
  long mayorA6=0,mayorA7=0,mayorA8=0,mayorA9=0;
  string cadena="";
  char line[200];
  //Procesamos el archivo por cada espacio
  fseek (fp, 0, SEEK_END); // mueve el apuntador al final del archivo
  // leer la posición actual
  int pos = ftell(fp)/(numprocs); // Divide el archivo en el total de procesos ingresados
  fseek (fp,(pos*myid), SEEK_SET); // seekg determina desde que posicion empieza a leer
  while(ftell(fp)<pos*(1+myid)) { // recorre hasta  la posicion según el procesador
    fgets(line, sizeof(line),fp);
    m=atoi(line);
    n++;
    if (m>=0+areglo[2] and m<=datos_int+areglo[2]){
      fprintf(archivo1, "%s",line );
      A1++;
      if (menorA1>m) {
          menorA1=m;
      }
      if (mayorA1<m) {
          mayorA1=m;
      }
    }
    else if (m>=datos_int+areglo[2] and m<((datos_int*2)+areglo[2])){
        fprintf(archivo2, "%s",line );
        A2++;
        if (menorA2>m) {
          menorA2=m;
        }
        if (mayorA2<m) {
          mayorA2=m;
        }
      }
      else if (m>=((datos_int*2)+areglo[2]) and m<((datos_int*3)+areglo[2])){
        fprintf(archivo3, "%s",line );
        A3++;
        if (menorA3>m) {
          menorA3=m;
        }
        if (mayorA3<m) {
          mayorA3=m;
        }
      }
      else if (m>=((datos_int*3)+areglo[2]) and m<((datos_int*4)+areglo[2])){
        fprintf(archivo4, "%s",line );
        A4++;
        if (menorA4>m) {
          menorA4=m;
        }
        if (mayorA4<m) {
          mayorA4=m;
        }
      }
      else if (m>=((datos_int*4)+areglo[2]) and m<((datos_int*5)+areglo[2])){
        fprintf(archivo5, "%s",line );
        A5++;
        if (menorA5>m) {
          menorA5=m;
        }
        if (mayorA5<m) {
          mayorA5=m;
        }
      }
      else if (m>=((datos_int*5)+areglo[2]) and m<((datos_int*6)+areglo[2])){
        fprintf(archivo6, "%s",line );
        A6++;
        if (menorA6>m) {
          menorA6=m;
        }
        if (mayorA6<m) {
          mayorA6=m;
        }
      }
      else if (m>=((datos_int*6)+areglo[2]) and m<((datos_int*7)+areglo[2])){
        fprintf(archivo7, "%s",line );
        A7++;
        if (menorA7>m) {
          menorA7=m;
        }
        if (mayorA7<m) {
          mayorA7=m;
        }
      }
      else if (m>=((datos_int*7)+areglo[2]) and m<((datos_int*8)+areglo[2])){
        fprintf(archivo8, "%s",line );
        A8++;
        if (menorA8>m) {
          menorA8=m;
        }
        if (mayorA8<m) {
          mayorA8=m;
        }
      }
      else if (m>=((datos_int*8)+areglo[2]) and m<=areglo[3]){
        fprintf(archivo9, "%s",line );
        A9++;
        if (menorA9>m) {
          menorA9=m;
        }
        if (mayorA9<m) {
          mayorA9=m;
        }
      }
      else {
      /*  std::cout << "id " <<myid<< '\n';
        std::cout << "prueba" <<((datos_int*9)+areglo[2])<< '\n';
        std::cout << "menor" <<arregloMenor[3]<< '\n';
        std::cout << "mayor" <<arreglomayor[3]<< '\n';
        std::cout << "minimo " <<areglo[2]<< '\n';
        std::cout << "maximo " <<areglo[3]<< '\n';
        std::cout << "datos_int " <<datos_int<< '\n';
        std::cout << "archivo " <<archivo_tem<< '\n';
        std::cout << "error aqui no entra " <<m<< '\n';*/
         A10++;
        /* exit(0);*/
      }
    }
  fclose(fp);
  fclose(archivo1);
  fclose(archivo2);
  fclose(archivo3);
  fclose(archivo4);
  fclose(archivo5);
  fclose(archivo6);
  fclose(archivo7);
  fclose(archivo8);
  fclose(archivo9);
  arregloA[0]=A1;
  arregloA[1]=A2;
  arregloA[2]=A3;
  arregloA[3]=A4;
  arregloA[4]=A5;
  arregloA[5]=A6;
  arregloA[6]=A7;
  arregloA[7]=A8;
  arregloA[8]=A9;
  arregloA[9]=A10;
  arregloMenor[0]=menorA1;
  arregloMenor[1]=menorA2;
  arregloMenor[2]=menorA3;
  arregloMenor[3]=menorA4;
  arregloMenor[4]=menorA5;
  arregloMenor[5]=menorA6;
  arregloMenor[6]=menorA7;
  arregloMenor[7]=menorA8;
  arregloMenor[8]=menorA9;
  arreglomayor[0]=mayorA1;
  arreglomayor[1]=mayorA2;
  arreglomayor[2]=mayorA3;
  arreglomayor[3]=mayorA4;
  arreglomayor[4]=mayorA5;
  arreglomayor[5]=mayorA6;
  arreglomayor[6]=mayorA7;
  arreglomayor[7]=mayorA8;
  arreglomayor[8]=mayorA9;
  std::cout << "total "<< n ;
  std::cout << ";"<< A1 ;
  std::cout << ";"<< A2 ;
  std::cout << ";"<< A3 ;
  std::cout << ";"<< A4 ;
  std::cout << ";"<< A5 ;
  std::cout << ";"<< A6 ;
  std::cout << ";"<< A7 ;
  std::cout << ";"<< A8 ;
  std::cout << ";"<< A9 ;
  std::cout << ";"<< A10 ;
  std::cout << ";" << A1+A2+A3+A4+A5+A6+A7+A8+A9+A10 <<'\n';
  /*if (archivo_tem==0) {
    /*std::cout << "entro" << '\n';
    union_arreglos(areglo,arregloA,arregloMenor,arreglomayor);
  }*/
}

int elegir_archivo (long areglo[4],int archivo_tem,long A[10],long menorA[9],long mayorA[9]){
  long m=0;
/*  if (archivo_tem==0) {
    m=areglo[0]/2;
  } else {
    m=areglo[1];
  }*/
  m=areglo[1];
  if (m<A[0]) {
      areglo[0]=A[0];
      areglo[1]=m;
      areglo[2]=menorA[0];
      areglo[3]=mayorA[0];
      return 1;
  } else if (m<=(A[1]+A[0])) {
      areglo[0]=A[1];
      areglo[1]=m-A[0];
      areglo[2]=menorA[1];
      areglo[3]=mayorA[1];
      return 2;
  } else if (m<=(A[2]+A[1]+A[0])) {
      areglo[0]=A[2];
      areglo[1]=m-(A[1]+A[0]);
      areglo[2]=menorA[2];
      areglo[3]=mayorA[2];
      return 3;
  } else if (m<=(A[3]+A[2]+A[1]+A[0])) {
      areglo[0]=A[3];
      areglo[1]=m-(A[2]+A[1]+A[0]);
      areglo[2]=menorA[3];
      areglo[3]=mayorA[3];
      return 4;
  } else if (m<=(A[4]+A[3]+A[2]+A[1]+A[0])) {
      areglo[0]=A[4];
      areglo[1]=m-(A[3]+A[2]+A[1]+A[0]);
      areglo[2]=menorA[4];
      areglo[3]=mayorA[4];

      return 5;
  } else if (m<=(A[5]+A[4]+A[3]+A[2]+A[1]+A[0])) {
      areglo[0]=A[5];
      areglo[1]=m-(A[4]+A[3]+A[2]+A[1]+A[0]);
      areglo[2]=menorA[5];
      areglo[3]=mayorA[5];

      return 6;
  } else if (m<=(A[6]+A[5]+A[4]+A[3]+A[2]+A[1]+A[0])) {
      areglo[0]=A[6];
      areglo[1]=m-(A[5]+A[4]+A[3]+A[2]+A[1]+A[0]);
      areglo[2]=menorA[6];
      areglo[3]=mayorA[6];

      return 7;
  } else if (m<=(A[7]+A[6]+A[5]+A[4]+A[3]+A[2]+A[1]+A[0])) {
      areglo[0]=A[7];
      areglo[1]=m-(A[6]+A[5]+A[4]+A[3]+A[2]+A[1]+A[0]);
      areglo[2]=menorA[7];
      areglo[3]=mayorA[7];

      return 8;
  } else if (m<=(A[8]+A[7]+A[6]+A[5]+A[4]+A[3]+A[2]+A[1]+A[0])) {
      areglo[0]=A[8];
      areglo[1]=m-(A[7]+A[6]+A[5]+A[4]+A[3]+A[2]+A[1]+A[0]);
      areglo[2]=menorA[8];
      areglo[3]=mayorA[8];

      return 9;
  }else{return 99;}
}

int media(int archivo_tem,int datos,int iteraciones){
  long arreglo[datos-1];
  int n=0;
  FILE *archivo;
  if (archivo_tem == 1) {
    archivo= fopen("1.csv", "r");
  }else if (archivo_tem == 2) {
    archivo= fopen("2.csv", "r");
  }else if (archivo_tem == 3) {
    archivo= fopen("3.csv", "r");
  }else if (archivo_tem == 4) {
    archivo= fopen("4.csv", "r");
  }else if (archivo_tem == 5) {
    archivo= fopen("5.csv", "r");
  }else if (archivo_tem == 6) {
    archivo= fopen("6.csv", "r");
  }else if (archivo_tem == 7) {
    archivo= fopen("7.csv", "r");
  }else if (archivo_tem == 8) {
    archivo= fopen("8.csv", "r");
  }else if (archivo_tem == 9) {
    archivo= fopen("9.csv", "r");
  }
  else {
    std::cout << "Error al abrir archivo media" << '\n';
  }
  char line[200];
  while (fgets(line, sizeof(line), archivo)){
    arreglo[n]=atoi(line);
    n++;
  }
    fclose(archivo);
    quicksort(arreglo, 0, datos);

    std::cout << arreglo[iteraciones] << '\n';
}
