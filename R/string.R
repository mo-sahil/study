#substr(x, start = n1, stop = n2) returns a substring of x starting from index n1 and ending on index n2
x <- "123456789"
substr(x, start = 3, stop = 6)

#grep(pattern, x, ignore.case = FALSE, fixed = FALSE) searches for patterns in x
str <- c("Sahil", "Aban", "Ayush")
grep("a", str)
grep("S", str, ignore.case = TRUE)

#sub(pattern, replacement, x, ignore.case = FALSE, static = FALSE) replaces a pattern in x with replacement
sub("sh", "s", str)

#paste(x, y, .... , sep = " ") concatenates strings x, y , .. using sep
p <- paste("Sahil", "Maz", "Aban", sep = " ")

#strsplit(x, split) splits a string or char vector using split
strsplit(p, " ")
