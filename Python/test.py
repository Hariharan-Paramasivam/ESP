while True:
    a=eval(input("Enter: "))
    try:
        
        b=5
        
        if '.' in a:
            print("you have entered Float")
            print("Enter valid Number")
        else:
            c=int(a)+b
            print(c)
    except:
        print("you have entered {}".format(type(a)))
        print("Enter valid Number")