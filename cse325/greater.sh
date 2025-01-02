echo "Lets eneter a number of your choice"
echo "enter the first number: "
read a
echo "Enter the second number: "
read b
if test $a -gt $b
then
echo $a is greater than $b
else
echo $b is greater than $a
fi
