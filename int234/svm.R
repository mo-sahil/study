library(e1071)

df <- as.data.frame(iris)

set.seed(123)
idx = sample(1:nrow(df), nrow(df)*0.75)
train <- df[idx,]
test <- df[-idx,]

model <- svm(Species ~ Petal.Length + Petal.Width , data = train, kernel = "linear", cost = 10)
pred <- predict(model, test)

cm <- table(test$Species, pred)
cm

accuracy <- sum(diag(cm))/sum(cm)*100
accuracy

plot(model, train, Petal.Length ~ Petal.Width)
