#!/bin/bash
plantilla=1
while [ $plantilla -le 1 ]
do
  clear
  echo "---------------------"
  echo "pc-profesor"
  echo "|P1 |P2x |P3 |P4x|"
  echo "|P6x |P7 |P8 |P9 |P10|"
  echo "|P11|P12|P13|P14x|P15x|"
  echo "---------------------"
  echo " "
  echo "0)Prender pc porfesor"
  echo "1)Prender P9 de felipe"
  echo "2)Prender P8 de diego"
  echo "3)Prender P10 de ignacio"
  echo "4)Prender P7 de leo"
  echo "5)Prender P13 reyes"
  echo "6)Prender P12 francisco"
  echo "7)Prender P11 Fabian"
  echo " "
  echo "8)Prender P1"
  echo "9)Prender P3"
  echo "----------------------"
  echo "20)conectar al pc del profesor"
  echo "21)conectar al pc de felipe"
  echo "22)conectar al pc de diego"
  echo "23)conectar al pc de ignacio"
  echo "24)conectar al pc de leo"
  echo "25)conectar al pc reyes"
  echo "26)conectar al pc francisco"
  echo "27)conectar al pc Fabian"
  echo " "
  echo "28)conectar al pc P1"
  echo "29)conectar al pc P3"
  echo "----------------------"
  echo "99) salir"
  read x
  case $x in
      0)
      wakeonlan 4c:72:b9:b1:92:f2
      echo "encendido  ip 10.1.10.115"
      sleep 40
      ;;
      1)
      wakeonlan ac:16:2d:06:3a:7c
      echo "encendido  ip 10.1.10.124"
      sleep 40
      ;;
      2)
      wakeonlan ac:16:2d:0d:db:21
      echo "encendido  ip 10.1.10.122"
      sleep 40
      ;;
      3)
      wakeonlan ac:16:2d:11:c9:49
      echo "encendido ip 10.1.10.125"
      sleep 40
      ;;
      4)
      wakeonlan ac:16:2d:11:c9:59
      echo "encendido ip 10.1.10.121"
      sleep 40
      ;;
      5)
      wakeonlan 24:be:05:07:a6:4a
      echo "encendido ip 10.1.10.127"
      echo "paralelanueva"
      echo "distribuida"
      sleep 40
      ;;
      6)
      wakeonlan ac:16:2d:11:c9:51
      echo "encendido ip 10.1.10.126"
      echo "paralelavieja"
      echo "peramaxima"
      sleep 40
      ;;
      7)
      wakeonlan ac:16:2d:06:3a:6e
      echo "encendido ip 10.1.10.123"
      echo "paralelavieja"
      echo "peramaxima"
      sleep 40
      ;;
      8)
      #no tiene puertos  o no funciona
      wakeonlan ac:16:2d:06:3a:7f
      echo "encendido ip 10.1.10.116"
      echo "paralelanueva"
      echo "distribuida"
      sleep 40
      ;;
      9)
      wakeonlan ac:16:2d:0e:58:77
      echo "encendido ip 10.1.10.118"
      echo "paralelanueva"
      echo "distribuida"
      sleep 40
      ;;
      ##########################################################################
      21)
      ssh paralela_nueva@10.1.10.124
      ;;
      22)
      ssh paralela_nueva@10.1.10.122
      ;;
      23)
      ssh paralela_nueva@10.1.10.125
      ;;
      24)
      ssh paralela_nueva@10.1.10.121
      ;;
      25)
      ssh xxxxxx@10.1.10.127 #tiene q ser mismo user en 25 26 27
      ;;
      26)
      ssh xxxxxx@10.1.10.126 #tiene q ser mismo user en 25 26 27
      ;;
      27)
      ssh xxxxxxx@10.1.10.123 #tiene q ser mismo user en 25 26 27
      ;;
      28)
      ssh paralela_nueva@10.1.10.116 #aun no se configua
      ;;
      29)
      ssh paralela_nueva@10.1.10.118 #aun no se configura
      ;;
     99)
        exit
     ;;
  esac
done
