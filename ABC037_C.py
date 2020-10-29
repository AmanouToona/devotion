# C - 総和 
import sys

N, K = map(int, sys.stdin.readline().strip().split())
A = list(map(int, sys.stdin.readline().strip().split()))

left = 0
right = K
tot = sum(A[: right])
ans = tot

for i in range(N - K):
    tot += A[right] - A[left]
    ans += tot
    right += 1
    left += 1

print(ans)
