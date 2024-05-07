#!/bin/bash

#leap year 
echo -n "Enter a year : "
read year

if [ $(($year%4)) -eq 0 -a $(($year%100)) -ne  0 -o $(($year%400)) -eq 0 ]
	
then
	echo "given year is leap year = $year"
else
	echo "given year is not leap year = $year"
fi	


