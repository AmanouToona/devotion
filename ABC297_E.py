import sys
import heapq

sys.setrecursionlimit = 10**8


def main():
    _, K = map(int, sys.stdin.readline().strip().split())
    A = list(map(int, sys.stdin.readline().strip().split()))
    A.sort()

    q = [0]
    pay = set()
    nxt = 0

    while len(pay) <= K:
        nxt = heapq.heappop(q)

        if nxt in pay:
            continue
        pay.add(nxt)

        for a in A:
            heapq.heappush(q, nxt + a)

    print(nxt)


if __name__ == "__main__":
    main()
