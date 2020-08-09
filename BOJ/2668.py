if __name__ == "__main__":
    N = int(input())
    adj = [int(input()) - 1 for _ in range(N)]
    ans = set()

    for start in range(N):
        vst = set()
        end = start
        while end not in vst:
            vst.add(end)
            end = adj[end]
        if end == start: ans |= vst

    print(len(ans))
    for i in sorted(ans):
        print(i + 1)