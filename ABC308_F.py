import sys

from sortedcontainers import SortedList

sys.setrecursionlimit(10**8)


def main():
    N, M = map(int, sys.stdin.readline().strip().split())
    P = list(map(int, sys.stdin.readline().strip().split()))
    L = list(map(int, sys.stdin.readline().strip().split()))
    D = list(map(int, sys.stdin.readline().strip().split()))

    coupon = [(l, d) for l, d in zip(L, D)]
    coupon.sort(key=lambda x: -x[1])
    coupon.sort(key=lambda x: -x[0])

    itm = SortedList(P)

    ans = 0
    for l, d in coupon:
        pos = itm.bisect_left(l)

        if pos >= len(itm):
            continue

        value = itm.pop(pos)
        ans += value - d

    while itm:
        ans += itm.pop()

    print(ans)

    return


if __name__ == '__main__':
   main()