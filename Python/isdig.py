def int_input(n):
    #print(n.isdigit())
    #print(n,n,n)
    return n.isdigit()

n=1
while(n):
    i=input("Enter input")
    c=int_input(i)
    print(c)
    if c:
        print("hello ",i)
    else:
        n=0
    