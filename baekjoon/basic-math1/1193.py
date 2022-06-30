target = int(input())
level = 1
num = 1

# 해당 level대각선에 target이 있으면 중단
while target > num:
    level += 1
    num += level

# level이 짝수: 왼쪽 아래부터 되돌아가기
# 홀수 : 오른쪽 위부터 돌아가기
gap = num - target

if level == 1:
    print('1/1')
elif level % 2 == 0:
    print('{}/{}'.format(level - gap, gap + 1))
else:
    print('{}/{}'.format(gap + 1, level - gap))
