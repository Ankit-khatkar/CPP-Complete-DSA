#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Given an integer n, print the first n rows of pascal's triangle.

// METHOD 1st- Stright forward approach-------
int get_factorial(int n)
{
  int ans = 1;
  while (n > 0)
  {
    ans = ans * n;
    n--;
  }
  return ans;
}
void pascal_triangle1st(int n)
{
  int ans;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j <= i; j++)
    {
      ans = get_factorial(i) / (get_factorial(j) * get_factorial(i - j));
      cout << ans << " ";
    }
    cout << endl;
  }
}

// METHOD 2nd- According to DSA prespective-------
/**
 * @brief Fills and prints the first n rows of Pascal's Triangle into the provided 2D vector.
 *
 * This function appends n rows to the provided vector `v`, initializes each row with the
 * correct number of elements, computes Pascal's Triangle values (binomial coefficients),
 * and prints the triangle to stdout (each row on a new line, values separated by spaces).
 *
 * The intended layout after calling this function with n = 5:
 * 1
 * 1 1
 * 1 2 1
 * 1 3 3 1
 * 1 4 6 4 1
 *
 * Behavior and notes:
 * - The function modifies `v` by pushing n new rows to its end. If `v` is non-empty,
 *   the new rows are appended after existing rows; the function does not clear existing data.
 * - Each row i (0-based) will contain i+1 integers.
 * - The triangle edges (first and last element of each row) are set to 1; internal values
 *   are computed from the two values directly above: v[i][j] = v[i-1][j] + v[i-1][j-1].
 * - Printing is performed after the triangle is computed.
 *
 * Preconditions:
 * - n should be non-negative. If n <= 0, the function will append no rows and print nothing.
 * - The caller should be aware that `v` will grow by n rows; if the caller expects to
 *   overwrite an existing triangle, clear `v` before calling.
 *
 * Important implementation notes / potential pitfalls:
 * - Use logical OR (||) rather than bitwise OR (|) when checking boolean conditions:
 *     if (i == j || j == 0) ...
 * - When accessing v[i-1][...], ensure i > 0 (the edge case i == 0 is handled by the
 *   condition that sets the first element to 1).
 * - Consider using size_t for indices to avoid signed/unsigned comparison warnings.
 * - If large n is used, values will grow quickly and may overflow int; consider using a
 *   larger integer type (long long or arbitrary-precision) if needed.
 *
 * Complexity:
 * - Time: O(n^2) — each element of the triangle is computed once.
 * - Space: O(n^2) additional storage in `v` to hold the triangle. Temporary per-row
 *   allocations are performed when pushing new rows.
 *
 * Example usage:
 *   std::vector<std::vector<int>> triangle;
 *   pascal_triangle2nd(triangle, 5);
 *
 * Suggested inline comments to add inside pascal_triangle2nd() for clarity:
 *   // 1) Allocate n rows with appropriate sizes (row i has i+1 elements initialized to 0)
 *   // 2) For each row i and column j:
 *   //    - If j == 0 or j == i, this is an edge -> set value to 1
 *   //    - Otherwise, compute value as sum of two values from previous row:
 *   //        v[i][j] = v[i-1][j] + v[i-1][j-1]
 *   // 3) After filling all rows, print each row's elements separated by spaces and a newline
 *
 * Suggested minor improvements (optional):
 * - Replace 'int' loop counters with 'size_t' for index variables.
 * - Reserve space in v ahead of time: v.reserve(v.size() + n);
 * - Replace printing with returning the filled vector (or provide a flag) to separate
 *   computation from I/O in contexts where printing is undesirable (e.g., unit tests).
 */
void pascal_triangle2nd(vector<vector<int>> &v, int n)
{
  for (int i = 0; i < n; i++)
  {
    vector<int> rows;
    for (int j = 0; j < i + 1; j++)
    {
      rows.push_back(0);
    }
    v.push_back(rows);
  }
  for (int i = 0; i < v.size(); i++)
  {
    for (int j = 0; j < v[i].size(); j++)
    {
      if (i == j | j == 0)
      {
        v[i][j] = 1;
      }
      else
      {
        v[i][j] = v[i - 1][j] + v[i - 1][j - 1];
      }
    }
  }
  for (int i = 0; i < v.size(); i++)
  {
    for (int j = 0; j < v[i].size(); j++)
    {
      cout << v[i][j] << " ";
    }
    cout << endl;
  }
}
int main()
{
  pascal_triangle1st(5);
}