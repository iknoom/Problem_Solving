a, b, c = map(int, input().split())
for operator in ['+', '-', '*', '/']:
    if eval('a'+operator+'b') == c:
        print(f'{a}{operator}{b}={c}')
        break
    if eval('b'+operator+'c') == a:
        print(f'{a}={b}{operator}{c}')
        break
    if a == b == c:
        print(f'{a}={b}={c}')
        break