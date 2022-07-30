import sys


def main():
    N, R = map(int, sys.stdin.readline().strip().split())
    S = input()
    S = [s for s in S]

    # 一番右の塗られていないマスの位置
    right_white = -1
    for i, s in enumerate(S):
        if s == ".":
            right_white = i

    # 最初から全部塗られている
    if right_white == -1:
        print(0)
        return

    ans = 0
    pos = 0
    while True:
        # 今いるマスが塗装済みでないならば塗装する
        if S[pos] == ".":
            ans += 1
            for i in range(R):
                S[pos + i] = "o"
        elif pos + R - 1 == right_white:
            ans += 1

        if pos + R - 1 == right_white:
            print(ans)
            return

        pos += 1
        ans += 1


if __name__ == "__main__":
    main()
