import sys


def main():
    N = int(input())
    points = []
    for _ in range(N):
        x, y = map(int, sys.stdin.readline().strip().split())
        points.append((x, y))

    def far_point_distance(cx, cy):
        res = 0

        for x, y in points:
            res = max(res, ((cx - x) ** 2 + (cy - y) ** 2) ** 0.5)

        return res

    # 2重3分探索
    def ternary_search_y(cx):
        # 座標 (x, y) を中心とする円であり、すべての点を含む円の半径の最小値を求める
        # y は自由に定めて良い
        res = float("inf")

        # y 座標の位置を 3分探索する
        left = 0
        right = 1001
        while right - left > 10**-7:
            c1 = (left * 2 + right) / 3
            c2 = (left + right * 2) / 3

            dist1 = 0
            dist2 = 0
            for x, y in points:
                dist1 = max(dist1, ((cx - x) ** 2 + (c1 - y) ** 2) ** 0.5)
                dist2 = max(dist2, ((cx - x) ** 2 + (c2 - y) ** 2) ** 0.5)

            if dist2 < dist1:
                left = c1
            else:
                right = c2

        res = 0
        for x, y in points:
            res = max(res, ((cx - x) ** 2 + (left - y) ** 2) ** 0.5)

        return res

    left = 0
    right = 1001
    while right - left > 10**-7:
        c1 = (left * 2 + right) / 3
        c2 = (left + 2 * right) / 3

        if ternary_search_y(c1) > ternary_search_y(c2):
            left = c1
        else:
            right = c2

    ans = ternary_search_y(left)
    print(ans)

    return


if __name__ == "__main__":
    main()
