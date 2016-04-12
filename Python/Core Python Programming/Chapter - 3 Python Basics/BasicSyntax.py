x = 123; y = 145
print x, y

if x > 100 \
and y < 150:
	print "Yes"

# ''' Can continue to multiple lines as well

print '''he there, this is a sample long message to
demonstrate. I could have even assigned this sentence
to a variable using triple quotes. Single or double quotes
cannot take in new line characters'''


# Assigning Varaibles
xa, ya, za = (1, 2, 3)
(a, b, c) = (1, 4, 5)
print xa, ya, za
print za, ya
print (a, b, c)

# Use four spaces instead of tabs for cross platform development

t = u = v = 1
t += 1
print t, u, v