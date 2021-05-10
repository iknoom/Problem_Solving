from sys import stdin
input = stdin.readline

# 어느 날 두 별이 처음으로 반짝인 시간과 반짝이는 주기가 주어졌을 때,
# 언제 동시에 반짝이는지 구하는 프로그램을 작성하시오.

# 오늘은 토요일(Saturday)이다.

# 첫째 줄의 시간은 첫 번째 별이 반짝인 시간,
# 둘째 줄은 두 번째 별이 반짝인 시간,
# 세 번째 줄은 첫 번째 별이 반짝이는 주기,
# 네 번째 줄은 두 번째 줄이 반짝이는 주기이다.

DAY = 24 * 60

def get_min(string):
    h, m = map(int, string.split(':'))
    return m + 60 * h

def get_time(time):
    time %= DAY * 7
    D = ["Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday"]
    ans = D[time//DAY]
    time %= DAY
    h = time // 60
    m = time % 60
    return ans, f'{h:02d}:{m:02d}'

if __name__ == '__main__':
    T1 = get_min(input())
    T2 = get_min(input())
    P1 = get_min(input())
    P2 = get_min(input())
    times = []
    for n in range(P2 + 1):
        for m in range(P1 + 1):
            if T1 + P1 * n == T2 + P2 * m:
                times.append(T1 + P1 * n)
    if not times:
        print("Never")
    else:
        d, hm = get_time(min(times))
        print(d)
        print(hm)
