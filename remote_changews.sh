#!/bin/bash

function DeleteTmpFile {

	rm -f /soft/scripts/CWR_online.txt	#Удаляем временные файлы
	rm -f /soft/scripts/CWR_offline.txt
	rm -f /soft/scripts/kdialog.sh
	rm -f /soft/scripts/HOSTNAME
	rm -f /soft/scripts/PRODUCT

}

function CancelButtonClicked {		#Выход из окна при нажании на Отмена или х

	if [ -z "$1" ]
	then

		DeleteTmpFile
		zenity --warning --ellipsize --text="Нажата отмена или\nне выбран компьютер!" --title="Предупреждение" --timeout=2
		exit 1

	fi

}

function MakeDialogWindow {		#Создание диалогового окна

#Собираем окно из отдельных элементов
ListItem="zenity --title=\"Система управления ЗИП\" --height=350 --width=350 --list --text=\"$1\" --column=\"$2\" --column=\"Описание\" --ok-label=\"Применить\" --cancel-label=\"Выход\""
for Host in $3			#Добавляем в список соответствующие хосты
do

	ListItem="$ListItem \"$Host\""

done
ListItem="$ListItem $5"

cd /soft/scripts
rm -f kdialog.sh		#Создаем основное диалоговое окно
echo -E "#! /bin/bash" >>kdialog.sh
echo -E "RESULT=\`$ListItem\`" >>kdialog.sh
echo -E "echo \$RESULT" >>kdialog.sh
chmod +x kdialog.sh
./kdialog.sh > $4	#Фиксируем вывод окна
rm -f kdialog.sh

}

#Блок отключения других экземпляров программы при повторном запуске
FindPIDs=`pgrep -f "remote_changews.sh"`	#Ищем PID процесса(ов)
for RunPID in $FindPIDs
do

	if [ "$RunPID" != "$$" ]	#Перебираем PID'ы и если есть не текущий
	then

		kill $RunPID		#Убиваем его вместе со
		killall zenity		#всеми активными окнами
		DeleteTmpFile		#Очищаем рабочую область

	fi

done

#Подключаем переменные окружения и глобальные переменные
. /soft/scripts/path.sh		#Подтягиваем переменные окружения
export LANG=ru_RU.UTF-8		#Подключаем язык
CONFIG=`/system/bin/regtool.bin -r /system/etc/system.xml / Config`
PRODUCT=`cat $NITAROOT/PRODUCT`
HOMEHOST=`cat $NITAROOT/HOSTNAME`
touch /soft/scripts/CWR_online.txt	#Временный файл со списком онлайн хостов
touch /soft/scripts/CWR_offline.txt	#Временный файл со списком оффлайн хостов
ProgressBarIncrement=0; inc=0		#Инкремент хода выполнения проверки (для визуализации)

