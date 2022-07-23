import sys


def main():
    N = int(input())
    P = list(map(int, sys.stdin.readline().strip().split()))
    P = [p - 1 for p in P]

    ans = []
    right = -1
    for left in range(N):
        if left < right:
            continue

        if P[left] == left:
            continue

        r = left + 1
        while r < N:
            if P[r] == left:
                break
            r += 1

        if r == N:
            print(-1)
            return

        right = r

        while r > left:
            P[r], P[r - 1] = P[r - 1], P[r]
            ans.append(r)
            r -= 1

    for i, p in enumerate(P):
        if i != p:
            print(-1)
            return

    if len(ans) != N - 1:
        print(-1)
        return

    for i in ans:
        print(i)

    return


if __name__ == "__main__":
    main()
