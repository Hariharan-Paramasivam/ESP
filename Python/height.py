def val(n):
    return n.isdigit()
def wt(height):
    if val(height):
        height=int(height)
        if height==0:
            print("Error in Height(Zero)")
            print("Please Enter Positive Number")
        weight = height - 100
        if weight <=0:
            print(" Weight is Zero or Negative")
            return 1
        else:
            print("Weight should be {}".format(weight))
            return 0
    else:
        print("Error in Height(Negative)")
        print("Please Enter Positive Number")
        return 1
    

i=1
while(i):
    name = input("Enter your NAME : ")
    height = input("Enter your Height : ")
    check = wt(height)
    if check ==0:
        c = input("Do you want to exit(y/n):")
        if c in ['Yes', 'Y', "YES" ,'y']:
            i=0
        else:
            pass