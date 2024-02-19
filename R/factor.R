a <- c("true","false", "false", "true")
a

b <- factor(a)
b

c <- c("north", "east", "south", "swet", "west")
c

d <- factor(c)
d

d[c(FALSE, TRUE, FALSE, TRUE, TRUE)]

e <- factor(c("male", "female", "female", "female","mail"), levels = c("male", "female"))
e
e[3]
e[c(2,4)]
e[-3]

levels(e)
e

f <- gl(3, 4, labels = c("Sahil", "Aban", "Maz"))
f

f <- factor(f, levels= c(levels(f), "Ayush"))
levels(f)

f <- factor(f, levels = c("Maz", "Aban", "Sahil", "Ayush"))
f

f[4] = "Ayush"
f

f[c(8,12)] = c("Ayush", "Ayush")
f
