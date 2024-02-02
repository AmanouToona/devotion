import copy
import sys

sys.setrecursionlimit(10**8)


class BinaryIndexedTree:
    # 1-index
    def __init__(self, n: int) -> None:
        x = 1
        while x <= n:
            x <<= 1

        self.n = x
        self.data = [0] * (self.n + 1)
        return

    def update(self, i: int, x: int):
        while i <= self.n:
            self.data[i] += x
            i += i & -i
        return

    def query(self, a: int):
        res = 0

        while a:
            res += self.data[a]
            a -= a & -a

        return res


def main():
    H, W = map(int, sys.stdin.readline().strip().split())

    A = []
    for _ in range(H):
        A.append(list(map(int, sys.stdin.readline().strip().split())))

    col_no = dict()
    row_no = dict()

    for i, a in enumerate(A):
        a = copy.copy(a)
        a.sort()
        a = tuple(a)
        col_no[a] = i + 1

    for i, a in enumerate(zip(*A)):
        a = list(copy.copy(a))
        a.sort()
        a = tuple(a)
        row_no[a] = i + 1

    B = []
    for _ in range(H):
        B.append(list(map(int, sys.stdin.readline().strip().split())))

    b_col_no = []
    for b in B:
        b = copy.copy(b)
        b.sort()
        b = tuple(b)

        if b not in col_no.keys():
            print(-1)
            return

        b_col_no.append(col_no[b])

    b_row_no = []
    for b in zip(*B):
        b = list(copy.copy(b))
        b.sort()
        b = tuple(b)

        if b not in row_no.keys():
            print(-1)
            return

        b_row_no.append(row_no[b])

    # 転倒数の和
    def count_inv_num(lis):
        bit = BinaryIndexedTree(10)

        res = 0
        for li in lis:
            bit.update(li, 1)

            res += bit.query(10) - bit.query(li)

        return res

    ans = count_inv_num(b_col_no) + count_inv_num(b_row_no)
    print(ans)

    return


if __name__ == "__main__":
    main()
