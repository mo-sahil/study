library(dplyr)

df <- data.frame(
  name = c("Sahil", "Maz", "Anas"),
  Age = c(19,20,18)
)

df

rs <- df %>% filter(Age > 18)
rs

df.name <- arrange(df, name)
df

select(df, 1)
select(df, -starts_with("A"))

df <- iris
View(df)

str(iris)

df %>% select(Sepal.Length, Petal.Length, Species) %>% filter(Species == "setosa" & Petal.Length > 1.4 & Sepal.Length > 3.5)

df %>% filter(Species == "setosa" & Petal.Length > 1.4 & Sepal.Length > 3.5) %>% mutate(SL = Sepal.Width) %>% select(Sepal.Length, Petal.Length, Species, SL)
