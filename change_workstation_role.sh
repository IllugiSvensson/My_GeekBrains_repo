#! /bin/bash

RUN_TEST=`pgrep -f "change_workstation_role.sh"`
for RUN_PID in $RUN_TEST ; do
	if [ "$RUN_PID" != "$$" ] ; then
		exit 1
	fi
done

# Environment
. /soft/scripts/path.sh

PRODUCT=`cat $NITAROOT/PRODUCT`

export LANG=ru_RU.UTF-8
cd /soft/scripts

# ZIP server
if [ "$PRODUCT" == "alpha5" ]; then
	ZIP_SERVER=10.101.100.12
else 	if [ "$PRODUCT" == "granit" ]; then
		PING_TEST=`ping -c 1 -w 1 10.101.104.211`
		if [ $? == 0 ] ; then
			ZIP_SERVER=10.101.104.211
		else
			ZIP_SERVER=10.101.104.221
		fi
	else 	if [ "$PRODUCT" == "PIVP" ]; then
			ZIP_SERVER=192.168.5.141
		fi
	fi
fi

# Check available zip server
ping -c 1 -W 1 $ZIP_SERVER
if [ $? != 0 ] ; then
	kdialog --error "Сервер обновлений недоступен."
else
	if [ ! -d /tmp/zip ] ; then
		mkdir /tmp/zip
	else
		umount /tmp/zip
	fi
	mount -t nfs $ZIP_SERVER:/soft /tmp/zip
	if [ $? != 0 ] ; then
		kdialog --error "Не могу подключить каталог обновлений."
	else
		diff /soft/version /tmp/zip/version
		if [ $? == 0 ] ; then
			kdialog --msgbox "Версия ПО совпадает с сервером обновлений."
		else
			kdialog --yesno "Версия ПО отличается от сервера обновлений.\nУстановить новое ПО?"
			if [ $? == 0 ] ; then
				rsync -avz --delete --exclude HOSTNAME /tmp/zip/ /soft
				if [ $? == 0 ] ; then
					kdialog --msgbox "ПО успешно обновлено."
				else
					kdialog --msgbox "Не удалось обновить ПО."
				fi
			fi
		fi
		umount /tmp/zip
	fi
	rmdir /tmp/zip
fi

# Get host list
HOST_LIST=`/system/bin/regtool -n /system/etc/$PRODUCT.xml /Hosts`

# Select workstation
ITEM="kdialog --menu \"Изменить роль АРМ\""
for HOST in $HOST_LIST ; do
	echo $HOST
	if [[ $HOST != *ZIP* ]] ; then
		ALIEN=`/system/bin/regtool -r /system/etc/$PRODUCT.xml /Hosts/$HOST Alien 0`
		if [ "$ALIEN" == "1" ] ; then
			continue
		fi
	else
		echo "good"
	fi
	DESCRIPTION=`/system/bin/regtool -r /system/etc/$PRODUCT.xml /Hosts/$HOST Description $HOST`
#	ITEM="$ITEM \"$HOST\" \"$DESCRIPTION\""
	ITEM="$ITEM \"$HOST\" \"$HOST\""
done
rm -f kdialog.sh
echo -E "#! /bin/bash" >>kdialog.sh
echo -E "RESULT=\`$ITEM\`" >>kdialog.sh
echo -E "echo \$RESULT" >>kdialog.sh
chmod +x kdialog.sh
ITEM=`kdialog.sh`
rm -f kdialog.sh

# Process selection
if [ $? == 0 ] ; then
	# If it's canceled
	if [ "$ITEM" == "" ] ; then
		exit
	fi
	# Check if host is exists
	PING_TEST=`ping -c 1 -w 1 $ITEM`
	if [ $? == 0 ] ; then
		kdialog --msgbox "Такой компьютер уже есть"
		exit
	#  Write HOSTNAME and generate config
	else
		echo "$ITEM" >$NITAROOT/HOSTNAME
		mount -nwo remount /
		/system/scripts/system.sh $PRODUCT GenerateConfig
	fi
	# Ask for next actions
	RESULT=`kdialog --radiolist "Выберите следующее действие" halt "Выключить" on reboot "Перезагрузить" off`
	if [ "$RESULT" == "reboot" ] ; then
		# Reboot computer
		kdialog --msgbox "Компьютер будет перезагружен" 1>/dev/null 2>/dev/null
		reboot
	else
		# Halt computer
		kdialog --msgbox "Компьютер будет выключен" 1>/dev/null 2>/dev/null
		halt
	fi
fi

exit 0
