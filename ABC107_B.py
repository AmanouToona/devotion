import sys

H, W = map(int, sys.stdin.readline().strip().split())

table = []
for h in range(H):
    a = list(str(sys.stdin.readline().strip()))
    if "#" in a:
        table.append(a)

ans_table = [[] for _ in range(len(table))]
for w in range(W):
    black = False
    for h in range(len(table)):
        if table[h][w] == "#":
            black = True
            break

    if black:
        for h in range(len(table)):
            ans_table[h].append(table[h][w])

for h in range(len(table)):
    print("".join(ans_table[h]))
