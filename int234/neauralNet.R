setwd("C:/users/Sahil/Downloads")

df <- read.csv("Concrete_Data.csv")
View(df)

library(neuralnet)
library(ggplot2)

set.seed(123)
trainIndex <- createDataPartition(df$strength, p = 0.8, list = FALSE)
train_data <- df[trainIndex, ]
test_data <- df[-trainIndex, ]

nn_model <- neuralnet(strength ~ cement + slag + ash + water + superplasticizer + coarseagg + fineagg + age, data = train_data, hidden = 5)
nn_predictions <- predict(nn_model, test_data)
nn_predictions <- ifelse(nn_predictions > 0.5, 1, 0)

conf_matrix <- table(nn_predictions, test_data$strength)
conf_matrix

accuracy <- sum(diag(conf_matrix)) / sum(conf_matrix) * 100
accuracy
d2 <- file.choose()
