import sys


def main():
    _ = int(input())
    D = list(map(int, sys.stdin.readline().strip().split()))

    d_pop = [0] * 13
    for d in D:
        d_pop[d] += 1

    # 高橋君は時刻0
    d_pop[0] += 1

    # 0, 12 時は 2人いた時点で 0
    if d_pop[0] > 1 or d_pop[12] > 1:
        print(0)
        return

    # 3人以上いる場合も 0
    for d in d_pop:
        if d >= 3:
            print(0)
            return

    ans = 0
    for bit in range(1 << 10):
        times = [0]
        if d_pop[12] != 0:
            times.append(12)

        for i in range(11):
            if d_pop[i + 1] == 0:
                continue
            if d_pop[i + 1] == 2:
                times.append(i + 1)
                times.append(24 - (i + 1))
                continue
            if (bit >> i) & 1:
                times.append(i + 1)
            else:
                times.append(24 - (i + 1))

        times.sort()

        min_diff = float("inf")
        for i in range(len(times)):
            diff = times[(i + 1) % len(times)] - times[i]
            diff = abs(diff)
            min_diff = min(min_diff, diff, 24 - diff)

        ans = max(ans, min_diff)

    print(ans)

    return


if __name__ == "__main__":
    main()
