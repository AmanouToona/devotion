import sys


def main():
    N = int(input())  # 2 <= N <= 50
    A = list(map(int, sys.stdin.readline().strip().split()))

    ans = -float("inf")
    for taka in range(N):
        aoki_point = -float("inf")
        taka_point = -float("inf")
        for ao in range(N):
            if taka == ao:
                continue

            left = min(taka, ao)
            right = max(taka, ao)

            aoki_temp_point = 0
            taka_temp_point = 0
            for i, j in enumerate(range(left, right + 1)):
                if i % 2 == 0:
                    taka_temp_point += A[j]
                else:
                    aoki_temp_point += A[j]

            if aoki_temp_point > aoki_point:
                taka_point = taka_temp_point
                aoki_point = aoki_temp_point

        ans = max(ans, taka_point)

    print(ans)

    return


if __name__ == "__main__":
    main()
