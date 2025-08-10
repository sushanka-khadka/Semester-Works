# Illustrate the Euler totient function.

def gcd(a,b):
    while (b!=0):
        r= a - a//b * b     # a- int(a/b)*b
        a= b
        b=r
    return a

def euler_totient(n):
    count =0
    for a in range(1,n):
        if gcd(n,a) == 1:
            count += 1
    return count

while True:
    n= int(input("Enter a number: "))
    print("Euler's totient: ",euler_totient(n))