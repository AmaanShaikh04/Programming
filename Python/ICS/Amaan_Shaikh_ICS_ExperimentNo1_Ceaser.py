"""
Experiment No 1
Author: Amaan Shaikh
Branch: TYCSE-A
File name: Amaan_Shaikh_ICS_ExperimentNo1_Ceaser.py
"""


# Write a program using Java or Python or C++ to implement any classical cryptographic technique (ceaser cipher)

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


def main():
    plain_text = input("Enter the Plain Text: ")
    key = 4

    # Encrypt the plain_text using the Caesar cipher with the given key
    ciphertext = caesar_cipher_encrypt(plain_text, key)
    print("Plain text message:\n", plain_text)
    print("Encrypted ciphertext:\n", ciphertext)

    # Decrypt the ciphertext back to the original plain_text using the same key
    decrypted_msg = caesar_cipher_decrypt(ciphertext, key)
    print("The decrypted message is:\n", decrypted_msg)


if __name__ == "__main__":
    main()