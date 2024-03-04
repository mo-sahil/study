library(httr)
library(rvest)
library(xml2)
url <- "http://chess.com"
response <- GET(url)
html_content <- content(response, "text")
html_content
parsed_html <- read_html(html_content)
parsed_html
write_html(parsed_html,"chess.html")
getwd()
