def main():
    N, K = map(int, input().strip().split())

    ans = 0
    for b in range(1, N + 1):
        if b - K <= 0:
            continue
        ans += ((N + 1) // b) * (b - K)

        # a == 0 の場合を除外する
        if K == 0:
            ans -= 1

        if (N + 1) % b == 0:
            continue

        if N % b >= K:
            ans += N % b - K + 1

    print(ans)


if __name__ == "__main__":
    main()
