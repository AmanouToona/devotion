import sys


def main():
    _ = int(input())
    A = list(map(int, sys.stdin.readline().strip().split()))

    A.sort(key=lambda x: -x)

    ans = 0
    for i in range(0, len(A), 2):
        ans += A[i]
    print(ans)
    return


if __name__ == "__main__":
    main()
