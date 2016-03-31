# creating a list

numbers = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10]

# list splicing
print("Numbers[:]", numbers[:])
print("Numers[0:5]", numbers[0:5])
print("Numbers[-5:-1]", numbers[-5:-1])
print("Numbers[-1:-5]", numbers[-1:-5])
print("Number[:3]", numbers[:3])
print("Numbers[-2:]", numbers[-2:])

# multiplying and joining lists
endings = ['st', 'nd', 'rd'] + 17 * ['th'] + ['st', 'nd', 'rd'] + 7 * ['th'] + ['st']

day = int(input("Enter the day(1 - 31)"))
finaloutput = str(day) + endings[day - 1]
print(finaloutput)


# list membership
list1 = 'abc'
result = 'c' in list1
print("Is c a part of list1?", result)

result = 'd' in list1
print("Is d a part of list1?", result)

# List 1
samplelist = ['Hey', 'Hi', 'etc']
samplelist2 = ['ohh', 'Apples', 'banana']

mergelist = [samplelist, samplelist2]
samplelist.remove('Hey')

print(mergelist)





