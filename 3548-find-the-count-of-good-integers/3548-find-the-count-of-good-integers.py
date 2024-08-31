import math
from typing import List, Set

class Solution:
    def __init__(self):
        self.factorial_arr = [1] * 11
        for i in range(1, 11):
            self.factorial_arr[i] = self.factorial_arr[i - 1] * i
    
    def countGoodIntegers(self, n: int, k: int) -> int:
        palindromes = self.generate_palindromes(n)
        valid_palindromes = [p for p in palindromes if p % k == 0]
        
        unique_digit_freq: Set[tuple] = set()
        for palindrome in valid_palindromes:
            digit_freq = self.count_digits(palindrome, n)
            unique_digit_freq.add(tuple(digit_freq))
        
        total_good_integers = 0
        for digit_freq in unique_digit_freq:
            total_good_integers += self.calculate_permutations(list(digit_freq), n)
        
        return total_good_integers
    
    def generate_palindromes(self, digit_count: int) -> List[int]:
        palindrome_list = []
        if digit_count == 0:
            return palindrome_list
        
        half_len = (digit_count + 1) // 2
        start_num = 10**(half_len - 1)
        end_num = 10**half_len - 1
        
        if digit_count == 1:
            start_num = 0
        
        for first_half in range(start_num, end_num + 1):
            half_str = str(first_half)
            if digit_count % 2 == 0:
                full_palindrome = half_str + half_str[::-1]
            else:
                full_palindrome = half_str + half_str[:-1][::-1]
            
            if len(full_palindrome) == digit_count:
                palindrome_list.append(int(full_palindrome))
        
        return palindrome_list
    
    def count_digits(self, number: int, digit_count: int) -> List[int]:
        digit_freq = [0] * 10
        num_str = str(number).zfill(digit_count)
        
        for digit in num_str:
            digit_freq[int(digit)] += 1
        
        return digit_freq
    
    def calculate_permutations(self, digit_freq: List[int], digit_count: int) -> int:
        permutation_count = 0
        for digit in range(1, 10):
            if digit_freq[digit] == 0:
                continue
            
            adjusted_freq = digit_freq[:]
            adjusted_freq[digit] -= 1
            
            if any(freq < 0 for freq in adjusted_freq):
                continue
            
            valid_permutations = self.factorial_arr[digit_count - 1]
            for freq in adjusted_freq:
                valid_permutations //= self.factorial_arr[freq]
            
            permutation_count += valid_permutations
        
        return permutation_count
