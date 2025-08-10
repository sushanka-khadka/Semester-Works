# program for lucas lehmar test for primality test
# The Lucas–Lehmer Test is a primality test specifically designed for Mersenne numbers, which are numbers of the form:
# Mp= 2^p - 1 where p = prime and to check if Mp is prime:
#  s0= 4 to find sn from 1 to p-2 ; sn= sn-1^2 - 2
# mersenne primes
def is_prime(a):
    if a<2:
        return False
    for i in range(2, a//2 + 1):
        if a%i == 0:
            return False
    return True


def lucas_lehmar(Mp):
    # Mp= 31
    p= 2    # smallest prime only applied for p>= 3 not apply for p = 2
    s= [4]
    while Mp > (2**p -1):
        p += 1

    if Mp == 2**p -1 :
        if is_prime(p):
            for i in range(1, p-1):      # upto p-2
                s.append((s[i-1] ** 2 - 2) % Mp)
            if s[p-2] == 0 :
                print("Given number is Mersenne prime number.")
            elif p == 2:
                print("Given number is Mersenne Prime.")  # lucas test not applicable for p==2
            else:
                print("Composite number.")
        else:
            print('Not a mersenne prime number')
    else:
        # print("p: ", p)
        print("Not a Mersenne prime number.")


print("-----Lucas Lehmar Test (Mersenne Prime Number)----")
while True:
    n= int(input("Enter any positive integer: "))
    lucas_lehmar(n)
