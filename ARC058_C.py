import sys

sys.setrecursionlimit(10**8)


def main():
    N, K = map(int, input().strip().split())
    D = set(map(str, sys.stdin.readline().strip().split()))

    for i in range(N, 10**5):
        i = str(i)

        if set(list(i)).isdisjoint(D):
            print(i)
            return

    return


if __name__ == "__main__":
    main()
