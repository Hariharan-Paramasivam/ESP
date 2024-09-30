def Prime_numbers(n):
    prime_numbers = []
    for num in range(2, n + 1):
        if all(num % i != 0 for i in range(2, num)):
            prime_numbers.append(num)
    return prime_numbers