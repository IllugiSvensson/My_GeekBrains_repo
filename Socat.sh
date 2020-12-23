#!/bin/bash

if [ "$HOSTNAME" == "SRV1" ]
then

	#Редактируем хмл файлы под открываемые порты
	sed -i "s/tty./tty1/g" /soft/etc/K23800/Ship/Connections/cnct_nmea_kama.xml
	sed -i "s/tty./tty2/g" /soft/etc/K23800/Ship/Connections/cnct_nmea_sev.xml
	sed -i "s/tty./tty3/g" /soft/etc/K23800/Ship/Connections/cnct_nmea_harakter.xml

	#На СРВ и АЗН открываем порты для прослушивания
	#Прослушка идет в фоновом режиме
	socat TCP-LISTEN:14141,fork,reuseaddr pty,raw,waitslave,unlink-close=0,echo=0,link=/dev/tty1 &
	socat TCP-LISTEN:14142,fork,reuseaddr pty,raw,waitslave,unlink-close=0,echo=0,link=/dev/tty2 &
	socat TCP-LISTEN:14143,fork,reuseaddr pty,raw,waitslave,unlink-close=0,echo=0,link=/dev/tty3 &
	wait

elif [ "$HOSTNAME" == "SRV2" ]
then

	sed -i "s/tty./tty4/g" /soft/etc/K23800/Ship/Connections/cnct_nmea_kama.xml
	sed -i "s/tty./tty5/g" /soft/etc/K23800/Ship/Connections/cnct_nmea_sev.xml
	sed -i "s/tty./tty6/g" /soft/etc/K23800/Ship/Connections/cnct_nmea_harakter.xml

	#На СРВ и АЗН открываем порты для прослушивания
	#Прослушка идет в фоновом режиме
	socat TCP-LISTEN:14144,fork,reuseaddr pty,raw,waitslave,unlink-close=0,echo=0,link=/dev/tty4 &
	socat TCP-LISTEN:14145,fork,reuseaddr pty,raw,waitslave,unlink-close=0,echo=0,link=/dev/tty5 &
	socat TCP-LISTEN:14146,fork,reuseaddr pty,raw,waitslave,unlink-close=0,echo=0,link=/dev/tty6 &
	wait

elif [ "$HOSTNAME" == "AZNX" ]
then

	socat TCP-LISTEN:14147,fork,reuseaddr pty,raw,waitslave,unlink-close=0,echo=0,link=/dev/tty7 &
	wait
	#Добавить редактор для стартсервера

elif [ "$HOSTNAME" == "AZN2" ]
then

	socat TCP-LISTEN:14148,fork,reuseaddr pty,raw,waitslave,unlink-close=0,echo=0,link=/dev/tty8 &
	wait

