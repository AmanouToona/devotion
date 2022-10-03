import sys


def main():
    N = int(input())
    D = list(map(int, sys.stdin.readline().strip().split()))

    # 鳩の巣原理より
    if N >= 24:
        print(0)
        return

    # 高橋君を含め 最大で 24 人の時刻を調べればよい
    ans = 0
    for b in range(1 << N):
        time = [0]
        for i, d in enumerate(D):
            if (b >> i) & 1:
                time.append(d)
            else:
                time.append(24 - d)

        if len(set(time)) != len(time):
            continue

        time.sort()
        min_diff = float("inf")
        for i in range(len(time)):
            diff = abs(time[(i + 1) % len(time)] - time[i])
            min_diff = min(min_diff, diff, 24 - diff)

        ans = max(ans, min_diff)

    print(ans)

    return


if __name__ == "__main__":
    main()

