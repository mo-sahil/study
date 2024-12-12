df <- mtcars

set.seed(123)

split <- sample(1:nrow(df), 0.75*nrow(df))
train <- df[split,]
test <- df[-split,]

model <- lm(mpg ~ hp + wt, data = train)

pred <- predict(model, test)

plot(test$mpg, pred, xlab = "Actual", ylab = "Predicted", main = "Actual vs Predicted", col = "blue", pch = 19)
abline(0, 1, col="red")

mse <- mean((test$mpg - pred)^2)
print(mse)
