import sys


MOD = 998244353


def main():
    N = int(sys.stdin.readline().strip())

    div = [0] * 3  # N の素因数分解 [2, 3, 5] の個数
    for i, j in enumerate([2, 3, 5]):
        while N % j == 0:
            N //= j
            div[i] += 1

    if N != 1:
        print(0)
        return

    # 貰うdp
    dp = [[[0] * 60 for _ in range(60)] for _ in range(60)]
    dp[0][0][0] = 1

    inv_5 = pow(5, MOD - 2, MOD)

    def solve(two, three, five):
        if two < 0 or three < 0 or five < 0:
            return dp[two][three][five]

        if dp[two][three][five] != 0:
            return dp[two][three][five]

        #

        # 2
        dp[two][three][five] += solve(two=two - 1, three=three, five=five) * inv_5

        # 3
        dp[two][three][five] += solve(two=two, three=three - 1, five=five) * inv_5

        # 4
        dp[two][three][five] += solve(two=two - 2, three=three, five=five) * inv_5

        # 5
        dp[two][three][five] += solve(two=two, three=three, five=five - 1) * inv_5

        # 6
        dp[two][three][five] += solve(two=two - 1, three=three - 1, five=five) * inv_5

        dp[two][three][five] %= MOD

        return dp[two][three][five]

    print(solve(two=div[0], three=div[1], five=div[2]))

    return


if __name__ == "__main__":
    main()
