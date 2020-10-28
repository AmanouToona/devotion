# B - おとぎの国の高橋君
import sys

b = list(map(int, sys.stdin.readline().strip().split()))
N = int(input())

converter = {}
for i in range(10):
    converter[str(b[i])] = i

A = []
for n in range(N):
    a = str(int(input()))

    num = 0
    for i in range(1, len(a) + 1):
        num += int(converter[a[-i]]) * 10 ** i
    A.append((num, a))

A.sort(key=lambda x: x[0])
for a in A:
    print(a[1])
