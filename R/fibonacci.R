a = as.integer(readline("Enter a number: "))
x <- 0
x
y <- 1
y
while(y <= a){
  temp <- y
  y <- x + y
  x <- temp
  print(y)
}
