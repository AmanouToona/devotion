import sys

sys.setrecursionlimit(10 ** 8)


N = int(input())
A = list(map(int, sys.stdin.readline().strip().split()))

# [x][y][z]: x: 1個 y: 2個 z: 3個 のっている皿の個数 から 000 に持っていくときの期待値
dp = [[[-1] * 301 for _ in range(301)] for _ in range(301)]

dp[0][0][0] = 0


def solve(x, y, z):
    if dp[x][y][z] != -1:
        return dp[x][y][z]

    res = 0
    if x > 0:
        res += solve(x - 1, y, z) * x
    if y > 0:
        res += solve(x + 1, y - 1, z) * y
    if z > 0:
        res += solve(x, y + 1, z - 1) * z

    res += N

    res /= x + y + z

    dp[x][y][z] = res

    return res


one = 0
two = 0
three = 0

for a in A:
    if a == 1:
        one += 1
    elif a == 2:
        two += 1
    else:
        three += 1

print(solve(one, two, three))
