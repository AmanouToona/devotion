import sys


def main():
    N = int(input())
    A = list(map(int, sys.stdin.readline().strip().split()))

    for i in range(1, N + 1):
        A[i - 1] -= i

    A.sort()

    A_nodup = list(set(A))

    return


if __name__ == "__main__":
    main()
