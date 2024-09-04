wbcd <- read.csv("C:/users/Sahil/Downloads/wisc_bc_data.csv", header = TRUE)

wbcd <- wbcd[-1]

table(wbcd$diagnosis)

wbcd$diagnosis[wbcd$diagnosis == "B"] <- "Benign"
wbcd$diagnosis[wbcd$diagnosis == "M"] <- "Malignant"

summary(wbcd$radius_mean)
summary(wbcd$radius_mean) 
summary(wbcd$smoothness_mean)

normalize <- function(x) {
  return ((x - min(x)) / (max(x) - min(x)))
}

wbcd_n <- as.data.frame(lapply(wbcd[2:31], normalize))

wbcd_train <- wbcd[1:469,]
wbcd_test <- wbcd[470:569,]

model <- knn(train = wbcd_train[,-1], test = wbcd_test[,-1], cl = wbcd$diagnosis[1:469], k = 15, use.all = TRUE)
table(wbcd_test, model)