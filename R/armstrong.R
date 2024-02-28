power <- function(base, pow) {
  num = base
  for(i in 1:(pow-1)) {
    num = base * num
  }
  return(num)
}

is_armstrong <- function(a) {
  temp1 = a
  length = 0
  while(temp1 > 0) {
    length = length + 1
    temp1 = as.integer(temp1/10)
  }
  sum = 0
  temp2 = a
  while(temp2 > 0) {
    rem = temp2%%10
    sum = sum + power(rem,length)
    temp2 = as.integer(temp2/10)
  }
  
  if(a == sum ) {
    return(TRUE)
  } else {
    return(FALSE)
  }
}

print(is_armstrong(153))
