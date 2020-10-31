# C - Back and Forth
import sys

sx, sy, tx, ty = map(int, sys.stdin.readline().strip().split())

# sx < tx かつ sy < ty なので簡単に解ける そうでないと場合分けが必要
ans = []

# 1回目 s -> t
ans += ['U'] * (ty - sy)
ans += ['R'] * (tx - sx)

# 1回目 t -> s
ans += ['D'] * (ty - sy)
ans += ['L'] * (tx - sx)

# 2回目 s -> t
ans += ['L']
ans += ['U'] * (ty - sy + 1)
ans += ['R'] * (tx - sx + 1)
ans += ['D']

# 2回目 t -> s
ans += ['R']
ans += ['D'] * (ty - sy + 1)
ans += ['L'] * (tx - sx + 1)
ans += ['U']

print("".join(ans))