elif  [ "$HOSTNAME" == "Emul" ]
then

	if [ "$1" == "srv1" ]		#Соединение для сервера
	then
		#Проверяем, работает ли Сервер
		ping -c 1 -w 10 192.168.10.72 >/dev/null 2>&1 && Host1="SRV1"
		ping -c 1 -w 10 192.168.11.72 >/dev/null 2>&1 && Host2="SRV1"

		if [ "$Host1" == "" -a "$Host2" == "" ]
		then

			exit

		elif [ "$Host1" == "$Host2" ]
		then

			sleep 45s
			flag=0

			while [ "$Host1" == "SRV1" -a "$Host2" == "SRV1" ]
			do

				if [ "$flag" == "0" ]
				then

					#Если работает, то создаем соединение 
					socat -u -u pty,raw,echo=0,link=/dev/tty1 TCP:192.168.111.52:14141 &	#Kama
					socat -u -u pty,raw,echo=0,link=/dev/tty2 TCP:192.168.111.52:14142 &	#Sev
					socat -u -u pty,raw,echo=0,link=/dev/tty3 TCP:192.168.111.52:14143 &	#Harakter
					ssh $Host1 killall -9 cnct_nmea.bin
					flag=1

				fi

				ping -c 1 -w 10 192.168.10.72 >/dev/null 2>&1 && Host1="0"
				ping -c 1 -w 10 192.168.11.72 >/dev/null 2>&1 && Host2="0"

			done

			exit

		fi

	elif [ "$1" == "srv2" ]		#Соединение для сервера
	then
		#Проверяем, работает ли Сервер
		ping -c 1 -w 10 192.168.10.74 >/dev/null 2>&1 && Host1="SRV2"
		ping -c 1 -w 10 192.168.11.74 >/dev/null 2>&1 && Host2="SRV2"

		if [ "$Host1" == "" -a "$Host2" == "" ]
		then

			exit

		elif [ "$Host1" == "$Host2" ]
		then

			sleep 45s
			flag=0

			while [ "$Host1" == "SRV2" -a "$Host2" == "SRV2" ]
			do

				if [ $flag == 0 ]
				then

					#Если работает, то создаем соединение 
					socat -u -u pty,raw,echo=0,link=/dev/tty4 TCP:192.168.121.52:14144 &	#Kama
					socat -u -u pty,raw,echo=0,link=/dev/tty5 TCP:192.168.121.52:14145 &	#Sev
					socat -u -u pty,raw,echo=0,link=/dev/tty6 TCP:192.168.121.52:14146 &	#Harakter
					ssh $Host1 killall -9 cnct_nmea.bin
					flag=1

				fi

				ping -c 1 -w 10 192.168.10.74 >/dev/null 2>&1 && Host1="0"
				ping -c 1 -w 10 192.168.11.74 >/dev/null 2>&1 && Host2="0"

			done

			exit

		fi

	elif [ "$1" == "azn1" ]		#Соединение для АЗН
	then

		ping -c 1 -w 10 192.168.10.71 >/dev/null 2>&1 && Host1="AZN1"
		ping -c 1 -w 10 192.168.11.71 >/dev/null 2>&1 && Host2="AZN1"

		if [ "$Host1" == "" -a "$Host2" == "" ]
		then

			exit

		elif [ "$Host1" == "$Host2" ]
		then

			sleep 45s
			flag=0

			while [ "$Host1" == "AZN1" -a "$Host2" == "AZN1" ]
			do

				if [ $flag == 0 ]
				then

					socat -u -u pty,raw,echo=0,link=/dev/tty7 TCP:192.168.11.71:14147 &	#AZN
					#Перезапускаем приемопередатчик данных
					ssh $Host1 killall -9 StartServer.bin
					flag=1

				fi

				ping -c 1 -w 10 192.168.10.71 >/dev/null 2>&1 || Host1="0"
				ping -c 1 -w 10 192.168.11.71 >/dev/null 2>&1 || Host2="0"

			done

			exit

		fi

	elif [ "$1" == "azn2" ]		#Соединение для АЗН
	then

		ping -c 1 -w 10 192.168.10.73 >/dev/null 2>&1 && Host1="AZN2"
		ping -c 1 -w 10 192.168.11.73 >/dev/null 2>&1 && Host2="AZN2"

		if [ "$Host1" == "" -a "$Host2" == "" ]
		then

			exit

		elif [ "$Host1" == "$Host2" ]
		then

			sleep 45s
			flag=0

			while [ "$Host1" == "AZN2" -a "$Host2" == "AZN2" ]
			do

				if [ $flag == 0 ]
				then

					socat -u -u pty,raw,echo=0,link=/dev/tty8 TCP:192.168.11.73:14148 &	#AZN
					#Перезапускаем приемопередатчик данных
					ssh $Host1 killall -9 StartServer.bin
					flag=1

				fi

				ping -c 1 -w 10 192.168.10.73 >/dev/null 2>&1 && Host1="0"
				ping -c 1 -w 10 192.168.11.73 >/dev/null 2>&1 && Host2="0"

			done

			exit

		fi

	fi

fi