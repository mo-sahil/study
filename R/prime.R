a = as.numeric(readline("Enter a number: "))

is_prime <- function(a) {
  for(i in 2:(a-1)) {
    if (a%%i == 0) {
      return(FALSE)
    }
  }
  return(TRUE)
}

print(is_prime(a))