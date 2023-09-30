def solve():
    a, b, c = map(int, input().split())
    d = list(map(int, input().split()))
    
    ans = 1
    last = 1
    
    for i in range(b):
        if d[i] != 1:
            pp = d[i] - last
            ans += (pp + c - 1) // c
            last = d[i]
    
    if d[b - 1] != a:
        pp = a - last
        ans += (pp + c - 1) // c
    
    ansf = float('inf')
    ansf1 = 0
    
    for i in range(b):
        ans1 = ans
        
        if d[i] == 1:
            continue
        
        if i == b - 1:
            if d[b - 1] != a:
                pp = d[i] - last
                ans1 -= (pp + c - 1) // c
                pp = a - d[i]
                ans1 -= (pp + c - 1) // c
                pp = a - last
                ans1 += (pp + c - 1) // c
                ansf = min(ansf, ans1)
                last = d[i]
                continue
            
            ansf = min(ansf, ans1 - 1)
            last = d[i]
            continue
        
        pp = d[i] - last
        ans1 -= (pp + c - 1) // c
        pp = d[i + 1] - d[i]
        ans1 -= (pp + c - 1) // c
        pp = d[i + 1] - last
        ans1 += (pp + c - 1) // c
        ansf = min(ansf, ans1)
        last = d[i]
    
    last = 1
    for i in range(b):
        ans1 = ans
        
        if d[i] == 1:
            continue
        
        if i == b - 1:
            if d[b - 1] != a:
                pp = d[i] - last
                ans1 -= (pp + c - 1) // c
                pp = a - d[i]
                ans1 -= (pp + c - 1) // c
                pp = a - last
                ans1 += (pp + c - 1) // c
                
                if ansf == ans1:
                    ansf1 += 1
                last = d[i]
                continue
            
            if ans1 - 1 == ansf:
                ansf1 += 1
            
            last = d[i]
            continue
        
        pp = d[i] - last
        ans1 -= (pp + c - 1) // c
        pp = d[i + 1] - d[i]
        ans1 -= (pp + c - 1) // c
        pp = d[i + 1] - last
        ans1 += (pp + c - 1) // c
        
        if ans1 == ansf:
            ansf1 += 1
        
        last = d[i]
    
    print(ansf, ansf1)

def main():
    t = int(input())
    for _ in range(t):
        solve()

if __name__ == "__main__":
    main()
