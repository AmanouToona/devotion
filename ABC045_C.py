def main():
    S = input()
    S = list(reversed(S))

    ans = 0
    for bit in range(2 ** (len(S) - 1)):
        ten = 0
        for i, s in enumerate(S):
            ans += int(s) * 10**ten
            ten += 1

            if i == len(S) - 1:
                continue

            if bit >> i & 1 == 1:
                ten = 0

    print(ans)

    return


if __name__ == "__main__":
    main()
