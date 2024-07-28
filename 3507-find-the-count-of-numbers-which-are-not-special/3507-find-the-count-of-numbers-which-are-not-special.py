def sieve_of_eratosthenes(n):
    is_prime = [True] * (n + 1)
    p = 2
    while (p * p <= n):
        if (is_prime[p] == True):
            for i in range(p * p, n + 1, p):
                is_prime[i] = False
        p += 1
    return [p for p in range(2, n + 1) if is_prime[p]]

def count(l, r):
    upper_bound = int(math.sqrt(r)) + 1
    primes = sieve_of_eratosthenes(upper_bound)
    
    special_numbers = set()
    for p in primes:
        square = p * p
        if l <= square <= r:
            special_numbers.add(square)
    
    total_numbers = r - l + 1
    nscount = total_numbers - len(special_numbers)
    
    return nscount

class Solution:
    def nonSpecialCount(self, l: int, r: int) -> int:
        return count(l,r)
        