# A - 掲示板 
import sys

N, M = map(int, sys.stdin.readline().strip().split())

A = [[0, n + 1] for n in range(N)]
for m in range(1, M + 1):
    a = int(input())
    a -= 1

    A[a][0] = m

A.sort(key=lambda x: x[0], reverse=True)

for a in A:
    print(a[1])
