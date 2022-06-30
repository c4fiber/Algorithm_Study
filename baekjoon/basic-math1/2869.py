# 달팽이는 올라가고 싶다

climb, sled, height = map(int, input().split(' '))

# 만 하루가 지났을 때 오르는 거리
averageSpeed = climb - sled

# 다 오르기 직전까지 걸리는 날짜
if (height - climb) % averageSpeed == 0:
    lastday = (height - climb) // averageSpeed
else:
    lastday = (height - climb) // averageSpeed + 1
print(lastday + 1)
