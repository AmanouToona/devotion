import sys


def main():
    N = int(input())
    A = []
    for _ in range(N):
        A.append(int(sys.stdin.readline().strip()))

    A.sort()
    print(A)

    return


if __name__ == "__main__":
    main()
