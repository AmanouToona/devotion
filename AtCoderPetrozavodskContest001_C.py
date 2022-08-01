def judege(n):
    print(n)
    s = input()
    return s


def main():
    N = int(input())

    s = judege(0)
    if s == "Vacant":
        return
    l_sex = s

    s = judege(N - 1)
    if s == "Vacant":
        return
    r_sex = s

    l = 0
    r = N - 1

    while True:
        mid = (l + r) // 2

        s = judege(mid)
        if s == "Vacant":
            return

        if (mid - l) % 2 == 0:
            if s == l_sex:
                l = mid
                continue
            else:
                r = mid
                continue
        else:
            if s == l_sex:
                r = mid
                r_sex = s
                continue
            else:
                l = mid
                l_sex = s
                continue


if __name__ == "__main__":
    main()
