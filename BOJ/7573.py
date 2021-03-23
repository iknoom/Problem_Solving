from sys import stdin
input = stdin.readline

def getInFishY(fish, x, w):
    for fx, fy in fish:
        if x <= fx <= x + w:
            yield fy

def solution(N, I, fish):
    answer = 0
    for x in range(1, N):
        for w in range(1, I // 2):
            h = I // 2 - w
            if x + w > N: continue
            inFishY = sorted(getInFishY(fish, x, w))
            l = 0
            for r in range(len(inFishY)):
                while inFishY[r] - inFishY[l] > h:
                    l += 1
                answer = max(answer, r - l + 1)
    return answer

def main():
    N, I, M = map(int, input().split())
    fish = [tuple(map(int, input().split())) for _ in range(M)]
    answer = solution(N, I, fish)
    print(answer)

if __name__ == '__main__':
    main()