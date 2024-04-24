temp <- c(10:18)
res <- barplot(
        temp, 
        main = "Result", 
        xlab = "x", 
        ylab = "y", 
        names.arg = 1:9, 
        col = "blue", 
        density = 95, 
        border =  "red", 
        cex.names = 1.5, 
        cex.axis = 1.5, 
        horiz = FALSE
  )

mat <- matrix(c(100, 203, 102, 303, 323, 214), nrow = 2, ncol = 3)
mat
matres <- barplot(
  mat,
  main = "title",
  xlab = "class",
  names.arg = 1:3,
  col = c("red", "green"),
  border = "blue",
  cex.names = 1.5,
  cex.axis = 1.5
)

legend("topleft", c("c1", "c2"), fill = c("red", "green"))
