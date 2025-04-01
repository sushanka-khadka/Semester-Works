uppercase_alphabets = [chr(i) for i in range(65, 91)]
# lowercase_alphabets= [chr(i) for i in range (97, 123)]

def encryption(plain_text, shift_key):
    """ encrypts the plain text with the shift key and returns an encrypted msg """
    encrypted= ''
    for char in plain_text:
        if char.upper() in uppercase_alphabets:
            pos = uppercase_alphabets.index(char.upper())
            encrypted += uppercase_alphabets[(pos + shift_key) % len(uppercase_alphabets)]
        else:
            encrypted += char
    return encrypted

def decryption(encrypted_text, shift_key):
    """decrypts encrypted msg with shift key and returns plain text"""
    decrypted = ''
    for char in encrypted_text:
        if char.upper() in uppercase_alphabets:
            pos = uppercase_alphabets.index(char.upper())
            decrypted += uppercase_alphabets[(pos - shift_key) % len(uppercase_alphabets)]
        else:
            decrypted += char
    return decrypted

# shift_key= 3
# plain_text= 'decode me xyz'
plain_txt= input('Enter your plain-text: ')
key= int(input('Enter encryption key: '))

encrypted_msg= encryption(plain_txt, key)
decrypted_msg= decryption(encrypted_msg, key)

print(f'Pain text: {plain_txt}')
print(f'Encrypted msg: {encrypted_msg}')
print(f'Decrypted msg: {decrypted_msg}')