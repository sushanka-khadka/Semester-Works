import re

def is_valid_gmail(input_string):
    gmail = input_string.split('@')
    username = gmail[0]
    domain = '@'.join(gmail[1:])  # in case there are multiple '@' symbols

    print(username)
    print(domain)
    if not domain == 'gmail.com':
        print('Not a valid gmail address.')
        return False
    else:
        if not re.fullmatch(r'[a-zA-Z0-9_.]+',
                            username):  # username must only contain alphanumeric, dot(.) and underscore(-) character
            print("Not a valid username.")
            return False
        else:
            state = 0
            print('DFA path: Q0', end=' ')
            for char in username:
                if state == 0:
                    if re.match(r'[a-zA-Z]', char):
                        state = 1
                    else:
                        return False
                elif state == 1:
                    if char == '.':
                        state = 2
                    elif char == '_':
                        state = 4
                    elif re.match(r'[a-zA-Z0-9]', char):
                        pass    # as it is(state = 1)
                    else:
                        return False
                elif state == 2:
                    if char == '_':
                        state = 3
                    elif re.match(r'[a-zA-Z0-9]', char):
                        state = 1
                    else:
                        return False
                elif state == 3:
                    if char == '.':
                        state = 2
                    elif re.match(r'[a-zA-Z0-9]', char):
                        state = 1
                    else:
                        return False
                elif state == 4:
                    if char == '.':
                        state = 5
                    elif re.match(r'[a-zA-Z0-9]', char):
                        state = 1
                    else:
                        return False
                elif state == 5:
                    if char == '_':
                        state = 4
                    elif re.match(r'[a-zA-Z0-9]', char):
                        state = 1
                    else:
                        return False
                print(f"Q{state}", end=' ')

            return  True    # will be at state 1 if not returned false on any other state.

print('DFA accepting valid Gmail Id')
print("Enter a input string:  ", end='')
input_string = input().strip()  # removes leading/trailing whitespace

if is_valid_gmail(input_string):
    print("\nValid Gmail Address. (String Accepted)")
else:
    print("\nInvalid Gmail Id. (String Not Accepted)")