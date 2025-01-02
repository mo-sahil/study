library(randomForest)

df = iris

set.seed(123)
trainIndex = sample(1:nrow(df), 0.8*nrow(df))
train = df[trainIndex,]
test = df[-trainIndex,]

rf = randomForest(Species ~ ., data=train, ntree=100, mtry=2)
pred = predict(rf, test)

cm <- table(test$Species, pred, dnn=c("Predicted", "Actual"))
cm

accuracy = sum(diag(cm))/sum(cm)*100
accuracy

imp <- importance(rf)
varImpPlot(rf)
