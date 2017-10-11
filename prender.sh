#!/bin/bash
plantilla=1
while [ $plantilla -le 1 ]
do
  clear
  echo "---------------------"
  echo "|P1 |P2 |P3 |P4 |P5 |"
  echo "|P6 |P7 |P8 |P9 |P10|"
  echo "|P11|P12|P13|P14|P15|"
  echo "---------------------"
  echo " "
  echo "1)Prender P9 de felipe"
  echo "2)Prender P8 de diego"
  echo "3)Prender P10 de ignacio"
  echo "4)Prender P7 de leo"
  echo "5)Prender pc reyes"
  echo "6)Prender pc francisco"
  echo "7)Prender pc Fabian"
  echo " "
  echo "8)Prender P1"
  echo "9)Prender P2"
  echo "10)Prender P3"
  echo "11)Prender P4"
  echo "12)Prender P5"
  echo "13)Prender P6"
  echo "14)Prender P11"
  echo "15)Prender P12"

  echo "----------------------"
  echo "21)conectar al pc de felipe"
  echo "22)conectar al pc de diego"
  echo "23)conectar al pc de ignacio"
  echo "24)conectar al pc de leo"
  echo "25)conectar al pc reyes"
  echo "26)conectar al pc francisco"
  echo "26)conectar al pc Fabian"
  echo "99) salir"
  read x
  case $x in
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

      21)
      echo "ip 10.1.10.124"
      ssh paralela_nueva@10.1.10.124
      ;;
      22)
      echo "ip 10.1.10.122"
      ssh paralela_nueva@10.1.10.122
      ;;
      23)
      echo "ip 10.1.10.125"
      ssh paralela_nueva@10.1.10.125
      ;;
      24)
      echo "ip 10.1.10.121"
      ssh paralela@10.1.10.121
      ;;

     99)
        exit
     ;;
  esac
done
