# D - Flipping Signs 
import sys

N = int(input())
A = list(map(int, sys.stdin.readline().strip().split()))

pm = 0
min_a = 10 ** 9
total = 0
for a in A:
    min_a = min(min_a, abs(a))
    total += abs(a)
    if a < 0:
        pm += 1

# print(f'min_a: {min_a} total: {total}')
if pm % 2 != 0:
    # print(f'pm: {pm}')
    total -= min_a * 2

print(total)
