import sys
import copy


class UnionFind:
    def __init__(self, n):
        self.n = n
        self.parents = [-1] * n  # 負値 :-size  正:parent を表す

    def find(self, x):  # root を返す
        if self.parents[x] < 0:
            return x
        else:
            return self.find(self.parents[x])

    def union(self, x, y):  # x, y を結合する
        x_root = self.find(x)
        y_root = self.find(y)

        if x_root == y_root:
            return

        if self.parents[x_root] > self.parents[y_root]:
            x_root, y_root = y_root, x_root

        self.parents[x_root] += self.parents[y_root]
        self.parents[y_root] = x_root

    def size(self, x):  # x が含まれる木のサイズを返す
        return -self.parents[self.find(x)]

    def same(self, x, y):  # x, y が同一の木に含まれるか返す
        return self.find(x) == self.find(y)

    def members(self, x):  # x を含む木に含まれるメンバーをかえす
        x_root = self.find(x)
        return [i for i in range(self.n) if self.find(i) == x_root]

    def roots(self):  # 根の一覧を返す
        return [i for i in range(self.n) if self.parents[i] < 0]


def main():
    A = []
    for _ in range(10):
        A.append(sys.stdin.readline().strip())

    pos2land = {}
    for row in range(10):
        for col in range(10):
            if A[row][col] == "x":
                continue

            pos2land[row * 10 + col] = len(pos2land)

    uf = UnionFind(len(pos2land))
    for row in range(10):
        for col in range(10):
            if A[row][col] == "x":
                continue

            if row + 1 < 10 and A[row + 1][col] == "o":
                uf.union(pos2land[row * 10 + col], pos2land[(row + 1) * 10 + col])

            if col + 1 < 10 and A[row][col + 1] == "o":
                uf.union(pos2land[row * 10 + col], pos2land[row * 10 + col + 1])

    if len(uf.roots()) == 1:
        print("YES")
        return

    for row in range(10):
        for col in range(10):
            uf2 = copy.deepcopy(uf)
            if A[row][col] == "o":
                continue

            dr = [0, -1, 0, 1]
            dc = [1, 0, -1, 0]

            connect = []
            for i in range(4):
                if row + dr[i] < 0 or row + dr[i] >= 10:
                    continue
                if col + dc[i] < 0 or col + dc[i] >= 10:
                    continue

                if A[row + dr[i]][col + dc[i]] == "o":
                    connect.append(i)

            for i in range(len(connect) - 1):
                uf2.union(
                    pos2land[(row + dr[connect[i]]) * 10 + col + dc[connect[i]]],
                    pos2land[(row + dr[connect[i + 1]]) * 10 + col + dc[connect[i + 1]]],
                )

            if len(uf2.roots()) == 1:
                print("YES")

                return

    print("NO")


if __name__ == "__main__":
    main()
