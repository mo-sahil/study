a = matrix(c(1:6), nrow = 2, ncol = 3, byrow = TRUE, dimnames = list(c("R1", "R2"), c("C1", "C2", "C3")))
a

a[1,2]
a[1, ]
a[ , 1]
a[c(1,2), ]
a <- cbind(a, c(7, 8))
a

a <- rbind(a, c(9, 10, 11, 12))
a

a <- a[-3, ]
a

10 %in% a
13 %in% a

dim(a)
length(a)

for(i in 1:nrow(a)){
  for(j in 1:ncol(a)){
    print(a[i, j])
  }
}

b = matrix(c(1:8), nrow = 2, ncol = 4, byrow = TRUE)
b

c = rbind(a, b)
c

c = c[-4, ]
c
