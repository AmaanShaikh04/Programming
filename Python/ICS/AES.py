# Import necessary modules and classes
from cryptography.hazmat.primitives.ciphers import Cipher, algorithms, modes
from cryptography.hazmat.backends import default_backend
from cryptography.hazmat.primitives.ciphers.modes import ECB
from cryptography.hazmat.primitives.padding import PKCS7
import os

# Function to generate round keys
def generate_round_keys(key):
    backend = default_backend()
    cipher = Cipher(algorithms.AES(key), ECB(), backend=backend)
    encryptor = cipher.encryptor()
    round_keys = [key]
    for _ in range(10):
        key = encryptor.update(key)
        round_keys.append(key)
    return round_keys

# Function to perform AES encryption
def perform_encryption(key, plaintext):
    backend = default_backend()
    cipher = Cipher(algorithms.AES(key), ECB(), backend=backend)
    encryptor = cipher.encryptor()
    padder = PKCS7(algorithms.AES.block_size).padder()
    plaintext_padded = padder.update(plaintext) + padder.finalize()
    ciphertext = encryptor.update(plaintext_padded) + encryptor.finalize()
    return ciphertext

# Take input from the user
plaintext = input("Enter the plaintext: ").encode()

# Generate a random key
key = os.urandom(16)

# Generate the round keys using the function
round_keys = generate_round_keys(key)

# Print the round keys in matrix format
print("Round Keys:")
for i, round_key in enumerate(round_keys):
    print(f"\nRound {i}:")
    # Display the round key bytes in matrix format
    for j in range(0, len(round_key), 4):
        print(" ".join(f"{byte:02X}" for byte in round_key[j:j+4]))

# Perform AES encryption using the function
ciphertext = perform_encryption(key, plaintext)

# Print the encrypted text
print("\nEncrypted Text:", ciphertext.hex())
