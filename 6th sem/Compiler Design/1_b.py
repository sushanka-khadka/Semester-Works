import re

def is_valid_c_variable_name(input_string):
    reserved_keywords = {'int', 'float', 'char', 'double', 'long', 'short', 'void', 
                        'if', 'else', 'while', 'for', 'return'}
    if input_string in reserved_keywords:
        print(f"{input_string} is a reserved keyword.")
        return False
        
    if re.fullmatch(r'[a-zA-Z0-9_]+', input_string) is None:
        print("Symbols are invalid.")
        return False

    state = 0  # initial state
    print('DFA path: Q0', end=' ')
    for char in input_string:
        if state == 0:
            if re.fullmatch(r'[a-zA-Z]', char):
                state = 1
            elif char == '_':
                state = 2
            else:
                return False
        elif state == 1:
            if re.fullmatch(r'[a-zA-Z0-9_]', char):
                state = 1
            else:
                return False
        elif state == 2:
            if re.fullmatch(r'[a-zA-Z]', char):
                state = 1
            elif char == '_':
                state = 2
            else:
                return False
        print(f"Q{state}", end=' ')
    if state == 1:
        return True


print("DFA accepting valid C variable names.")
print("Enter a input string:  ", end='')
input_string = input().strip()  # removes leading/trailing whitespace

if is_valid_c_variable_name(input_string):
    print("\nString Accepted")
else:
    print("\nNot a valid C variable name.")
