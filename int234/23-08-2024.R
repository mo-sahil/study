#find location of current working directory
#define any 3 variables
#save those variables in  file named abc into some other directory
#list down all the variables and remove the first 3 variables
#open a csv file and store one data frame consisting of record of three students

getwd()
var1 <- "Sahil"
var2 <- 19L
var3 <- 3+4i
setwd("C:/study/int234")
save(var1, var2, var3, file = "abc.RData")
ls()
rm(var1, var2, var3)

df <- data.frame(
  name = c("Sahil", "Maz", "Pushp"),
  age = c(19, 20, 20)
)

write.csv(df, file = "data1.csv")   
read.csv("data1.csv")

summary(df)
summary(df$age)
range(df$age)
diff(range(df$age))

round(prop.table(table(df$age))*100, digits = 1)
