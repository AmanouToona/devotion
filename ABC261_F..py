import sys
from collections import defaultdict


class SegmentTree:
    def __init__(self, n: int) -> None:
        x = 1
        while x < n:
            x *= 2

        self.n = x  # 葉の数
        self.data = [0] * (2 * x - 1)  # データ
        return

    def update(self, i: int, x: int):
        i += self.n - 1
        self.data[i] += x

        while i > 0:
            i = (i - 1) // 2
            self.data[i] = self.data[i * 2 + 1] + self.data[i * 2 + 2]
        return

    def query(self, a: int, b: int):
        return self._query(a, b, 0, 0, self.n)

    def _query(self, a: int, b: int, k: int, left: int, right: int):
        # [a, b) : 要求範囲
        # k: 現在のノード番号
        # [left, right): 探索範囲

        if b <= left or a >= right:
            return 0

        if a <= left and right <= b:
            return self.data[k]

        value_left = self._query(a, b, k * 2 + 1, left, (left + right) // 2)
        value_right = self._query(a, b, k * 2 + 2, (left + right) // 2, right)

        return value_left + value_right


def main():
    N = int(input())
    C = list(map(int, sys.stdin.readline().strip().split()))
    X = list(map(int, sys.stdin.readline().strip().split()))

    # 全体の転倒数を求める
    inverse_num = 0
    seg = SegmentTree(N + 1)
    for x in X:
        inverse_num += seg.query(x + 1, N + 1)
        seg.update(x, 1)

    # 同色の転倒数を求める
    def compress(raw):  # 座標圧縮
        raw_num = sorted(list(set(raw)))

        raw2compress = {}
        for i, b in enumerate(raw_num):
            raw2compress[b] = i

        res = [raw2compress[i] for i in raw]

        return res

    balls_by_color = defaultdict(list)
    for c, x in zip(C, X):
        balls_by_color[c].append(x)

    for _, balls in balls_by_color.items():
        balls = compress(balls)
        n = max(balls)
        seg = SegmentTree(n + 1)

        for ball in balls:
            inverse_num -= seg.query(ball + 1, n + 1)
            seg.update(ball, 1)

    print(inverse_num)

    return


if __name__ == "__main__":
    main()
