x <- 1:5
y <- c(200,400,600,700,500)


plot(x,y, type = "o", col = "red", lwd = 3, lty = 2, pch = LETTERS[10:14])
plot(x,y, type = "l", col = "blue", lwd = 5, lty = 3)
plot(x,y, type = "s", col = "green", lwd = 10, lty = 5, xlim = c(0,6), ylim = c(100, 800))
plot(x,y, type = "b", col = "purple", lwd = 7, lty = 6)
