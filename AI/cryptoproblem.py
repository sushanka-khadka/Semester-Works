from itertools import permutations

def is_valid_solution(perm):
    s, e, n, d, m, o, r, y = perm
    send = s * 1000 + e * 100 + n * 10 + d
    more = m * 1000 + o * 100 + r * 10 + e
    money = m * 10000 + o * 1000 + n * 100 + e * 10 + y
    return send + more == money

def solve_cryptarithmetic():
    letters = 'sendmory'
    digits = range(10)
    for perm in permutations(digits, len(letters)):
        if perm[letters.index('m')] == 0 or perm[letters.index('s')] == 0:
            continue
        if is_valid_solution(perm):
            return {letters[i]: perm[i] for i in range(len(letters))}
    return None

solution = solve_cryptarithmetic()
if solution:
    print("Solution found:")
    for letter, digit in solution.items():
        print(f"{letter.upper()} = {digit}")
else:
    print("No solution found.")
