palindrome <- function(a) {
  b <- a
  x = 0
  while (a > 0) {
    rem = a%%10
    x = x*10 + rem
    a = as.integer(a/10)
  }
  
  if(x == b) {
    return(TRUE)
  } else {
    return(FALSE)
  }
}

print(palindrome(124521))


