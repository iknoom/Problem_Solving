def get_value(X, Y):
    return (1000 / Y) * X
    # return (1000 // Y + (1000 % Y != 0)) * X

if __name__ == '__main__':
    X, Y = map(int, input().split())
    N = int(input())
    answer = get_value(X, Y)
    for _ in range(N):
        x1, y1 = map(int, input().split())
        answer = min(answer, get_value(x1, y1))
    print(answer)

    
