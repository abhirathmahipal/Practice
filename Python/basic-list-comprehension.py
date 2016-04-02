# http://www.secnetix.de/olli/Python/list_comprehensions.hawk
# Run with Python 2
# xrange is more efficient than range
# range 10 gives the values from 0 to 9 to x

# List comprehensions are easier and faster ways to populate lists

s = [x**2 for x in xrange(10)]
print(s)

m = [2*x for x in xrange(13)]
print(m)

t = [2*x for x in xrange(12) if x % 3 == 0]
print(t)