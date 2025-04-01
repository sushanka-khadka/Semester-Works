uppercase_alphabets = [chr(i) for i in range(65, 91)]
lowercase_alphabets= [chr(i) for i in range (97, 123)]

import numpy as np
# playfair_size= 5
mat= np.resize(None, new_shape=(5,5))

def build_playfair_mat(keyword):
    """build a 5x5 playfair matrix with keyword """
    key = 0 # for index in keyword
    ind = 0 # for index in alphabets
    for row in range(5):
        col= 0  # start form 0 th index
        while col < 5:
            if key < len(keyword):  # appending keyword in matrix(till end)
                if keyword[key] not in mat[row]:   # ensure unique elements over mat(no duplicate)
                    mat[row][col]= keyword[key]
                    col+= 1 # ready to append on next
                key +=1 # always incremented whether it is appended on mat or not(loop for keyword)
            else:
                # completing playfair mat using remaining letters
                if ind < 26:    # upto 25->z
                    char= lowercase_alphabets[ind]
                    if char != 'j':  # j is ignored as it will be replaced by i later
                        if not any(char in i for i in mat): # append letters only if it doesn't exist
                            mat[row][col] = lowercase_alphabets[ind]
                            col += 1    # incremented after inserting on playfair mat
                    ind += 1  # always incremented whether it is appended on mat or not(loop for alphabets)
                else:
                    break   # playfair mat build successfully
    return mat

def get_diagraph(plain_text):
    """ returns a list of pair or chars """
    for char in plain_text:
        if char not in lowercase_alphabets:
            plain_text = plain_text.replace(char, '')   # all non-alphabetic chars are skipped
    plain_text= plain_text.replace('j','i')  # all j are replaced by i
    diagraph = []
    i=0
    while i < len(plain_text): # tills end or plain-text
       a = plain_text[i]    # first char of pair is always appended
       if i+1 == len(plain_text):   # check if last pair has only one char
           # b='z'
           b = 'x'
       elif plain_text[i] == plain_text[i + 1]: # if both char are same
           b = 'x'
           i -=1    # decremented cuz it is increased by 2 units later ensure no chars are skipped
       else:
           b = plain_text[i + 1]
       diagraph.append(a + b)
       i += 2
    return diagraph


def encrypt_pair(new_mat, pair):
    """ encrypt a diagram pair based on playfair mat"""
    mat_len= len(new_mat)   # usually 5
    index_a = [(row,col) for row in range(len(new_mat)) for col in range(len(new_mat[row])) if new_mat[row][col] == pair[0]]
    index_b = [(row,col) for row in range(len(new_mat)) for col in range(len(new_mat[row])) if new_mat[row][col] == pair[1]]

    # get actual index form [[row,col]] as [row,col]
    index_a= index_a[0]
    index_b= index_b[0]
    row_a= index_a[0]; col_a= index_a[1]; row_b= index_b[0]; col_b= index_b[1]

    # if same row next char are taken on same row in cycle
    if row_a == row_b:
        substr= str(new_mat[row_a][(col_a + 1) % mat_len])
        substr += str(new_mat[row_b][(col_b + 1) % mat_len])
        return substr
    elif col_a == col_b: # if same col next char are taken on same col in cycle
        substr = str(new_mat[(row_a + 1) % mat_len][col_a])
        substr += str(new_mat[(row_b + 1) % mat_len][col_b])
        return substr
    else:   # elements are on different rows and columns
        substr = str(new_mat[row_a][col_b]) # columns are interchanged
        substr += str(new_mat[row_b][col_a])
        return substr

def encryption(diagraph):
    encrypted= [encrypt_pair(new_mat=playfair_mat, pair=pair) for pair in diagraph]
    return str(''.join(encrypted))




def decrypt_pair(new_mat, pair):
    """ encrypt a diagram pair based on playfair mat"""
    mat_len= len(new_mat)   # usually 5
    index_a = [(row,col) for row in range(len(new_mat)) for col in range(len(new_mat[row])) if new_mat[row][col] == pair[0]]
    index_b = [(row,col) for row in range(len(new_mat)) for col in range(len(new_mat[row])) if new_mat[row][col] == pair[1]]

    # get actual index form [[row,col]] as [row,col]
    index_a= index_a[0]
    index_b= index_b[0]
    row_a= index_a[0]; col_a= index_a[1]; row_b= index_b[0]; col_b= index_b[1]

    # if same row previous char are taken on same row in cycle(decryption)
    if row_a == row_b:
        substr= str(new_mat[row_a][(col_a - 1) % mat_len])
        substr += str(new_mat[row_b][(col_b - 1) % mat_len])
        return substr
    elif col_a == col_b: # if same col previous char are taken on same col in cycle
        substr = str(new_mat[(row_a - 1) % mat_len][col_a])
        substr += str(new_mat[(row_b - 1) % mat_len][col_b])
        return substr
    else:   # no change on diagonal
        substr = str(new_mat[row_a][col_b]) # columns are interchanged
        substr += str(new_mat[row_b][col_a])
        return substr


def decryption(diagraph):
    decrypted= [decrypt_pair(new_mat=playfair_mat, pair=pair) for pair in diagraph]
    return str(''.join(decrypted))

playfair_keyword= 'monarchy'
plain_txt= 'destroy the letter'

# create a diagraph
playfair_diagraph= get_diagraph(plain_txt)

# build a 5x5 playfair matrix
playfair_mat= build_playfair_mat(playfair_keyword)

# encrypt plain text
encrypted_msg= encryption(playfair_diagraph)

# decryption
enc_diagraph= get_diagraph(encrypted_msg)
decrypted_msg= decryption(enc_diagraph)

print('Plain text: ',plain_txt)
print('Plain Diagram: ',enc_diagraph)
print('Encrypted msg: ',encrypted_msg)

print('Enc Diagram: ',enc_diagraph)
print('Decrypted msg: ',decrypted_msg)


"""
during decryption 
all process is reversed except the diagonal one 
"""