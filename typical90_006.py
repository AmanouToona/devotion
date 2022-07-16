import sys


def main():
    _, K = map(int, sys.stdin.readline().strip().split())
    S = input()

    dp = [[float("inf")] * (len(S) + 1) for _ in range(26)]

    for i, s in enumerate(S):
        dp[ord(s) - ord("a")][i + 1] = i + 1

    for i in range(26):
        for j in range(len(S), 0, -1):
            dp[i][j - 1] = min(dp[i][j - 1], dp[i][j])

    ans = []
    i = 1
    while i <= len(S):
        for j in range(26):
            if len(S) - dp[j][i] > K - len(ans):
                i = dp[j][i] + 1
                ans.append(chr(ord("a") + j))
                break
        if len(ans) == K:
            break

    ans = "".join(ans)
    print(ans)
    return


if __name__ == "__main__":
    main()
