def palindrome_substrings(digits):
    n = len(digits)
    result = 0

    # Helper function to check if a number can be a permutation of a palindrome
    def is_palindrome(num):
        freq = {}
        for digit in str(num):
            freq[digit] = freq.get(digit, 0) + 1
        odd_freq_count = 0
        for count in freq.values():
            if count % 2 == 1:
                odd_freq_count += 1
            if odd_freq_count > 1:
                return False
        return True

    # Iterate over all possible substrings
    for i in range(n):
        for j in range(i+1, n+1):
            # Check if the substring can be a permutation of a palindrome
            if is_palindrome(digits[i:j]):
                result += 1

    return result


n=input()
print(palindrome_substrings(n))
