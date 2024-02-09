import itertools
import argparse
import concurrent.futures


def generate_passwords(length, characters):
      passwords = []
      for combination in itertools.product(characters, repeat=length):
            passwords.append("".join(combination))
      return passwords


def write_to_file(passwords, output_file):
      with open(output_file, "a") as file:
            for password in passwords:
                  file.write(password + "\n")


def generate_wordlist(characters, min_length, max_length, output_file):
      with concurrent.futures.ProcessPoolExecutor() as executor:
            passwords = list(itertools.chain.from_iterable(
                  executor.map(generate_passwords, range(min_length, max_length + 1), itertools.repeat(characters))))

            write_to_file(passwords, output_file)

      print("Wordlist generated successfully!")


if __name__ == "__main__":
      parser = argparse.ArgumentParser(description="Wordlist Generator")
      parser.add_argument("--characters", type=str, default="abcdefghijklmnopqrstuvwxyz0123456789",
                          help="Characters used in the wordlist")
      parser.add_argument("--min_length", type=int, default=8,
                          help="Minimum password length")
      parser.add_argument("--max_length", type=int, default=8,
                          help="Maximum password length")
      parser.add_argument("--output_file", type=str, default="wordlist.txt",
                          help="Output file name to save the wordlist")
      args = parser.parse_args()

      characters = args.characters + "!@#$%^&*"  # special characters
      generate_wordlist(characters, args.min_length, args.max_length, args.output_file)
