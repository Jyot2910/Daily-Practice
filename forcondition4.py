for n in range ( 1 , 10000):

    sum = 0
    for i in range ( 1 , n ):
        if(n%1==0):
            sum += i
if( sum == n):
    print(f"{n} is perfect")