import sys
from collections import defaultdict


def main():
    N = int(sys.stdin.readline().strip())

    R = defaultdict(int)
    C = defaultdict(int)
    sqr = dict()  # square
    for _ in range(N):
        r, c, x = map(int, sys.stdin.readline().strip().split())
        R[r] += x
        C[c] += x
        sqr[(r, c)] = x

    C_sort = [(j, i) for i, j in C.items()]
    C_sort.sort(key=lambda x: -x[0])

    ans = 0
    for r, r_val in R.items():
        ans = max(ans, r_val)
        for c_val, c in C_sort:
            if (r, c) not in sqr.keys():
                ans = max(ans, r_val + c_val)
                break
            ans = max(ans, r_val + c_val - sqr[(r, c)])

    print(ans)
    return


if __name__ == "__main__":
    main()
