a <- data.frame(stud_rollno = c(1:3), stud_names = c("Sahil", "Ayush", "Maz"), stud_marks = c(10,9,8))
a

a[c(1,2), ]
a[, c(1,2)]
a[1,2]

str(a)

length(a)

result <- data.frame(a$stud_names, a$stud_rollno)
result

sub <- subset(a , stud_names == "Sahil")
sub

