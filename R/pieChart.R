x = c(4, 3, 5, 2)
pie(x)

label <- c("Apple", "Mango", "Orange", "Grapes")

colors <- c("Red", "Yellow", "Orange", "Green")

pie(x, main = "Fruits", labels = labels, col = colors)
legend("bottomright", label, fill = colors)
