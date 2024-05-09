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
#define ALPHABET 26 // number of alphabet
struct Node {
    int next[ALPHABET];
    int fail; // kmp at this node
    int len; // depth level
    bool end_of_word;
    Node() {
        REP(i, ALPHABET) next[i] = -1; // point to null
        fail = 0; // all kmp = 0
        len = 0; // still dont have level yet
        end_of_word = false;
    }
};
 
#define MAX 

int n;
vector<Node> trie;

// add st to the set like normal
void add(string st) {
    int u = 0;
    for (auto c : st) {
        int x = c - 'a'; // convert char to int
        if (trie[u].next[x] == -1) { 
            trie[u].next[x] = sz(trie);
            trie.push_back(Node());
        }
        trie[trie[u].next[x]].len = trie[u].len + 1; // calculate the level of next node
        u = trie[u].next[x];
    }
    trie[u].end_of_word = true;
}

// AhoCorasick requires to BFS
void AC_BFS() {
    queue<int> q;
    REP(c, ALPHABET) { // add first level 
        if (trie[0].next[c] == -1) { // if c does not exist in first level
            trie[0].next[c] = 0; // we just give it the direction to root
        } else {
            q.push(trie[0].next[c]); // push into queue
        }
    }

    // next: if next[c] does not exist in tree, we point to the deepest kmp node 
    // at that time, trie[u].next[c] is equal to trie[trie[u].next[c]].fail, if trie[u].next[c] was existed
    while (!q.empty()) {
        int u = q.front(); q.pop();
        int f = trie[u].fail; // deepest kmp node of u
        REP(c, ALPHABET) {
            if (trie[u].next[c] == -1) { // if c does not exist in next level
                trie[u].next[c] = trie[f].next[c]; // assign location to kmp node
            } else { // if c does exist in next level
                trie[trie[u].next[c]].fail = trie[f].next[c]; // assign the fail value of that node
                q.push(trie[u].next[c]); // add to queue to repeat process 
            }
        }
    }
}

// find longest subsequence of st existing in set st, if not exist, print "no existence!!"
string query(string st) {
    string res;
    int u = 0;
    ii ans = mp(0, -1);
    REP(i, sz(st)) {
        int x = st[i] - 'a'; //  convert char to int
        u = trie[u].next[x];
        if (trie[u].end_of_word && trie[u].len > ans.se - ans.fi + 1) 
            ans = mp(i - trie[u].len + 1, i); 
    }
    if (ans == mp(0, -1)) res = "no existence!!";
    else FOR(i, ans.fi, ans.se) res.push_back(st[i]);
    return res;
}

void solve() {
    cin >> n;
    trie.push_back(Node());
    FOR(i, 1, n) {
        string st; cin >> st;
        add(st);
    }
    cout << sz(trie) << "\n";
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
        freopen("AhoCorasick.inp", "r", stdin);
        freopen("AhoCorasick.out", "w", stdout);
        #else
        //
        #endif // ONLINE_JUDGE*/
        int t = 1; //cin >> t;
        while (t--) solve();
    return 0;
}
