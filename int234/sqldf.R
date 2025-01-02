library(sqldf)

df <- iris
sqldf("select * from df")
sqldf(c("update df set Species = 'Setosa' where Species = 'setosa'", "select * from df"))

