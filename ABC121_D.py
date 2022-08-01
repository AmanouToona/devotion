def main():
    A, B = map(int, input().strip().split())

    # f(A, B) = f(0, B) xor f(0, A - 1)
    # F(x) = f(0, x)

    def F(x):
        if x % 2 == 1:
            if ((x - 1) // 2 + 1) % 2 == 1:
                return 1
            else:
                return 0
        return F(x - 1) ^ x

    ans = F(B) ^ F(A - 1)
    print(ans)


if __name__ == "__main__":
    main()
