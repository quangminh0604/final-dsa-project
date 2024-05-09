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
 
#define ALPHABET 53
struct Node {
    int next[ALPHABET];
    int number_of_word;
    Node() {
        REP(i, ALPHABET) next[i] = -1;
        number_of_word = 0;
    }
};
 
#define MAX 1001001

int n; // number of string
vector<Node> trie; // trie(vector) manages list of nodes

int converting(char c) { // change char to int as identified
    if (c == ' ') return 52; // if c is a blank, blank id = 52
    if ('a' <= c && c <= 'z') return 26 + c - 'a'; // uncapital characters have id from 26 to 51
    if ('A' <= c && c <= 'Z') return c - 'A'; // capital charactes have id from 0 to 25 
    assert(false);
}

// add function
void add(string st) {
    int u = 0; 
    for (auto c : st) {
        int x = converting(c); // convert char to int
        if (trie[u].next[x] == -1) {
            trie[u].next[x] = sz(trie);
            trie.push_back(Node());
        }
        u = trie[u].next[x];
    }
    trie[u].number_of_word++; 
}

// remove function
void erase(string st) {
    int u = 0;
    for (auto c : st) {
        int x = converting(c); // convert char to int
        if (trie[u].next[x] == -1) {
            trie[u].next[x] = sz(trie);
            trie.push_back(Node());
        }
        u = trie[u].next[x];
    }
    trie[u].number_of_word--;
}

// check whether a existence of string in the set 
bool check(string st) {
    int u = 0;
    for (auto c : st) {
        int x = converting(c); // convert char to int
        if (trie[u].next[x] == -1) return false;
        u = trie[u].next[x];
    }
    return trie[u].number_of_word > 0;
}

void solve() {
    cin >> n;
    string tmp; getline(cin, tmp);
    trie.push_back(Node());
    FOR(i, 1, n) {
        string st; getline(cin, st); // input string with all capital letters
        add(st);
    }
    
    int n; cin >> n; 
    string st; getline(cin, st); 
    FOR(i, 1, n) {
        getline(cin, st);
        if (check(st)) cout << st << " is in set\n";
        else cout << st << " is not in set\n";
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
