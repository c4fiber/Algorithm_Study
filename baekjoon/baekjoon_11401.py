import math

n, k = input().split(' ')
n, k = int(n), int(k)
nk = math.factorial(n) // (math.factorial(k) * math.factorial(n-k))
#print(nk)
print(nk % 1000000007)
