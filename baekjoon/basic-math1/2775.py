# 부녀회장이 될테야
# 1. 재귀로 구현해보자 -> 시간 초과
# 2. 반복문으로 구현

# 1. 재귀함수
def humans(floor, ho):
    if floor == 0:
        return ho
    if ho == 1:
        return humans(floor-1,ho)

    return humans(floor,ho-1) + humans(floor-1, ho)


# 2. 반복문, 배열을 미리 선언해서 사용했다가 append로 추가하는식으로 변경함. 이게 더 파이썬에 맞는것 같다
# 소요시간은 오히려 더걸려서 기존방식을 고수함
apartment = [[x for x in range(16)] for y in range(15)]
for floor in range(1,15):
    for ho in range(1,15):
        apartment[floor][ho] = apartment[floor-1][ho] + apartment[floor][ho-1]

t = int(input())
for _ in range(t):
    k = int(input())
    n = int(input())

    print(apartment[k][n])