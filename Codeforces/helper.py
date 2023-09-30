

def can_rearrange_to_palindrome(s, queries):
    def is_palindrome_possible(substring, substitutions):
        char_count = {}

        for char in substring:

        char_count[char] = char_count.get(char, 0) + 1

        odd_count = 0

        for count in char_count.values():

        if count % 2 != 0:

        odd_count += 1

# If odd_count is greater than substitutions, it's not possible to form a palindrome.

return odd_count <= substitutions

results = []

for query in queries:

start, end, substitutions = query

substring = s[start - 1:end] # Adjust indices to be 0-based

if is_palindrome_possible(substring, substitutions):

results.append("YES")

else:

results.append("NO")

return results

# Example usage:

s = "abba"

queries = [(1, 4, 0), (1, 4, 1), (1, 4, 2)]

results = can_rearrange_to_palindrome(s, queries)

print(results) # Output: ['YES', 'YES', 'YES']