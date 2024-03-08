trees
plot(trees)
cars
plot(cars)
min(cars$dist)
max(cars$speed)

mean(cars$speed)
mean(cars$dist)

sd(cars$speed)
sd(cars$dist)

h <- subset(trees, Height > 70)
h

c <- subset(trees, Girth > 8.6, select = Volume)
c

c <- subset(trees, Height == 63, Height)
c

trees[c(15,17,21,23), ]
