#include <bits/stdc++.h>
using namespace std;

// Input : N=7,arr[]={3,2,8,5,1,4,23}
// Output : {1,2,3,4,5,8,23}
// Explanation : Given array is sorted in non-decreasing order.

void merge(vector<int> &arr, int st, int mid, int end)
{
  vector<int> temp;
  int i = st;
  int j = mid + 1;
  while (i <= mid && j <= end)
  {
    if (arr[i] <= arr[j])
    {
      temp.push_back(arr[i]);
      i++;
    }
    else
    {
      temp.push_back(arr[j]);
      j++;
    }
  }
  while (i <= mid)
  {
    temp.push_back(arr[i]);
    i++;
  }
  while (j <= end)
  {
    temp.push_back(arr[j]);
    j++;
  }
  for (int idx = 0; idx < temp.size(); idx++)
  {
    arr[idx + st] = temp[idx];
  }
}
void mergeSort(vector<int> &V, int st, int end)
{

  if (st < end)
  {
    int mid = st + (end - st) / 2;

    mergeSort(V, st, mid);
    mergeSort(V, mid + 1, end);
    merge(V, st, mid, end);
  }
}

int main()
{
  vector<int> arr = {3, 2, 8, 5, 1, 4, 23};
  int st = 0;
  int end = arr.size() - 1;
  mergeSort(arr, st, end);
  for (int i = 0; i < arr.size(); i++)
  {
    cout << arr[i] << " ";
  }
}