library(sqldf)
stu <- read.csv("C://Users//sahil//Downloads//students.csv")
stu
View(sqldf("select * from stu where roll_no = 2"))
