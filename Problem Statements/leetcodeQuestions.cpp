#include <bits/stdc++.h>
using namespace std;

// find the mejority element form the arrya.
// Note:- array will only have positive numbers.

// EX:- arr={1,2,2,3,2,6,2,2}
// Output:- 2 (Mejority element)
int majorityElem(vector<int> &nums)
{
  if (nums.empty())
    return 0;
  int max = INT_MIN;
  for (int i = 0; i < nums.size(); i++)
  {
    if (max < nums[i])
    {
      max = nums[i];
    }
  }
  vector<int> temp(max + 1, 0);

  for (int i = 0; i < nums.size(); i++)
  {
    temp[nums[i]] += 1;
  }
  int heap_max = INT_MIN;
  for (int i = 0; i < temp.size(); i++)
  {
    if (heap_max < temp[i])
    {
      heap_max = temp[i];
    }
  }
  auto it = find(temp.begin(), temp.end(), heap_max);
  if (it != temp.end())
  {
    int index = it - temp.begin();
    return index;
  }
}

// Que:-  Given an array, we have to find the largest element in the array.

// Input: arr[] = {2, 5, 1, 3, 0}
// Output: 5

int largestElem(vector<int> &arr)
{
  int i = 0;
  int j = arr.size() - 1;
  int max = INT16_MIN;
  while (i < j)
  {
    if (arr[i] > arr[j])
    {
      max = arr[i];
      j--;
    }
    else
    {
      max = arr[j];
      i++;
    }
  }

  // Alternative Method..........

  // for (int i = 0; i < arr.size(); i++)
  // {
  //   if (arr[i] > max)
  //   {
  //     max = arr[i];
  //   }
  // }

  return max;
}

// Given an array, find the second smallest and second largest element in the array. Print ‘-1’ in the event that either of them doesn’t exist.

// Input: [1, 2, 4, 7, 7, 5]
// Output: Second Smallest : 2
// Second Largest : 5

void getElements(vector<int> &arr)
{
  if (arr.size() < 2)
  {
    cout << "Array only have " << arr.size() << " element." << endl;
    return;
  }
  int n = arr.size();
  for (int i = n - 1; i > 0; i--)
  {
    for (int j = 0; j < i; j++)
    {
      if (arr[j] > arr[j + 1])
      {
        swap(arr[j], arr[j + 1]);
      }
    }
  }
  cout << "Second Smallest Element: " << arr[1] << endl;
  cout << "Second Largest Element: " << arr[arr.size() - 2] << endl;
}
// Time Complexity O(n^2)

void getElements(int arr[], int n)
{
  // Edge case: when the array has less than 2 elements
  if (n == 0 || n == 1)
    cout << -1 << " " << -1 << endl; // If only one element, print -1 for both second smallest and second largest

  // Initialize variables to track the smallest, second smallest, largest, and second largest elements
  int small = INT_MAX, second_small = INT_MAX;
  int large = INT_MIN, second_large = INT_MIN;
  int i;

  // Find the smallest and largest elements in the array
  for (i = 0; i < n; i++)
  {
    small = min(small, arr[i]); // Update the smallest element
    large = max(large, arr[i]); // Update the largest element
  }

  // Find the second smallest and second largest elements
  for (i = 0; i < n; i++)
  {
    // If the current element is smaller than second_small and not equal to the smallest, update second_small
    if (arr[i] < second_small && arr[i] != small)
      second_small = arr[i];

    // If the current element is larger than second_large and not equal to the largest, update second_large
    if (arr[i] > second_large && arr[i] != large)
      second_large = arr[i];
  }

  // Output the second smallest and second largest elements
  cout << "Second smallest is " << second_small << endl;
  cout << "Second largest is " << second_large << endl;
}
// Time Complexity O(n)

void rotateArrayLeft(vector<int> &arr, int t)
{
  int x = t % (arr.size());
  int n = arr.size();
  for (int i = 1; i <= x; i++)
  {
    int temp = arr[0];
    for (int j = 0; j < n - 1; j++)
    {
      arr[j] = arr[j + 1];
    }
    arr[n - 1] = temp;
  }
  for (auto val : arr)
  {
    cout << val << " ";
  }
}

void rotateArrayRight(vector<int> &arr, int t)
{

  int n = arr.size();
  int x = t % n;
  if (n == 1)
  {
    return;
  }
  for (int i = 1; i <= x; i++)
  {
    int temp = arr[n - 1];
    for (int j = n - 1; j > 0; j--)
    {
      arr[j] = arr[j - 1];
    }
    arr[0] = temp;
  }
};
// QUE:-Given an array nums, return true if the array was originally sorted in non-decreasing order, then rotated some number of positions (including zero). Otherwise, return false.

// There may be duplicates in the original array.

// Note: An array A rotated by x positions results in an array B of the same length such that B[i] == A[(i+x) % A.length] for every valid index i.
// Input: nums = [3,4,5,1,2]
// Output: true
// Explanation: [1,2,3,4,5] is the original sorted array.
// You can rotate the array by x = 2 positions to begin on the element of value 3: [3,4,5,1,2].
bool check(vector<int> &arr)
{
  vector<int> new_arr(arr);
  int n = arr.size();

  sort(arr.begin(), arr.end());
  bool flag = false;

  for (int i = 0; i < n; i++)
  {

    for (int j = 0; j < n; j++)
    {
      if (new_arr[j] != arr[(j + i) % n])
      {
        break;
        ;
      }
      else if (new_arr[j] == arr[(j + i) % n] && j == (n - 1))
      {
        flag = true;
        break;
      }
    }
    if (flag == true)
    {
      break;
    }
  }
  return flag;
}

// QUE:- Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once. The relative order of the elements should be kept the same.

// Consider the number of unique elements in nums to be k​​​​​​​​​​​​​​. After removing duplicates, return the number of unique elements k.

// The first k elements of nums should contain the unique numbers in sorted order. The remaining elements beyond index k - 1 can be ignored.
int removeDuplicate(vector<int> &arr)
{
  if (arr.size() == 0)
  {
    return 0;
  }
  int k = arr.size();
  for (int i = 0; i < arr.size() - 1; i++)
  {

    if (arr[i] == arr[i + 1])
    {
      arr[i] = -101;
      k--;
    }
  }
  vector<int> new_arr(k);
  int count = 0;
  for (int i = 0; i < arr.size(); i++)
  {
    if (arr[i] != -101)
    {
      new_arr[count] = arr[i];
      arr[count] = new_arr[count];
      count++;
    }
  }

  return k;
}
// Optimal Approach
int removeDuplicates(vector<int> &nums)
{
  int n = nums.size();
  int i = 0;
  for (int j = 1; j < n; j++)
  {
    if (nums[i] != nums[j])
    {
      nums[i + 1] = nums[j];
      i++;
    }
  }
  return i + 1;
}
int main()
{

   return 0;
}