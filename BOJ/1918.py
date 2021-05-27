# boj1918 후위 표기식 풀이
# 1. 여는 괄호: 스택에 넣는다.
# 2. 닫는 괄호: 여는 괄호가 나올 때까지 스택에서 연산자를 pop하여 후위 표기식에 추가한다.
# -> 괄호 안에 있는 연산은 가장 먼저 실행하기 때문

# 3. 연산자:
#       a. 현재 연산자보다 우선순위가 낮은 연산자가 올 때까지 스택에서 연산자를 pop하여 후위 표기식에 추가한다.
#       b. 스택에 현재 연산자를 넣는다.
# -> */의 우선순위가 +-의 우선순위보다 낮다.

# 4. 피연산자: 바로 후위 표기식에 추가한다.

priority = {'*': 1, '/': 1, # 우선순위가 높음
            '+': 2, '-': 2} # 우선순위가 낮음

def get_postfix(infix):
    stack = []
    ret = ''
    for c in infix:
        # 1. 여는 괄호
        if c == '(':
            stack.append(c)
        # 2. 닫는 괄호
        elif c == ')':
            while stack[-1] != '(':
                ret += stack.pop()
            stack.pop()
        # 3. 연산자
        elif c in priority:
            while stack and stack[-1] in priority and priority[stack[-1]] <= priority[c]:
                ret += stack.pop()
            else:
                stack.append(c)
        # 4. 피연산자
        else:
            ret += c

    # 남은 연산자들을 후위 표기식에 추가
    while stack:
        ret += stack.pop()

    return ret


if __name__ == '__main__':
    infix = input()
    postfix = get_postfix(infix)
    print(postfix)