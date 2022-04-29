#include "solution.h"
#include "util.h"
#include <unordered_set>
#include <numeric>
#include <iterator>
#include <unordered_map>
#include <stack>
#include <string>
using namespace sol833;
using namespace std;

/*takeaways
  - use Union Find to group similar anagrams
  - use edit distance to determine if two anagrams
    are similar

*/

UF::UF(int n) : groups(n), parent(n)
{
  /*there are n groups initially
    - set the parent to itself initially
  */
  std::iota(parent.begin(), parent.end(), 0);
}
void UF::merge(int c, int p)
{
  auto i = find(c);
  auto j = find(p);

  /* in the same group already */
  if (i == j)
    return;
  parent[i] = j;
  /* two groups merged into one */
  groups--;
}
/* find the parent */
int UF::find(int i)
{
  while (parent[i] != i)
    i = parent[i];
  return i;
}
int UF::getGroups()
{
  return groups;
}

bool Solution::isSimilar(string &a, string &b)
{
  /* there are all anagrams so the edit distance
     can't be 1 as you can't just change the order
     of one char and the other chars remain intact
  */
  auto distance = 0;
  for (auto i = 0; i < a.size(); i++)
  {
    if (a[i] != b[i])
      distance++;
    if (distance > 2)
      return false;
  }

  return true;
}

int Solution::findGroups(vector<string> &A)
{
  const int N = A.size();
  auto uf = UF(N);
  for (auto i = 0; i < N - 1; i++)
    for (auto j = i + 1; j < N; j++)
      if (isSimilar(A[i], A[j]))
        uf.merge(i, j);

  return uf.getGroups();
}