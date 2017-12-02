#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> a;
	cout << "a.size(): " << a.size() << "       a.capacity(): " << a.capacity() << endl;
	for (int i = 0; i < 10; i++)
	{
		a.push_back(i);
		cout << "a.size(): " << a.size() << "   a.capacity(): " << a.capacity() << endl;
	}
	return 0;
}
