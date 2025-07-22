#!bin/bash

printf "Enter a number: "
read num
res=1
for i in $(seq 1 $num)
do
	res=$(( res * i ))
done
echo $res

