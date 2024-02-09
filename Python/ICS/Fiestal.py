import binascii

def xor(a, b):
    return "".join("0" if bit_a == bit_b else "1" for bit_a, bit_b in zip(a, b))

def binary_to_decimal(binary):
    return int(binary, 2)

def feistel_cipher(plaintext, key1, key2):
    n = len(plaintext) // 2
    left = plaintext[:n]
    right = plaintext[n:]

    # Encryption
    round1_output = xor(right, key1)
    left_new = xor(round1_output, left)
    right_new = right

    round2_output = xor(right_new, key2)
    left_final = xor(round2_output, left_new)
    right_final = left_new

    ciphertext = left_final + right_final
    return ciphertext

def feistel_decipher(ciphertext, key1, key2):
    left_final = ciphertext[:len(ciphertext)//2]
    right_final = ciphertext[len(ciphertext)//2:]

    # Decryption
    round1_output = xor(left_final, key2)
    left_new = xor(right_final, round1_output)
    right_new = left_final

    round2_output = xor(left_new, key1)
    left_original = xor(right_new, round2_output)
    right_original = right_new

    plaintext = left_original + right_original
    return plaintext

if __name__ == "__main__":
    plaintext = "11111001"
    key1 = "1011"
    key2 = "1110"

    # Encryption
    ciphertext = feistel_cipher(plaintext, key1, key2)
    print("Ciphertext:", ciphertext)

    # Decryption
    decrypted_text = feistel_decipher(ciphertext, key1, key2)
    decrypted_decimal = binary_to_decimal(decrypted_text)
    print("Decrypted Text:", decrypted_decimal)
