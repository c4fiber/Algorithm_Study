korean, english, math = 80, 75, 55
avg = (korean+english+math)/3
print korean, english, math
print avg

a=13
if 13%2 == 1:
    print "odd"
else:
    print "even"

hong = "881120-1068234"
hong1, hong2 = hong.split('-')
print 'birth: ' + hong1, 'last: ' + hong2

pin = "881120-1068234"
print pin[0:6]

a = "a:b:c:d"
a.replace(':','#')
print a

list1 = [1,3,5,4,2]
list1.sort()
list1.reverse()
print list1

list2 = ['Life', 'is', 'too', 'short']
' '.join(list2)
print list2

a=(1,2,3)
b=(4,)
print a+b

#3. list can not use as key because it's changeable

dict1 = {'A':90, 'B':80, 'C':70}
dict1.pop('B')

list11 = [1, 1, 1, 2, 2, 3, 3, 4, 4, 5]
print set(list11)

a12 = b12 = [1, 2, 3]
a12[1] = 4
print a12, b12
print id(a12), id(b12)
