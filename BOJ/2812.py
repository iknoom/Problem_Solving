if __name__ == '__main__':
    N, K = map(int, input().split())
    nums = list(map(int, input()))
    stack = []
    for num in nums:
        while stack and stack[-1] < num and K:
            stack.pop()
            K -= 1
        stack.append(num)
    while K:
        stack.pop()
        K -= 1
    print(*stack, sep='')