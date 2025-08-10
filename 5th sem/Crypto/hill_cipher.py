import numpy as np
from mul_inv import multiplicative_inv

uppercase_alphabets = [chr(i) for i in range(65, 91)]
# print(uppercase_alphabets)

# key = 'GYBNQKURP'
# for i in key:
#     print(uppercase_alphabets.index(i), end=',')
# print('\n')


# matrix multiplication 3*3 into 3x1= 3x1
def encrypt():
    cipher_mat= [0]*n   # null matrix initialization
    for i in range(n):
        for j in range(n):
            cipher_mat[i] += key_mat[i][j] * plain_mat[j]
        cipher_mat[i] = cipher_mat[i] % 26     # modular operation 26 to fit alphabets
    return cipher_mat

def minor(mat, i, j):
    # remove row i and column j
    return np.delete(np.delete(mat, i, axis=0), j, axis=1)

def cofactor_matrix(mat):
    cofactors= [[0]*n for _ in range(n)]
    for i in range(n):
        for j in range(n):
            minor_ij= minor(mat, i, j)
            sign= (-1) ** (i+j)
            cofactors[i][j] = sign * round(np.linalg.det(minor_ij))
            # print("minor det: ", np.linalg.det(minor_ij))
            # print(("is cofactors float: ", cofactors[i][j]))
    return cofactors

def adjoint_matrix(mat):
    cofactors= cofactor_matrix(mat)
    return np.transpose(cofactors)

def inverse_matrix(mat):
    adj_A = adjoint_matrix(key_mat)
    # print(f"Adjoint matrix:\n {adj_A}")
    det_inv= multiplicative_inv(np.linalg.det(key_mat), 26)
    if det_inv == None:
        print("The matrix is not invertible MOD 26")
        exit()
    # print(f"mul_inv of {np.linalg.det(key_mat)} is {det_inv}")
    inv_A= det_inv * adj_A
    #  modular operation on inverse matrix
    return inv_A % 26

def decrypt():
    plain_mat= [0] * n  # null matrix initialization
    inv_key_mat= inverse_matrix(key_mat)
    # print("inverse key matrix with multiplicative inv:\n", inv_key_mat)
    for i in range(n):
        for j in range(n):
            plain_mat[i] += inv_key_mat[i][j] * cipher_mat[j]
        plain_mat[i]= plain_mat[i] % 26
    print("Message matrix", np.round(plain_mat))
    print("Original msg: ",[uppercase_alphabets[round(u)] for u in plain_mat])

# given n= 3
key = 'GYBNQKURP'
plaintext= 'ACT'
n=3

# plaintext= "GFG"
# key= "HILLMAGIC"

key_mat= [[0] * n for _ in range(n)]
for i in range(n):
    for j in range(n):
        key_mat[i][j]= uppercase_alphabets.index(key[i*n +j])  # (1*3+2= 5)

print("-------Hill Cipher-------")
print(f"keyword: {key} \n"
      f"key matrix: {key_mat}")

plain_mat= [uppercase_alphabets.index(i) for i in plaintext]
print(f"plain text: {plaintext}\n"
      f"plain matrix: {plain_mat}")

cipher_mat= encrypt()
print(f"Cipher matrix: {cipher_mat}\n"
      f"Cipher text:{[uppercase_alphabets[i] for i in cipher_mat]}")

decrypt()
