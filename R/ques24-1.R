#create vector of 30 el using c(), seq() and :
a = rep(c(1, 2, 3), c(10, 10, 10))
b = seq(from = 3, to = 90, by = 3)
c = c(1:30)
a
b
c

#sort these vectors in ascending and descending order
sort(a)
sort(b)
sort(c)
sort(a, decreasing = TRUE)
sort(b, decreasing = TRUE)
sort(c, decreasing = TRUE)

#print max and min
max(a)
max(b)
max(c)
min(a)
min(b)
min(c)

#print 6th and 10th elements
a[c(6, 10)]
b[c(6, 10)]
c[c(6, 10)]

#print all values except 19th
a[-19]
b[-19]
c[-19]

#merge two vectors
c(a,b)

#perform all the arithmetic operators
a+b
a-b
a*b
a/b
a%%b
a%/%b
a^b
