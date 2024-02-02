import sys

from sortedcontainers import SortedList

sys.setrecursionlimit(10**8)


def main():
    _, _ = map(int, sys.stdin.readline().strip().split())
    P = list(map(int, sys.stdin.readline().strip().split()))
    L = list(map(int, sys.stdin.readline().strip().split()))
    D = list(map(int, sys.stdin.readline().strip().split()))

    coupon = [(l, d) for l, d in zip(L, D)]
    coupon.sort(key=lambda x: (-x[1], x[0]))

    itm = SortedList(P)

    ans = 0
    for l, d in coupon:
        pos = itm.bisect_left(l)

        if pos >= len(itm):
            continue

        value = itm.pop(pos)
        ans += value - d

    ans += sum(itm)

    print(ans)

    return


if __name__ == '__main__':
   main()