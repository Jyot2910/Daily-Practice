n=int(input("Enter n:"))
count=0 
for i in range ( 1, n+1 ):
    if(n%i==0):
        count+=1
if (count==2):
    print(f"{n} is prime " )
else:
    print(f"{n} is not prime" )
    
    
num = int(input("Enter a number: "))
sum_factors = 0
for i in range(1, num):
    if num % i == 0:
        sum_factors += i
if sum_factors == num:
    print(f"{num} is a Perfect Number")
else:
    print(f"{num} is NOT a Perfect Number")
    


    