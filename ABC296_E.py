import sys

sys.setrecursionlimit(10**8)


def main():
    N = int(input())
    A = list(map(int, sys.stdin.readline().strip().split()))
    A = [a - 1 for a in A]

    ord = [0] * N
    k = 0

    ans = 0
    for u in range(N):
        if ord[u] != 0:
            continue

        v = u
        while ord[v] == 0:
            k += 1
            ord[v] = k

            v = A[v]

            if ord[v] == 0:
                continue

            if ord[v] < ord[u]:
                break

            ans += k - ord[v] + 1
            break

    print(ans)
    return


if __name__ == "__main__":
    main()
