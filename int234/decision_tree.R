library(rpart)
library(rpart.plot)

df <- as.data.frame(iris)
set.seed(123)
split <- sample(1:nrow(df), 0.7 * nrow(df))
train <- df[split, ]
test <- df[-split, ]

model <- rpart(Species ~ ., data = train, method = "class")

rpart.plot(model, fallen.leaves = FALSE)

pred <- predict(model, test, type = "class")

cm <- table(test$Species, pred)
cm

accuracy <- sum(diag(cm)) / sum(cm)
print(paste("Accuracy:", round(accuracy * 100, 2), "%"))
