#!/bin/bash

#simple print 
echo "hello"

#print using variables
Name="SaSuMaAaTA"
NO_OF_PPL=5
echo "$Name, Group of $NO_OF_PPL"

#user input
echo
echo "Enter your age and press <-"
read Age 

#if else
if [ "$Age" -eq 20 ]; then
	echo "Congo u r not sans!"
else 
	echo "U are Sans!"	
fi

# dir
echo
echo "Enter the name of the Directory then press <-"
read Dir
if [ -d "$Dir" ]; then
	ls "$Dir"
else
	mkdir "$Dir"
	echo "Created DIR"
fi

#for loop
echo
s=1
e=5
echo "for loop"
for (( i=s; i<=e; i++ ))
do
	echo "sundi tapori"
done

#while loop

i=1
echo
echo "while loop"
while [[ $i -le e ]]

do 
	echo " $i. Hello there" 
	(( i=i+1 ))
done	
echo
# sum of natural no till 40
echo
echo "sum of natural no till 40"
end=40
sum=0 
for (( i=s; i<=end; i++ ))
do
	((sum = sum + i))
done
echo $sum
echo

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
