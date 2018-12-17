#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

template<typename T>
vector<T> InsertionSort(vector<T> DataSet, int Length)
{
	T value = 0;
	for (int i = 1; i < Length; ++i)
	{
		if (DataSet[i - 1] <= DataSet[i])
			continue;
		else
		{
			value = DataSet[i];

			/*  //memmove를 사용하는 방법
			for (int j = 0; j < i; ++j)
			{
			if (DataSet[j] > value)
			{
			memmove(&DataSet[j + 1], &DataSet[j], sizeof(DataSet[0]) * (i - j));
			DataSet[j] = value;
			break;
			}
			}*/

			/* //역순 탐색을 하는 방법
			for (int j = i - 1; j >= 0; --j)
			{
				if (DataSet[j] > value)
				{
					DataSet[j + 1] = DataSet[j];
					DataSet[j] = value;
				}
				else
				{
					DataSet[j + 1] = value;
					break;
				}
			}*/

			// 순차 탐색하여 하나씩 뒤로 미는 방법
			for (int j = 0; j < i; ++j)
			{
				if (DataSet[j] > value)
				{
					//memmove(&DataSet[j + 1], &DataSet[j], sizeof(DataSet[0]) * (i - j));
					for (int k = i - 1; k >= j; --k)
					{
						DataSet[k + 1] = DataSet[k];
					}

					DataSet[j] = value;
					break;
				}
			}
		}

		for (int i = 0; i < Length; ++i)
		{
			cout << DataSet[i] << "  ";
		}
		cout << endl;

	}
	return DataSet;
}

void main(void)
{
	srand(unsigned(time(NULL)));
	vector<int> DataSet;

	for (int i = 0; i < 10; ++i)
	{
		DataSet.push_back(rand() % 26);
		cout << DataSet[i] << "  ";
	}

	cout << endl;
	int Lenght = DataSet.size();

	DataSet = InsertionSort(DataSet, Lenght);

	for (int i = 0; i < Lenght; ++i)
	{
		cout << DataSet[i] << "  ";
	}
	cout << endl;
}