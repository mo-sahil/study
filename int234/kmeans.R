library(arules)
library(cluster)

iris_data <- iris[,1:4]

set.seed(123)
kmeans_model <- kmeans(iris_data, centers = 3, nstart = 2)
kmeans_model

kmeans_model$cluster
kmeans_model$centers

confusion_matrix <- table(iris$Species, kmeans_model$cluster)

confusion_matrix

accuracy <- sum(diag(confusion_matrix))/sum(confusion_matrix)*100
accuracy

plot(iris_data[, c("Sepal.Length", "Sepal.Width")], col = kmeans_model$cluster, main = "K-means Clustering of Iris Data with 3 clusters")
points(kmeans_model$centers, col = 1:3, pch = 8, cex = 2)
