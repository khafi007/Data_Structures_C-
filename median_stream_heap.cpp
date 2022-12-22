#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void printMedians(double arr[], int n)
{
	// max heap to store the smaller half elements
	priority_queue<double> smaller;

	// min heap to store the greater half elements
	priority_queue<double,vector<double>,greater<double> > greater;

	double median = arr[0];
	smaller.push(arr[0]);

	cout << median << " ";

	for (int i=1; i < n; i++)
	{
		double current = arr[i];

		// if max heap has more elements
		if (smaller.size() > greater.size())
		{
			if (current < median)
			{
				greater.push(smaller.top());
				smaller.pop();
				smaller.push(current);
			}
			else
				greater.push(current);

			median = (smaller.top() + greater.top())/2.0;
		}

		// if both heaps are balanced
		else if (smaller.size()==greater.size())
		{
			if (current < median)
			{
				smaller.push(current);
				median = (double)smaller.top();
			}
			else
			{
				greater.push(current);
				median = (double)greater.top();
			}
		}

		// if min heap has more elements
		else
		{
			if (current > median)
			{
				smaller.push(greater.top());
				greater.pop();
				greater.push(current);
			}
			else
				smaller.push(current);

			median = (smaller.top() + greater.top())/2.0;
		}

		cout << median << " ";
	}
}

int main()
{
	double arr[] = {5,15,1,3,2,8};
	int n = sizeof(arr)/sizeof(arr[0]);
	printMedians(arr, n);
	return 0;
}

