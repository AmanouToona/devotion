import sys

sys.setrecursionlimit(10**8)


def main():
    N = int(input())
    A = list(map(int, sys.stdin.readline().strip().split()))
    A = [a - 1 for a in A]

    loop = set()
    fp = set()

    def search_loop(u):
        _fp = [False] * N  # foot print

        def _search_loop(u):
            if u in loop:
                return

            if _fp[u]:
                return u
            if u in fp:
                return
            fp.add(u)

            _fp[u] = True
            nxt = A[u]
            return _search_loop(nxt)

        start = _search_loop(u)

        if start is None:
            return

        p = start

        while p not in loop:
            loop.add(p)
            p = A[p]

    for u in range(N):
        if u in loop:
            continue
        if u in fp:
            continue
        search_loop(u)

    print(len(loop))
    return


if __name__ == "__main__":
    main()
