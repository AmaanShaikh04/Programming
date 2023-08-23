"""
Experiment No 4
Author: Amaan Shaikh
Branch: TYCSE-A
PRN: 1032221184
File name: Amaan_Shaikh_ICS_ExperimentNo4.py
"""

# Write a program using JAVA or Python or C++ to implement RSA Asymmetric
# Key generation
# Encryption
# Decryption

import math

# Function to generate RSA key pair (public key and private key)
def generate_keypair(p, q):
    n = p * q
    phi = (p - 1) * (q - 1)

    # Find an appropriate public exponent 'e'
    for i in range(2, phi):
        if math.gcd(phi, i) == 1:
            e = i
            break

    # Find the corresponding private exponent 'd'
    for j in range(e):
        d = (1 + (j * phi)) / e
        if d.is_integer():
            k = j
            break

    return ((n, e), (n, d))

# Function to perform encryption using public key
def encrypt(public_key, plaintext):
    n, e = public_key
    ciphertext = (plaintext ** e) % n
    return ciphertext

# Function to perform decryption using private key
def decrypt(private_key, ciphertext):
    n, d = private_key
    decrypted_text = (ciphertext ** d) % n
    return decrypted_text

# Main program
def main():
    print("Enter two prime numbers")
    p = int(input("p: "))
    q = int(input("q: "))

    # Generate RSA key pair
    public_key, private_key = generate_keypair(p, q)
    print("Public Key (n, e):", public_key)
    print("Private Key (n, d):", private_key)

    # Get the plain text from the user
    while True:
        M = int(input("Enter plain text: "))
        if M >= public_key[0]:
            print("M should be less than n")
        else:
            print("Plain Text:", M)
            break

    # Encrypt the plain text using the public key
    C = encrypt(public_key, M)
    print("Cipher Text:", C)

    # Decrypt the cipher text using the private key
    m = decrypt(private_key, C)
    print("Decrypted Text:", m)

if __name__ == "__main__":
    main()
