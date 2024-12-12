library(nnet)
library(NeuralNetTools)

df <- iris

set.seed(123)
trainIndex <- sample(1:nrow(df), 0.7 * nrow(df))
train <- df[trainIndex,]
test <- df[-trainIndex,]

model <- nnet(Species ~ ., data = train, size = 2, maxit = 1000, trace = FALSE)
pred <- predict(model, test, type = "class")

cm <- table(test$Species, pred)
cm

accuracy <- sum(diag(cm)) / sum(cm)*100
accuracy

plotnet(model)
