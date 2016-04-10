# Iterating over a for loop. It doesn't behave like a traditional 
# counter but rather iterates over a sequence

for item in ['email', 'surfing', 'homework', 'chat']:
    print item,

# Modifying for loops to behave like a counter
print "\n"
for x in xrange(10):
    print x,
    
# Iterating over each character in a string
foo = 'abcd'
print "\n"
for c in foo:
    print c,

print "\n"

# Using enumerate in a for loop

for i, ch in enumerate(foo):
    print ch, '(%d)' %i
    
help(enumerate)
