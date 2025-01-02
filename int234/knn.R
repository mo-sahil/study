library(class)

df = as.data.frame(iris)

df[-5] = scale(df[-5])

set.seed(123)
split = sample(1:nrow(df), 0.7*nrow(df))

train = df[split,]
test = df[-split,]

model = knn(train = train[,-5], test = test[,-5], cl = train[,5], k = 3)

cm <- table(test[,5], model)
cm

accuracy = sum(diag(cm))/sum(cm)*100
accuracy

