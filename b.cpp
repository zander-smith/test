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
  string s = "";
  // need to buffer G with R, O with B and V with Y
  while (n > 0)
  {
    // find max of R, G, Y
    select (last)
    {
      case 'R':
        if (B > Y)
          { s = s + (last = 'B'); B--; }
        else
          { s = s + (last = 'Y'); Y--; }
        break;
      case 'Y':
        if (B > R)
          { s = s + (last = 'B'); B--; }
        else
          { s = s + (last = 'R'); R--; }
        break;
      case 'B':
        if (Y > R)
          { s = s + (last = 'Y'); Y--; }
        else
          { s = s + (last = 'R'); R--; }
        break;
      default:
        if ((R > B) && (R > Y))
          { s = s + (last = 'R'); R--; }
        else if ((B > R) && (B > Y))
          { s = s + (last = 'B'); B--; }
        else
          { s = s + (last = 'Y'); Y--; }
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
