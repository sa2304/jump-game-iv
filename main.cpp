#include <iostream>
#include <vector>

#include "solution.h"

using namespace std;

int main()
{
  vector<int> numbers{11,22,7,7,7,7,7,7,7,22,13};
  Solution s;
  cout << "s.minJumps(numbers) = " << s.minJumps(numbers) << endl;
  return 0;
}
