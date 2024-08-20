v <- 1:5
v

a <- c(1L, 2.3, 3+4i, 'Sahil', TRUE)
a
class(a) #character

b <- c(1L, 2.3, 3+4i, TRUE)
b
class(b) #complex

c <- c(1L, 2.3, TRUE)
c
class(c) #numeric

d <- c(1L, TRUE)
d
class(d) #integer

e <- c(TRUE, FALSE)
e
class(e) #logical

#take 2 vectors having 5 elements each and perform addition, subtraction, multiplication, division, modulus and integer division on this data
v1 <- c(5, 2, 3, 7, 9)
v2 <- c(8, 1, 6, 11, 10)

add <- v1 + v2
add

sub <- v1 - v2
sub

mul <- v1 * v2
mul

div <- v1 / v2
div

mod <- v1 %% v2
mod

intdiv <- v1 %/% v2
intdiv
print(list(add, sub, mul, div, mod, intdiv))
      
#consider three vectors one will store patients name, second will store their temperature and third will store their infectivity.
#print temperature of last two
#exclude temp of 2nd patient
#print the name of the patient who is infected
#print name of patients with certain range

patients <- c('Sahil', 'Maz', 'Ayush')
temp <- c(98.6, 99.2, 100.5)
value <- c(TRUE, FALSE, TRUE)

temp[2:3]
temp[-2]
patients[value]
patients[temp > 99]

#logical operators
x <- c(TRUE, FALSE, TRUE, FALSE)
y <- c(TRUE, TRUE, FALSE, FALSE)

x & y
x | y
!x
!y

#conditionals
marks <- 84
if(marks > 90){
  print('Grade A')
}else if(marks > 80){
  print('Grade B')
}else if(marks > 70){
  print('Grade C')
}else{
  print('Grade D')
}

#find if a number is even or odd
num <- as.numeric(readline(prompt = 'Enter a number: '))
if(num %% 2 == 0){
  print('Even')
}else{
  print('Odd')
}

#finds roots of a quadratic equation
a <- 1
b <- 2
c <- 3

d <- b^2 - 4*a*c

if(d>0) {
  root1 <- (-b + sqrt(d))/(2*a)
  root2 <- (-b - sqrt(d))/(2*a)
  print(paste('Roots are:', root1, 'and', root2))
} else if(d==0) {
  root1 <- -b/(2*a)
  print(paste('Roots are:', root1))
} else {
  realPart <- -b/(2*a)
  imaginaryPart <- sqrt(-d)/(2*a)
  print(paste('Roots are:', realPart, '+', imaginaryPart, 'i and', realPart, '-', imaginaryPart, 'i'))
}