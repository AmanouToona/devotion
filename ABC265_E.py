import sys

MOD = 998244353


def main():
    N, M = map(int, sys.stdin.readline().strip().split())
    A, B, C, D, E, F = map(int, sys.stdin.readline().strip().split())

    obstacles = set()
    for _ in range(M):
        x, y = map(int, sys.stdin.readline().strip().split())
        obstacles |= set([(x, y)])

    # dp[n][x][y] != n回移移動 ワープ1をx回 ワープ2をy回 した時の移動経路数
    dp = [[[0] * (N + 1) for _ in range(N + 1)] for _ in range(N + 1)]
    dp[0][0][0] = 1

    # 配る dp
    for n in range(N):
        for x in range(n + 1):
            for y in range(n + 1):
                ux = A * x + C * y + E * (n - x - y)
                uy = B * x + D * y + F * (n - x - y)
                # 移動1
                if (ux + A, uy + B) not in obstacles:
                    dp[n + 1][x + 1][y] += dp[n][x][y]
                    dp[n + 1][x + 1][y] %= MOD

                # 移動2
                if (ux + C, uy + D) not in obstacles:
                    dp[n + 1][x][y + 1] += dp[n][x][y]
                    dp[n + 1][x][y + 1] %= MOD

                # 移動3
                if (ux + E, uy + F) not in obstacles:
                    dp[n + 1][x][y] += dp[n][x][y]
                    dp[n + 1][x][y] %= MOD

    ans = 0
    for x in range(N + 1):
        for y in range(N + 1):
            ans += dp[N][x][y]
            ans %= MOD

    print(ans)

    return


if __name__ == "__main__":
    main()
