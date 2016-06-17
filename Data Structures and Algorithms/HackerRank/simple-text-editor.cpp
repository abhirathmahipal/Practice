// https://www.hackerrank.com/challenges/simple-text-editor
#include <iostream>
#include <stdint.h>

using namespace std;

int main ()
{	

	typedef struct stacks
	{
		int8_t order[100000];
	 	int countorder[100000];
	 	char undostore[100000];
	 	int position[100000];
	 } stacks;

	stacks hs;

	int orderi = -1, countorderi = -1, undostorei = -1, positioni = -1;

	int test, instruction, instruction2;
	char s[1000005], temp[1000005];
	int si = -1, tempint = 0;

	cin >> test;

	for (int z = 0; z < test; z++)
	{
		cin >> instruction;

		switch (instruction)
		{
			case 1:
				cin >> temp;

				// Copying the contents of Temp
				for (tempint = 0; temp[tempint] != '\0'; tempint++)
				{
					s[++si] = temp[tempint];
					hs.undostore[++undostorei] = temp[tempint];
					hs.position[++positioni] = tempint;
				}

				hs.order[++orderi] = 1;
				hs.countorder[++countorderi] = tempint;			
				break;

			case 2:
				cin >> instruction2;

				tempint = si;
				for (int i = 0; i < instruction2; i++, tempint--)
				{
					hs.undostore[++undostorei] = s[tempint];
					hs.position[++positioni] = tempint;
					s[tempint] = ' ';

				}
				hs.order[++orderi] = 2;
				hs.countorder[++countorderi] = instruction2;

				break;


			case 3:
				cin >> instruction2;
				for (tempint = 0; instruction2 != 0; tempint++)
				{
					if (s[tempint] != ' ')
						instruction2--;

				}

				cout << s[tempint - 1] << endl;
				break;


			case 4:
				if (hs.order[orderi] == 1)
				{
					orderi--;
					for (tempint = 0; tempint < hs.countorder[countorderi]; tempint++)
						s[hs.position[positioni--]] = ' ';
						

					

					undostorei -= hs.countorder[countorderi];

					countorderi--;

				}
				else
				{
					orderi--;
					for (tempint = 0; tempint < hs.countorder[countorderi]; tempint++)
					{
						s[hs.position[positioni--]] = hs.undostore[undostorei--];

					}
					countorderi--;

				}
				break;
		}



	}

	return 0;
}