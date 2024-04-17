library(tidyr)

df <- read.csv("C://Users/sahil/Downloads/bill data for tidyr 2.csv")
df

pivot <- gather(df, Bill_type, Bill_Amt, waterbill:gasbill)
pivot

sprd <- spread(pivot, Bill_type, Bill_Amt)
View(sprd)

sprt <- separate(df, Date, c("Day", "Month", "Year"), sep = "-")
View(sprt)

unt <- unite(sprt, Date, c("Day", "Month", "Year"), sep='/')
unt

replace_na(data.frame(c(1, 2, NA), y = c("a", NA, "b")), list(x = 0, y = "Unknown"))
