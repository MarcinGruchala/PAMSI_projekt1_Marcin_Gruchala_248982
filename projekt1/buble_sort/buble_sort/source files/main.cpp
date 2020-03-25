#include <iostream>

int main()
{
	int [10000] = {};

	bool sorted = false;
	while (!sorted)
	{
		sorted = true;

		for (int i = 0; i < (sizeof(table) / sizeof(int)) - 1; i++)
		{
			int tmp;
			if (table[i] > table[i + 1])
			{
				sorted = false;
				tmp = table[i];
				table[i] = table[i + 1];
				table[i + 1] = tmp;
			}
			if (table[i] < table[i + 1] && sorted == true)
			{
				sorted = true;
			}
		}
	}

}