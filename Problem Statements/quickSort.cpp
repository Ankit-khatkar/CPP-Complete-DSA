#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &arr, int st, int end)
{
  int idx = st - 1;
  for (int j = st; j < end; j++)
  {
    if (arr[j] < arr[end])
    {
      idx++;
      swap(arr[idx], arr[j]);
    }
  }
  idx++;
  swap(arr[idx], arr[end]);
  return idx;
}
void quickSort(vector<int> &V, int st, int end)
{
  if (st < end)
  {
    int pivotIdx = partition(V, st, end);
    quickSort(V, st, pivotIdx - 1);
    quickSort(V, pivotIdx + 1, end);
  }
}
int main()
{
  vector<int> arr = {2, 3, 5, 1, 4, 6};
  int st = 0;
  int end = arr.size() - 1;
  quickSort(arr, st, end);
  for (auto val : arr)
  {
    cout << val << " ";
  }
}