import sys

sys.setrecursionlimit(10 ** 8)


def main():
    N = int(input())
    C = list(map(int, sys.stdin.readline().strip().split()))

    min_cost = min(C)
    num_digit_use = N // min_cost  # 用いる数字の個数

    # 用いる数字の個数を減らさない範囲で、可能な限り大きな数字を用いる
    use = {}
    res = N
    res_num = num_digit_use
    for i, c in zip(range(9, 0, -1), C[::-1]):
        if c == min_cost:
            use[i] = res_num
            break
        num_i = (res - min_cost * res_num) // (c - min_cost)

        if num_i == 0:
            continue
        use[i] = num_i

        res_num -= num_i
        res -= use[i] * c

    ans = []

    for i in range(1, 10):
        if i not in use.keys():
            continue

        ans.append(f"{i}" * use[i])

    ans.reverse()
    ans = "".join(ans)
    print(ans)

    return


if __name__ == "__main__":
    main()
