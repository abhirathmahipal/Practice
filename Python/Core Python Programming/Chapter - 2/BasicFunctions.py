# Excerpt from the book
# Python can be considered "call by reference." This means that any changes to these parameters within
# the function affect the original objects in the calling function. However, the caveat is that in Python, it is# 
# really dependent on the object type being passed. If that object allows updating, then it behaves as you
# would expect from "call by reference," but if that object's value cannot be changed, then it will behave
# like "call by value."

def add(x, y):
    return x + y

print add("Abhirath", "Mahipal")

# Default Arguments. If nothing is passed in, whatever is set is taken

def foo (debug = True):
    if debug:
        print"In Debug Mode"
    else:
        print"Debug Mode Inactive"

foo()
foo(False)