def foo():
    return ['xyz', 10000, -98]

# Function bar returns a tuple. Tuples can be represented without '()' as well
def bar():
    return 'ab', [4, 5], 'cd'

print foo()
print bar()

aTuple = bar()

# 1st Element of the tuple is assigned to x, 2nd to y and so on.
x, y, z = bar()
print x
print x, y, z

(a,b,c) = bar()
print (a,b,c)
print a