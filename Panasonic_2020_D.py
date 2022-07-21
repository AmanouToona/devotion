def main():
    N = int(input())

    ans = []

    def dfs(num, max_digit):
        if len(num) == max_digit:
            ans.append(num.copy())
            return

        num_limit = max(num) + 1
        for i in range(num_limit + 1):
            num.append(i)
            dfs(num, max_digit)
            num.pop()

        return

    dfs([0], N)

    for a in ans:
        a = [chr(ord("a") + i) for i in a]
        a = "".join(a)
        print(a)


if __name__ == "__main__":
    main()
