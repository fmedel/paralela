#!/bin/bash
plantilla=1
while [ $plantilla -le 1 ]
do
  clear
  echo "1)Prender pc de felipe"
  echo "2)Prender pc de diego"
  echo "3)Prender pc de ignacio"
  echo "4)Prender pc de leo"
  echo "5)Prender pc extra 1"
  echo "6)Prender pc extra 2"
  echo "----------------------"
  echo "11)conectar al pc de felipe"
  echo "12)conectar al pc de diego"
  echo "13)conectar al pc de ignacio"
  echo "14)conectar al pc de leo"
  echo "15)conectar al pc extra 1"
  echo "16)conectar al pc extra 2"
  echo "99) salir"
  read x
  case $x in
      1)

      wakeonlan ac:16:2d:06:3a:7c
      echo " p 19964 encendido  ip 10.1.10.124"
      sleep 30
      ;;
      2)
      wakeonlan ac:16:2d:0d:db:21
      echo " p 20452 encendido  ip 10.1.10.122"
      sleep 30
      ;;
      3)
      wakeonlan ac:16:2d:11:c9:49
      echo " p 19966 encendido ip 10.1.10.125"
      sleep 30
      ;;
      4)
      wakeonlan ac:16:2d:11:c9:59
      echo " p 20411 encendido ip 10.1.10.121"
      sleep 30
      ;;
      5)
      ;;
      11)
      echo "ip 10.1.10.124"
      ssh paralela_nueva@10.1.10.124
      ;;
      12)
      echo "ip 10.1.10.122"
      ssh paralela_nueva@10.1.10.122
      ;;
      13)
      echo "ip 10.1.10.125"
      ssh paralela_nueva@10.1.10.125
      ;;
      14)
      echo "ip 10.1.10.121"
      ssh paralela@10.1.10.121
      ;;
     99)
        exit
     ;;
  esac
done
