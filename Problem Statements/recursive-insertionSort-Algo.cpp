#include <bits/stdc++.h>
using namespace std;

// Basic Insertion sort algorithm..........
void insertionSort(vector<int> &arr)
{
  int n = arr.size();
  for (int i = 0; i < n; i++)
  {
    int j = i;
    while (j > 0 && arr[j - 1] > arr[j])
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

// Recursive insertion sort algorithm.......
void recursiveInsertionSort(vector<int> &arr, int i)
{
  int n = arr.size();
  if (i == n)
    return;
  int j = i;
  while (j > 0 && arr[j - 1] > arr[j])
  {
    swap(arr[j - 1], arr[j]);
    j--;
  }
  recursiveInsertionSort(arr, i + 1);
}
int main()
{
  vector<int> arr = {13, 46, 24, 52, 20, 9};
  recursiveInsertionSort(arr, 0);
  for (auto val : arr)
  {
    cout << val << " ";
  }
}