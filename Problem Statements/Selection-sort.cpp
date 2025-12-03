#include <bits/stdc++.h>
using namespace std;

vector<int> sort_arr(vector<int> &arr)
{
  int n = arr.size();
  for (int i = 0; i < n - 1; i++)
  {
    int min = arr[i];
    for (int j = i; j < n; j++)
    {
      if (arr[j] < arr[i])
      {
        min = arr[j];
        swap(arr[i], arr[j]);
      }
    }
  }
}

int main()
{
  vector<int> arr = {7, 2, 53, 43, 13, 23, 5};
  sort_arr(arr);
  for (int i = 0; i < arr.size(); i++)
  {
    cout << arr[i] << " ";
  }
}