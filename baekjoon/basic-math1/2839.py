# 설탕 배달
# 최소공배수인 15로 나눈 나머지를 3 과 5로 표현할 수 있다면 정확히 나눌 수 있다?

n = int(input())
answer = -1
for i in range(n // 5, -1, -1):
    rest = n - (5 * i)
    if rest % 3 == 0:
        answer = i + rest // 3
        break

print(answer)
