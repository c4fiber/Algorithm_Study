def calc(n, a, b):
    res = [[0]*n for _ in range(n)]
    for i in range(n):
        for j in range(n):
            for k in range(n):
                res[i][j] += a[i][k]*b[k][j]
    #1000으로 나눈 나머지                
    for i in range(n):
        for j in range(n):
            res[i][j] %= 1000

    return res

n, b = map(int, input().split(' '))

#입력된 행렬
a = [[*map(int, input().split(' '))]for _ in range(n)]

#단위행렬
res = [[1 if i == j else 0 for i in range(n)] for j in range(n)]       

#2진수로 표현하기
t = []
while b > 0:
    if b == 1:
        t.append(1)
        break
    elif b % 2 == 1:
        t.append(1)
        b = b // 2
    else:
        t.append(0)
        b = b // 2

for _ in range(len(t)):
    if t.pop() == 1:
        res = calc(n, calc(n, res, res), a)
    else:
        res = calc(n, res, res)

for i in res:
    print(*i)








