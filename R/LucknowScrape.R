library(rvest)
webPage = read_html("https://en.m.wikipedia.org/wiki/Lucknow")
data = webPage %>% html_nodes('p') %>% html_text()
writeLines(data, 'Lucknow.txt')

