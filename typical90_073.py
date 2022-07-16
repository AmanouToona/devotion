import sys

MOD = 10 ** 9 + 7


def main():
    N = int(input())
    c = list(sys.stdin.readline().strip().split())

    g = [[] for _ in range(N)]
    for _ in range(N - 1):
        a, b = map(int, sys.stdin.readline().strip().split())
        a -= 1
        b -= 1
        g[a].append(b)
        g[b].append(a)

    dp = [[0] * 3 for _ in range(N)]  # dp[頂点][abの組み合わせ] 0: aのみ 1:bのみ 2: a, b 両方

    def dfs(u, p):
        val_1 = 1
        val_2 = 1
        for v in g[u]:
            if v == p:
                continue
            dfs(v, u)

            if c[u] == "a":
                val_1 *= dp[v][0] + dp[v][2]
                val_2 *= dp[v][0] + dp[v][1] + 2 * dp[v][2]
            else:
                val_1 *= dp[v][1] + dp[v][2]
                val_2 *= dp[v][0] + dp[v][1] + 2 * dp[v][2]

            val_1 %= MOD
            val_2 %= MOD

        if c[u] == "a":
            dp[u][0] = val_1
            dp[u][1] = 0
            dp[u][2] = val_2 - val_1 + MOD
        else:
            dp[u][0] = 0
            dp[u][1] = val_1
            dp[u][2] = val_2 - val_1 + MOD

        dp[u][0] %= MOD
        dp[u][1] %= MOD
        dp[u][2] %= MOD

        return

    dfs(0, -1)
    print(dp[0][2])

    return


if __name__ == "__main__":
    main()
