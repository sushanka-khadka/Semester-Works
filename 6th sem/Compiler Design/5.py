grammar = 'S = Sab | ab | a | b'
print("Given Grammar: ", grammar)


V = set()   # set of variables  (set will avoid duplicates)
T = set()   # set of terminals
productions_dict = dict()   # dictionary to hold productions
productions_set = set()   # set to hold all productions
starting_symbol = ''

# Parsing the grammar
l_s, r_s  = grammar.split('=')
l_s = l_s.strip()
r_s = r_s.strip()

if l_s.isupper():
    starting_symbol = l_s
    V.add(l_s)  # adding variable to V
    productions = [prod.strip() for prod in r_s.split('|')]     # splitting productions
    for prod in productions:
        for char in prod:
            if char.isupper():
                V.add(char)
            else:
                T.add(char)  # adding terminal to T
        productions_set.add(l_s + '->' + prod)
else:
    print("Invalid Grammar: Left side must be a variable (uppercase letter).")
    exit()

print("Starting Symbol: ", starting_symbol)
print("Variables (V): ", V)
print("Terminals (T): ", T)
print("Productions: ", productions_set)