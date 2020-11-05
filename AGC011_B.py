import sys

N = int(input())
A = list(map(int, sys.stdin.readline().strip().split()))

A.sort()

cusum_A = A
for i in range(N - 1):
    cusum_A[i + 1] += cusum_A[i]

# print(cusum_A)

min_n = 0
for i in range(N - 1):
    if A[i + 1] - A[i] > 2 * A[i]:
        min_n = i + 1

ans = N - min_n
print(ans)
