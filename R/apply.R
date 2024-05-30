m <- matrix(1:10, 4, 5, TRUE)
m

apply(m, 2, sum)
apply(m, 1, sum)

a <- c("Sahil", "maz", "Ayush")
a

lapply(a, tolower)
unlist(lapply(a, tolower))

c <- cars
c

sapply(c, max)
lapply(c, max)

avg <- function(x) {
  (min(x) + max(x)) /2
}

sapply(c, avg)

d <- iris
tapply(d$Sepal.Width, d$Species, median)
