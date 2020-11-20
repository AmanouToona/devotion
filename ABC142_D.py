import sys
import math

"""
917861648772 917861648772
"""


A, B = map(int, sys.stdin.readline().strip().split())

gcd = math.gcd(A, B)

cds = [1, gcd]
for i in range(2, int(math.sqrt(gcd)) + 1):
    if gcd % i == 0:
        cds.append(i)
        cds.append(gcd // i)

cds = list(set(cds))

# cds = [1, ... ]
cds.sort()

tf = [True] * len(cds)
for i in range(1, len(cds)):
    if tf[i] is False:
        continue
    for j in range(i + 1, len(cds)):
        if cds[j] % cds[i] == 0:
            tf[j] = False

# print(f'cds: {cds}  tf: {tf}')

print(sum(tf))
