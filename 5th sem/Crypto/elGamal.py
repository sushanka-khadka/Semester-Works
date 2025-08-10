import random
from mul_inv import multiplicative_inv
from RSA import random_prime
from diffie_hellman import primitive_root

def generate_key():
    X_a = random.randint(2, q-1)  # less than q-1
    global Y_a
    Y_a = pow(a, X_a) % q  # public a, X_a, q
    return X_a

def decryption():
    X_a= generate_key()
    c1,c2= encryption()
    K= pow(c1, X_a) % q
    M= (c2* multiplicative_inv(K,q)) % q
    print(f"Decryption: K={K} \n\tMsg: {M} \n\tC2: {c2}")

def encryption():
    M = random.randint(0, q)  # message < q
    k = random.randint(0, q)  # less than q
    K = pow(Y_a, k) % q
    C1= pow(a,k) % q
    C2= (K*M) % q
    # cipher (C1, C2) public
    print(f"Encryption: \n\tMsg: {M} \n\tK:{K} \n\t(C1,C2): {C1,C2}")
    return C1, C2

global Y_a
q= random_prime()
a= primitive_root(q)   # primitive root of q


if __name__ == '__main__':
    print('------Elgamal CryptoSystem------')
    decryption()