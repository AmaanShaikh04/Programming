import gnupg

def generate_key_pair(gpg):
    input_data = gpg.gen_key_input(
        key_type="RSA",
        key_length=1024,
        name_real="Test User",
        name_email="test@example.com",
        passphrase="passphrase"
    )
    key = gpg.gen_key(input_data)
    return key.fingerprint

def encrypt_message(gpg, message, recipient_key):
    encrypted_data = gpg.encrypt(message, recipient_key, always_trust=True)
    return encrypted_data.data

def decrypt_message(gpg, encrypted_message):
    decrypted_data = gpg.decrypt(encrypted_message)
    return decrypted_data.data

def sign_file(gpg, file_path):
    signature = gpg.sign_file(open(file_path, "rb"), detach=True, passphrase="passphrase")
    return signature

def verify_signature(gpg, file_path, signature):
    verified = gpg.verify_file(open(file_path, "rb"), signature)
    return verified.valid

def main():
    gpg = gnupg.GPG()

    # Generate key pair
    key_fingerprint = generate_key_pair(gpg)
    print(f"Key pair generated with fingerprint: {key_fingerprint}")

    # Encrypt and decrypt a message
    original_message = "This is a secret message."
    encrypted_message = encrypt_message(gpg, original_message, key_fingerprint)
    decrypted_message = decrypt_message(gpg, encrypted_message)

    print(f"Original Message: {original_message}")
    print(f"Encrypted Message: {encrypted_message}")
    print(f"Decrypted Message: {decrypted_message}")

    # Sign and verify a file
    file_to_sign = "example.txt"
    with open(file_to_sign, "w") as file:
        file.write("File content to sign.")

    signature = sign_file(gpg, file_to_sign)
    verification_result = verify_signature(gpg, file_to_sign, signature)

    print(f"File Signature: {signature}")
    print(f"Signature Verification Result: {verification_result}")

if __name__ == "__main__":
    main()
