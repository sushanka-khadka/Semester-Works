import random
import numpy as np

uppercase_alphabets= [chr(i) for i in range(65,91)]
# print(uppercase_alphabets)

def Vegenere_cipher():
    keyword = "deceptive"
    msg = "we are discovered save yourself"

    print('-----Encryption-----')
    print("Message: ", msg)
    print("keyword: ", keyword)

    msg = msg.replace(' ', '')

    # to make keyword equal to message lenth
    keyword = (keyword * (len(msg) // len(keyword) + 1))[:len(msg)]  # repeat exactly factor + 1 times and slice down

    msg_value = [uppercase_alphabets.index(char.upper()) for char in msg]
    key_value = [uppercase_alphabets.index(char.upper()) for char in keyword]

    cipher_value = [(key + msg) % 26 for key, msg in zip(key_value, msg_value)]

    cipher = [uppercase_alphabets[i] for i in cipher_value]
    # cipher = ''.join(cipher)

    print("Message: ", msg)
    print("keyword: ", keyword)
    print("Cipher text:", ''.join(cipher))

    dec_plain= [(c - k + 26) % 26 for c,k in zip(cipher_value, key_value )]
    dec_plain= [uppercase_alphabets[i] for i in dec_plain]
    print('-----Decryption-----')
    print("Decrypted msg: ", ''.join(dec_plain))


def Vernam_cipher():
    # msg= 'Each letter of the plaintext is XORed with key'
    msg = 'Random key generation'
    msg= msg.replace(' ','')    # remove all whitespaces

    random_key_value = random.choices(np.arange(0,26).tolist(), k=len(msg))     # take a random sample from 0-26 of length equal to msg(number can repeat)
    random_key= [uppercase_alphabets[i] for i in random_key_value]

    msg_value= [uppercase_alphabets.index(_) for _ in msg.upper()]
    cipher_value= [(k + p) % 26 for k,p in zip(random_key_value, msg_value) ]
    cipher= [uppercase_alphabets[_] for _ in cipher_value]

    print("-----Encryption-----")
    print(f"Msg: {msg} \nRandom key: {''.join(random_key)} \nCipher: {''.join(cipher)}")

    print("-----Decryption-----")
    plain_value= [(c - k + 26) % 26 for c,k in zip(cipher_value, random_key_value)]
    plain_text= [uppercase_alphabets[_] for _ in plain_value]

    print("Plain: ", ''.join(plain_text))

print("*******Vegenere Cipher*******")
Vegenere_cipher()
print("\n*******Vernam Cipher*******")
Vernam_cipher()

