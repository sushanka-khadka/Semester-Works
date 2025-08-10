# 14. Write a program to find the multiplicative inverse using extended Euclidean algorithm.
import random


# multiplicative inverse of 3 mod 11
def gcd(a,b):
    while (b!=0):
        r= a - a//b * b     # a- int(a/b)*b
        a= b
        b=r
    return a

def multiplicative_inv(a,b):
    """returns multiplicative inverse of a mod b"""
    if gcd(a,b) == 1:
        x1, x2 = 1, 0
        while b != 0:
            r = a % b;
            q = a // b
            a = b; b = r
            x = x1 - q * x2
            x1 = x2;
            x2 = x
            # print(f"q: {q},a:{a}, b={b}, x1={x1}, x2={x2}, x={x} ")
        return x1
    # else:
    #     print("GCD(a,b) is not 1. So they are not coprime and there is not multiplicative inverse.")

if __name__ == "__main__":

    print(f"-----Multiplicative inverse using Extended Euclidean Algorithm-----")

    # A= 5; M= 26 # A mod M
    # A= random.randint(1,100); M= random.randint(1,100)
    A= int(input("Enter dividend: "))
    M = int(input("Enter Modulo: "))
    mul_inv= multiplicative_inv(A,M)

    if mul_inv == None:
        print("GCD(A,B) is not 1. So they are not coprime and there is not multiplicative inverse.")
    elif mul_inv < 0:
        i=1
        while i*M + mul_inv < 0:    # as mul_inv is -ve ---> % operator can do so
            i+= 1
        mul_inv= i*M + mul_inv
    print(f"Multiplicative inverse of {A} mod {M} is {mul_inv}")