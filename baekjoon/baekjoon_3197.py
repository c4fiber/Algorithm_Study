def search(box):
    
#not finished
r, c = input().split(' ')
r, c = int(r), int(c)
box=[]
for _ in range(r):
    box.append(input())
print(box)

for i in range(r):
    for j in range(1, c-1):
        if box[i][j] == '.':
            box[i][j-1] = '.'
            box[i][j+1] = '.'
            box[i-1][j] = '.'
            box[i+1][j] = '.'
