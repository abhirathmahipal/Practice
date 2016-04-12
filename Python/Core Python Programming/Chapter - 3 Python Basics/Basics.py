import keyword


x = 12
y = 100
x, y = y, x

print x, y

x, y, z = 1, 2, 3

print x, y, z

print keyword.iskeyword("Hello")

# Common Practice of using variabe names with _ as private
# This variable should be used within this script (it can be used outside as well, but it's a bad practice)
_abhirath = 'Mahipal'

# __name__ are how inbuilt variables are named. Generally a bad practice to
# name variables like this.

print _abhirath

