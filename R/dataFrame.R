data <- data.frame(
  names <- c("Sahil", "Maz", "Anas"),
  age <- c(19, 19, 20),
  dob <- c(2005, 2005, 2004)
)
data

summary(data)

data[1]
data$dob

data <- rbind(data, c("Arpit", 21, 2003))
data

data <- cbind(data, weight = c(82, 78, 67, 75))
data

dim(data)
length(data)
