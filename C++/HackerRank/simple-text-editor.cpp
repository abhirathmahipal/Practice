#include <iostream>


int main ()
{
	int test, instruction, order[100000], stacki = -1, instruction2;
	char s[1000005], temp[1000005];
	cin >> test;

	for (int z = 0; z < test; z++)
	{
		cin >> instruction;

		if (instruction == 1)
			cin >> temp;

		if (instruction == 2 || instruction == 3)
			cin >> instruction2;

		if (instruction == 1 || instruction == 2)
			order[++stacki] = instruction;

		switch (instruction)
		{
			case 1:
				break;
			case 2:
				break;
			case 3:
				break;
			case 4:
				break;
		}



	}

	return 0;
}