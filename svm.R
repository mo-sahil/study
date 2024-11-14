library(e1071)
library(caret)

data(iris)

set.seed(123)
trainIndex <- createDataPartition(iris$Species, p = .8, 
                                  list = FALSE, 
                                  times = 1)
train <- iris[ trainIndex,]
test  <- iris[-trainIndex,]

model <- svm(Species ~ ., data = train)
summary(model)

predictions <- predict(model, test)
confusionMatrix(predictions, test$Species)

