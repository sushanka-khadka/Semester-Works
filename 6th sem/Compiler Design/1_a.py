# DFA accepting binary string that starts with '0' and ends with '1'

print("DFA accepting binary strings that start with '0' and end with '1'.")
print("Enter a binary string:  ", end='')
input_string = input().strip()  # removes leading/trailing whitespace

state = 0  # initial state
print('DFA path: Q0', end=' ')
for char in input_string:
    if char not in '01':
        print("Invalid input. Please enter a binary string.")
        exit()
    else:
        if state == 0:
            if char == '0':
                state = 1
            else:
                state = 3
        elif state == 1:
            if char == '0':
                state = 1
            else:
                state = 2
        elif state == 2:
            if char == '0':
                state = 1
            else:
                state = 2
        elif state == 3:
            state = 3
        print(f"Q{state}", end=' ')

if state == 2:
    print("\nAccepted")
else:
    print("\nNot Accepted")
