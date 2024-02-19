# 10 examples for if statement take all inputs from user
# check even and odd in case of vector by using if else statement
# check the less than or greater than by using if else statement
# check the number is present in vector or not by using if else statement
# 5 e more examples for if else statement
# check whether the number is positive, negative, or equals to zero by using else if note: take input from user
# 5 more examples for else if ladder

#2
a <- 1:10
for(i in a){
  if (i%%2 == 0){
    print(paste(i, "even"))
  } else {
    print(paste(i, "odd"))
  }
}

#3
if(2 < 3){
  print("true")
} else {
  print("false")
}

#4
if (4 %in% a){
  print("true")
} else {
  print("false")
}

#6
x = as.numeric(readline("Enter a number: "))
if(x == 0){
  print(paste(x, "is equal to zero"))
} else if (x>0) {
  print(paste(x, "is greater than zero"))
} else {
  print(paste(x, "is less than zero"))
}
