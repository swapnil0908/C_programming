#!/bin/bash

if [ $# -gt 0 ]; then
	LIST=$@
fi


Path=/import/linux/home1/skharch2/cs580u/assignment3/TRASH/*

if [ ! -d "TRASH" ]
then
	mkdir "/import/linux/home1/skharch2/cs580u/assignment3/TRASH"
fi

for FILE in $LIST
do
if [ -e $FILE ]
then
	mv $FILE "/import/linux/home1/skharch2/cs580u/assignment3/TRASH"

elif [ ! -e $FILE ]
then
	echo	"File does not exist"
fi
done


for i in $Path
 do
       if [[ -f $i ]]
	then
	current=`date +%s`
	last_modified=`stat -c "%Y" $i`
        if [ $(($current-$last_modified)) -gt 3600 ]
        then
       	rm $i
        echo ""$i" has been deleted from TRASH folder"
        fi
       	fi
done













