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


n = 10 
tidy_dataframe = data.frame( 
  S.No = c(1:n),  
  Group.1 = c(23, 345, 76, 212, 88,  
              199, 72, 35, 90, 265), 
  Group.2 = c(117, 89, 66, 334, 90,  
              101, 178, 233, 45, 200), 
  Group.3 = c(29, 101, 239, 289, 176, 
              320, 89, 109, 199, 56)) 

tidy_dataframe 

long <- tidy_dataframe %>% gather(Group, Frequency, Group.1:Group.3)
long

seperate <- long %>% separate(Group, c("Allotment", "Number"))
seperate

unite <- seperate %>% unite(Group, Allotment, Number, sep = "_")
unite

spread <- unite %>% spread(Group, Frequency)
spread
