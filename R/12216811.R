#ques 1:Create a 3x3 array named my_array containing numbers from 1 to 9.
my_array <- array(1:9, dim = c(3,3))
print(my_array)
#1a:Access and print the element in the second row and third column of the my_array.
print(my_array[2,3])
#1b:Add 5 to all elements of the my_array.
my_array <- array(my_array+5, dim = c(3,3))
print(my_array)
#1c:Check the dimensions of the my_array.
print(dim(my_array))
#1d:Reshape the my_array into a 1-dimensional array
my_array <- array(my_array)
print(my_array)
#1e:Create another array named another_array with the same dimensions as my_array and add it to my_array.
another_array <- array(16:24, dim = dim(my_array))
print(another_array)
my_array <- rbind(my_array,another_array)
print(my_array)
#1f:Create a subset of the my_array containing only the elements in the second row.
sub_array <- my_array[2,]
print(sub_array)
#1g:Transpose the my_array.
my_array <- t(my_array)
print(my_array)
#1h:Calculate the mean, median, and standard deviation of the my_array
m = mean(my_array)
m
md = median(my_array)
md
sd = sd(my_array)
sd
#1i:Concatenate two arrays array1 and array2 along a specific dimension.
my_array <- cbind(my_array,another_array)
my_array
#1j:.  Sort the elements of the my_array in ascending order.
my_array <- apply(my_array,MARGIN = 2 ,sort)
my_array
#1k:.  Insert a new row or column into the my_array.
my_array <- rbind(my_array, 1:3)
my_array

#ques 2:Write a function named pyramid_pattern that takes a single argument n and displays a pyramid pattern of asterisks (*) with height n.
pyramid_pattern <- function(n) {
  for(i in 1:n) {
    str = "";
    for(j in i:n) {
      str = paste(str," ",sep = "")
    }
    for(j in 1:(2*i-1)) {
      str = paste(str, "*",sep = "")
    }
    print(str)
  }
}
n = readline()
pyramid_pattern(n)

