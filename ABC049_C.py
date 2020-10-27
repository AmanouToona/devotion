# C - 白昼夢
import sys

S = list(str(input()))

right = len(S)
while True:
    if right == 0:
        print('YES')
        sys.exit()

    if "".join(S[right - 5: right]) == 'dream' or "".join(S[right - 5: right]) == 'erase':
        right -= 5
    elif right - 6 >= 0 and "".join(S[right -6: right]) == 'eraser':
        right -= 6
    elif right - 7 >= 0 and "".join(S[right - 7: right]) == 'dreamer':
        right -= 7
    else:
        print('NO')
        sys.exit()
        

