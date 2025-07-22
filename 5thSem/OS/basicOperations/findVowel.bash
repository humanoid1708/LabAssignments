#!bin/bash

printf "Enter an alphabet: "
read alpha
echo "You entered '$alpha'"
case $alpha in
a) echo "This is a vowel";;
e) echo "This is a vowel";;
i) echo "This is a vowel";;
o) echo "This is a vowel";;
u) echo "This is a vowel";;
*) echo "This is a consonant";;
esac
