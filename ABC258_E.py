import sys


def main():
    N, Q, X = map(int, sys.stdin.readline().strip().split())
    W = list(map(int, sys.stdin.readline().strip().split()))

    # 準備
    w_sum = sum(W)
    x = X % w_sum

    # いもfrom から詰め始め いもto - 1 で詰め終わり、次は いもtoから詰め始める
    nxt = [-1] * N

    weight_sum = 0
    to = 0
    for fr0m in range(N):
        while weight_sum < x:
            weight_sum += W[to]
            to += 1
            to %= N
        nxt[fr0m] = to
        weight_sum -= W[fr0m]

    ord = [-1] * N
    path = []
    now = 0
    while ord[now] == -1:
        ord[now] = len(path)
        path.append(now)
        now = nxt[now]

    loop_size = len(path) - ord[now]
    non_loop_size = len(path) - loop_size

    # 箱に入っているじゃがいもの総数
    potato_amount = [-1] * N
    for i in range(N):
        amount = nxt[i] - i
        if amount <= 0:
            amount += N
        amount += N * (X // w_sum)
        potato_amount[i] = amount

    for _ in range(Q):
        K = int(sys.stdin.readline().strip())

        K -= 1

        if K > non_loop_size:
            K = non_loop_size + (K - non_loop_size) % loop_size

        box = path[K]

        print(potato_amount[box])

    return


if __name__ == "__main__":
    main()
