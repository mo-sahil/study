a <- data.frame(A = c(1:3), B = c(4:6), C = c(7:9), D = c(10:12), E = c(13:15))
a

b <- a$E
b

c <- a[, c(2,3,4)]
c

d <- a[3,]
d

e <- a[c(2,3),]
e

str(a)

length(a)

a <-cbind(a, F = c(16:18))
a <-cbind(a, G = c(19:21))

a <-cbind(a, H = c(22:24))
a

a <- rbind(a, c(25:32))
a <- rbind(a, c(33:40))
a
a <- a[-5,]
a

a <- a[-2, ]
a

x <- data.frame(a = c(1:3), b = c(4:6))
Y <- data.frame(a = c(7:9), b = c(10:12))
A <- cbind(x, Y)
A

B <- rbind(x, Y)
B
