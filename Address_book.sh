#!/bin/bash

choice=0

while [[ $choice -lt 6 ]]
do
	echo
	echo "*****************************"
	echo "Welcome"
	echo "1. Create Address book"
	echo "2. View Address Book"
	echo "3. Insert a record"
	echo "4. Delete a record"
	echo "5. Modify a record"
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
				echo -e "\nEnter Roll no"
				read roll
				
				echo -e "\nEnter Name"
				read name
				
				echo -e "\nEnter Year"
				read year
				
				echo -e "\nEnter Dept"
				read dept
				
				echo
				
				echo -e "$roll \t\t $name \t\t $year \t\t $dept" | cat >> "$file_name"
				
				echo "press [1] to continue"
				echo "press [0] to exit"
				read a
				
				
				
			done
			;;
			
		4)
			echo
			echo "Delete record!"	
			echo "Enter Name or Rollno"
			read abc
			
			temp="temp"
			
			grep -v $abc $file_name | cat >> $temp
			
			rm $file_name
			
			cat $temp | cat >> $file_name
			
			rm $temp
			
			echo
			echo "Record Deleted Successfully"
			echo
			
			cat $file_name
			
			;;
			
		5)
			echo
			echo "Modify a record"
			echo
			cat $file_name
			echo
			echo "Enter name or rollno to be modified"
			read xyz
			
			temp="temp"
			
			grep -v $xyz $file_name | cat >> $temp
			
			rm $file_name
			
			cat $temp | cat >> $file_name
			
			rm $temp
			
			echo -e "\nModify Roll no"
			read roll1
			
			echo -e "\nModify Name"
			read name1
			
			echo -e "\nModify Year"
			read year1
			
			echo -e "\nModify Dept"
			read dept1
			
			echo
			
			echo -e "$roll1 \t\t $name1 \t\t $year1 \t\t $dept1" | cat >> "$file_name"	
			
			echo
			cat $file_name
			echo
			;;
	esac

done
