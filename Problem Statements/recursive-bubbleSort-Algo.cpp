#include <bits/stdc++.h>
using namespace std;

// Simple Bubble Sort Algorithm......
void bubbleSort(vector<int> &arr)
{
  int n = arr.size();
  for (int i = n - 1; i >= 1; i--)
  {
    for (int j = 0; j <= i - 1; j++)
    {
      if (arr[j] > arr[j + 1])
      {
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
  for (auto value : arr)
  {
    cout << value << " ";
  }
}

// Recursive Bubble Sort Algorithm......
void recursiveBubbleSort(vector<int> &arr, int n)
{
  if (n == 1)
    return;
  for (int i = 0; i < n - 1; i++)
  {
    if (arr[i] > arr[i + 1])
    {
      swap(arr[i], arr[i + 1]);
    }
  }
  recursiveBubbleSort(arr, n - 1);
}
int main()
{
  vector<int> arr = {13, 46, 24, 52, 20, 9};
  int n = arr.size();
  recursiveBubbleSort(arr, n);
  for (auto val : arr)
  {
    cout << val << " ";
  }
}