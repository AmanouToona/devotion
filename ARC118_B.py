import sys
from math import floor

sys.setrecursionlimit(10 ** 8)


def main():
    K, N, M = map(int, sys.stdin.readline().strip().split())
    A = list(map(int, sys.stdin.readline().strip().split()))

    B = [0] * K
    for i, a in enumerate(A):
        B[i] = floor(M * a / N)

    # 残りの追加すべき人数は？
    residual = M - sum(B)

    # 差分の大きい順にインデックスを保存
    diff_idx = [(M * a - N * b, idx) for idx, (a, b) in enumerate(zip(A, B))]

    diff_idx.sort(key=lambda x: -x[0])

    for _, idx in diff_idx[:residual]:
        B[idx] += 1

    B = [str(b) for b in B]
    print(" ".join(B))

    return


if __name__ == "__main__":
    main()
