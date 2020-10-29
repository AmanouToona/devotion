# D - Binomial Coefficients 
import sys

n = int(input())
A = list(map(int, sys.stdin.readline().strip().split()))

a_max = max(A)
a_half = A[0]
for a in A:
    if abs(a - a_max * 0.5) <= abs(a_half - a_max * 0.5):
        a_half = a

print(a_max, a_half)


