// https://www.hackerrank.com/challenges/simple-text-editor
#include <iostream>

using namespace std;

int main ()
{	

	typedef struct stacks
	{
		int order[100000];
	 	int orderi;
	 	int countorder[100000];
	 	int countorderi;
	 	char undostore[1000000];
	 	int undostorei;
	 	int position[1000000];
	 	int positioni;
	} stacks;

	stacks hs;

	hs.orderi = -1;
	hs.countorderi = -1;
	hs.undostorei = -1;
	hs.positioni = -1;

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
					hs.undostore[++hs.undostorei] = temp[tempint];
					hs.position[++hs.positioni] = tempint;
				}

				hs.order[++hs.orderi] = 1;
				hs.countorder[++hs.countorderi] = tempint;			

				break;

			case 2:
				cin >> instruction2;

				tempint = si;
				for (int i = 0; i < instruction2; i++, tempint--)
				{
					hs.undostore[++hs.undostorei] = s[tempint];
					hs.position[++hs.positioni] = tempint;
					s[tempint] = ' ';

				}
				hs.order[++hs.orderi] = 2;
				hs.countorder[++hs.countorderi] = instruction2;

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
				if (hs.order[hs.orderi] == 1)
				{
					hs.orderi--;
					for (tempint = 0; tempint < hs.countorder[hs.countorderi]; tempint++)
					{
						s[hs.position[hs.positioni--]] == ' ';
						hs.undostorei--;

					}

					hs.countorderi--;

				}
				else
				{
					hs.orderi--;
					for (tempint = 0; tempint < hs.countorder[hs.countorderi]; tempint++)
					{
						s[hs.position[hs.positioni--]] = hs.undostore[hs.undostorei--];

					}
					hs.countorderi--;

				}
				break;
		}



	}

	return 0;
}