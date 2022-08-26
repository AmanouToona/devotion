def main():
    N = int(input())

    ans = [15, 10, 6]

    set_ans = set(ans)
    for i in [15, 10, 6]:
        if len(ans) >= N:
            break
        for j in range(2, 10000 // i):
            if len(ans) >= N:
                break

            if i * j in set_ans:
                continue

            ans.append(i * j)
            set_ans.add(i * j)
    print(" ".join([str(a) for a in ans]))


if __name__ == "__main__":
    main()
