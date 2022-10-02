import sys


def main():
    N, T = map(int, sys.stdin.readline().strip().split())
    A = list(map(int, sys.stdin.readline().strip().split()))

    A1 = []
    A2 = []
    for i in range(N):
        if i < N // 2:
            A1.append(A[i])
        else:
            A2.append(A[i])

    sum1 = []
    for bit in range(1 << len(A1)):
        s = 0
        for i in range(len(A1)):
            if (bit >> i) & 1:
                s += A1[i]

        sum1.append(s)

    sum2 = []
    for bit in range(1 << len(A2)):
        s = 0
        for i in range(len(A2)):
            if (bit >> i) & 1:
                s += A2[i]
        sum2.append(s)

    sum2.sort()

    ans = 0
    for s1 in sum1:
        if T < s1:
            continue

        if s1 + sum2[-1] <= T:
            ans = max(ans, s1 + sum2[-1])
            continue

        if s1 + sum2[0] > T:
            ans = max(ans, s1)
            continue

        ok = 0
        ng = len(sum2)

        while ng - ok > 1:
            mid = (ok + ng) // 2

            if s1 + sum2[mid] <= T:
                ok = mid
            else:
                ng = mid

        ans = max(ans, s1 + sum2[ok])

    print(ans)

    return


if __name__ == "__main__":
    main()
