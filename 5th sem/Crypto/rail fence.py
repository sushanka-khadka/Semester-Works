
def encryption(msg, rail_depth):
    pattern = [['_' for _ in range(len(msg))] for _ in range(rail_depth)]
    # print(pattern)

    dir_down = False
    row, col = 0, 0

    for i in range(len(msg)):
        if (row == 0) | (row == rail_depth - 1):
            dir_down = not dir_down

        # fill the rail fence with corresponding alphabet
        pattern[row][col] = msg[i]
        col += 1

        if dir_down:  # find next row using dir_down flag
            row += 1
        else:
            row -= 1

    # construct cipher
    cipher = []
    for i in range(rail_depth):
        for j in range(len(msg)):
            if pattern[i][j] != '_':
                cipher.append(pattern[i][j])

    return ''.join(cipher)

def decryption(cipher, rail_depth):
    pattern= [['_' for _ in range(len(cipher))] for _ in range(rail_depth)]

    dir_down= False
    row,col= 0,0

    # mark places with *
    for _ in range(len(cipher)):
        if (row == 0) | (row == rail_depth - 1):
            dir_down= not dir_down

        pattern[row][col] = '*'
        col += 1

        if dir_down:
            row += 1
        else:
            row -= 1

    # fill the fence with the cipher text
    index=0 # to count on cipher chars
    for i in range(rail_depth):
        for j in range(len(cipher)):
            if pattern[i][j] == '*' and index < len(cipher):
                pattern[i][j] = cipher[index]
                index += 1

    # now read zig-zag manner to get message
    plain= []
    dir_down= None
    row,col= 0,0
    for _ in range(len(cipher)):
        if (row == 0) | (row == rail_depth - 1):
            dir_down= not dir_down


        # read the alphabets
        if pattern[row][col] != '*':
            plain.append(pattern[row][col])
            col += 1

        if dir_down:
            row += 1
        else:
            row -= 1

    return ''.join(plain)

print("--------Rail Fence-------")
msg= input("Enter plain text: ")
rail_depth= int(input("Enter rail depth: "))

# rail_depth = 3
# msg = 'we are discovered flee at once'
msg = msg.replace(' ', '')


cipher= encryption(msg, rail_depth)
plain= decryption(cipher,rail_depth)

print(f"Message: {msg}\n"
      f"Cipher: {cipher}\n"
      f"Plain: {plain}")