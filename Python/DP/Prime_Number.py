def is_prime(num):
    if num < 2:
        return False
    for i in range(2, int(num ** 0.5) + 1):
        if num % i == 0:
            return False
    return True

def generate_prime_numbers(limit):
    prime_numbers = []
    for num in range(2, limit + 1):
        if is_prime(num):
            prime_numbers.append(num)
    return prime_numbers

limit = int(input("Enter the limit: "))
prime_numbers = generate_prime_numbers(limit)
print("Prime numbers up to", limit, "are:", prime_numbers)