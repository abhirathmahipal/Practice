# Tuples are more or less like lists. The difference being that tuples cannot be changed.
# useful for data that is likely to remain the same.

# lists use sqaure braces (like the ones used for arrays in c, tuples use regular braces
mytuple = (3, 4, 5, 6) 
sampletuple = list(mytuple)
mylist = sampletuple

print(mylist)
print(mytuple)

print(len(mytuple))
print(min(mylist))