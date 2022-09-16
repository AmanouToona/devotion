import sys
from collections import defaultdict


def main():
    N, M = map(int, sys.stdin.readline().strip().split())
    A = list(map(int, sys.stdin.readline().strip().split()))

    all = sum(A) % M

    mod_A = [a % M for a in A]

    from_left = [0] + mod_A[:-1]
    from_right = list(reversed(mod_A[1:] + [0]))

    for i in range(len(from_left) - 1):
        from_left[i + 1] += from_left[i]
        from_left[i + 1] %= M
    for i in range(len(from_right) - 1):
        from_right[i + 1] += from_right[i]
        from_right[i + 1] %= M

    count = defaultdict(int)
    for r in from_right:
        count[r] += 1

    ans = 0
    for i, left in enumerate(from_left):
        ans += count[(all - left) % M]
        count[from_right[-(i + 1)]] -= 1

    print(ans)
    return


if __name__ == "__main__":
    main()
