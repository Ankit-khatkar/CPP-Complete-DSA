#include <bits/stdc++.h>
using namespace std;
// QUE:-  Sort the array using selection sort.
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

// QUE:- You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively.

// Merge nums1 and nums2 into a single array sorted in non-decreasing order.

// The final sorted array should not be returned by the function, but instead be stored inside the array nums1. To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged, and the last n elements are set to 0 and should be ignored. nums2 has a length of n.

// Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
// Output: [1,2,2,3,5,6]

// Heap Buffer issues with this code.....
void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
  if (n >= 1)
  {
    int j = n;
    for (int i = 0; i < n; i++)
    {
      nums1[j] = nums2[i];
      j++;
    }
  }
  for (int i = m - 1; i >= 1; i--)
  {
    for (int j = 0; j <= i - 1; j++)
    {
      if (nums1[j] > nums1[j + 1])
      {
        swap(nums1[j], nums1[j + 1]);
      }
    }
  }
  for (auto value : nums1)
  {
    cout << value << " ";
  }
}

// Better time and space complexity........
void merge1(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
  int i = m - 1;
  int j = n - 1;
  int k = m + n - 1;
  while (j >= 0)
  {
    nums1[k] = nums2[j];
    j--;
    k--;
  }
  for (auto value : nums1)
  {
    cout << value << " ";
  }
}

int main()
{
  vector<int> arr1 = {1, 2, 3, 0, 0, 0};
  vector<int> arr2 = {2, 5, 6};
  int m = 3;
  int n = 3;

  merge1(arr1, m, arr2, n);
}