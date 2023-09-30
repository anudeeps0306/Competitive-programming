def min_moves(n, s, d):
    farthest = 0
    moves = 0
    for i in range(n):
        if s[i] == 'B':
            if i > farthest:
                j = i + 1
                while j < n and j <= i + d[i]:
                    if s[j] == 'R':
                        farthest = j
                    j += 1
                if farthest <= i:
                    return -1
                moves += 1
                farthest = i + 2*d[i] + 1 if i + 2*d[i] + 1 > farthest else farthest
    return moves


t = int(input())
for _ in range(t):
    n = int(input())
    s = input().strip()
    d = list(map(int, input().strip().split()))
    print(min_moves(n, s, d))
