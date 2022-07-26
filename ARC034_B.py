def main():
    N = int(input())

    def bit_sum(x):
        res = 0
        while x > 0:
            res += x % 10
            x //= 10

        return res

    ans = []
    for fx in range(1, 9 * 17 + 1):
        x = N - fx

        if fx != bit_sum(x):
            continue

        ans.append(x)

    if not ans:
        print(0)
        return

    ans.sort()

    print(len(ans))
    for a in ans:
        print(a)


if __name__ == "__main__":
    main()
