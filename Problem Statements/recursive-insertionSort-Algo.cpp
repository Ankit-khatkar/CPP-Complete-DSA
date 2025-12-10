#include <bits/stdc++.h>
using namespace std;

void insertionSort(vector<int> &arr)
{
  for (int i = 0; i < arr.size() - 1; i++)
  {
    int j = i;
    while (j > 1 && arr[j - 1] > arr[j])
    {
      swap(arr[j - 1], arr[j]);
      j--;
    }
  }
  for (auto val : arr)
  {
    cout << val << " ";
  }
}

int main()
{
  vector<int> arr = {13, 46, 24, 52, 20, 9};
  insertionSort(arr);
  // for (auto val : arr)
  // {
  //   cout << val << " ";
  // }
}