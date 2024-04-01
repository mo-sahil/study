mat <- matrix(c(1:10), nrow = 5,ncol = 2, byrow = F)
mat

apply(mat, 1, sum)
apply(mat, 2, sum)

apply(mat, 1, mean)
apply(mat, 2, mean)

apply(mat, 1, median)
apply(mat, 2, median)

mult <- function(arr) {
  for(i in arr) {
    print(i*2)
  } 
}

apply(mat, 1, mult)
