a <- data.frame(names = c("Sahil", "Maz", "Ayush"), age = c(18:20))
a

b <- subset(a, age < 20, c(names, age))
b
