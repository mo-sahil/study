echo "enter a number"
read a
for i in {1..10}
do
		echo "$a * $i = $((a * i))"
done
