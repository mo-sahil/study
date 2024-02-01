plot(1,2)

plot(c(1:5), c(2:6))

plot(1:10)

plot(1:10, type = 'l')

plot(1:10, main = "Graph", xlab = "X-axis", ylab = "Y-axis")

plot(1:10, main = "Graph", xlab = "X-axis", ylab = "Y-axis", type = 'l')

plot(1:10, main = "Graph", xlab = "X-axis", ylab = "Y-axis", type = 'l', col="red")

plot(1:10, main = "Graph", xlab = "X-axis", ylab = "Y-axis", type = 'l', col="red", lwd = 3)

plot(1:10, main = "Graph", xlab = "X-axis", ylab = "Y-axis", type = 'l', col="red", lwd = 3, lty = 6)

line1 <- c(1,2,3,4,5,10)
line2 <- c(1,5,7,8,9,10)

plot(line1, type = "l", col = "blue", lty = 6, lwd  = 4)
lines(line2, type="l", col = "red", lty = 2, lwd = 4) 

x <- c(5,7,8,7,2,2,9,4,11,12,9,6)
y <- c(99,86,87,88,111,103,87,94,78,77,85,86)

plot(x, y)

pie(x, init.angle = 90)

