import random
from RSA import random_prime, is_prime

def primitive_root(p):
    totient_p= p-1 # prime no
    pr = 0  # primitive root
    # prime factor of (p-1)
    for i in range(2,totient_p//2+1):
        found = 0
        if totient_p%i ==0: # if factor
            if is_prime(i): # factor and is prime
                pow_root= totient_p/i
                # let's test for primitive root g form 2 to p-1
                for g in range(2,p):
                    if pow(g,pow_root) % p != 1:
                        # print("primitive root: ", g)
                        # print("pow_root root: ", pow_root)
                        pr=g
                        found=1
                        break
        if found:
            break
    return pr

if __name__ == "__main__":
    q= random_prime()
    a= primitive_root(q)   # primitive root of q

    X_a= random.randint(2,q)    # less than q-1
    Y_a= pow(a, X_a) % q    # public a, X_a, q

    X_b= random.randint(2,q)
    Y_b= pow(a, X_b) % q

    K_a= pow(Y_b, X_a) % q
    K_b= pow(Y_a, X_b) % q

    print(f"-----Deffie Hellman Algorithm----- \n"
          f"q: {q} \t primitive root(alpha): {a} \n"
          f"For User A: X_a= {X_a}, Y_a= {Y_a} K_a= {K_a} \n"
          f"For User B: X_b= {X_b}, Y_b= {Y_b} K_b= {K_b}")


"""
g is a primitive root modulo n if its powers generate all numbers in the group of integers modulo n.
"""