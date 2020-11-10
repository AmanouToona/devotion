import sys

N = int(input())
A = list(map(int, sys.stdin.readline().strip().split()))

ans = 0
left = 0
right = 1

while right <= N:
    if right == N or A[right - 1] >= A[right]:
        n = right - left + 1
        ans += (n * (n - 1)) // 2

        left = right
    right += 1


print(ans)
