#include <iostream>
#pragma warning (disable: 4996)
#pragma warning (disable: 6031)

int main()
{
	char input;
	char inputArray[50] = {};
	int naturalNums[50] = {};
	char* p1 = inputArray;
	int* p2 = naturalNums;
	int result = 0;


	while (true)
	{
		scanf("%c", &input);

		if (input == '\n')
			break;
		else
			*p1 = input;

		if (*p1 >= '0' && *p1 <= '9')
		{
			*p2 = (int)*p1 - 48;
			p2++;
		}

		p1++;
	}

	for (int i = 0; i < naturalNums; i++)
	{
		int tmp = naturalNums[i];

		for (int j = 0; j < counter2 - (i+1); j++)
		{
			tmp *= 10;
		}

		result += tmp;
	}

	printf("%d", result);
	
	return 0;
}
