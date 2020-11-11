import sys

S = list(str(sys.stdin.readline().strip()))  # len S <= 10 ** 5

left = 0
right = 0

ans = 0
for left in range(len(S)):
    if right == left:
        right += 1

    if S[left] != '2':
        continue

    while right < len(S):
        if S[right - 1] == '2' and S[right] == '5':
            right += 1
        elif S[right - 1] == '5' and S[right] == '2':
            right += 1
        else:
            break
    
    
    if right - left >= 2:
        ans += (right - left) // 2
    
    # print(f'left: {left} right: {right} ans : {ans}')
print(ans)
