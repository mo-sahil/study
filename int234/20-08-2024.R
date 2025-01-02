##WAP find factorial of a given number

n = as.numeric(readline("Enter a number : "))
#method 1
fact = 1

for(i in 2:n) {
  fact = fact * i
}

print(fact)

#method 2
factorial <- function(n) {
  if( n == 1) {
    return(1);
  }
  
  return(n*factorial(n-1))
}

print(factorial(n))

#whenever an element of an object is declared then that element becomes the datatype of that variable

##matrix

mat1 <- matrix(1:6, 2, 3, TRUE)
mat1

mat2 <- matrix(4:9, 2, 3)
mat2

mat3 <- mat1 + mat2
mat3

mat4 <- matrix(1:10, 2, 5)
mat4

mat4[2,4]

mat4[2,]

##dataframes

df <- data.frame(
  name = c("Sahil", "Maz"),
  age = c(19, 20),
  semester = c(5, 5)
)

df <- df[-3]
df

cbind(df, branch = c("CSE", "ECE"))

##factors

x <- c("North", "North", "East", "South", "West", "East")

fc <- as.factor(x)
fc

levels(fc)

#create a list having 4 kinds of datatypes string, vector, logical and numeric
#after printing this add an item to this existing list
#enter any random string find out that string is present in the given list or not
#remove the third item from the existing list

l <- list("Sahil", 1:4, TRUE, 23.4)
l

l <- append(l,34)
l

"How" %in% l

l <- l[-3]
l

#create a 2*4 matrix with random numbers and transpose it
#multiply two matrices


m1 <- matrix(10:17, 2, 4)
m1

transpose <- function(m) {
  res <- matrix(0, nrow = ncol(m), ncol = nrow(m))
  for(i in 1:nrow(m)) {
    for (j in 1:ncol(m)) {
      res[j,i] = m[i,j]
    }
  }
  
  return(res)
}

m1 <- transpose(m1)
m1

m2 <- matrix(12:19, 4, 2)
m2


if(nrow(m2) == ncol(m1)){
  m1 %*% m2
} else {
  paste("Incompatible")
}
m1 %*% m2

#create a data frame with columns called name, age and gender
#add a new column occupation
#write a program to filter the rows where a numeric column is greater than a specified value

df1 <- data.frame(
  name = c("A", "B", "C", "D", "E"),
  age = c(19:23),
  gender = c("Male", "Female", "Female", "Male", "Male")
)
df1

df1 <- cbind(df1, occupation = c("R", "S", "T", "U", "V"))

df1[df1$age > 20,]