df <- data.frame(value = c(10,20,32,35), group = paste0("G", 1:4))
df

library(ggplot2)
library(dplyr)

hsize <- 4

df <- df %>% mutate(x = hsize)
df

ggplot(df, aes(x = hsize, y = value, fill = group)) +
  geom_col() + coord_polar(theta = "y") + xlim(c(0.2, hsize+0.8))
