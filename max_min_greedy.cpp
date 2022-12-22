#include <bits/stdc++.h>
using namespace std;

int ArrayDiff(vector<int> A, vector<int> B)
{
    if (A.size() != B.size() || A.size() == 0) return -1;

    int sum = 0;
    for (int i = 0; i < A.size(); i++)
    {
        sum += abs(A[i] - B[i]);
    }
    return sum;
}

// Given a vector arr, find the max and min "Difference"
void PrintMaxAndMin(vector<int> arr)
{
    int n = arr.size();
    if (n <= 0) return;
    vector<int> Amax, Amin, Bmax, Bmin;

    // for each iteration of removing n/2 elements, we find the max and min of the arrays
    sort(arr.begin(), arr.end());

    for (int i = 0; i < n/2; i++)
    {
        Amax.push_back(arr[i]);
        Bmax.push_back(arr[n-i-1]);

        Amin.push_back(arr[n-i-1]);
        Bmin.push_back(arr[n-i-2]);
    }

    cout << ArrayDiff(Amax, Bmax) << " " << ArrayDiff(Amin, Bmin) << endl;
}

// Run the above functions on a vector of odd and even sizes
int main(){      
    vector<int> arr_even = { 4,3,2,1 };
    cout << "Even Length Vector: ";
    PrintMaxAndMin(arr_even);

    vector<int> arr_odd = { 5,4,3,2,1 };
    cout << "Odd Length Vector: ";
    PrintMaxAndMin(arr_odd);

    return 0;
}
