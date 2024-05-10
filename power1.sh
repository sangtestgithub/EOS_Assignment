#!/bin/bash

echo -n "Enter the base and power: "
read base power
val=1
pow=$power
while [ $power -ne 0 ]
do
        val=`expr $val \* $base`
        power=`expr $power - 1`
done
echo "$base^$pow = $val"


#echo -n "Enter the base number (a): "
#read a

#echo -n "Enter the exponent (b): "
#read b

# Calculate a^b using bc
#result=$(echo "$a^$b" | bc)

# Display the result
#echo "The result of $a^$b is: $result"
