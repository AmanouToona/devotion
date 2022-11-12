import sys


def main():
    _ = int(input())
    P = list(map(int, sys.stdin.readline().strip().split()))

    S = set([0])
    for p in P:
        S_ = S.copy()
        for s in S:
            S_.add(s + p)
        S = S_

    print(len(S))


if __name__ == "__main__":
    main()
