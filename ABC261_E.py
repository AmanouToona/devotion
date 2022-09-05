import sys


def main():
    N, C = map(int, sys.stdin.readline().strip().split())
    X = C

    g0 = 0
    g1 = (1 << 31) - 1
    for _ in range(N):
        T, A = map(int, sys.stdin.readline().strip().split())

        if T == 1:
            g0 = g0 & A
            g1 = g1 & A
        elif T == 2:
            g0 = g0 | A
            g1 = g1 | A
        else:
            g0 = g0 ^ A
            g1 = g1 ^ A

        X0 = g0 & ((1 << 31) - 1 - X)
        X1 = g1 & X

        X = X0 + X1
        print(X)

    return


if __name__ == "__main__":
    main()
