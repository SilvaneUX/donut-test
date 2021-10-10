code = "iamcode"
userAnswer = ""
again = False

while userAnswer != code and (again is False):
    userAnswer = input("Guest the code : ")
else:
    again = True
    print("Yes the code is correct!")
