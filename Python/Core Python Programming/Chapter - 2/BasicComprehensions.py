# some comprehensions
sqdEvens = [x ** 2 for x in xrange(8) if not x % 2]
count = [x for x in xrange(4)]
sum = [{x: x*(x+1)/2} for x in range(8)]

print sqdEvens, count, sum