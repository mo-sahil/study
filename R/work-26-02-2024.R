a <- 1:10

b = sort(a, decreasing = TRUE)

c <- 1:20
c[-c(2,4,6,8)]

d <- list("Sahil", 19.1, 19L, 19+1i, TRUE)
d

for(i in d) {
  if (is.numeric(i)) {
    print(i)
  }
}

for(i in d) {
  if (!is.logical(i)) {
    print(i)
  }
}

arr <= array(c(1:48),
