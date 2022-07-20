import sys


def main():
    N = int(input())
    A = list(map(int, sys.stdin.readline().strip().split()))

    A = [a - i for i, a in enumerate(A)]
    A.sort()

    # 中央値取得
    A_mid = A[len(A) // 2]

    ans = 0
    for a in A:
        ans += abs(a - A_mid)

    print(ans)

    return


if __name__ == "__main__":
    main()
