import sys


class SegmentTree:
    def __init__(self, n: int) -> None:
        x = 1
        while x < n:
            x *= 2

        self.n = x  # 葉の数
        self.data = [-float("inf")] * (2 * x - 1)  # データ
        return

    def update(self, i: int, x: int):
        i += self.n - 1
        self.data[i] = x

        while i > 0:
            i = (i - 1) // 2
            self.data[i] = min(self.data[i * 2 + 1], self.data[i * 2 + 2])
        return

    def query(self, a: int, b: int):
        return self._query(a, b, 0, 0, self.n)

    def _query(self, a: int, b: int, k: int, left: int, right: int):
        # [a, b) : 要求範囲
        # k: 現在のノード番号
        # [left, right): 探索範囲

        if b <= left or a >= right:
            return float("inf")

        if a <= left and right <= b:
            return self.data[k]

        value_left = self._query(a, b, k * 2 + 1, left, (left + right) // 2)
        value_right = self._query(a, b, k * 2 + 2, (left + right) // 2, right)

        return min(value_left, value_right)


def main():
    N = int(input())

    C = []
    A = []
    for _ in range(N - 1):
        c, a = map(int, sys.stdin.readline().strip().split())
        C.append(c)
        A.append(a)

    # 椀に豆一つの場合の grundy 数を導出
    tree = SegmentTree(N + 1)

    grundy = [-1] * N
    grundy[0] = 0
    tree.update(0, 0)

    for i in range(N - 1):
        left = max(0, i + 1 - C[i])

        # grundy 数を二分探索
        if tree.query(0, 1) < left:
            grundy[i + 1] = 0
            tree.update(0, i + 1)
            continue

        ng = 0
        ok = N

        while ok - ng > 1:
            mid = (ok + ng) // 2

            right = tree.query(0, mid + 1)

            if right < left:
                ok = mid
            else:
                ng = mid

        grundy[i + 1] = ok
        tree.update(ok, i + 1)

    # 問題文の状態の grundy数を導出
    g = 0
    for i, a in enumerate(A):
        a %= 2

        if not a:
            continue

        g ^= grundy[i + 1]

    if not g:
        print("Second")
    else:
        print("First")

    return


if __name__ == "__main__":
    main()
