# http://www.programiz.com/python-programming/if-elif-else

num = float(input("Enter a number: "))

if num > 0:
	print("Positive Number")
elif num == 0:
	print("Zero")
else:
	print("Negative Number")

# Nested Conditions

num1 = int(input("Enter Another Number: "))

if num1 >= 0:
	
	if num1 == 0:
		print("Zero")
	else:
		print("Positive Number")

else:
	print("Negative Number")










