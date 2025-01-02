library(class)
library(shiny)
library(caret)
library(e1071)
library(rpart)
library(rpart.plot)
library(randomForest)
library(cluster)

# data
setwd("C:/Users/sahil/OneDrive/Desktop/Predictive_Project")
data <- read.csv("loan_approval_dataset.csv")

# preprocessing
data <- data[, -1]
data$loan_status <- as.factor(trimws(data$loan_status))
data$loan_status <- as.factor(data$loan_status)
data$education <- as.numeric(as.factor(data$education))
data$self_employed <- as.numeric(as.factor(data$self_employed))

# splitting
set.seed(123)
train_index <- sample(1:nrow(data), 0.75 * nrow(data))
train_data <- data[train_index, ]
test_data <- data[-train_index, ]

# Shiny UI
ui <- fluidPage(
  titlePanel("Loan Approval Predictive Models Comparision"),
  sidebarLayout(
    sidebarPanel(
      h4("Select Model"),
      radioButtons("model", "Choose a Model:", 
                   choices = c("KNN", "Naive Bayes", "SVM", "Random Forest", "K-means"), 
                   selected = "KNN"),
      hr(),
      h4("Model Accuracies"),
      tableOutput("accuracy_table")
    ),
    mainPanel(
      tabsetPanel(
        tabPanel("Confusion Matrix", plotOutput("conf_matrix_plot")),
        tabPanel("Visualization", plotOutput("cluster_plot")),
        tabPanel("Comparison of Models", plotOutput("accuracy_plot"))
      )
    )
  )
)

