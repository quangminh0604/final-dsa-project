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
 
#define ALPHABET 53 // number of differnces of characters 
struct Node {
    int next[ALPHABET]; // array next
    int number_of_word; // the quantity of word which are stop in this node 
    Node() {
        REP(i, ALPHABET) next[i] = -1; // everynode point to null
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
        if (trie[u].next[x] == -1) { // if the prefix does not exist, create new branch
            trie[u].next[x] = sz(trie);
            trie.push_back(Node());
        }
        u = trie[u].next[x]; // go to next node 
    }
    trie[u].number_of_word++; // increase count variant
}

// remove function
void erase(string st) {
    int u = 0;
    for (auto c : st) {
        int x = converting(c); // convert char to int
        u = trie[u].next[x]; // go to next node 
    }
    trie[u].number_of_word--;  // decrease counting of word
}

// check whether a existence of string in the set 
bool check(string st) {
    int u = 0;
    for (auto c : st) {
        int x = converting(c); // convert char to int
        if (trie[u].next[x] == -1) return false; // return false if next node is empty
        u = trie[u].next[x]; // go to next node
    }
    return trie[u].number_of_word > 0;
}

void solve() {
    cin >> n;
    string tmp; getline(cin, tmp); // preparing line in order to getline work normally
    trie.push_back(Node()); // create root of tree 
    FOR(i, 1, n) {
        string st; getline(cin, st); // input string with all capital, uncapital and blank characters
        add(st); 
    }
    
    int n; cin >> n; 
    string st; getline(cin, st); // for normal running like line 104
    FOR(i, 1, n) {
        string T; cin >> T; 
        getline(cin, st);

        reverse(ALL(st));
        st.pop_back();
        reverse(ALL(st));

        if (T == "check") {
            if (check(st)) cout << st << " is in set\n"; // check return true when it finds st in the set and false when can not
            else cout << st << " is not in set\n"; 
        } 
        if (T == "delete") {
            if (check(st)) {
                erase(st);
                cout << st << " is erased completely!\n";
            } else cout << "error delete!\n";
        }
    }
}

// main goes right here 
int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        #ifndef ONLINE_JUDGE
        freopen("Trie.inp", "r", stdin);
        freopen("Trie.out", "w", stdout);
        #else
        //
        #endif // ONLINE_JUDGE*/
        int t = 1; //cin >> t;
        while (t--) solve();
    return 0;
}
