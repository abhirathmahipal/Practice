# Loops, they have a different construct
# I've been using this video for the tutorials
# https://www.youtube.com/watch?v=N4mEzFDjqtA

import random

for x in range(0,10):
	print(x, ' ', end="")

print('\n')

dummylist = ['Hey', 'I', 'Am', 'Abhirath', 'how', 'are', 'you']

for y in dummylist:
	print(y)

for x in [1, 3, 5]:
	print(x)

num_list = [[1,3,5], [120, 3434, 456]]

for x in range(0, 2):
	for y in range(0, 3):
		print(num_list[x][y])


random_num = random.randrange(0,100)

# i++ is not a valid expression in Python

x = 0
while(random_num != 15 and x < 6):
	print(random_num)
	random_num = random.randrange(0,100)
	x += 1

i = 0

while(i <= 20):
	if (i % 2 == 0):
		print(i)
	elif(i === 9):
		break
	else:
		i += 1






