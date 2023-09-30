t=int(input())
for i in range(0,t):
    n=int(input())
    s = input() 

    
    dp = [[0] * n for _ in range(n)]

    for i in range(n):
        dp[i][i] = 1

    for L in range(2, n+1):
        for i in range(n-L+1):
            j = i + L - 1
            if s[i] == s[j]:
                dp[i][j] = dp[i+1][j-1]
            else:
                dp[i][j] = dp[i+1][j] + dp[i][j-1] - dp[i+1][j-1]

    print(dp[0][n-1])


