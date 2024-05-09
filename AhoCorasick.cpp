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
    int fail;
    int len;
    Node() {
        REP(i, ALPHABET) next[i] = -1;
        fail = len = 0;
    }
};
 
#define MAX 

int n;
vector<Node> trie;

// add st to the set
void add(string st) {
    int u = 0;
    for (auto c : st) {
        int x = c - 'A'; // convert char to int
        if (trie[u].next[x] == -1) {
            trie[u].next[x] = sz(trie);
            trie.push_back(Node());
        }
        trie[trie[u].next[x]].len = trie[u].len + 1;
        u = trie[u].next[x];
    }
}

// AhoCorasick requires to BFS
void AC_BFS() {
    queue<int> q;
    REP(c, ALPHABET) {
        if (trie[0].next[c] == -1) {
            trie[0].next[c] = 0;
        } else {
            q.push(trie[0].next[c]);
        }
    }
    while (!q.empty()) {
        int u = q.front(); q.pop();
        int f = trie[u].fail;
        REP(c, ALPHABET) {
            if (trie[u].next[c] == -1) {
                trie[u].next[c] = trie[f].next[c];
            } else {
                trie[trie[u].next[c]].fail = trie[f].next[c];
                q.push(trie[u].next[c]);
            }
        }
    }
}

// find longest string in set is existence in the string st, if not exist, cout << -1
int query(string st) {
    int res = -1;
    int u = 0;
    for (auto c : st) {
        int x = c - 'A'; //  convert char to int
        u = trie[u].next[x];
        maximize(res, trie[u].len);
    }
    return res == 0 ? -1 : res;
}

void solve() {
    cin >> n;
    trie.push_back(Node());
    FOR(i, 1, n) {
        string st; cin >> st;
        add(st);
    }
    AC_BFS();
    int numQ; cin >> numQ;
    FOR(i, 1, numQ) {
        string st; cin >> st;
        cout << query(st) << "\n";
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
