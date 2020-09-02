import heapq


down, up = [], []
n = int(input())

for i in range(n):
    v = int(input())
    if i%2==0:
        #number of values are even or 0
        #min_heap, 가치를 마이너스로 잡는다. 이러면 역정렬 됨.
        heapq.heappush(down, (-v, v))
    else:
        #number of values are Odd
        heapq.heappush(up, (v,v))

    if up and down[0][1] > up[0][1]:
        d = heapq.heappop(down)[1]
        u = heapq.heappop(up)[1]
        
        heapq.heappush(down,(-u, u))
        heapq.heappush(up, (d, d))

    print(down[0][1])
