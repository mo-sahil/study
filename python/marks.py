maths = int(input("maths marks "))
english = int(input("engish marks "))
science = int(input("science marks "))

average = (maths+english+science)/3

if average >= 90 :
    print("O")
elif average >= 80 : 
    print("A+")
elif average >= 70 :
    print("B+")
elif average >= 60 :
    print("B")
else : 
    print("C")