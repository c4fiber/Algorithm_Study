from copy import copy

a=4
b=a
print a, b
print id(a)
print id(b)

b=copy(a)
print id(a)
print id(b)

a="test"
b=copy(a)

print id(a)
print id(b)

a += "123"
print id(a)
print id(b)
