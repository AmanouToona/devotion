import sys
import math

sys.setrecursionlimit = 10**8


def main():
    N, M = map(int, sys.stdin.readline().strip().split())

    if N**2 < M:
        print(-1)
        return

    ans = N**2
    for a in range(1, min(N, int(math.sqrt(M))) + 1):
        b = math.ceil(M / a)
        if b > N:
            continue
        ans = min(ans, a * math.ceil(M / a))

    print(ans)

    return


if __name__ == "__main__":
    main()
