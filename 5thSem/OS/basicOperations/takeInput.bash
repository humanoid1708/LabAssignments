#!bin/bash

printf "Enter your first name : "
read fname

printf "Enter your last name : "
read lname

echo "Your name is $fname $lname"

printf "Enter a number:"
read num1

printf "Enter another number:"
read num2

echo $((num1 + num2))

