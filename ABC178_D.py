# D - Redistribution
import sys
mod = 10 ** 9 + 7

S = int(input())

if S <= 2:
    print(0)
    sys.exit()

dp = [0] * S
dp[2] = 1

for i in range(3, S):
    dp[i] = (dp[i - 3] + dp[i - 1]) % mod

print(dp[-1])

