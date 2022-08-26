import sys
from collections import defaultdict


def main():
    N, K = map(int, sys.stdin.readline().strip().split())
    S = sys.stdin.readline().strip()

    for res in range(1, N + 1):
        if N % res != 0:
            continue

        to_change = 0
        for start in range(res):
            count = defaultdict(int)
            n = start
            while n < N:
                count[S[n]] += 1
                n += res

            _to_chage = float("inf")
            for _, val in count.items():
                _to_chage = min(_to_chage, N // res - val)

            to_change += _to_chage

        if to_change <= K:
            print(res)
            return


if __name__ == "__main__":
    main()
