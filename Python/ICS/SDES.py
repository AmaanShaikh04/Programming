# S-Box tables for SDES
S0 = [
    [1, 0, 3, 2],
    [3, 2, 1, 0],
    [0, 2, 1, 3],
    [3, 1, 3, 2]
]

S1 = [
    [0, 1, 2, 3],
    [2, 0, 1, 3],
    [3, 0, 1, 0],
    [2, 1, 0, 3]
]

# Permutation tables for SDES
P10 = [2, 4, 1, 6, 3, 9, 0, 8, 7, 5]
P8 = [5, 2, 6, 3, 7, 4, 9, 8]

P4 = [1, 3, 2, 0]

IP = [1, 5, 2, 0, 3, 7, 4, 6]
IP_INV = [3, 0, 2, 4, 6, 1, 7, 5]

# Utility function to perform a permutation
def permute(bits, permutation_table):
    return [bits[i] for i in permutation_table]

# Utility function to perform a left circular shift
def left_circular_shift(bits, shift):
    return bits[shift:] + bits[:shift]

# Utility function to perform XOR operation on two bit strings
def xor(bits1, bits2):
    return [b1 ^ b2 for b1, b2 in zip(bits1, bits2)]

# Utility function to split a bit string into two halves
def split_half(bits):
    half = len(bits) // 2
    return bits[:half], bits[half:]

# Utility function to perform S-Box substitution
def sbox_substitution(bits, sbox):
    row = int(bits[0] * 2 + bits[3], 2)
    col = int(bits[1] * 2 + bits[2], 2)
    return [int(b) for b in format(sbox[row][col], '02b')]

# Key generation function for SDES
def generate_round_keys(key):
    key = permute(key, P10)
    left, right = split_half(key)
    left = left_circular_shift(left, 1)
    right = left_circular_shift(right, 1)
    round_key1 = permute(left + right, P8)
    left = left_circular_shift(left, 2)
    right = left_circular_shift(right, 2)
    round_key2 = permute(left + right, P8)
    return round_key1, round_key2

# Encryption function for SDES
def encrypt(plaintext, key):
    round_key1, round_key2 = generate_round_keys(key)
    plaintext = permute(plaintext, IP)
    left, right = split_half(plaintext)
    # Round 1
    expanded_right = permute(right, [3, 0, 1, 2, 1, 2, 3, 0])
    xor_result = xor(expanded_right, round_key1)
    sbox_result = sbox_substitution(xor_result[:4], S0) + sbox_substitution(xor_result[4:], S1)
    p4_result = permute(sbox_result, P4)
    new_right = xor(left, p4_result)
    # Round 2
    expanded_new_right = permute(new_right, [3, 0, 1, 2, 1, 2, 3, 0])
    xor_result = xor(expanded_new_right, round_key2)
    sbox_result = sbox_substitution(xor_result[:4], S0) + sbox_substitution(xor_result[4:], S1)
    new_left = xor(right, permute(sbox_result, P4))
    ciphertext = permute(new_left + new_right, IP_INV)
    return ciphertext

# Take input from the user
plaintext = input("Enter the plaintext (8 bits): ")
key = input("Enter the key (10 bits): ")

# Convert the input to lists of bits
plaintext_bits = [int(b) for b in plaintext]
key_bits = [int(b) for b in key]

# Perform SDES encryption
ciphertext = encrypt(plaintext_bits, key_bits)

# Print the encrypted text
print("Encrypted Text:", ''.join(str(b) for b in ciphertext))