# Write a program to find the GCD of given two positive integers using Euclidean algorithm.
import random

def euclidean_gcd(a,b):
    while (b!=0):
        r= a - a//b * b     # a- int(a/b)*b
        a= b
        b=r
        # print(f"a:{a}, b={b}")
    return a

# x= random.randint(0,100)
# y= random.randint(0,100)
print("-----GCD using euclidean algorithm-----")
x= int(input("Enter first number: "))
y= int(input("Enter second number: "))

print(f"GCD({x},{y}) = {euclidean_gcd(x,y)}")