def diffie_hellman(q, a, xa, xb):
    # Calculate public keys
    ya = (a ** xa) % q
    yb = (a ** xb) % q

    # Calculate secret keys
    ka = (yb ** xa) % q
    kb = (ya ** xb) % q

    return ka, kb

if __name__ == "__main__":
    # Given parameters
    q = 23
    a = 5
    xa = 6
    xb = 15

    # Perform Diffie-Hellman key exchange
    secret_key_a, secret_key_b = diffie_hellman(q, a, xa, xb)

    # Display results
    print("A's Secret Key:", secret_key_a)
    print("B's Secret Key:", secret_key_b)
