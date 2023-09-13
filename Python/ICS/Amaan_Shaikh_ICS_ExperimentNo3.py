"""
Experiment No 3
Author: Amaan Shaikh
Branch: TYCSE-A
PRN: 1032221184
File name: Amaan_Shaikh_ICS_ExperimentNo3.py
"""


# Write a program using Java or Python or C++ to implement RSA Asymmetric using Libraries

from cryptography.hazmat.primitives.asymmetric import rsa, padding
from cryptography.hazmat.primitives import serialization, hashes

# Generate RSA key pair using the library
private_key = rsa.generate_private_key(
    public_exponent=65537,
    key_size=2048
)
public_key = private_key.public_key()

# Convert keys to PEM format using the library
private_pem = private_key.private_bytes(
    encoding=serialization.Encoding.PEM,
    format=serialization.PrivateFormat.PKCS8,
    encryption_algorithm=serialization.NoEncryption()
)
public_pem = public_key.public_bytes(
    encoding=serialization.Encoding.PEM,
    format=serialization.PublicFormat.SubjectPublicKeyInfo
)

# Print the keys in PEM format
print("Private Key (PEM format):")
print(private_pem.decode())
print("\nPublic Key (PEM format):")
print(public_pem.decode())

# Encrypt and decrypt a message using the library
message = b"Amaan Shaikh RSA Test"
print("Plain Text:")
print(message.decode())

# Encrypt the message using the public key and padding scheme from the library
ciphertext = public_key.encrypt(
    message,
    padding.OAEP(
        mgf=padding.MGF1(algorithm=hashes.SHA256()),
        algorithm=hashes.SHA256(),
        label=None
    )
)
print("\nEncrypted Message:")
print(ciphertext.hex())

# Decrypt the message using the private key and padding scheme from the library
decrypted_message = private_key.decrypt(
    ciphertext,
    padding.OAEP(
        mgf=padding.MGF1(algorithm=hashes.SHA256()),
        algorithm=hashes.SHA256(),
        label=None
    )
)
print("\nDecrypted Message:")
print(decrypted_message.decode())

# Store the keys, plain text, encrypted/decrypted text in a text file
with open("rsa_output.txt", "w") as file:
    file.write("\n\nPrivate Key (PEM format):\n")
    file.write(private_pem.decode())
    file.write("\n\nPublic Key (PEM format):\n")
    file.write(public_pem.decode())
    file.write("\n\nPlain Text:\n")
    file.write(message.decode())
    file.write("\n\nEncrypted Message:\n")
    file.write(ciphertext.hex())
    file.write("\n\nDecrypted Message:\n")
    file.write(decrypted_message.decode())

print("Output has been saved to rsa_output.txt file.")