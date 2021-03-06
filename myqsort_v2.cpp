#include <vector>
#include <cstddef>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <algorithm>
using std::sort;
using std::vector;
using std::endl;
using std::cout;
using std::cin;
inline void swap(vector<int> &Array, int i, int j)
{
	// no need to load or write in the same place
	// I/O is very time consuming
	if (i == j)
		return;
	int temp = Array[i];
	Array[i] = Array[j];
	Array[j] = temp;
}

void myqsort(vector<int> &Array, int start, int end)
{
	if (start >= end)
		return;
	if (start == end - 1) {
		if (Array[start] > Array[end])
			swap(Array, start, end);
		return;
	}
	int mid = (end - start) / 2 + start;
	int Pivot = Array[mid];
	cout << Pivot << endl;
	swap(Array, mid, start);
	int LastLeftPosition = start - 1;
	int LastPivotPosition = start;
	for (int i = start + 1; i <= end; i++) {
		if (Array[i] > Pivot)
			continue;
		if (Array[i] == Pivot) {
			LastPivotPosition++;
			swap(Array, LastPivotPosition, i);
			continue;
		}
		LastLeftPosition++;
		swap(Array, i, LastLeftPosition);
		LastPivotPosition++;
		swap(Array, i, LastPivotPosition);
	}

	myqsort(Array, start, LastLeftPosition);
	myqsort(Array, LastPivotPosition + 1, end);
}


int main(int argn, char *argv[])
{
	//int Num = 10;
	int Num = atoi(argv[1]);

	vector<int> Array(Num);
	srand(time(NULL));
	for (int i = 0; i < Num; i++) {
		Array[i] = rand() % 21 - 10;
		cout << Array[i] << " ";
	}
	cout << endl;

	vector<int> Golden(Array);
	sort(Golden.begin(), Golden.end());
	myqsort(Array, 0, Num - 1);

	for (int i = 0; i < Num; i++)
		cout << Golden[i] << " ";
	cout << endl;
	for (int i = 0; i < Num; i++)
		cout << Array[i] << " ";
	cout << endl;

	return 1;
}

