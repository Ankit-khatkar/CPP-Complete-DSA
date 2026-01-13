#include <bits/stdc++.h>
using namespace std;

// QUE:- You are given a string s consisting of lowercase English letters.

// Return an integer denoting the maximum number of
// you can split s into such that each substring starts with a distinct character (i.e., no two substrings start with the same character).
int maxDistinct(string s)
{
  unordered_map<int, int> mpp;
  string count = "";
  for (int i = 0; i < s.size(); i++)
  {
    mpp[s[i]]++;
  }
  for (const auto &pair : mpp)
  {
    count += pair.first;
  }
  return count.size();
}

// QUE :- You are given a string s. The score of a string is defined as the sum of the absolute difference between the ASCII values of adjacent characters.
int stringscore(string s)
{
  int score = 0;
  for (int i = 0; i < s.size() - 1; i++)
  {
    score += abs(s[i] - s[i + 1]);
  }
  return score;
}
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

// QUE:-  Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

// Note that you must do this in-place without making a copy of the array.

// Brute force approach. Time Complexity = O(n2)
void moveZeros(vector<int> &arr)
{
  int j = arr.size() - 1;
  while (j > 0)
  {
    for (int i = 0; i < j; i++)
    {
      if (arr[i] == 0)
      {
        swap(arr[i], arr[i + 1]);
      }
    }
    j--;
  }
}

// Optimal Solution. Time Complexity=O(n)
void moveZeros01(vector<int> &arr)
{
  int insernums = 0;
  for (int i = 0; i < arr.size(); i++)
  {
    if (arr[i] != 0)
    {
      arr[insernums++] = arr[i];
    }
  }
  while (insernums < arr.size())
  {
    arr[insernums++] = 0;
  }
}

// QUE:- Print the fobonaci series according to the length of user's input.
void fibonaciseries(int a, int b, int k)
{

  if (k < 1)
  {
    return;
  }
  int c = a + b;
  a = b;
  cout << c << " ";
  fibonaciseries(a, c, k - 1);
}
// QUE:-  Given an array, and an element num the task is to find if num is present in the given array or not. If present print the index of the element or print -1.

void linearSearchElem(vector<int> &arr, int n, int k)
{
  if (k < 0)
  {
    cout << "Didn't find element";
    return;
  }
  else if (arr[k] == n)
  {
    cout << "Element is at " << k << "th index";
    return;
  }
  else
  {
    linearSearchElem(arr, n, k - 1);
  }
}

// QUE:- Given two sorted arrays, arr1, and arr2 of size n and m. Find the union of two sorted arrays.

// The union of two arrays can be defined as the common and distinct elements in the two arrays.

// NOTE: Elements in the union should be in ascending order.

void findUnion(vector<int> &arr, vector<int> &arr1)
{
  map<int, int> mpp;
  vector<int> unionArr;
  for (int i = 0; i < arr.size(); i++)
  {
    mpp[arr[i]]++;
  }
  for (int i = 0; i < arr1.size(); i++)
  {
    mpp[arr1[i]]++;
  }
  for (auto &it : mpp)
  {
    unionArr.push_back(it.first);
  }
  for (int i = 0; i < unionArr.size(); i++)
  {
    cout << unionArr[i] << " ";
  }
}

// QUE:-  Given an array that contains only 1 and 0 return the count of maximum consecutive ones in the array.
int maximumOnes(vector<int> &nums)
{
  int current = 0;
  int maxcount = 0;
  for (int i = 0; i < nums.size(); i++)
  {
    if (nums[i] == 1)
    {
      current++;
      maxcount = max(maxcount, current);
    }
    else
    {
      current = 0;
    }
  }
  return maxcount;
}

// QUE:- Given a non-empty array of integers arr, every element appears twice except for one. Find that single one.
// Input Format: arr[] = {2,2,1}
// Result: 1
// Explanation: In this array, only the element 1 appear once and so it is the answer.
int singleNumber(vector<int> &nums)
{
  map<int, int> mpp;
  for (int i = 0; i < nums.size(); i++)
  {
    mpp[nums[i]]++;
  }
  int ans;
  for (auto &it : mpp)
  {
    if (it.second == 0)
    {
      ans = it.first;
      break;
    }
  }
  return ans;
}

// QUE:- Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.
// A subarray is a contiguous non-empty sequence of elements within an array.
int subarray(vector<int> &arr, int k)
{
  int n = arr.size();
  int subarrays = 0;
  int sum = 0;
  for (int i = 0; i < n; i++)
  {
    for (int j = i; j < n; j++)
    {
      sum += arr[j];
      if (sum == k)
      {
        subarrays += 1;
      }
    }
    sum = 0;
  }
  return subarrays;
}

// Optimal Solution....

int subarraySum(vector<int> &nums, int k)
{
  int n = nums.size();
  int count = 0;

  vector<int> prefixSum(n, 0);
  prefixSum[0] = nums[0];
  for (int i = 1; i < n; i++)
  {
    prefixSum[i] = prefixSum[i - 1] + nums[i];
  }

  unordered_map<int, int> mpp;
  for (int j = 0; j < n; j++)
  {
    if (prefixSum[j] == k)
    {
      count++;
    }
    int val = prefixSum[j] - k;
    if (mpp.find(val) != mpp.end())
    {
      count += mpp[val];
    }
    if (mpp.find(prefixSum[j]) == mpp.end())
    {
      mpp[prefixSum[j]] = 0;
    }
    mpp[prefixSum[j]]++;
  }
  return count;
}

