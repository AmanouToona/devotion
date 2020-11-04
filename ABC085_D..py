import sys
import math

N, H = map(int, sys.stdin.readline().strip().split())

sords = []
max_a = 0
for n in range(N):
    a, b = map(int, sys.stdin.readline().strip().split())
    sords.append((a, b))

    max_a = max(max_a, a)

sords.sort(reverse=True, key=lambda x: x[1])

attack_count = 0
for i in range(N):
    # print(f'i: {i} H: {H}')
    if H <= 0:  # 魔物は死んだ
        print(attack_count)
        sys.exit()

    if sords[i][1] == max_a:
        if i < N - 1:
            if sords[i + 1][0] == max_a:  # まだ剣を投げられる
                H -= sords[i][1]
                attack_count += 1
                continue

        H -= sords[i][1]
        attack_count += 1
        break

    if sords[i][1] < max_a:  # 剣を投げるよりも斬りつけた方がよい
        break

    H -= sords[i][1]
    attack_count += 1

# print(f'H: {H}, max_a: {max_a}')
attack_count += math.ceil(H / max_a)

print(attack_count)


