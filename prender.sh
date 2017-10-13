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
  echo "14)Prender P1X"
  echo "15)Prender P1X"
  echo "----------------------"
  echo "21)conectar al pc de felipe"
  echo "22)conectar al pc de diego"
  echo "23)conectar al pc de ignacio"
  echo "24)conectar al pc de leo"
  echo "25)conectar al pc reyes"
  echo "26)conectar al pc francisco"
  echo "27)conectar al pc Fabian"
  echo " "
  echo "28)conectar al pc P1"
  echo "29)conectar al pc P2"
  echo "30)conectar al pc P3"
  echo "31)conectar al pc P4"
  echo "32)conectar al pc P5"
  echo "33)conectar al pc P6"
  echo "34)conectar al pc P1X"
  echo "35)conectar al pc P1X"
  echo "----------------------"
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
      8)
      #no tiene puertos  o no funciona
      wakeonlan ac:16:2d:06:3a:7f
      echo "encendido ip 10.1.10.??"
      sleep 40
      ;;
      9)
      #no tiene puertos  o no funciona
      wakeonlan 24:be:05:07:a6:4a
      echo "encendido ip 10.1.10.??"
      sleep 40
      ;;
      10)
      #no tiene puertos  o no funciona
      wakeonlan ac:16:2d:11:c7:9c
      echo "encendido ip 10.1.10.??"
      sleep 40
      ;;
      11)
      #no tiene puertos  o no funciona
      wakeonlan ac:16:2d:06:3a:94
      echo "encendido ip 10.1.10.??"
      sleep 40
      ;;
      12)
      #no tiene puertos  o no funciona
      wakeonlan  ac:16:2d:11:c9:54
      echo "encendido ip 10.1.10.??"
      sleep 40
      ;;
      13)
      #no tiene puertos  o no funciona
      wakeonlan ac:16:2d:0d:da:fb
      echo "encendido ip 10.1.10.??"
      sleep 40
      ;;
      14)
      #no tiene puertos  o no funciona
      wakeonlan ac:16:2d:0d:da:f3
      echo "encendido ip 10.1.10.??"
      sleep 40
      ;;
      15)
      #no tiene puertos  o no funciona
      wakeonlan ac:16:2d:06:3a:6e
      echo "encendido ip 10.1.10.??"
      sleep 40
      ;;
      16)
      #no tiene puertos  o no funciona
      wakeonlan ac:16:2d:0e:58:77
      echo "encendido ip 10.1.10.??"
      sleep 40
      ;;
      17)
      #no tiene puertos  o no funciona
      wakeonlan ac:16:2d:11:c9:51
      echo "encendido ip 10.1.10.??"
      sleep 40
      ;;
      ##########################################################################
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
