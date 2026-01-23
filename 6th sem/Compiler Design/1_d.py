import re

def is_valid_prepaid_phone_no(input_string):
    if len(input_string) != 10 or not re.fullmatch(r'[0-9]+', input_string):
        print('Invalid Prepaid No.')
        return False
    elif input_string[:2] != '98':
        print('Not even a Nepali phone no.')
        return False
    else:
        state = 0
        print('DFA path: Q0', end=' ')
        for char in input_string[2:]:
            if state == 0:
                if char != '5' and re.match(r'[0-9]', char):
                    state = 1
                else:
                    return False
            elif state < 8 :
                if re.match(r'[0-9]', char):
                    state = state + 1
                else:
                    return False
            else:
                return False
            print(f"Q{state}", end=' ')

        return  True    # will be at state 1 if not returned false on any other state.

print('DFA accepting valid Prepaid Phone no.')
print("Enter a input string:  ", end='')
input_string = input().strip()  # removes leading/trailing whitespace

# input_string = '9815000098'

if is_valid_prepaid_phone_no(input_string):
    print("\nValid Prepaid no. (String Accepted)")
else:
    print("\nInvalid Prepaid no. (String Not Accepted)")