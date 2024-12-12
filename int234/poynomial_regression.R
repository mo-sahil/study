df <- mtcars

str(df)

set.seed(123)

split = sample(1:nrow(df), nrow(df)*0.75)
train <- df[split,]
test <- df[-split,]

model <- lm(mpg ~ poly(hp, degree = 2), data = train)
summary(model)

pred <- predict(model, test)

plot(train$hp, train$mpg,
     xlab = "Horsepower (hp)",
     ylab = "Miles per Gallon (mpg)",
     main = "Polynomial Regression: MPG vs HP",
     col = "blue", pch = 16)
curve(predict(model, data.frame(hp = x)), add = TRUE, col = "red")

legend("topright", legend = c("Data points", "Fitted curve"), 
       col = c("blue", "red"), pch = c(16, NA), lty = c(NA, 1))
