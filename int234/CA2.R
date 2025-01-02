# Q1 
data(mtcars)
model1 <- lm(mpg ~ poly(hp, 2), data = mtcars)

hp_vals <- seq(min(mtcars$hp), max(mtcars$hp), length.out = 50)

predicted_mpg <- predict(model1, newdata = data.frame(hp = hp_vals))

plot(mtcars$hp, mtcars$mpg, pch = 16, col = "blue", 
     xlab = "Horsepower (hp)", ylab = "Miles Per Gallon (mpg)", 
     main = "Polynomial Regression: MPG vs HP")

lines(hp_vals, predicted_mpg, col = "red", lwd = 2)

legend("topright", legend = c("Actual Data", "Regression Curve"), 
       col = c("blue", "red"), pch = c(16, NA), lty = c(NA, 1), lwd = 3)


# Q2
library(ggplot2)
data(diamonds)
View(diamonds)
library(e1071)
model2 <- naiveBayes(cut ~ carat + color + clarity + depth + price + table, data = diamonds)

predicted <- predict(model2, diamonds)

summary(model2)

confusion_matrix <- table(predicted, diamonds$cut)
confusion_matrix

accuracy <- sum(diag(confusion_matrix)) / sum(confusion_matrix)*100
accuracy

new_data <- data.frame(carat = 0.23, color = "E", clarity = "SI2", depth = 61.5, price = 326, table = 55)
predicted <- predict(model2, new_data)
predicted

#Q3
library(caret)
library(e1071)
library(rpart)

data(UCBAdmissions)
df <- as.data.frame(UCBAdmissions)

df$Admit <- factor(df$Admit, levels = c("Rejected", "Admitted"))
expanded_df <- df[rep(1:nrow(df), df$Freq), -5]

set.seed(123) 
trainIndex <- createDataPartition(expanded_df$Admit, p = 0.8, list = FALSE)
train_data <- expanded_df[trainIndex, ]
test_data <- expanded_df[-trainIndex, ]

nb_model <- naiveBayes(Admit ~ Gender + Dept, data = train_data)
nb_predictions <- predict(nb_model, test_data)
nb_conf_matrix <- confusionMatrix(nb_predictions, test_data$Admit)
nb_conf_matrix

dt_model <- rpart(Admit ~ Gender + Dept, data = train_data, method = "class")
dt_predictions <- predict(dt_model, test_data, type = "class")
dt_conf_matrix <- confusionMatrix(dt_predictions, test_data$Admit)
dt_conf_matrix

cat("Naive Bayes Model Accuracy:", nb_conf_matrix$overall['Accuracy']*100, "\n")
cat("Decision Tree Model Accuracy:", dt_conf_matrix$overall['Accuracy']*100, "\n")

input_gender <- "Male"
input_dept <- "A"

input_data <- data.frame(Gender = factor(input_gender, levels = levels(train_data$Gender)),
                         Dept = factor(input_dept, levels = levels(train_data$Dept)))

nb_input_prediction <- predict(nb_model, input_data)
dt_input_prediction <- predict(dt_model, input_data, type = "class")

cat("Naive Bayes Prediction for input:", levels(train_data$Admit)[nb_input_prediction], "\n")
cat("Decision Tree Prediction for input:", levels(train_data$Admit)[dt_input_prediction], "\n")
