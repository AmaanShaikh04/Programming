from random import randint

def generate_key(p, g, private_key):
    public_key = (g ** private_key) % p
    return public_key

def generate_shared_secret(public_key, private_key, p):
    shared_secret = (public_key ** private_key) % p
    return shared_secret

# Choose large prime numbers for p and g
p = 23
g = 5

# Amaan's private key
private_key_amaan = randint(1, 10)

# Raj's private key
private_key_raj = randint(1, 10)

# Generate public keys
public_key_amaan = generate_key(p, g, private_key_amaan)
public_key_raj = generate_key(p, g, private_key_raj)

# Exchange public keys

# Amaan receives Bob's public key and computes the shared secret
shared_secret_amaan = generate_shared_secret(public_key_raj, private_key_amaan, p)

# Raj receives Alice's public key and computes the shared secret
shared_secret_raj = generate_shared_secret(public_key_amaan, private_key_raj, p)

# Print the results
print("Amaan's private key:", private_key_amaan)
print("Amaan's public key:", public_key_amaan)
print("\nRaj's private key:", private_key_raj)
print("Raj's public key:", public_key_raj)
print("\nShared Secret (Amaan):", shared_secret_amaan)
print("Shared Secret (Raj):", shared_secret_raj)
