#!/bin/bash

#do sum of no given by user until they provide negative value and print no of sums

echo "Enter number"
read num
s=0
no_of_sum=0

while [[ $num -ge 0 ]]
do
	((s = s + num))
	((no_of_sum = no_of_sum + 1 ))
	echo "sum = $s"
	echo 
	echo "Enter number"
	read num
done
echo
echo "negative no found"
echo "final sum = $s"
echo
echo "No of sums = $no_of_sum"	
