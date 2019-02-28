#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template <class T> int size(const T &x) { return x.size(); }
#define rep(i,a,b) for(int i = (a); i < (b); i++)
#define iter(it,c) for(auto it = (c).begin(); it != (c).end();++it)
#define pb push_back
#define fs first
#define sc second
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int INF = ~(1<<31);
const double pi = acos(-1);
const double EPS = 1e-9;

char t[100050];
int Size[100050];
vector<string> k[100050];

set<string> get(ii b) {
    set<string> hold;
    iter(it,k[b.first]) hold.insert(*it);
    iter(it,k[b.second]) hold.insert(*it);
    return hold;
}

int calc(ii a, ii b) {
    set<string> first = get(a);
    set<string> second = get(b);
    int c1 = 0, c2 = 0, c3 = 0;
    iter(it,first) {
        if(second.find(*it) != second.end()) {
            c2++;
        }
    }
    iter(it,first) {
        if(second.find(*it) == second.end()) {
            c1++;
        }
    }
    swap(first,second);
    iter(it,first) {
        if(second.find(*it) == second.end()) {
            c3++;
        }
    }

    return min(c1,min(c2,c3));

}

vector<ii> ans;

int getCost(int i) {
    int j = i+1;
    int totals = 0;
    if(j < ans.size()) {
        totals += calc(ans[i], ans[j]);
    }
    j = i-1;
    if(j > 0) {
        totals += calc(ans[i], ans[j]);
    }
    return totals;
}

int main() {
    cin.sync_with_stdio(false);
    srand(time(NULL));
    //ifstream fin("b_lovely_landscapes.txt");
    ifstream fin("e_shiny_selfies.txt");
    //ifstream fin("d_pet_pictures.txt");
    //ifstream fin("c_memorable_moments.txt");
    int n;
    fin >> n;
    rep(i,0,n) {
        fin >> t[i] >> Size[i];
        rep(j,0,Size[i]) {
            string s;
            fin >> s;
            k[i].push_back(s);
        }
    }
    vector<int> P;
    rep(i,0,n) P.pb(i);
    int bst = 0;

    while(true) {

        cout << "Test ---------------" << endl;
        random_shuffle(P.begin(), P.end());
        ans.clear();
        rep(i,0,n) {
            if(t[P[i]] == 'H') {
                ans.pb(ii(P[i],P[i]));
            } else if(t[P[i]] == 'V') {
                if(i != n-1 && t[P[i+1]] == 'V') {
                    ans.pb(ii(P[i], P[i+1]));
                    i++;
                }
            }
        }
        int sm = 0;
        rep(i,0,ans.size()-1) {
            sm += calc(ans[i], ans[i+1]);
        }
        int besthad = sm;
        cout << "Starting : " << sm << endl;
        rep(j,0,100000) {
            // do whole swap
            int first = rand()%int(ans.size());
            int second = rand()%int(ans.size());
            while(first == second) {
                second = rand()%int(ans.size());
            }
            sm -= getCost(first);
            sm -= getCost(second);
            swap(ans[first],ans[second]);
            sm += getCost(second);
            sm += getCost(first);
            if(sm < besthad) {
                swap(ans[first],ans[second]);
                sm = besthad;
            } else {
                besthad = sm;
                cout << besthad << endl;
            }

            // swap weird
            first = rand()%int(ans.size());
            second = rand()%int(ans.size());
            while(first == second) {
                second = rand()%int(ans.size());
            }
            sm -= getCost(first);
            sm -= getCost(second);
            swap(ans[first].fs, ans[second].fs);
            sm += getCost(second);
            sm += getCost(first);
            if(sm < besthad) {
                swap(ans[first].fs,ans[second].fs);
                sm = besthad;
            } else {
                cout << besthad << endl;
                besthad = sm;
            }

            // swap weird
            first = rand()%int(ans.size());
            second = rand()%int(ans.size());
            while(first == second) {
                second = rand()%int(ans.size());
            }
            sm -= getCost(first);
            sm -= getCost(second);
            swap(ans[first].fs, ans[second].sc);
            sm += getCost(second);
            sm += getCost(first);
            if(sm < besthad) {
                swap(ans[first].fs,ans[second].sc);
                sm = besthad;
            } else {
                cout << besthad << endl;
                besthad = sm;
            }
        }
        cout << "End : " << sm << endl;
        if(sm > bst) {
            cout << "NEW REAL BEST : " << sm << endl;
            bst = sm;
            ofstream fout("output.txt");
            fout << ans.size() << endl;
            iter(it,ans) {
                if(it->first == it->second) fout << it->first << endl;
                else fout << it->first << " " << it->second << endl;
            }
        }

    }
    return 0;
}


