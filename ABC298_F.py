import sys


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

    R_sum = [0] * len(R)
    C_sum = [0] * len(C)
    board = dict()

    for r, c, x in rcx:
        R_sum[R[r]] += x
        C_sum[C[c]] += x
        board[(R[r], C[c])] = x

    C_sum_idx = [(i, j) for j, i in enumerate(C_sum)]
    C_sum_idx.sort(key=lambda x: -x[0])

    ans = 0
    for r in range(len(R)):
        for c_val, c_idx in C_sum_idx:
            if (r, c_idx) not in board.keys():
                ans = max(ans, R_sum[r] + c_val)
                break
            ans = max(ans, R_sum[r] + c_val - board[(r, c_idx)])

    print(ans)
    return


if __name__ == "__main__":
    main()
