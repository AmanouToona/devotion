import sys
from itertools import permutations

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

    A = [list(map(int, sys.stdin.readline().strip().split())) for _ in range(H)]
    B = [list(map(int, sys.stdin.readline().strip().split())) for _ in range(H)]

    # 転倒数の和
    def count_inv_num(lis):
        lis = list(lis)
        lis = [i + 1 for i in lis]
        bit = BinaryIndexedTree(10)

        res = 0
        for li in lis:
            bit.update(li, 1)

            res += bit.query(10) - bit.query(li)

        return res

    for col in permutations([i for i in range(W)]):
        for row in permutations([i for i in range(H)]):
            is_ans = True
            for i, c in enumerate(col):
                for j, r in enumerate(row):
                    if A[r][c] != B[j][i]:
                        is_ans = False
                        break

                if not is_ans:
                    break
            if is_ans:
                ans = count_inv_num(col) + count_inv_num(row)
                print(ans)
                return

    print(-1)

    return


if __name__ == "__main__":
    main()
