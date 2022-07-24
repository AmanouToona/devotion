import sys


def main():
    N = int(input())

    F = []
    for _ in range(N):
        F.append(list(map(int, sys.stdin.readline().strip().split())))

    P = []
    for _ in range(N):
        P.append(list(map(int, sys.stdin.readline().strip().split())))

    ans = -float("inf")
    for i in range(1, 1 << 10):
        benefit = 0
        for n in range(N):
            open = 0  # 重複する開店日数
            for j in range(10):
                if i >> j & F[n][j]:
                    open += 1
            benefit += P[n][open]
        ans = max(ans, benefit)
    print(ans)
    return


if __name__ == "__main__":
    main()
