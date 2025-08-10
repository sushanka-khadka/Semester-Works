import random
from RSA import random_prime

def is_primptive_root(a,p):
    ans=[]
    for i in range(1,p):
        ans.append(pow(a,i) % p)
    print("Remainders: ", ans)
    return sorted(ans) == [i for i in range(1,p)]

# a=2; p=11

print("------Primitive root check------")
p= random_prime()
a= random.randint(2,p)
if is_primptive_root(a,p):
    print(f"Yes {a} is primitive root of {p} (modulo)")
else:
    print(f"No {a} is not primitive root of {p} (modulo)")