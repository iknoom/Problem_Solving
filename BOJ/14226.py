if __name__ == "__main__":
    S = int(input())
    start = (1, 0, 0)
    queue = [start]
    vst = {start}

    ans = float('inf')
    for u, clip, count in queue:
        if count >= ans:
            continue
        if u >= S:
            ans = min(ans, u - S + count)
            continue
        nxt = []
        # 1
        if u != clip: nxt.append((u, u, count + 1))
        # 2
        if clip != 0: nxt.append((u + clip, clip, count + 1))
        # 3
        if u > 1: nxt.append((u - 1, clip, count + 1))

        for v in nxt:
            if v not in vst:
                vst.add(v)
                queue.append(v)
    print(ans)