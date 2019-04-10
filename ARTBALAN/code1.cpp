#include <iostream>
#include <string>
using namespace std;

bool isAsolution(const string & s)
{
  int count['Z' - 'A' + 1] = { 0 };

  for (auto c : s)
    count[c - 'A'] += 1;

  string::const_iterator it = s.begin();
  int count0 = count[*it++ - 'A'];

  while (it != s.end())
    if (count[*it++ - 'A'] != count0)
      return false;

  return true;
}

void search(string & s, size_t pos, unsigned nChanges, unsigned & minChanges, string & sol)
{
  if (pos == s.length()) {
      // nChanges <  minChanges, useless to check
    if (isAsolution(s)) {
      minChanges = nChanges;
      sol = s;
    }
  }
  else if (nChanges < (minChanges - 1)) {
    for (char c = 'A'; c <= 'Z'; c += 1) {
      // the string is modified to avoid a lot of copies
      char old = s[pos];

      s[pos] = c;
      search(s, pos + 1, (old == c) ? nChanges : (nChanges + 1), minChanges, sol);
      s[pos] = old;
    }
  }
}

int main()
{
    int t;
    scanf("%d", &t);

    while (t--)
    {
        string s;
        cin>>s;
        cout<<s<<endl;
        for (auto c : s) {
            if ((c < 'A') || (c > 'Z')) {
                cout << "invalid input, chars must be between a and z" << endl;
                return 0;
            }
        }

        if (s.empty() || isAsolution(s))
            cout << s << " is already a solution" << endl;
        else {
            unsigned min = ~0u;
            string sol;

            search(s, 0, 0, min, sol);
            cout << min << " changes to do " << sol << " from " << s << endl;
        }
    }
  return 0;
}
