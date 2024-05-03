library(tm)
library(SnowballC)
library(wordcloud)
library(RColorBrewer)
text <- read.csv(file.choose())

corp <- iconv(text$sentence)

corp <- Corpus(VectorSource(corp))
inspect(corp[1:4])

corp <- tm_map(corp, removeNumbers)
corp <- tm_map(corp, removeWords, stopwords("english"))
corp <- tm_map(corp, content_transformer(tolower))
