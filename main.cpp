#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <unordered_map>
#include "solution.h"
#include "util.h"

using namespace std;
using namespace sol833;

/*
Input: ["tars","rats","arts","star"]
Output: 2
*/

tuple<vector<string>, int>
testFixture1()
{
  return make_tuple(vector<string>{"tars", "rats", "arts", "star"}, 2);
}

void test1()
{
  auto f = testFixture1();
  cout << "Expect to see " << to_string(get<1>(f)) << endl;
  Solution sol;
  cout << sol.findGroups(get<0>(f)) << endl;
}

main()
{
  test1();
  return 0;
}