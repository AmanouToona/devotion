import sys

from sortedcontainers import SortedList

sys.setrecursionlimit(10**8)


def main():
    Q = int(input())

    A = SortedList([])

    def solve():
        query = list(sys.stdin.readline().strip().split())

        if int(query[0]) == 1:
            x = int(query[1])
            A.add(x)
            return
        elif int(query[0]) == 2:
            x, k = map(int, query[1:])
            pos = A.bisect_right(x)
            if pos < k:
                print(-1)
                return
            num = A[pos - k]
            print(num)
            return
        else:
            x, k = map(int, query[1:])
            pos = A.bisect_left(x)
            if len(A) - 1 < pos + k - 1:
                print(-1)
                return

            num = A[pos + k - 1]
            print(num)

    for _ in range(Q):
        solve()

    return


if __name__ == "__main__":
    main()
