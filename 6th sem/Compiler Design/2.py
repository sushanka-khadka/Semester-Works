# transition states for the NFA accepting the regular expression (a+b)*a
transitions_1 = {
    0: {'': {1, 5}},
    1: {'': {2, 3}},
    2: {'a': {4}},
    3: {'b': {4}},
    4: {'': {1, 5}},
    5: {'a': {6}},
    6: {}
}

# transition states for the NFA accepting the regular expression (a+b)(a+b)
transitions_2 = {
    0: {'': {1, 2}},      # ε-split to first (a+b)
    1: {'a': {3}},        # first a branch
    2: {'b': {3}},        # first b branch
    3: {'': {4, 5}},      # ε-split to second (a+b)
    4: {'a': {6}},        # second a branch
    5: {'b': {6}},        # second b branch
    6: {}                 # final accepting state
}


start_state = 0
accept_states = {6}     # same for both NFAs

def epsilon_closure(states, transitions):
    closure = set(states)
    stack = list(states)
    while stack:
        state = stack.pop()
        if state in transitions and '' in transitions[state]:
            for next_state in transitions[state]['']:
                if next_state not in closure:
                    closure.add(next_state)
                    stack.append(next_state)
    return closure

def nfa_accepts(input_string, transitions):
    current_states = epsilon_closure({start_state}, transitions)
    
    for symbol in input_string:
        next_states = set()
        for state in current_states:
            if state in transitions and symbol in transitions[state]:
                next_states.update(transitions[state][symbol])
        current_states = epsilon_closure(next_states, transitions)
    
    return bool(current_states & accept_states)

# Test
test_strings = ['', 'a', 'b', 'aa', 'ab', 'ba', 'cd']

print("Testing NFA for (a+b)*a:")
for str in test_strings:
    result = "ACCEPT" if nfa_accepts(str, transitions_1) else "REJECT"
    print(f"'{str}' -> {result}")



print("\n----- Testing NFA for (a+b)(a+b): -----")
for str in test_strings:
    result = "ACCEPT" if nfa_accepts(str, transitions_2) else "REJECT"
    print(f"'{str}' -> {result}")

