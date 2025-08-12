#basic calculator
#!/bin/bash
while true
do
	echo "Calculator"
	printf "Enter first number: "
	read a
	printf "Enter second number: "
	read b
	echo "The entered numbers are $a and $b."

	echo "Menu:- "
	echo "1. Addition (a+b)"
	echo "2. Subtraction (a-b)"
	echo "3. Multiplication (a*b)"
	echo "4. Division (a/b)"
	echo "5. Exit"
	printf "Enter the number to perform an operation: "
	read choice

	case $choice in 
	1) echo "`expr $a + $b`";;
	2) echo "`expr $a - $b`";;
	3) echo "`expr $a \* $b`";;
	4) if [ $b -eq 0 ]
		then
			echo "Denominator can't be zero"
		else
			ans=$(echo "scale=2; $a / $b" | bc)
			echo "$ans"
		fi;;
	5) exit 0;;
	*) echo "Invalid operation";;
	esac
done
