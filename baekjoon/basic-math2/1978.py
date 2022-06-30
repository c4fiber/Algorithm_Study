'''
2022-05-02
소수 찾기

'''

def isPrimeNumber(num):
    # 1이면 소수가 아니다.
    if num == 1:
        return 0
    # 소수가 아닌게 확인되는 순간 0 반환
    for i in range(2, num):
        if num % i == 0:
            return 0
        
    # 소수가 맞으면 1
    return 1

input()
nums = list(map(int,input().split(' ')))
result = 0

for num in nums:
    result += isPrimeNumber(num)

print(result)
