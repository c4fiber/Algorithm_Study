num = input().split(" ")
num = list(map(int, num))
num.sort()
print (int(num[1]))
#문자열도 상수처럼 동일하게 정렬된다고 착각했다.
