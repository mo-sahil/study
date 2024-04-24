install.packages("plotrix")
library(plotrix)
x <- c(600, 300, 150, 100, 200)

pie3D(x, main = "3D", labels = letters[1:5], col = c("red", "green", "blue", "purple", "pink"))
legend("topright")
