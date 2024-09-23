sms <- read.csv("sms_spam.csv", stringsAsFactors = FALSE)
str(sms)
sms$type <- factor(sms$type)
table(sms$type)

library(tm)
sms_corpus <- VCorpus(VectorSource(sms$text))
print(sms_corpus)
as.character(sms_corpus[[1]])
lapply(sms_corpus[1:3], as.character)

sms_corpus_clean <- tm_map(sms_corpus, content_transformer(tolower))
sms_corpus_clean <- tm_map(sms_corpus_clean, removeNumbers)
sms_corpus_clean <- tm_map(sms_corpus_clean, removePunctuation)
sms_corpus_clean <- tm_map(sms_corpus_clean, removeWords, stopwords())
as.character(sms_corpus_clean[[1]])

library(SnowballC)
sms_corpus_clean <- tm_map(sms_corpus_clean, stemDocument)
sms_corpus_clean <- tm_map(sms_corpus_clean, stripWhitespace)

sms_dtm <- DocumentTermMatrix(sms_corpus_clean)
sms_dtm

sms_dtm_train <- sms_dtm[1:4000, ]
sms_dtm_test <- sms_dtm[4001:5559, ]

sms_train_labels <- sms[1:4000, ]$type
sms_test_labels <- sms[4001:5559, ]$type

prop.table(table(sms_train_labels))*100
prop.table(table(sms_test_labels))*100

library(wordcloud)
wordcloud(sms_corpus_clean, min.freq = 40, random.order = FALSE)

sms_freq_words <- findFreqTerms(sms_dtm_train, 5)
str(sms_freq_words)

sms_dtm_freq_train <- sms_dtm_train[, sms_freq_words]
sms_dtm_freq_test <- sms_dtm_test[, sms_freq_words]

convert_counts <- function(x) {
  x <- ifelse(x > 0, "Yes", "No")
}

sms_train <- apply(sms_dtm_freq_train, MARGIN = 2, convert_counts)
sms_test <- apply(sms_dtm_freq_test, MARGIN = 2, convert_counts)

library(e1071)
sms_classifier <- naiveBayes(sms_train, sms_train_labels)
sms_test_pred <- predict(sms_classifier, sms_test)

library(gmodels)
CrossTable(sms_test_pred, sms_test_labels, prop.t = FALSE, dnn = c('predicted', 'actual'))

table(sms_test_pred, sms_test_labels)
#make it more presentable
table(sms_test_pred, sms_test_labels)