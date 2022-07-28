import sys


def retrun_win(s1, s2):
    if s1 == s2:
        return s1

    if s1 == "R":
        if s2 == "S":
            return s1
        else:
            return s2

    if s1 == "P":
        if s2 == "R":
            return s1
        else:
            return s2

    if s1 == "S":
        if s2 == "P":
            return s1
        else:
            return s2


def main():
    _, k = map(int, input().strip().split())
    s = sys.stdin.readline().strip()

    while k > 0:
        s = s + s
        s_ = []
        for i in range(0, len(s) - 1, 2):
            s_.append(retrun_win(s[i], s[i + 1]))

        s = "".join(s_)
        k -= 1

    print(s[0])


if __name__ == "__main__":
    main()
