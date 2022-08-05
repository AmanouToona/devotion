import sys


def main():
    N, _ = map(int, sys.stdin.readline().strip().split())
    H = list(map(int, sys.stdin.readline().strip().split()))  # len = N
    W = list(map(int, sys.stdin.readline().strip().split()))  # len = M

    H = sorted(H)

    # 前処理
    cusum_1 = [0]
    for i in range(N // 2):
        cusum_1.append(H[2 * i + 1] - H[2 * i])

    for i in range(len(cusum_1) - 1):
        cusum_1[i + 1] += cusum_1[i]

    cusum_2 = [0]
    for i in range(N // 2):
        cusum_2.append(H[2 * (i + 1)] - H[2 * i + 1])
    for i in range(len(cusum_2) - 1):
        cusum_2[i + 1] += cusum_2[i]

    # 本処理
    sum_min = float("inf")
    for w in W:
        left = 0
        right = N

        while right - left > 1:
            mid = (right + left) // 2
            if H[mid] < w:
                left = mid
            else:
                right = mid

        # 先生が組む生徒は先頭から奇数番目の生徒のみ
        # 先生が組む生徒を left とすると
        if left % 2 == 1:
            left += 1

        _sum = abs(H[left] - w)
        _sum += cusum_1[left // 2]
        _sum += cusum_2[-1] - cusum_2[left // 2]

        sum_min = min(sum_min, _sum)

    print(sum_min)

    return


if __name__ == "__main__":
    main()
