wbcd <- read.csv("C:/users/Sahil/Downloads/wisc_bc_data.csv", header = TRUE)

wbcd

str(wbcd)

wbcd <- wbcd[-1]

wbcd$diagnosis<- factor(wbcd$diagnosis, levels = c("B", "M"), labels = c("Benign", "Malignant"))

round(prop.table(table(wbcd$diagnosis)) * 100, digits = 1)

summary(wbcd[c("radius_mean", "area_mean", "smoothness_mean")])

normalize <- function(x) {
  return ((x - min(x)) / (max(x) - min(x)))
}

wbcd_n <- as.data.frame(lapply(wbcd[2:31], normalize))
summary(wbcd_n[c("radius_mean", "area_mean", "smoothness_mean")])

library(class)

wbcd_train <- wbcd_n[1:469, ]
wbcd_test <- wbcd_n[470:569, ]

wbcd_train_labels <- wbcd[1:469,1]
wbcd_test_labels <- wbcd[470:569,1]

model <- knn(train = wbcd_train, test = wbcd_test, cl = wbcd_train_labels, k = 21, use.all = TRUE)

library(caret)

confusionMatrix(data = model, reference = wbcd_test_labels)

table(wbcd_test_labels, model)