// QUE:- find the manixum subarray sum with window size k.
int maximumSumSubarray(vector<int> &arr, int k)
{
  int n = arr.size();

  if (n < k || k == 0)
  {
    return -1;
  }
  int i = 0, j = 0;
  int sum = 0;
  int maxSum = INT_MIN;
  while (j < n)
  {
    sum = sum + arr[j];
    if (j - i + 1 < k)
    {
      j++;
    }
    else if (j - i + 1 == k)
    {
      maxSum = max(sum, maxSum);
      sum = sum - arr[i];
      i++;
      j++;
    }
  }
  return maxSum;
}

// QUE:- Given an array arr[]  and a positive integer k, find the first negative integer for each and every window(contiguous subarray) of size k.

// Note: If a window does not contain a negative integer, then return 0 for that window.
vector<int> firstNegativeElem(vector<int> &nums, int k)
{
  int n = nums.size();
  int i = 0, j = 0;
  vector<int> ans;
  list<int> l;
  while (j < n)
  {
    if (nums[j] < 0)
    {
      l.push_back(nums[j]);
    }
    if (j - i + 1 < k)
    {
      j++;
    }
    else if (j - i + 1 == k)
    {
      if (l.size() == 0)
      {
        ans.push_back(0);
      }
      else
      {
        ans.push_back(l.front());
        if (nums[i] == l.front())
        {
          l.pop_front();
        }
      }
      i++;
      j++;
    }
  }
  return ans;
}

// QUE:- Write the code to print the pascal's triangle;
vector<vector<int>> pascalTriangle(int k)
{
  vector<vector<int>> ans(k);
  for (int i = 0; i < k; i++)
  {
    ans[i].resize(i + 1);
    for (int j = 0; j <= i; j++)
    {
      if (j == 0 || j == i)
      {
        ans[i][j] = 1;
      }
      else
      {
        ans[i][j] = ans[i - 1][j - 1] + ans[i - 1][j];
      }
    }
  }
  return ans;
}

// QUE:- Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

// You may assume that each input would have exactly one solution, and you may not use the same element twice.

// You can return the answer in any order.
vector<int> twoSum(vector<int> &nums, int target)
{
  unordered_map<int, int> mpp;

  for (int i = 0; i < nums.size(); i++)
  {
    int num = nums[i];
    int moreNeeded = target - num;

    // Check if the complement exists in the map ALREADY
    if (mpp.find(moreNeeded) != mpp.end())
    {
      // If found, return the index of the complement and current index
      return {mpp[moreNeeded], i};
    }

    // If not found, add the current number and index to the map
    mpp[num] = i;
  }

  return {}; // Return empty if no solution found
}

// QUE:- find the mejority element of given array.
int mejorityElem(vector<int> &nums)
{
  int ans = INT_MIN;
  int freq = 0;
  unordered_map<int, int> mpp;
  for (int i = 0; i < nums.size(); i++)
  {
    mpp[nums[i]];

    if (freq < mpp.at(nums[i]))
    {
      freq++;
      ans = nums[i];
    }
  }
  return ans;
}

// QUE:- You are given an array prices where prices[i] is the price of a given stock on the ith day.

// You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

// Return the maximum profit

// I have solved it with O(N) time complexity. Check leetcode profile.
int maxProfit(vector<int> &prices)
{
  int maxprofit = 0;
  for (int i = 0; i < prices.size() - 1; i++)
  {
    int profit = 0;
    for (int j = i + 1; j < prices.size(); j++)
    {
      profit = prices[j] - prices[i];
      maxprofit = max(maxprofit, profit);
      if (prices[j] < prices[i])
      {
        break;
      }
    }
  }
  return maxprofit;
}

vector<int> rearrangeArray(vector<int> &nums)
{
  // int l = 0, r = nums.size() - 1;
  int pI = 0, nI = 1;
  vector<int> ans(nums.size());
  for (int i = 0; i < nums.size(); i++)
  {
    if (nums[i] > 0)
    {
      ans[pI] = nums[i];
      pI += 2;
    }
    if (nums[i] < 0)
    {
      ans[nI] = nums[i];
      nI += 2;
    }
  }

  return ans;
}

void nextPermutation(vector<int> &nums)
{
  int pivotIdx = -1;
  int n = nums.size();
  for (int i = n - 2; i >= 0; i--)
  {
    if (nums[i] < nums[i + 1])
    {
      pivotIdx = i;
      break;
    }
  }
  for (int i = n - 1; i > pivotIdx; i--)
  {
    if (nums[i] > nums[pivotIdx])
    {
      swap(nums[pivotIdx], nums[i]);
      break;
    }
  }
  reverse(nums.begin() + pivotIdx + 1, nums.end());
}

int main()
{
  vector<int> arr = {1, 0, 1, 2};
  // cout << longestConsicative(arr);

  return 0;
}