print("***** Modular Arithmetic Operation *****")
m= int(input("Enter modulo(+ve): "))
a= int(input('Enter (+ve, -ve) dividend: '))
print("------a mod m ------")

# a= -5
# m=11
if a<0:
    i=1
    while i * m + a < 0:  # as mul_inv is -ve
        i += 1
    r = i * m + a
    """ alternate way;  r= (abs(a)//m +1)*m + a """
else:
    r= a- a//m*m

print(f"{a} mod {m} = {r}")
