#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;
inline void swap(vector<int> &Array, int i, int j)
{
	int temp = Array[i];
	Array[i] = Array[j];
	Array[j] = temp;
}

void my_qsort(vector<int> &Array, int K, int begin, int end)
{
	if (end <= begin)
		return;
	if (begin + 1 == end) {
		if (Array[end] < Array[begin])
			swap(Array, end, begin);
		return;
	}
	K = Array[(end - begin) / 2 + begin];
	int i = begin;// the end point of {< K}
	int j = end;
	int l = begin; // the end point of {== K}
	while (l <= j) {
		if (Array[l] < K) {
			swap(Array, i, l);
			i++;
			l++;
		} else if (Array[l] == K) {
			l++;
		} else {
			swap(Array, l, j);
			j--;
		}

	}
	my_qsort(Array, K, begin, i - 1);
	my_qsort(Array, K, l, end);
}

void output(vector<int> &Array)
{
	int Size = Array.size();
	for (int i = 0; i < Size; i++)
		cout << Array[i] << " ";
	cout << endl;
}

int main(int argn, char *argv[])
{
	int Num = atoi(argv[1]);
	vector<int> Array(Num);
	int K = 1;
	srand(time(NULL));
	for (int i = 0; i < Num; i++) {
		Array[i] = rand() % 20;
		cout << Array[i] << " ";
	}
	cout << endl;
	vector<int> Golden(Array);
	sort(Golden.begin(), Golden.end());
	my_qsort(Array, K, 0, Num - 1);
	cout << "Sorted: "; 
	output(Array);
	cout << "Golden: ";
	output(Golden);
	return 0;
}

