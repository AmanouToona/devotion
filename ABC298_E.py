import sys

MOD = 998244353


def main():
    N, A, B, P, Q = map(int, sys.stdin.readline().strip().split())

    # 配るdp の確率遷移で解ける
    dp = [[0] * (N + 1) for _ in range(N + 1)]  # dp[高橋君の位置][青木君の位置] となる確率
    dp[A][B] = 1

    inv_p = pow(P, MOD - 2, MOD)
    inv_q = pow(Q, MOD - 2, MOD)

    for a in range(N):
        for b in range(N):
            for p in range(1, P + 1):
                for q in range(1, Q + 1):
                    dp[min(N, a + p)][min(N, b + q)] += dp[a][b] * inv_p * inv_q
                    dp[min(N, a + p)][min(N, b + q)] %= MOD
    print(sum(dp[N]) % MOD)

    return


if __name__ == "__main__":
    main()
