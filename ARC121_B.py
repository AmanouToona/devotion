import sys


def main():
    N = int(input())

    AC = []

    count_r = 0
    count_g = 0
    count_b = 0

    for _ in range(2 * N):
        a, c = sys.stdin.readline().strip().split()
        a = int(a)
        AC.append((a, c))

        if c == "R":
            count_r += 1
        elif c == "G":
            count_g += 1
        else:
            count_b += 1

    if count_r % 2 == 0 and count_g % 2 == 0 and count_b % 2 == 0:
        print(0)
        return

    if count_r % 2 == 0:
        even_color = "R"
    elif count_g % 2 == 0:
        even_color = "G"
    else:
        even_color = "B"

    odd_colors = []

    for color in ["R", "G", "B"]:
        if color == even_color:
            continue
        odd_colors.append(color)

    AC.sort()

    def search_min_diff(color1, color2):
        res = float("inf")

        right = 0
        for left in range(len(AC) - 1):
            if AC[left][1] != color1:
                continue

            if right <= left:
                right = left + 1

            while right + 1 < len(AC) and AC[right][1] != color2:
                right += 1

            if AC[right][1] != color2:
                continue

            res = min(res, AC[right][0] - AC[left][0])

        for left in range(len(AC) - 1):
            if AC[left][1] != color2:
                continue

            if right <= left:
                right = left + 1

            while right + 1 < len(AC) and AC[right][1] != color1:
                right += 1

            if AC[right][1] != color1:
                continue

            res = min(res, AC[right][0] - AC[left][0])

        return res

    ans = search_min_diff(odd_colors[0], odd_colors[1])
    ans = min(ans, search_min_diff(odd_colors[0], even_color) + search_min_diff(odd_colors[1], even_color))

    print(ans)

    return


if __name__ == "__main__":
    main()
