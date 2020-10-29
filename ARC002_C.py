# C - コマンド入力
import sys

N = int(input())
C = str(sys.stdin.readline().strip())

button = ['A', 'B', 'X', 'Y']

LR = []
for i in button:
    for j in button:
        LR.append(i + j)


counts = []
for L in LR:
    dp = [0] * (N + 1)
    for R in LR:
        if L == R:
            continue
        
        for n in range(1, N):
            if C[n - 1 : n + 1] in [L, R]:
                dp[n + 1] = max(dp[n - 1] + 1, dp[n])
            else:
                dp[n + 1] = max(dp[n - 1], dp[n])
        
        counts.append(dp[-1])

ans = N - max(counts)

print(ans)
