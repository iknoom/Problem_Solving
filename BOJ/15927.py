def is_palindrome(A):
    for i in range(len(A) // 2 + 1):
        if A[i] != A[-i-1]:
            return False
    return True

if __name__ == '__main__':
    A = input()
    if len(set(A)) == 1:
        print(-1)
    elif is_palindrome(A):
        print(len(A) - 1)
    else:
        print(len(A))