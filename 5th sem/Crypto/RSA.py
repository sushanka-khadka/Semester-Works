import random
def gcd(a,b):
    while b!=0:
        r= a - a//b * b     # a- int(a/b)*b
        a= b
        b=r
    return a

# def euler_totient(n):
#     count =0
#     for a in range(1,n):
#         if gcd(n,a) == 1:
#             count += 1
#     return count

def random_prime():
    p= random.randint(0,100)
    while not is_prime(p):
        p = random.randint(0, 100)
    # print("prime: ",p)
    return p

def is_prime(a):
    if a<2:
        return False
    for i in range(2, a//2 + 1):
        if a%i == 0:
            return False
    return True

global e,n
def decryption():
    # private key generation
    while True:
        p, q = random_prime(), random_prime()   # random prime numbers p != q
        if p != q:
            break
    print(f"private key: \np={p} \tq={q}")
    global e,n  # public key
    n= p*q
    totient_n = (p-1) *(q-1) # as both prime (totient_n = euler_totient(n))
    # choose e as (1 < e < totient_n)
    # e= random.randint(1,totient_n)    # can be computationally heavy instead use loop so start fron 2
    e,d = 2,2
    while True:
        # print("d: ",d)
        if d >= totient_n:
            e+=1
            d=2 # start from beginning
            # print("e: ", e)
        if d*e - d*e//totient_n * totient_n == 1:
            # print("d: ", d)
            break
        d += 1
    # print("d: ",d)

    C= encryption()
    M= pow(C,d)
    M= M- M//n *n   # modular operation: M^d mod n
    # print("M: ", M)
    print(f"Decryption: d={d} \n\tMsg: {M} \n\tCipher: {C}")

def encryption():
    M= random.randint(0,n) # message < n
    C= pow(M,e)
    C= C - int(C/n) *n
    print(f"Encryption: public key: e={e}, n={n} \n\tMsg: {M} \n\tCipher: {C}")
    return C

if __name__ == '__main__':
    print("----------RSA Algorithm----------")
    decryption()