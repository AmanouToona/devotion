import sys


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
    # 発電所の親を N + M として全ての発電所を結合する。 親に含まれる地点の数 - 発電所の数 - 1 が送電できる都市の数

    N, M, E = map(int, sys.stdin.readline().strip().split())

    lines = []
    for _ in range(E):
        u, v = map(int, sys.stdin.readline().strip().split())

        u -= 1
        v -= 1

        lines.append((u, v))

    Q = int(sys.stdin.readline().strip())
    X = []
    for _ in range(Q):
        x = int(sys.stdin.readline().strip())
        x -= 1
        X.append(x)

    set_X = set(X)

    uf = UnionFind(N + M + 1)

    # 発電所全てを N + M に結合する
    for i in range(N, N + M):
        uf.union(N + M, i)

    # 全てのイベント発生後の送電状況を作製する
    for i, (u, v) in enumerate(lines):
        if i in set_X:  # 全てのイベント後に切断されている送電線
            continue
        uf.union(u, v)

    ans = []
    # イベントを逆順に処理して、発電所に結合している都市数を蓄積する
    ans.append(uf.size(N + M))
    for i in range(len(X) - 1, -1, -1):
        u, v = lines[X[i]]
        uf.union(u, v)
        ans.append(uf.size(N + M))

    # 答えを出力する
    ans.reverse()
    for a in ans[1:]:
        print(a - M - 1)

    return


if __name__ == "__main__":
    main()
