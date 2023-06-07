import sys
from typing import Any


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
            raise Exception
        return self.compression[x]

    def __len__(self) -> int:
        return len(self.compression)


def main():
    N = int(sys.stdin.readline().strip())

    rcx = []
    for _ in range(N):
        r, c, x = map(int, sys.stdin.readline().strip().split())
        r -= 1
        c -= 1
        rcx.append((r, c, x))

    R = CoordinateCompression()
    C = CoordinateCompression()
    for r, c, _ in rcx:
        R.add(r)
        C.add(c)

    R.produce()
    C.produce()

    board = [[0] * len(C) for _ in range(len(R))]
    for r, c, x in rcx:
        board[R[r]][C[c]] = x

    R_sum = [sum(i) for i in board]
    C_sum = [sum(i) for i in zip(*board)]

    ans = 0
    for r in range(len(R)):
        for c in range(len(C)):
            ans = max(ans, R_sum[r] + C_sum[c] - board[r][c])

    print(ans)
    return


if __name__ == "__main__":
    main()
