#include <bits/stdc++.h>
using namespace std;

// Main function to run the program
int main() 
{ 
   int arr[] = {10, 30, 10, 20, 10, 20, 30, 10}; 
   int n = sizeof(arr)/sizeof(arr[0]); 

   unordered_map <int, int>mp;

   for(int i=0; i<n; i++)
      mp[arr[i]]++;

   for(auto it=mp.begin(); it!=mp.end(); it++)
      cout<first<<" occurs "<second<<" times\n";

}
