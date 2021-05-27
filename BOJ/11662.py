import math

def dist(r):
    ABx = Ax + (Bx - Ax) * r
    ABy = Ay + (By - Ay) * r
    CDx = Cx + (Dx - Cx) * r
    CDy = Cy + (Dy - Cy) * r
    return math.sqrt((ABx - CDx) ** 2 + (ABy - CDy) ** 2)

if __name__ == '__main__':
    Ax, Ay, Bx, By, Cx, Cy, Dx, Dy = map(int, input().split())
    L = 0.0
    R = 1.0
    # 삼분 탐색
    for _ in range(100):
        p = (L * 2 + R) / 3
        q = (L + R * 2) / 3
        if dist(p) < dist(q):
            R = q
        else:
            L = p
    print(dist(L))