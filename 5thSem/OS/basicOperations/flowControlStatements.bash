#!bin/bash

#use '#' for making comments

# if-else block
printf "Enter 1 or -1: "
read choice
if [ $choice -gt 0 ]
then
printf "Hello"
else
printf "World"
fi

# for loop
for i in {1..15}
do
	echo "Welcome $i time"
done

# while loop
j=1
n=99
while [ $j -le 10 ]
do 
	echo "$n * $j = `expr $j \* $n`"
	j=`expr $j + 1`
done

# switch-case block
echo "Enter a number: "
read var
case $var in
1) echo "Mathematics";;
2) echo "Artificial Intelligence";;
3) echo "Machine Learning";;
4) echo "Big Data Tech";;
*) echo "Operating System";;
esac
