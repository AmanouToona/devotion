import sys


def main():
    H, W, K = map(int, sys.stdin.readline().strip().split())

    S = []
    for _ in range(H):
        S.append(list(sys.stdin.readline().strip()))

    ans = float("inf")
    for h in range(2 ** (H - 1)):  # 横方向に割る位置
        h_cut = 0  # 横方向に割った回数
        for i in range(H - 1):
            if (h >> i) & 1:
                h_cut += 1

        h_group = [0]  # 同一のピースを同一番号にする

        for i in range(H - 1):
            if (h >> i) & 1:
                h_group.append(h_group[-1] + 1)
            else:
                h_group.append(h_group[-1])

        # 縦方向に割っていく
        count_white = [0] * H
        w_cut = 0
        for w in range(W):
            count_white_ = [0] * H
            cut = False
            for h, g in enumerate(h_group):
                if S[h][w] == "0":
                    continue
                count_white[g] += 1
                count_white_[g] += 1
                if count_white[g] > K and not cut:
                    w_cut += 1
                    cut = True
            if cut:
                count_white = count_white_

        ans = min(ans, h_cut + w_cut)
    print(ans)
    return


if __name__ == "__main__":
    main()
