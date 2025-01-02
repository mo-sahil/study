setwd("C:/users/Sahil/Downloads")
df <- read.csv("wisc_bc_data.csv")

kmeans_2 <- kmeans(df[, -c(1,2)], centers = 2, nstart = 10)

confusion_matrix <- table(kmeans_2$cluster, df$diagnosis)
confusion_matrix

accuracy <- sum(diag(confusion_matrix))/sum(confusion_matrix)*100
accuracy

plot(df$radius_mean, df$texture_mean, col = kmeans_2$cluster, main = "K-means with 2 clusters", xlab = "radius_mean", ylab = "texture_mean")
points(kmeans_2$centers, col = 1:2, pch = 8, cex = 5)
