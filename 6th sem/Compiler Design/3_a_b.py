# Program to check and eliminate left recursion from a given grammar

print("Enter a left recursive grammar...(e.g. S = Sab | ab | a | b) ")
grammar = input().strip()

# grammar = 'S = Sab | ab | a | b'
# grammar = 'B = BaaC | Bd | ef | g'
# grammar = 'A = A0 | A1 | 0'

l_s, r_s  = grammar.split('=')
l_s = l_s.strip()
r_s = r_s.strip()

productions = [prod.strip() for prod in r_s.split('|')]     # splitting productions

for prod in productions:
    if prod[0] == l_s:
        print(f"{grammar} is left recursive.")
        break
else:    # runs only if the loop completes normally (i.e., no break occurred).  => not left recursive
    print(f"{grammar} is not left recursive.")
    exit()  # to stop further execution if not left recursive

# Eliminating left recursion
print("Eliminating left recursion...")

new_prod = []   
prod_dash = []   

for prod in productions:
    if prod[0] == l_s:
        prod_dash.append(prod[1:] +  l_s + "'")   # A -> αA'
    else:
        new_prod.append(prod + l_s + "'")   # A -> βA'


print('\n***** Production after eliminating left recursion: *****')
print(f"{l_s} = {' | '.join(new_prod) }")
print(f"{l_s}'= {' | '.join(prod_dash) + ' | ε\n' }")   # adding ε production for A'
