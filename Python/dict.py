# Dictionaries are key value pairs. They are given different names. Hash Tables in C is an example of a dictionary
# Associative Arrays, Maps etc are all the same.
# We can't join dictionaries like how we did for lists.



# Use curly braces while declaring
key_valuepair = {'1' : 'One', '2' : 'Two', '3' : 'Three', 'Best' : 'Place', 'Fruit' : 'Apple'}


# Searches for the key "Best"
print(key_valuepair['Best'])

# Deletes entry with the key "Fruit"
del key_valuepair['Fruit']

key_valuepair['Three'] = 'Four'


print(key_valuepair.keys())
print(key_valuepair.values())

