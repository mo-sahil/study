#Question 1

library(sqldf)

students <- data.frame(
  name = c("Sahil", "Ayush", "Maz", "Pushp", "Pawan", "Avik", "Abhijeet", "Aditya", "Rahul", "Jack"),
  id = 5:14,
  branch = c("CSE", "ECE", "CSE", "ME", "CSE", "ECE", "ME", "CSE", "ECE", "ME"),
  marks = c(94, 80, 91, 60, 50, 40, 30, 20, 10, 70)
)

sqldf("SELECT * FROM students")
#a
sqldf("select name from students where marks > 90 and branch = 'CSE'")

#b
sqldf(c("update students set name = 'Aarav Sharma' where id = 12", "Select * from students"))
#c
sqldf(c("select avg(marks) from students"))

#d
sqldf(c("delete from students where name = 'Rahul'", "Select * from students"))

#question 2
library(ggplot2)
df <- as.data.frame(diamonds)
library(class)

#normalize data
normalize <- function(x) {
  return ((x - min(x)) / (max(x) - min(x)))
}

df$carat <- normalize(df$carat)
df$depth <- normalize(df$depth)
df$table <- normalize(df$table)
df$x <- normalize(df$x)
df$y <- normalize(df$y)
df$z <- normalize(df$z)

train <- sample(1:nrow(df), 0.7*nrow(df))
test <- -train
train_data <- df[train, ]
test_data <- df[test, ]
knn_pred <- knn(train = train_data[, c("carat", "depth", "table", "x", "y", "z")], test = test_data[, c("carat", "depth", "table", "x", "y", "z")], cl = train_data$cut, k = 20)

library(caret)
confusion_matrix <- table(knn_pred, test_data$cut)
confusion_matrix

accuracy <- sum(diag(confusion_matrix)) / sum(confusion_matrix)*100
accuracy

#question 3
cl<-read.csv("emp_data.csv")
cl
cl$Gender[cl$Gender=='M']<-"Male"
cl$Gender[cl$Gender=='F']<-"Female"
cl$Gender[cl$Gender=='']<-"Not Mentioned"
cl
cl$Salary=as.numeric(cl$Salary)
means<-mean(cl$Salary, na.rm = TRUE)
cl$Salary[is.na(cl$Salary)]<-mean(cl$Salary, na.rm = TRUE)
cl
cl$Age<-as.numeric(cl$Age)
cl$Age
cl$Age[is.na(cl$Age)]<-mean(cl$Age, na.rm = TRUE)
cl
cl$Survey_Score=as.numeric(cl$Survey_Score)
cl$Survey_Score[is.na(cl$Survey_Score)]<-mean(cl$Survey_Score, na.rm = TRUE)

normalize<- function(x)
{
  return (x-min(x)/(max(x)-min(x)))
}
normal<-as.data.frame(lapply(cl[,c(-2,-4)],normalize))
normal
cl<-cbind(cl[,c(2,4)],normal)
cl

