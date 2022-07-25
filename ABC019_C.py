import sys


def main():
    _ = int(input())
    A = list(map(int, sys.stdin.readline().strip().split()))

    A.sort()
    ans = 0
    num_set = set()
    for a in A:
        if a % 2 != 0:
            num_set.add(a)
            ans += 1
            continue

        num_set.add(a)
        is_same = False
        a_ = a
        while a_ % 2 == 0:
            a_ = a_ // 2
            if a_ in num_set:
                is_same = True
                break
        if not is_same:
            ans += 1

    print(ans)

    return


if __name__ == "__main__":
    main()
