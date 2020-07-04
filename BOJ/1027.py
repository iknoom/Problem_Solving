N = int(input())
H = list(map(int, input().split()))

def solve(x):
    count = 0
    for i in range(N):
        flag = True
        if i == x: continue
        a = min(i, x)
        b = max(i, x)
        dx = b - a
        dy = H[b] - H[a]
        for j in range(a + 1, b):
            if dy * (j - a) + H[a] * dx <= H[j] * dx:
                flag = False
        if flag:
            count += 1
    return count

if __name__ == '__main__':
    answer = 0
    for i in range(N):
        answer = max(answer, solve(i))
    print(answer)