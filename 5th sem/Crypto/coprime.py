def gcd(a,b):
    while (b!=0):
        r= a - a//b * b     # a- int(a/b)*b
        a= b
        b=r
    return a

def coprime_check(m,n):
    if gcd(m,n) == 1:
        print(f"{m} and {n} are coprime numbers.")
    else:
        print("Given numbers are not coprime.")

print("------Coprime check-------")
n1= int(input("Enter first number: "))
n2= int(input("Enter second number: "))

coprime_check(n1,n2)
