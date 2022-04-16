import sys
input = sys.stdin.readline

def solution():
    S = input().rstrip()
    answer = []
    stack = []
    for i in range(len(S) - 1):
        if ord(S[i]) < ord(S[i + 1]):
            while stack:
                answer.append(stack.pop() * 2)
            answer.append(S[i] * 2)
        elif ord(S[i]) == ord(S[i + 1]):
            stack.append(S[i])
        else:
            while stack:
                answer.append(stack.pop())
            answer.append(S[i])
    while stack:
        answer.append(stack.pop())
    answer.append(S[-1])
    return ''.join(answer)

if __name__ == '__main__':
    T = int(input())
    for case in range(1, T + 1):
        print("Case #"+str(case) + ":", solution())