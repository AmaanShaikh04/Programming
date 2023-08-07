# Experiment No 1
# Author: Amaan Shaikh
# Branch: TYCSE-A
# File name: Amaan_Shaikh_ICS_ExperimentNo1.py


# Implementation of the Caesar cipher

# Encryption function for the Caesar cipher
def caesar_cipher_encrypt(plain_text, key):
    encrypted = ""

    # Loop through each character in the plain_text
    for char in plain_text:
        if char.isupper():  # Check if it's an uppercase character
            c_index = ord(char) - ord('A')  # Get the index of the character in the range [0-25]
            c_shifted = (c_index + key) % 26 + ord('A')  # Shift the character by the key positions
            encrypted += chr(c_shifted)  # Convert the shifted index back to the character and append to the
            # encrypted text

        elif char.islower():  # Check if it's a lowercase character
            c_index = ord(char) - ord('a')  # Get the index of the character in the range [0-25]
            c_shifted = (c_index + key) % 26 + ord('a')  # Shift the character by the key positions
            encrypted += chr(c_shifted)  # Convert the shifted index back to the character and append to the
            # encrypted text

        else:  # If it's neither alphabetical nor a number, leave it unchanged
            encrypted += char

    return encrypted


# Decryption function for the Caesar cipher
def caesar_cipher_decrypt(ciphertext, key):
    decrypted = ""

    # Loop through each character in the ciphertext
    for char in ciphertext:
        if char.isupper():  # Check if it's an uppercase character
            c_index = ord(char) - ord('A')  # Get the index of the character in the range [0-25]
            c_og_pos = (c_index - key) % 26 + ord('A')  # Shift the character to its original position
            decrypted += chr(c_og_pos)  # Convert the original index back to the character and append to the
            # decrypted text

        elif char.islower():  # Check if it's a lowercase character
            c_index = ord(char) - ord('a')  # Get the index of the character in the range [0-25]
            c_og_pos = (c_index - key) % 26 + ord('a')  # Shift the character to its original position
            decrypted += chr(c_og_pos)  # Convert the original index back to the character and append to the
            # decrypted text

        else:  # If it's neither alphabetical nor a number, leave it unchanged
            decrypted += char

    return decrypted


# Implementation of a mono-alphabetic cipher

# Encryption function for the mono-alphabetic cipher
def encrypt(plaintext, key):
    # Ensure the key contains 26 unique letters (ignore case and non-alphabetic characters)
    key = ''.join(filter(str.isalpha, key)).lower()
    if len(key) != 26 or len(set(key)) != 26:
        raise ValueError("The key must contain 26 unique alphabetic characters.")

    # Create a dictionary to store the mapping of each letter in the plaintext to its corresponding letter in the key
    key_mapping = {}
    for i in range(26):
        key_mapping[chr(65 + i)] = key[i].upper()  # Map uppercase letters
        key_mapping[chr(97 + i)] = key[i]  # Map lowercase letters

    # Encrypt the plaintext
    ciphertext = ""
    for char in plaintext:
        if char.isalpha():  # If the character is alphabetic, perform substitution
            ciphertext += key_mapping[char]
        else:  # Non-alphabetic characters remain unchanged in the ciphertext
            ciphertext += char

    return ciphertext


# Decryption function for the mono-alphabetic cipher
def decrypt(ciphertext, key):
    # Inverse the key to create a decryption mapping
    inverse_key = {v: k for k, v in zip(key.upper(), 'ABCDEFGHIJKLMNOPQRSTUVWXYZ')}

    # Decrypt the ciphertext
    plaintext = ""
    for char in ciphertext:
        if char.isalpha():  # If the character is alphabetic, perform substitution
            plaintext += inverse_key[char.upper()]
        else:  # Non-alphabetic characters remain unchanged in the plaintext
            plaintext += char

    return plaintext


def main():
    plain_text = input("Enter the Plain Text: ")
    key_caesar = 4
    key_monoalphabetic = "ZYXWVUTSRQPONMLKJIHGFEDCBA"

    # Ceaser Cipher

    # Encrypt the plain_text using the Caesar cipher with the given key
    caesar_ciphertext = caesar_cipher_encrypt(plain_text, key_caesar)
    print("Plain text message:\n", plain_text)
    print("Encrypted ciphertext using Caesar cipher:\n", caesar_ciphertext)

    # Decrypt the ciphertext back to the original plain_text using the same key
    caesar_decrypted_msg = caesar_cipher_decrypt(caesar_ciphertext, key_caesar)
    print("The decrypted message using Caesar cipher is:\n", caesar_decrypted_msg)

    # Mono-alphabetic Cipher

    # Encrypt the plain_text using the mono-alphabetic cipher with the given key
    monoalphabetic_ciphertext = encrypt(plain_text, key_monoalphabetic)
    print("Encrypted ciphertext using monoalphabetic cipher:\n", monoalphabetic_ciphertext)

    # Decrypt the ciphertext back to the original plain_text using the same key
    monoalphabetic_decrypted_msg = decrypt(monoalphabetic_ciphertext, key_monoalphabetic)
    print("The decrypted message using monoalphabetic cipher is:\n", monoalphabetic_decrypted_msg)


if __name__ == "__main__":
    main()
