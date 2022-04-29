
#ifndef SOLUTION_H
#define SOLUTION_H

#include "node.h"
#include <vector>
#include <queue>
#include <unordered_map>
#include <string>
#include <stack>

using namespace std;
namespace sol833
{

  class UF
  {
  private:
    vector<int> parent;
    int groups;

  public:
    UF(int n);
    void merge(int c, int p);
    int find(int i);
    int getGroups();
  };

  class Solution
  {
  private:
    bool isSimilar(string &a, string &b);

  public:
    int findGroups(vector<string> &A);
  };
}
#endif