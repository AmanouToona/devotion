import heapq
import sys


class SegmentTree:
    def __init__(self, n: int) -> None:
        x = 1
        while x < n:
            x *= 2

        self.n = x  # 葉の数
        self.data = [(-1, None)] * (2 * x - 1)  # データ
        return

    def update(self, i: int, x: int):
        pos = i
        i += self.n - 1
        self.data[i] = (x, pos)

        while i > 0:
            i = (i - 1) // 2
            if self.data[i * 2 + 1][0] > self.data[i * 2 + 2][0]:
                self.data[i] = self.data[i * 2 + 1]
            else:
                self.data[i] = self.data[i * 2 + 2]
        return

    def query(self, a: int, b: int):
        return self._query(a, b, 0, 0, self.n)

    def _query(self, a: int, b: int, k: int, left: int, right: int):
        # [a, b) : 要求範囲
        # k: 現在のノード番号
        # [left, right): 探索範囲

        if b <= left or a >= right:
            return (-2, None)

        if a <= left and right <= b:
            return self.data[k]

        value_left = self._query(a, b, k * 2 + 1, left, (left + right) // 2)
        value_right = self._query(a, b, k * 2 + 2, (left + right) // 2, right)

        if value_left[0] > value_right[0]:
            return value_left
        else:
            return value_right


def check_top(q):
    if not q:
        return
    val, pos = heapq.heappop(q)
    heapq.heappush(q, (val, pos))
    return val


def main():
    N, K, Q = map(int, sys.stdin.readline().strip().split())

    # Aの管理
    A = [0] * N
    used = [False] * N
    seg = SegmentTree(N)

    for i in range(N):
        seg.update(i, 0)

    # 使用済みの数字の管理
    que = []
    ans = 0
    cnt_use = 0

    for _ in range(Q):
        x, y = map(int, sys.stdin.readline().strip().split())
        x -= 1

        if used[x]:
            ans -= A[x]
            ans += y
            heapq.heappush(que, (y, x))
        else:
            seg.update(x, y)

        A[x] = y

        while cnt_use < K:
            val, pos = seg.query(0, N + 1)

            ans += val
            used[pos] = True
            heapq.heappush(que, (val, pos))
            seg.update(pos, 0)

            cnt_use += 1

        while check_top(que) < seg.query(0, N + 1)[0]:
            val, pos = heapq.heappop(que)
            if not used[pos]:
                continue

            if val != A[pos]:
                heapq.heappush(que, (A[pos], pos))
                continue

            ans -= val
            seg.update(pos, val)
            used[pos] = False

            nxt_val, nxt_pos = seg.query(0, N + 1)
            ans += nxt_val
            seg.update(nxt_pos, 0)
            used[nxt_pos] = True
            heapq.heappush(que, (nxt_val, nxt_pos))

        print(ans)

    return


if __name__ == "__main__":
    main()
