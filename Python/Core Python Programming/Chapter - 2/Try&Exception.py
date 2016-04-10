# Once it encounters an exception, it skips and stops executing 
# that particular try and and except block
try:
    for x in range(-7, 7):
        print 1/x
except ZeroDivisionError:
        print "Division by Zero"

print "The End"