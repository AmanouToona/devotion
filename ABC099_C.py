def main():
    N = int(input())

    dp = [float("inf")] * (10 ** 5 + 1)
    dp[0] = 0

    for i in range(len(dp)):
        if dp[i] == float("inf"):
            continue
        # 6 の遷移
        six_times = 6
        while six_times + i < len(dp):
            dp[i + six_times] = min(dp[i + six_times], dp[i] + 1)
            six_times *= 6

        # 9 の遷移
        nine_times = 9
        while nine_times + i < len(dp):
            dp[i + nine_times] = min(dp[i + nine_times], dp[i] + 1)
            nine_times *= 9

    ans = 0
    while N > 0:
        if dp[N] != float("inf"):
            break
        ans += 1
        N -= 1

    ans += dp[N]
    print(ans)

    return


if __name__ == "__main__":
    main()
