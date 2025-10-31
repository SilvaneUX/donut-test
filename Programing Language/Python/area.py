#to calculate area 
print("press 1 if you want area of a circle, \n2 if area of triangle, \n3 if area of square and \n4 if area of reactangle")
c=int(input("enter your choice: "))
if c==1:
    r=float(input("pls enter the radius of the circle: "))
    A= (22*r*r)/7
    print("your required area is", A)
elif c==2:
    base=float(input("enter the base length: "))
    height=float(input("enter the height: "))
    A=base*height/2
    print("the area of triangle is", A)
else:
    print("invalid input")