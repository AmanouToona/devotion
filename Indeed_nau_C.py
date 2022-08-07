import sys
from collections import defaultdict


def main():
    N = int(input())
    S = []
    for _ in range(N):
        S.append(int(sys.stdin.readline().strip()))
    S.sort()

    # 座標圧縮
    s_m = defaultdict(int)
    s_m[0] = len(s_m)
    for s in S:
        if s in s_m.keys():
            continue
        s_m[s] = len(s_m)

    s_m_rev = [-1] * len(s_m)
    for key, val in s_m.items():
        s_m_rev[val] = key

    conv_s = []
    for s in S:
        conv_s.append(s_m[s])

    # 圧縮後点数をボーダーとしたときの通過者人数
    s_cum = [0] * len(s_m)
    for s in conv_s:
        s_cum[s] += 1

    for i in range(len(s_cum) - 1, 0, -1):
        s_cum[i - 1] += s_cum[i]

    # クエリー処理
    Q = int(input())
    for _ in range(Q):
        k = int(sys.stdin.readline().strip())

        if len(s_cum) == 1:
            print(0)
            continue

        if s_cum[1] <= k:
            print(0)
            continue

        left = 0
        right = len(s_cum)

        while right - left > 1:
            mid = (right + left) // 2
            if s_cum[mid] > k:
                left = mid
            else:
                right = mid

        print(s_m_rev[left] + 1)


if __name__ == "__main__":
    main()
