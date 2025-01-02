library(class)
library(gmodels)
data <- iris

str(data)

normalize <- function(x) {
  return ((x - (min(x)))/(max(x) - min(x)))
}
df <- as.data.frame(lapply(data[,-5], normalize))
head(df)

set.seed(123)
train <- sample(1:nrow(df), 0.7*nrow(df))
train_data <- df[train,]
test_data <- df[-train,]

train_labels <- data$Species[train]
test_labels <- data$Species[-train]

model <- knn(train = train_data, test = test_data, cl = train_labels, k=3)
cm <- table(model, test_labels)
cm

accuracy <- sum(diag(cm))/sum(cm)*100
accuracy