#Блок проверки хостов в сети
for XmlList in /system/etc/$CONFIG/*.xml	#Циклично перебираем все ХМЛки
do

	for HOST in `/system/bin/regtool.bin -n $XmlList /Hosts`	#Просматриваем адреса каждого хоста
	do

		ProgressBarIncrement=$(($ProgressBarIncrement + 10))
		echo $ProgressBarIncrement		#Процент выполнения
		ADDRESSES=`/system/bin/regtool.bin -l $XmlList /Hosts/$HOST/Network/Addresses`	#Список адресов хоста
		CountOfAddresses=`echo $ADDRESSES | grep -o " " | wc -l`		#Количество адресов хоста
		AddresCount=0		#Счетчик текущего адреса (для списка хостов не в сети)

		for ADDRES in $ADDRESSES	#Пингуем адреса отдельного хоста
		do

			ping -c 1 -W 1 $ADDRES >/dev/null 2>&1
			if [ $? == 0 ]		#Если хоть один адрес хоста ответил
			then

				DESCRIPTION=`/system/bin/regtool.bin -r $XmlList /Hosts/$HOST Description $HOST`
				echo $HOST \"$DESCRIPTION\">>/soft/scripts/CWR_online.txt	#Пишем хост в список "в сети"
				AddresCount=0			#Сбрасываем счетчик
				break				#Выходим из итерации

			elif [ $? != 0 ]	#Если адрес хоста не ответил
			then

				if [ $CountOfAddresses != $AddresCount ]
				then

					AddresCount=$((AddresCount + 1))	#Считаем адреса, пока не проверим все

				else 

					DESCRIPTION=`/system/bin/regtool.bin -r $XmlList /Hosts/$HOST Description $HOST`
					echo $HOST \"$DESCRIPTION\">>/soft/scripts/CWR_offline.txt	#Если все не пингуются, пишем хост "не в сети"

				fi

			fi

		done

	done

done | zenity --progress --title="Проверка сети" --text="Ищем компьютеры.." --auto-close

[ $? != 0 ] || { CANCEL="Cancel"; }		#Для подведения к общему виду работы функции
CancelButtonClicked $CANCEL			#Выходим из программы, если нажали отмену
echo `cat /soft/scripts/CWR_online.txt` >/soft/scripts/CWR_online.txt		#Транспонируем таблицу в список
echo `cat /soft/scripts/CWR_offline.txt` >/soft/scripts/CWR_offline.txt		#Для удобной работы
HostsOnline=`cat /soft/scripts/CWR_online.txt`		#Либо сохраняем списпки хостов
HostsOffline=`cat /soft/scripts/CWR_offline.txt`
DeleteTmpFile


#%%%%%%%%%%%%%%%%%%%%%%%
#Блок на случай, если не загрузилась сетевушка и список пустой или что то пошло не так (такой ситуации надеюсь никогда не случится)
[ -z $HostsOnline ] && {

	zenity --warning --title=Предупреждение --ellipsize --timeout=7 --text="Компьютер не в сети.\nПроверьте подключение и попробуйте еще раз\nлибо принудительно задайте роль\nдля локального компьютера."
	MakeDialogWindow "Выберите требуемую роль." "Роль" "$HostList" /soft/scripts/CWR_online.txt
	ROLE=`cat /soft/scripts/CWR_online.txt`		#Записали результат диалога
	CancelButtonClicked $ROLE			#Если нажали Выход

		if [ $ROLE == "ZIP" ]
		then

			PRODUCT=ZIP

		elif [ $ROLE != "ZIP" ]
		then

			PRODUCT=Ship

		fi

		echo $ROLE> /$NITAROOT/HOSTNAME		#Генерируем выбранную роль, задаем хостнейм
		echo $PRODUCT> /$NITAROOT/PRODUCT	#Генерируем продукт
		/system/bin/regtool.bin -w /$NITAROOT/etc/system.xml / Product $PRODUCT
		remount rw
		/system/scripts/system.sh $PRODUCT GenerateConfig

		zenity --info --title="Завершение работы" --text="Выбранная роль будет установлена\nпосле перезагрузки компьютера.\nПерезагрузка через 3 сек." --ellipsize --timeout=3
		DeleteTmpFile
		reboot

}
#%%%%%%%%%%%%%%%%%%%%%%


#Ведем диалог с пользователем
while :
do

	MakeDialogWindow "Выберите доступный компьютер." "Имя" "$HostsOnline" /soft/scripts/CWR_online.txt		#Диалог выбора хоста
	HOST=`cat /soft/scripts/CWR_online.txt`		#Записали результат диалога
	CancelButtonClicked $HOST			#Если нажали Выход

	MakeDialogWindow "Задайте роль для компьютера $HOST." "Роль" "$HostsOffline" /soft/scripts/CWR_offline.txt --extra-button="Назад"	#Диалог выбора роли
	ROLE=`cat /soft/scripts/CWR_offline.txt`
	CancelButtonClicked $ROLE

	[ $ROLE == "Назад" ] && { continue; }	#Возвращаемся назад в пункт меню

	[ -z $ROLE ] || {			#Если роль выбрана спрашиваем, применить или нет

		zenity --question --width=200 --title="Система управления ЗИП" --text="Применить роль $ROLE\nдля компьютера $HOST?" --ok-label="Применить" --cancel-label="Назад"

		if [ $? == 0 ]		#Если нажали да, то задаем роль
		then

			if [ $ROLE == "ZIP" ]
			then

				PRODUCT=ZIP

			elif [ $ROLE != "ZIP" ]
			then

				PRODUCT=Ship

			fi

			if [ $HOMEHOST == $HOST ]		#Если выбрали локальный компьютер
			then

				echo $ROLE> /$NITAROOT/HOSTNAME		#Генерируем выбранную роль, задаем хостнейм
				echo $PRODUCT> /$NITAROOT/PRODUCT	#Генерируем продукт
				/system/bin/regtool.bin -w /$NITAROOT/etc/system.xml / Product $PRODUCT

				remount rw
				/system/scripts/system.sh $PRODUCT GenerateConfig	#Генерируем конфигурацию

				zenity --info --title="Завершение работы" --text="Выбранная роль будет установлена\nпосле перезагрузки компьютера.\nПерезагрузка через 3 сек." --ellipsize --timeout=3
				DeleteTmpFile

				reboot

			else

				echo $ROLE> /$NITAROOT/scripts/HOSTNAME		#Генерируем выбранную роль, задаем хостнейм
				echo $PRODUCT> /$NITAROOT/scripts/PRODUCT	#Генерируем продукт
				scp /$NITAROOT/scripts/HOSTNAME root@$HOST:/soft
				scp /$NITAROOT/scripts/PRODUCT root@$HOST:/soft
				ssh $HOST /system/bin/regtool.bin -w /$NITAROOT/etc/system.xml / Product $PRODUCT

				ssh $HOST remount rw
				ssh $HOST /system/scripts/system.sh $PRODUCT GenerateConfig	#Генерируем конфигурацию

				zenity --info --title="Завершение работы" --text="Выбранная роль будет установлена\nпосле перезагрузки компьютера.\nПерезагрузка через 3 сек." --ellipsize --timeout=3
				DeleteTmpFile

				ssh $HOST reboot

			fi

			sleep 10; TIME=0		#Наблюдаем за компом, 10 сек форы на ребут
			while [ $TIME -lt 60 ]		#Если в течении минуты загрузится
			do

				ping -c 1 -W 1 $ROLE	#И ответит на пинг, то все хорошо
				[ $? == 0 ] && { 

					zenity --info --title=Успех --ellipsize --text="Компьютер $HOST принял роль $ROLE\nи готов к работе." --timeout=3
					exit 0

				}
				sleep 1			#счетчик времени
				TIME=$(( $TIME + 1 ))

			done
			#Если не ответит, выход с предупреждением
			zenity --error --title=Внимание --ellipsize --text="Компьютер $HOST в роли $ROLE не загрузился\nПроверьте подключение." --timeout=3
			exit 1

		else

			continue	#Если нажали отмена, повторяем цикл

		fi

	}

done