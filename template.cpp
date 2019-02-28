#include <bits/stdc++.h>
#pragma GCC target("arch=sandybridge")
#pragma GCC optimize("O3")
#pragma GCC optimize("expensive-optimizations")
using namespace std;
template <class T> int size(const T &x) { return x.size(); }
#define rep(i,a,b) for (__typeof(a) i=(a); i<(b); ++i)
#define iter(it,c) for (__typeof((c).begin()) \
  it = (c).begin(); it != (c).end(); ++it)
#define fs first
#define sc second
#define pb push_back
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long ll;
const int INF = ~(1<<31);

const double EPS = 1e-9;
const double pi = acos(-1);
typedef unsigned long long ull;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
template <class T> T smod(T a, T b) {
  return (a % b + b) % b; }

bool H[100000];
vector<string> tags[100000];

int check_score(vi& arr)
{
    if(arr.size() == 0) return 0;
    int res = 0;
    rep(j,0u,arr.size()-1)
    {
        int i = arr[j];
        size_t l = 0, r = 0;
        int inL = 0, inR = 0, inBoth = 0;
        while(l < tags[i].size() && r < tags[i+1].size())
        {
            if(tags[i][l] == tags[i+1][r])
            {
                inBoth++;
                l++;
                r++;
            }
            else if(tags[i][l] < tags[i+1][r])
            {
                inL++;
                l++;
            }
            else
            {
                inR++;
                r++;
            }
        }
        res += min(inBoth, min(inL, inR));
    }

    return res;
}

vi solve()
{
    return vi();
}

int main()
{
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    rep(i,0,n)
    {
        char c;
        cin >> c;
        H[i] = (c == 'H');
        int m;
        cin >> m;
        tags[i].clear();
        rep(j,0,m)
        {
            string t;
            cin >> t;
            tags[i].push_back(t);
        }
        sort(tags[i].begin(), tags[i].end());
    }

    vi solution = solve();

    cout << "Score: " << check_score(solution) << endl;

    return 0;
}
