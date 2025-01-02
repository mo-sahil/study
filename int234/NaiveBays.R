library(e1071)

df <- as.data.frame(iris)

df[-5] = scale(df[-5])

split = sample(1:nrow(df), 0.7*nrow(df))

training = df[split,]
testing = df[-split,]

model = naiveBayes(x = training[-5], y = training$Species)
model_pred = predict(model, testing[-5])

cm <- table(testing$Species, model_pred)
cm

accuracy = sum(diag(cm))/sum(cm)*100
accuracy
