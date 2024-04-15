

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


