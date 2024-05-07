#!/bin/bash


echo -n "Enter year: "
read year

if [ $(($year%4)) -eq 0 -a $(($year%100)) -ne 0 -o $(($year%400)) -eq 0 ]
then
        echo "$year is a Leap Year"

else
        echo "$year is Not a Leap Year"
fi


