import sys
from collections import defaultdict


def main():
    H, W = map(int, sys.stdin.readline().strip().split())

    A = []
    for _ in range(H):
        A.append(sys.stdin.readline().strip())

    cnt = defaultdict(int)
    for a in A:
        for a_ in a:
            cnt[ord(a_) - ord("a")] += 1

    four = ((H + 1) // 2 - H % 2) * ((W + 1) // 2 - W % 2)
    one = (H % 2) * (W % 2)
    two = (H * W - four * 4 - one) // 2

    for _, val in cnt.items():
        four_ = min(four, val // 4)
        four -= four_

        val -= four_ * 4
        two_ = min(two, val // 2)
        two -= two_
        val -= two_ * 2

        one -= val

        if one < 0:
            print("No")
            return

    if four == 0 and one == 0 and two == 0:
        print("Yes")
    else:
        print("No")

    return


if __name__ == "__main__":
    main()
