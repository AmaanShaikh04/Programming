import os

# Padding function to ensure data size is a multiple of block size
def pad_data(data, block_size):
    padding_len = block_size - (len(data) % block_size)
    padder = bytearray(data)
    padder.extend(bytes([padding_len] * padding_len))
    return bytes(padder)

# Perform XOR operation between two byte strings
def xor_bytes(a, b):
    return bytes(x ^ y for x, y in zip(a, b))

# Encrypt using the Electronic Codebook (ECB) mode
def encrypt_ecb(key, plaintext):
    block_size = 16  # AES block size
    padded_data = pad_data(plaintext, block_size)
    num_blocks = len(padded_data) // block_size
    cipher_text = b""
    for i in range(num_blocks):
        block = padded_data[i * block_size: (i + 1) * block_size]
        encrypted_block = xor_bytes(block, key)
        cipher_text += encrypted_block
    return cipher_text

# Encrypt using the Cipher Block Chaining (CBC) mode
def encrypt_cbc(key, iv, plaintext):
    block_size = 16  # AES block size
    padded_data = pad_data(plaintext, block_size)
    num_blocks = len(padded_data) // block_size
    cipher_text = b""
    previous_block = iv
    for i in range(num_blocks):
        block = padded_data[i * block_size: (i + 1) * block_size]
        xor_input = xor_bytes(block, previous_block)
        encrypted_block = xor_bytes(xor_input, key)
        cipher_text += encrypted_block
        previous_block = encrypted_block
    return cipher_text

# Encrypt using the Cipher Feedback (CFB) mode
def encrypt_cfb(key, iv, plaintext):
    block_size = 16  # AES block size
    cipher_text = b""
    previous_block = iv
    for byte in plaintext:
        encrypted_block = xor_bytes(previous_block, key)
        cipher_output = xor_bytes(encrypted_block, bytes([byte]))  # Encrypt one byte at a time
        cipher_text += cipher_output
        previous_block = cipher_output
    return cipher_text

# Encrypt using the Output Feedback (OFB) mode
def encrypt_ofb(key, iv, plaintext):
    block_size = 16  # AES block size
    cipher_text = b""
    previous_block = iv
    for byte in plaintext:
        encrypted_block = xor_bytes(previous_block, key)
        keystream_byte = xor_bytes(encrypted_block, bytes([byte]))  # Encrypt one byte at a time
        cipher_text += keystream_byte
        previous_block = encrypted_block
    return cipher_text

# Encrypt using the Counter (CTR) mode
def encrypt_ctr(key, iv, plaintext):
    block_size = 16  # AES block size
    cipher_text = b""
    counter = int.from_bytes(iv, byteorder="big")
    for byte in plaintext:
        counter_block = counter.to_bytes(block_size, byteorder="big")
        encrypted_counter = xor_bytes(counter_block, key)
        cipher_output = xor_bytes(encrypted_counter, bytes([byte]))  # Encrypt one byte at a time
        cipher_text += cipher_output
        counter += 1
    return cipher_text


# Main program
key = os.urandom(16)  # Generate a random 128-bit key
iv = os.urandom(16)   # Generate a random 128-bit IV
plaintext = b"Amaan 123 Shaikh."

print("Plain text:", plaintext)

print("Key: ",key)
print("IV: ",iv)

ecb_ciphertext = encrypt_ecb(key, plaintext)
print("ECB ciphertext:", ecb_ciphertext)

cbc_ciphertext = encrypt_cbc(key, iv, plaintext)
print("CBC ciphertext:", cbc_ciphertext)

cfb_ciphertext = encrypt_cfb(key, iv, plaintext)
print("CFB ciphertext:", cfb_ciphertext)

ofb_ciphertext = encrypt_ofb(key, iv, plaintext)
print("OFB ciphertext:", ofb_ciphertext)

ctr_ciphertext = encrypt_ctr(key, iv, plaintext)
print("CTR ciphertext:", ctr_ciphertext)