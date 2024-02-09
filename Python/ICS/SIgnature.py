from Crypto.PublicKey import RSA
from Crypto.Signature import pkcs1_15
from Crypto.Hash import SHA256

def generate_key_pair():
    key = RSA.generate(2048)
    private_key = key.export_key()
    public_key = key.publickey().export_key()
    return private_key, public_key

def sign_message(private_key, message):
    key = RSA.import_key(private_key)
    hashed_message = SHA256.new(message.encode())
    signature = pkcs1_15.new(key).sign(hashed_message)
    return signature

def verify_signature(public_key, message, signature):
    key = RSA.import_key(public_key)
    hashed_message = SHA256.new(message.encode())
    try:
        pkcs1_15.new(key).verify(hashed_message, signature)
        return True
    except ValueError:
        return False

if __name__ == "__main__":
    # Example usage
    private_key, public_key = generate_key_pair()
    message = input("Enter Your Message: ")
    signature = sign_message(private_key, message)

    print("Signature:", signature)
    is_verified = verify_signature(public_key, message, signature)
    print("Signature verified:", is_verified)
