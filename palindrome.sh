#!/bin/bash

#Palindrome

echo 
echo "Enter a string to check palindrome or not: "
read str

len=${#str}
rev=""
for (( i = $len - 1; i >= 0; i--))
	do
	rev="$rev${str:$i:1}"
	done
	
echo "rev = $rev "

if [ $str = $rev ]; then
	echo "palindrome"
else 
	echo "Not palindrome"
fi

