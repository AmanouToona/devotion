import sys


def count(A, x, y):
    cnt_x = [0] * (len(A) + 1)
    cnt_y = [0] * (len(A) + 1)

    for i, a in enumerate(A):
        if a == x:
            cnt_x[i + 1] = 1
        if a == y:
            cnt_y[i + 1] = 1

    for i in range(len(A)):
        cnt_x[i + 1] += cnt_x[i]
        cnt_y[i + 1] += cnt_y[i]

    res = 0
    right = 0
    for left in range(len(cnt_x)):
        while cnt_x[left] == cnt_x[right] and right + 1 < len(cnt_x):
            right += 1
        while cnt_y[left] == cnt_y[right] and right + 1 < len(cnt_y):
            right += 1

        if cnt_x[left] == cnt_x[right] or cnt_y[left] == cnt_y[right]:
            return res

        res += len(cnt_x) - right

    return res


def main():
    N, X, Y = map(int, sys.stdin.readline().strip().split())
    A = list(map(int, sys.stdin.readline().strip().split()))

    # Y未満 or X以上の数値を含む場合は解になりえないので省く
    As = [[]]
    for a in A:
        if a < Y or a > X:
            if As[-1]:
                As.append([])
            continue
        As[-1].append(a)

    if not As[-1]:
        As.pop()

    ans = 0
    for a in As:
        ans += count(a, X, Y)

    print(ans)

    return


if __name__ == "__main__":
    main()
