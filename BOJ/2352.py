import bisect

if __name__ == "__main__":
    N = int(input())
    port = list(map(int, input().split()))
    LIS = []
    for p in port:
        if not LIS or LIS[-1] < p:
            LIS.append(p)
        else:
            i = bisect.bisect_left(LIS, p)
            LIS[i] = p
    print(len(LIS))