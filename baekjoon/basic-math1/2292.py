# level별 숫자 개수
# 1   1
# 2   6  (2 ~ 7)
# 3   12 (8 ~ 19)
# n  (n - 1) * 6

target = int(input())
num = 1
level = 1

# 현재 레벨에서 도달할 수 있다면 중단
while target > num:
    num += level * 6
    level += 1

print(level)