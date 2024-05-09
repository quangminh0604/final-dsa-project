#include<bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define REP(i, b) for (int i = 0, _b = (b); i < _b; i++)
#define ii pair<int, int>
#define pb push_back
#define fi first
#define se second
#define mp make_pair
#define ALL(v) (v).begin(), (v).end()
#define MASK(i) (1LL << (i))
#define BIT(x, i) (((x) >> (i)) & 1LL)
#define ll long long
#define ld long double
#define sz(x) ((int)(x).size())
#define next ____next
#define prev ____prev
#define left ____left
#define right ___right
#define lcm ___lcm
#define index ____index
using namespace std;
 
template<class M> M myabs(M x) {
        return x < 0 ? -x : x;
}
template<class M1, class M2> bool minimize(M1 &x, const M2 &y) {
        if (x > y) {x = y; return true;} return false;
}
template<class M1, class M2> bool maximize(M1 &x, const M2 &y) {
        if (x < y) {x = y; return true;} return false;
}
 
const int INF = (int)1e9 + 7;
const ll INFLL = (ll)1e18 + 7LL;
 
const int dx[] = {1, 0, -1, 0, 1, -1, 1, -1};
const int dy[] = {0, 1, 0, -1, 1, -1, -1, 1};
 
//mt19937 rd(time(0));
 
#define ALPHABET 26
struct Node {
    int next[ALPHABET];
    bool end_of_word;
    Node() {
        REP(i, ALPHABET) next[i] = -1;
        end_of_word = false;
    }
};

#define MAX 1001001

int n;
vector<Node> trie;

void add(int newID, int oldID, string st) {
    for (auto c : st) {
        REP(i, ALPHABET) if (i == c - 'A') {
            trie[newID].next[i] = sz(trie);
            trie.push_back(Node());

            if (oldID != -1) oldID = trie[oldID].next[i];
        } else if (oldID != -1) trie[newID].next[i] = trie[oldID].next[i];
        newID = trie[newID].next[c - 'A'];
    }
    trie[newID].end_of_word = true;
}

bool check(int moment, string st) {
    for (auto c : st) {
        int x = c - 'A'; // convert char to int
        if (trie[moment].next[x] == -1) return false;
        moment = trie[moment].next[x];
    }
    return trie[moment].end_of_word;
}

void solve() {
    cin >> n;
    FOR(i, 0, n) trie.push_back(Node());
    FOR(i, 1, n) {
        string st; cin >> st;
        add(i, i - 1, st);
    }
    int numQ; cin >> numQ;
    FOR(i, 1, numQ) {
        int t; string st; 
        cin >> t >> st;
        if (check(t, st)) cout << "existence!\n"; else cout << "not exist!";
    }
}
 
int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        #ifndef ONLINE_JUDGE
        freopen("test.inp", "r", stdin);
        freopen("test.out", "w", stdout);
        #else
        //
        #endif // ONLINE_JUDGE*/
        int t = 1; //cin >> t;
        while (t--) solve();
    return 0;
}
