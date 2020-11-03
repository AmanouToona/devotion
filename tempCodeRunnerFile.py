# C - ダーツ
import sys
import bisect

"""
test
4 50
3
14
15
9
"""
def main():
    # 半分全列挙で解く (meet in the middle)

    # input
    N, M = map(int, sys.stdin.readline().strip().split())
    P =[0] * (N + 1)
    for n in range(N):
        P[n + 1] = int(sys.stdin.readline().strip())

    # make point group
    point = []
    for i in range(N + 1):
        for j_p in P[i:]:  # 高速化
            point.append(P[i] + j_p)
    
    point.sort()

    # meet in the middle
    ans = 0
    # befor = float('inf')
    for ab in point:
        # if ab == befor:
            # continue 
        # befor = ab

        limit = M - ab

        if ab > M:
            break
        elif ab == M:
            ans = M
            break

        if point[0] > limit and ab > ans:
            ans = ab
            break
        if point[-1] <= limit and ab + point[-1] > ans:
            ans = ab + point[-1]
            continue

        bi_search = bisect.bisect_left(point, limit)
        if bi_search > len(point) - 1:
            bi_search = len(point) - 1
        if point[bi_search] > limit:
            if bi_search == 0:
                continue
            else:
                bi_search -= 1

        if ab + point[bi_search] > ans:
            ans = ab + point[bi_search]

        # 2分探索

        # if point[0] <= limit:
        #     left = 0
        # elif ab > ans:
        #     ans = ab
        #     break
        # else:
        #     break
        
        # if point[-1] > limit:
        #     right = len(point) - 1
        # elif ab + point[-1] > ans:
        #     ans = ab + point[-1]
        #     continue
        # else:
        #     continue

        # while right - left > 1:
        #     mid = (right + left) // 2
        #     # print(f'left: {left} right: {right} mid: {mid}')
        #     if point[mid] <= limit:
        #         left = mid
        #     else:
        #         right = mid
        
        # if ab + point[left] > ans:
        #     ans = ab + point[left]

    print(ans)


if __name__ == '__main__':
    main()