# Shiny Server
server <- function(input, output) {
  
  model_results <- reactive({
    if (input$model == "KNN") {
      knn_model <- knn(train = train_data[, -12], test = test_data[, -12], cl = train_data$loan_status, k = 13)
      conf_matrix <- table(Predicted = knn_model, Actual = test_data$loan_status)
      accuracy <- sum(knn_model == test_data$loan_status) / nrow(test_data) * 100
      list(conf_matrix = conf_matrix, accuracy = accuracy)
      
    } else if (input$model == "Naive Bayes") {
      naive_bayes_model <- naiveBayes(train_data[, -12], train_data$loan_status)
      naive_bayes_pred <- predict(naive_bayes_model, test_data[, -12])
      conf_matrix <- table(Predicted = naive_bayes_pred, Actual = test_data$loan_status)
      accuracy <- sum(naive_bayes_pred == test_data$loan_status) / nrow(test_data) * 100
      list(conf_matrix = conf_matrix, accuracy = accuracy)
      
    } else if (input$model == "SVM") {
      svm_model <- svm(loan_status ~ ., data = train_data, kernel = "linear")
      svm_pred <- predict(svm_model, test_data)
      conf_matrix <- table(Predicted = svm_pred, Actual = test_data$loan_status)
      accuracy <- sum(svm_pred == test_data$loan_status) / nrow(test_data) * 100
      list(conf_matrix = conf_matrix, accuracy = accuracy)
      
    } else if (input$model == "Random Forest") {
      random_forest_model <- randomForest(loan_status ~ ., data = train_data, ntree = 100)
      random_forest_pred <- predict(random_forest_model, test_data)
      conf_matrix <- table(Predicted = random_forest_pred, Actual = test_data$loan_status)
      accuracy <- sum(random_forest_pred == test_data$loan_status) / nrow(test_data) * 100
      list(conf_matrix = conf_matrix, accuracy = accuracy)
      
    } else if (input$model == "K-means") {
      kmeans_model <- kmeans(data[, -12], centers = 2, nstart = 5)
      kmeans_model$cluster[kmeans_model$cluster == 1] <- "Approved"
      kmeans_model$cluster[kmeans_model$cluster == 2] <- "Rejected"
      conf_matrix <- table(data$loan_status, kmeans_model$cluster)
      accuracy <- sum(diag(conf_matrix)) / sum(conf_matrix) * 100
      list(conf_matrix = conf_matrix, accuracy = accuracy)
    }
  })
  
  #confusion matrix plot
  output$conf_matrix_plot <- renderPlot({
    res <- model_results()
    
    if(input$model == "K-means") {
      plot(res$conf_matrix, main = paste(input$model, "Confusion Matrix"), col = "skyblue")
    } else {
      conf_matrix <- as.data.frame(as.table(res$conf_matrix))
      ggplot(conf_matrix, aes(x = Predicted, y = Actual, fill = Freq)) +
        geom_tile(color = "white") +
        geom_text(aes(label = Freq), color = "black", size = 5) +
        scale_fill_gradient(low = "skyblue", high = "darkblue") +
        labs(title = paste(input$model, "Confusion Matrix Heatmap"),
             x = "Predicted",
             y = "Actual") +
        theme_minimal()
    }
  })
  
  
  # Accuracy Table
  output$accuracy_table <- renderTable({
    models <- c("KNN", "Naive Bayes", "SVM", "Random Forest", "K-means")
    accuracies <- sapply(models, function(mod) {
      if (mod == "KNN") {
        sum(knn(train = train_data[, -12], test = test_data[, -12], cl = train_data$loan_status, k = 13) == test_data$loan_status) / nrow(test_data) * 100
      } else if (mod == "Naive Bayes") {
        nb_pred <- predict(naiveBayes(train_data[, -12], train_data$loan_status), test_data[, -12])
        sum(nb_pred == test_data$loan_status) / nrow(test_data) * 100
      } else if (mod == "SVM") {
        svm_pred <- predict(svm(loan_status ~ ., data = train_data, kernel = "linear"), test_data)
        sum(svm_pred == test_data$loan_status) / nrow(test_data) * 100
      } else if (mod == "Random Forest") {
        rf_pred <- predict(randomForest(loan_status ~ ., data = train_data, ntree = 100), test_data)
        sum(rf_pred == test_data$loan_status) / nrow(test_data) * 100
      } else if (mod == "K-means") {
        km <- kmeans(data[, -12], centers = 2, nstart = 11)
        sum(diag(table(data$loan_status, km$cluster))) / sum(table(data$loan_status, km$cluster)) * 100
      }
    })
    data.frame(Model = models, Accuracy = round(accuracies, 2))
  })
  
  # Comparison of Models
  output$accuracy_plot <- renderPlot({
    models <- c("KNN", "Naive Bayes", "SVM", "Random Forest", "K-means")
    accuracies <- sapply(models, function(mod) {
      if (mod == "KNN") {
        sum(knn(train = train_data[, -12], test = test_data[, -12], cl = train_data$loan_status, k = 13) == test_data$loan_status) / nrow(test_data) * 100
      } else if (mod == "Naive Bayes") {
        nb_pred <- predict(naiveBayes(train_data[, -12], train_data$loan_status), test_data[, -12])
        sum(nb_pred == test_data$loan_status) / nrow(test_data) * 100
      } else if (mod == "SVM") {
        svm_pred <- predict(svm(loan_status ~ ., data = train_data, kernel = "linear"), test_data)
        sum(svm_pred == test_data$loan_status) / nrow(test_data) * 100
      } else if (mod == "Random Forest") {
        rf_pred <- predict(randomForest(loan_status ~ ., data = train_data, ntree = 100), test_data)
        sum(rf_pred == test_data$loan_status) / nrow(test_data) * 100
      } else if (mod == "K-means") {
        km <- kmeans(data[, -12], centers = 2, nstart = 5)
        sum(diag(table(data$loan_status, km$cluster))) / sum(table(data$loan_status, km$cluster)) * 100
      }
    })
    barplot(accuracies, names.arg = models, col = "blue", main = "Comparison of Model Accuracies", ylab = "Accuracy (%)", ylim = c(0, 100))
  })
  
  # Visualization
  output$cluster_plot <- renderPlot({
    if (input$model == "K-means") {
      # K-means Clustering
      kmeans_model <- kmeans(data[, -12], centers = 2, nstart = 11)
      plot(data[, c("income_annum", "loan_amount")], col = kmeans_model$cluster,
           main = "K-means Clustering of Loan Approval Data with 2 Clusters",
           xlab = "Income (Annual)", ylab = "Loan Amount")
    } else if (input$model == "KNN") {
      # KNN Visualization (Scatter Plot of Predicted vs. Actual)
      knn_pred <- knn(train = train_data[, -12], test = test_data[, -12], cl = train_data$loan_status, k = 13)
      plot(test_data$income_annum, test_data$loan_amount, col = as.numeric(knn_pred),
           main = "KNN Predictions (Scatter Plot)", xlab = "Income (Annual)", ylab = "Loan Amount", pch = 19)
      legend("topright", legend = levels(train_data$loan_status), col = 1:2, pch = 19, title = "Predicted Loan Status")
    } else if (input$model == "Naive Bayes") {
      # Naive Bayes Visualization (Scatter Plot of Predicted vs. Actual)
      naive_bayes_model <- naiveBayes(train_data[, -12], train_data$loan_status)
      naive_bayes_pred <- predict(naive_bayes_model, test_data[, -12])
      plot(test_data$income_annum, test_data$loan_amount, col = as.numeric(naive_bayes_pred),
           main = "Naive Bayes Predictions (Scatter Plot)", xlab = "Income (Annual)", ylab = "Loan Amount", pch = 19)
      legend("topright", legend = levels(train_data$loan_status), col = 1:2, pch = 19, title = "Predicted Loan Status")
    } else if (input$model == "SVM") {
      svm_model <- svm(loan_status ~ income_annum + loan_amount, data = train_data, kernel = "linear")
      svm_pred <- predict(svm_model, test_data[, c("income_annum", "loan_amount")])
      
      # SVM Visualization
      plot(test_data$income_annum, test_data$loan_amount, col = as.numeric(test_data$loan_status),
           pch = ifelse(as.numeric(test_data$loan_status) == as.numeric(svm_pred), 19, 1),
           xlab = "Income (Annual)", ylab = "Loan Amount", main = "SVM Classification with Support Vectors")
      points(svm_model$SV[, "income_annum"], svm_model$SV[, "loan_amount"],
             col = "red", pch = 4, cex = 1)
      legend("topright", legend = c("Correctly Classified", "Misclassified", "Support Vectors"),
             col = c(1, 1, "red"), pch = c(19, 1, 4), title = "Legend")
    } else if (input$model == "Random Forest") {
      # Random Forest Feature Importance Visualization
      random_forest_model <- randomForest(loan_status ~ ., data = train_data, ntree = 100)
      var_imp <- importance(random_forest_model)
      barplot(var_imp[, 1], names.arg = rownames(var_imp), col = "lightblue", las = 2,
              main = "Random Forest Feature Importance", ylab = "Mean Decrease in Accuracy")
    }
  })
}

# Run
shinyApp(ui = ui, server = server)
