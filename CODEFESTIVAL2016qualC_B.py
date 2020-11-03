import sys

K, T = map(int, sys.stdin.readline().strip().split())
a = list(map(int, sys.stdin.readline().strip().split()))

a = max(a)

if a <= (K + 1) // 2:
    print(0)
    sys.exit()

if K % 2 != 0:
    print(2 * (a - K // 2))
else:
    print(2 * ((a - 1 - K // 2)) + 1)