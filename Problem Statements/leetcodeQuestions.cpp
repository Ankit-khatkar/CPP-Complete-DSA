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

int main()
{
  vector<int> arr = {2, 3, 2, 0, 3, 5, 4, 2, 2, 2};
  cout << majorityElem(arr);
}