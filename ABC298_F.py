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

    def update_add(self, i: int, x: int):
        i += self.n - 1
        self.data[i] += x

        while i > 0:
            i = (i - 1) // 2
            self.data[i] = max(self.data[i * 2 + 1], self.data[i * 2 + 2])
        return

    def update_sub(self, i: int, x: int):
        i += self.n - 1
        self.data[i] -= x

        while i > 0:
            i = (i - 1) // 2
            self.data[i] = max(self.data[i * 2 + 1], self.data[i * 2 + 2])
        return

    def quere(self):
        return self._query(0, self.n, 0, 0, self.n)

    def _query(self, a: int, b: int, k: int, left: int, right: int):
        # [a, b) : 要求範囲
        # k: 現在のノード番号
        # [left, right): 探索範囲

        if b <= left or a >= right:
            return -float("inf")

        if a <= left and right <= b:
            return self.data[k]

        value_left = self._query(a, b, k * 2 + 1, left, (left + right) // 2)
        value_right = self._query(a, b, k * 2 + 2, (left + right) // 2, right)

        return max(value_left, value_right)


class CoordinateCompression:
    def __init__(self) -> None:
        self.coordinate = set()
        self.compression = dict()

    def add(self, x):
        self.coordinate.add(x)
        return self

    def produce(self):
        sorted(self.coordinate)
        self.compression = {j: i for i, j in enumerate(self.coordinate)}
        return self

    def __getitem__(self, x) -> int:
        if not self.compression:
            # call self.produce before getitem
            raise Exception
        return self.compression[x]

    def __len__(self) -> int:
        return len(self.compression)


def main():
    N = int(sys.stdin.readline().strip())

    rcx = []
    R = CoordinateCompression()
    C = CoordinateCompression()
    for _ in range(N):
        r, c, x = map(int, sys.stdin.readline().strip().split())
        rcx.append((r, c, x))
        R.add(r)
        C.add(c)

    R.produce()
    C.produce()

    c_sum = [0] * len(R)
    r_sum = SegmentTree(len(C))
    cs = defaultdict(list)

    for r, c, x in rcx:
        r = R[r]
        c = C[c]

        c_sum[r] += x
        r_sum.update_add(c, x)
        cs[r].append((c, x))

    ans = 0
    for r, c_val in enumerate(c_sum):
        for c, x in cs[r]:
            r_sum.update_sub(c, x)

        ans = max(ans, c_val + r_sum.quere())

        for c, x in cs[r]:
            r_sum.update_add(c, x)

    print(ans)

    return


if __name__ == "__main__":
    main()
