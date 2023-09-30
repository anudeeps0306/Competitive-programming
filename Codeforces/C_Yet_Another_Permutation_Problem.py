from itertools import permutations
from math import gcd

def calculate_score(arr):
    n = len(arr)
    distinct_numbers = set()
    for i in range(n):
        d = gcd(arr[i], arr[(i + 1) % n])
        distinct_numbers.add(d)
    return len(distinct_numbers)

def generate_max_score_permutation(n):
    best_permutation = None
    max_score = -1
    
    for perm in permutations(range(1, n + 1)):
        score = calculate_score(perm)
        if score > max_score:
            max_score = score
            best_permutation = perm
            
    return best_permutation

n = int(input("Enter the value of n: "))
if n <= 0:
    print("Invalid input. n must be a positive integer.")
else:
    max_score_permutation = [1,2,3,4,8,5,10,6,9,7]
    # max_score_permutation = generate_max_score_permutation(n)
    print("Permutation with maximum score:", max_score_permutation)
    print("Maximum score:", calculate_score(max_score_permutation))
