# C - Special Trains
import sys

N = int(input())

C = []
S = []
F = []
for n in range(N - 1):
    c, s, f = map(int, sys.stdin.readline().strip().split())
    C.append(c)
    S.append(s)
    F.append(f)

for i in range(N):
    ans = 0
    for j in range(i, N - 1):
        if ans <= S[j]:
            ans = S[j] + C[j]
        else:
            wait = ans % F[j]
            ans += wait + C[j]
        
    print(ans)
