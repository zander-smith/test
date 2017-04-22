#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <map>
#include <utility>
#include <algorithm>

using namespace std;

vector<int> init_pos;
vector<int> max_spd;

double solve()
{
  return 0;
}

int main(int argc, char * argv[])
{
  double res;
  int nr_cases;
  int D, N, ip, ms;
  cin >> nr_cases;

  for (int cas = 1; cas <= nr_cases; cas++)
  {
    cin >> D >> N;

    init_pos.erase(init_pos.begin(), init_pos.end());
    max_spd.erase(max_spd.begin(), max_spd.end());

    for (int i = 0; i < N; i++)
    {
      cin >> ip >> ms;
      init_pos.push_back(ip);
      max_spd.push_back(ms);
    }

    res = solve();

    cout << "Case #" << cas << ": " << res << endl;
  }
}
