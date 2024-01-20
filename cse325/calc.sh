echo "Simple Calculator"
echo "1. Addition"
echo "2. Subtraction"
echo "3. Multiplication"
echo "4. Division"
echo -n "Enter your choice (1/2/3/4): "
read choice

echo -n "Enter first number: "
read num1
echo -n "Enter second number: "
read num2

case $choice in
  1) result=$(($num1 + $num2));;
  2) result=$(($num1 - $num2));;
  3) result=$(($num1 * $num2));;
  4)
    if [ $num2 -eq 0 ]; then
      echo "Error: Division by zero is not allowed"
      exit 1
    fi
    result=$(awk "BEGIN {printf \"%.2f\", $num1 / $num2}")
    ;;
  *) echo "Invalid choice"; exit 1;;
esac

echo "Result: $result"

