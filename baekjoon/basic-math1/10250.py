# ACM 호텔
numOfInput = int(input())
for i in range(numOfInput):
    h, w, n = map(int, input().split(' '))

    floor = (n - 1) % h + 1
    number = (n - 1) // h + 1

    print('%d%02d' % (floor, number))
