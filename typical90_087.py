import sys
import copy


def main():
    N, P, K = map(int, sys.stdin.readline().strip().split())

    A = []
    for _ in range(N):
        A.append(list(map(int, sys.stdin.readline().strip().split())))

    def count_path(x):
        dp = copy.deepcopy(A)

        for i in range(N):
            for j in range(N):
                if dp[i][j] == -1:
                    dp[i][j] = x

        for k in range(N):
            for j in range(N):
                for i in range(N):
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j])

        ans = 0
        for i in range(N):
            for j in range(N):
                if j <= i:
                    continue
                if dp[i][j] <= P:
                    ans += 1
        return ans

    left = 0
    right = P + 1

    if count_path(right) >= K + 1:
        print(0)
        return

    if count_path(right) == K:
        print("Infinity")
        return

    # K となる最小の X
    while right - left > 1:
        mid = (left + right) // 2

        count = count_path(mid)
        if count >= K + 1:
            left = mid
        else:
            right = mid

    min_K = right

    left = 0
    right = P + 1
    # K - 1 となる最小の X
    while right - left > 1:
        mid = (left + right) // 2

        count = count_path(mid)
        if count >= K:
            left = mid
        else:
            right = mid

    min_Kp1 = right

    print(min_Kp1 - min_K)

    return


if __name__ == "__main__":
    main()
