#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <map>
#include <utility>
#include <algorithm>

using namespace std;

vector<int> max_dist;
vector<int> cnst_spd;

double solve(vector<map<int, int>>& distances, int start, int end)
{
  return 0;
}

int main(int argc, char * argv[])
{
  double res;
  int nr_cases;
  int N, Q;
  int start, end;
  int md, cs, ds;
  cin >> nr_cases;

  for (int cas = 1; cas <= nr_cases; cas++)
  {
    vector<map<int, int>> distances(N);

    cin >> N >> Q;

    for (int i = 0; i < N; i++)
    {
      cin >> md >> cs;
      max_dist.push_back(md);
      cnst_spd.push_back(cs);
    }

    for (int i = 0; i < N; i++)
      for (int j = 0; j < N; j++)
      {
        cin >> ds;
        distances[i][j] = ds;
      }

    cout << "Case #" << cas << ": ";

    for (int i = 0; i < Q; i++)
    {
      cin >> start >> end;
      res = solve(distances, start, end);
      cout << res << " ";
    }
    cout << endl;
  }
}
