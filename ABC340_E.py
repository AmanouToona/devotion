import sys

sys.setrecursionlimit(10**8)


class LazySegmentTree:
    # 区間加算の遅延セグ木
    def __init__(self, n: int) -> None:
        x = 1
        while x < n:
            x *= 2

        self.n = x  # 葉の数
        self.data = [0] * (2 * x - 1)  # データ
        self.lazy = [0] * (2 * x - 1)  # 遅延評価データ
        return

    def eval(self, k: int, left: int, right: int):
        # 遅延評価
        # 1. 自ノードに、自ノードの遅延配列の値を伝搬させる
        # 2. 子ノードに自ノードの遅延配列の値を伝搬させる
        # 3. 自ノードの遅延配列を空にする
        if self.lazy[k] != 0:
            self.data[k] += self.lazy[k]

            # 最下段ではないならば
            if right - left > 1:
                self.lazy[2 * k + 1] += self.lazy[k] // 2
                self.lazy[2 * k + 2] += self.lazy[k] // 2

        self.lazy[k] = 0

        return

    def update(self, a: int, b: int, x: int, k: int = 0, left: int = 0, right: int = -1):
        if right < 0:
            right = self.n

        if b <= left or right <= a:
            return

        if a <= left and right <= b:
            self.lazy[k] += int((right - left) * x)
            self.eval(k, left, right)
            return

        self.update(a, b, x, 2 * k + 1, left, (left + right) // 2)
        self.update(a, b, x, 2 * k + 2, (left + right) // 2, right)
        self.data[k] = self.data[2 * k + 1] + self.data[2 * k + 2]

        return

    def query(self, a: int, b: int):
        return self._query(a, b, 0, 0, self.n)

    def _query(self, a: int, b: int, k: int, left: int, right: int):
        # [a, b) : 要求範囲
        # k: 現在のノード番号
        # [left, right): 探索範囲

        if b <= left or right <= a:
            return 0

        self.eval(k, left, right)
        if a <= left and right <= b:
            return self.data[k]

        val_left = self._query(a, b, 2 * k + 1, left=left, right=(left + right) // 2)
        val_right = self._query(a, b, 2 * k + 2, left=(left + right) // 2, right=right)

        return val_left + val_right


def main():
    N, _ = map(int, sys.stdin.readline().strip().split())
    A = list(map(int, sys.stdin.readline().strip().split()))
    B = list(map(int, sys.stdin.readline().strip().split()))

    seg = LazySegmentTree(len(A))

    for i, a in enumerate(A):
        seg.update(i, i + 1, a)

    for b in B:
        x = seg.query(b, b + 1)

        # 箱から取り出す
        seg.update(b, b + 1, -x)

        # 箱に入れる
        seg.update(0, N, x // N)

        res = x - (x // N) * N

        seg.update(b + 1, min(b + res + 1, N), 1)

        res -= min(b + res + 1, N) - (b + 1)

        seg.update(0, max(0, res), 1)

    ans = []
    for i in range(N):
        ans.append(seg.query(i, i + 1))

    ans = " ".join(map(str, ans))
    print(ans)

    return


if __name__ == "__main__":
    main()
