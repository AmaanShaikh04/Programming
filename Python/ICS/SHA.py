import hashlib
from cryptography.fernet import Fernet


def calculate_sha1_hash(input_string):
      sha1 = hashlib.sha1()
      sha1.update(input_string.encode('utf-8'))
      hash_result = sha1.hexdigest()
      return hash_result


def decrypt_with_fernet(cipher_suite, encrypted_text):
      decrypted_text = cipher_suite.decrypt(encrypted_text)
      return decrypted_text.decode('utf-8')


if __name__ == "__main__":
      input_string = "This is SHA-1 algo"

      # Calculate SHA-1 hash
      sha1_hash = calculate_sha1_hash(input_string)
      print("SHA-1 Hash:", sha1_hash)

      # Encryption and Decryption with Fernet
      key = Fernet.generate_key()
      cipher_suite = Fernet(key)
      encrypted_text = cipher_suite.encrypt(sha1_hash.encode('utf-8'))

      decrypted_text = decrypt_with_fernet(cipher_suite, encrypted_text)

      print("Decrypted Text:", decrypted_text)
