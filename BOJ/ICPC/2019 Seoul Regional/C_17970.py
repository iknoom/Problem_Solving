N = int(input())
I1 = list(map(int, input().split()))
I2 = list(map(int, input().split()))

idx1 = [-1] * (N + 1)
idx2 = [-1] * (N + 1)

for i in range(N): idx1[ I1[i] ], idx2[ I2[i] ] = i, i

a = b = -1
vst = [-1] * (N + 1)

for x1, x2 in zip(idx1[1:], idx2[1:]):
    if vst[I1[x1]] > 0: continue
    c = 1
    cnt = 1
    ans = [I1[x1]]
    start = (x1, x2)
    while c < N:
        L1, L2 = (x1 - 1) % N, (x2 - 1) % N
        R1, R2 = (x1 + c) % N, (x2 + c) % N

        if I1[L1] == I2[L2]:
            if vst[I1[L1]] < 0:
                ans.append(I1[L1])
                x1, x2 = L1, L2
                c += 1
                cnt += 1
            else:
                x1 -= vst[I1[L1]]
                x2 -= vst[I2[L2]]
                c += vst[I1[L1]]

        elif I1[R1] == I2[R2]:
            if vst[I1[R1]] < 0:
                ans.append(I1[R1])
                c += 1
                cnt += 1
            else:
                c += vst[I1[R1]]

        elif I1[L1] == I2[R2]:
            if vst[I1[L1]] < 0:
                ans.append(I1[L1])
                x1 = L1
                c += 1
                cnt += 1
            else:
                x1 -= vst[I1[L1]]
                c += vst[I1[L1]]

        elif I1[R1] == I2[L2]:
            if vst[I1[R1]] < 0:
                ans.append(I1[R1])
                x2 = L2
                c += 1
                cnt += 1
            else:
                x2 -= vst[I2[L2]]
                c += vst[I1[R1]]
        else:
            for v in ans: vst[v] = cnt
            break
    if c == N:
        a, b = start
        break

if a >= 0:
    cnt = 1
    ans = [I1[a]]
    x1, x2 = a, b
    while cnt < N:
        L1, L2 = (x1 - 1) % N, (x2 - 1) % N
        R1, R2 = (x1 + cnt) % N, (x2 + cnt) % N

        if I1[L1] == I2[L2]:
            ans.append(I1[L1])
            x1, x2 = L1, L2
        elif I1[R1] == I2[R2]:
            ans.append(I1[R1])
        elif I1[L1] == I2[R2]:
            ans.append(I1[L1])
            x1 = L1
        elif I1[R1] == I2[L2]:
            ans.append(I1[R1])
            x2 = L2
        else:
            break
        cnt += 1
    if cnt == N:
        print(*ans)
    else:
        print(-1)
else:
    print(-1)