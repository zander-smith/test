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
  char last = '\0';
  int n = N;
  char max_char;
  int max = 0;
  string s = "";
  // need to buffer G with R, O with B and V with Y
  while (n > 0)
  {
    // find max of R, G, Y
    switch (last)
    {
      case 'G':
        if (R > 0) { s = s + (last = 'R'); R--; }
        else return "IMPOSSIBLE";
      case 'O':
        if (B > 0) { s = s + (last = 'B'); B--; }
        else return "IMPOSSIBLE";
      case 'V':
        if (Y > 0) { s = s + (last = 'Y'); Y--; }
        else return "IMPOSSIBLE";
      case 'R':
        if ((G > Y) && (G > B))
          if (G > 0) { s = s + (last = 'G'); G--; }
          else return "IMPOSSIBLE";
        else if ((Y > G) && (Y > B))
          if (Y > 0) { s = s + (last = 'Y'); Y--; }
          else return "IMPOSSIBLE";
        else
          if (B > 0) { s = s + (last = 'B'); B--; }
          else return "IMPOSSIBLE";
        break;
      case 'Y':
        if ((V > B) && (V > R))
          if (V > 0) { s = s + (last = 'V'); V--; }
          else return "IMPOSSIBLE";
        else if ((B > V) && (B > R))
          if (B > 0) { s = s + (last = 'B'); B--; }
          else return "IMPOSSIBLE";
        else
          if (R > 0) { s = s + (last = 'R'); R--; }
          else return "IMPOSSIBLE";
        break;
      case 'B':
        if ((O > R) && (O > Y))
          if (O > 0) { s = s + (last = 'O'); O--; }
          else return "IMPOSSIBLE";
        else if ((R > O) && (R > Y))
          if (R > 0) { s = s + (last = 'R'); R--; }
          else return "IMPOSSIBLE";
        else
          if (Y > 0) { s = s + (last = 'Y'); Y--; }
          else return "IMPOSSIBLE";
        break;
      default:
        if (R > max) { max = R; max_char = 'R'; }
        if (O > max) { max = O; max_char = 'O'; }
        if (Y > max) { max = Y; max_char = 'Y'; }
        if (G > max) { max = G; max_char = 'G'; }
        if (V > max) { max = V; max_char = 'V'; }
        if (B > max) { max = B; max_char = 'B'; }
        s = s + max_char;
        switch (max_char)
        {
          case 'R':
            R--; last = 'R';
            break;
          case 'O':
            O--; last = 'O';
            break;
          case 'Y':
            Y--; last = 'Y';
            break;
          case 'G':
            G--; last = 'G';
            break;
          case 'B':
            B--; last = 'B';
            break;
          case 'V':
            V--; last = 'V';
            break;
        }
    }
    n--;
  }

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
