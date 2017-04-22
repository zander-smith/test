#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <map>
#include <utility>
#include <algorithm>

using namespace std;

string solve(int N, int R, int O, int Y, int G, int B, int V)
{
  string s = "";
  for (int i = 0; i < R; i++)
    s = s + "R";
  for (int i = 0; i < O; i++)
    s = s + "O";
  for (int i = 0; i < Y; i++)
    s = s + "Y";
  for (int i = 0; i < G; i++)
    s = s + "G";
  for (int i = 0; i < B; i++)
    s = s + "B";
  for (int i = 0; i < V; i++)
    s = s + "V";
  return s;
}

int main(int argc, char * argv[])
{
  string res;
  int N, R, O, Y, G, B, V;
  int nr_cases;
  cin >> nr_cases;

  for (int cas = 1; cas <= nr_cases; cas++)
  {
    cin >> N >> R >> O >> Y >> G >> B >> V;

    res = solve(N, R, O, Y, G, B, V);

    cout << "Case #" << cas << ": " << res << endl;
  }
}
