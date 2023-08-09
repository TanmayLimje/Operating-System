#!/bin/bash

choice=0

while [[ $choice -lt 6 ]]
do
	
	echo "*****************************"
	echo "Welcome"
	echo "1. Create Address book"
	echo "2. View Address Book"
	echo "3. Insert a record"
	echo "4. Modify a record"
	echo "5. Delete a record"
	echo "6. Exit"
	echo "*****************************"
	echo
	echo "Enter your choice [1/2/3/4/5/6]"
	read choice
	echo
	
	case $choice in 
	
		1)	
			echo
			echo "Enter the name of file"
			read file_name
			
			
			
			#touch "$file_name"
			
			if [[ -e "$file_name" ]]; then
				rm "$file_name"
			fi
			
			echo
			echo -e "RollNo \t\t Name \t\t Year \t\t Dept" | cat >> "$file_name"
			
			echo
			echo "File created succesfully!"
			echo
			
			;;
			
		2)	
			
			cat "$file_name"
			echo
			;;	
			
		3)
			a=1
			while [[ a -gt 0 ]]
			do
				echo -e "\n Enter Roll no"
				read roll
				echo -e "\n Enter Name"
				read name
				echo -e "\n Enter Year"
				read year
				echo -e "\n Enter Dept"
				read dept
				echo
				
				echo -e "$roll \t\t $name \t\t $year \t\t $dept" | cat >> "$file_name"
				
				echo "press [1] to continue"
				echo "press [0] to exit"
				read a
				
			done
			;;

	esac

done
