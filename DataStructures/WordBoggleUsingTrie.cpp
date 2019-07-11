#include <bits/stdc++.h>
using namespace std;

struct TrieNode
{
    TrieNode *child[26];
    bool isLeaf;
};

TrieNode *getNode()
{

    TrieNode *root = new TrieNode;

    for (int i = 0; i < 26; i++)
        root->child[i] = NULL;

    root->isLeaf = false;

    return root;
}

void Insert(TrieNode *root, string str)
{

    int i;

    for (i = 0; i < str.size(); i++)
    {

        int index = str[i] >= 'A' && str[i] <= 'Z' ? str[i] - 'A' : str[i] - 'a';

        if (root->child[index] == NULL)
        {
            root->child[index] = getNode();
        }
        root = root->child[index];
    }
    root->isLeaf = true;
}

bool isSafe(int i, int j, int n, int m)
{
    return i >= 0 && j >= 0 && i < n && j < m;
}
void findWords(TrieNode *root, int i, int j, char boggle[][8],
               set<string> &words, bool visited[][8], string str, int n, int m)
{

    if (root->isLeaf)
    {
        words.insert(str);
    }
    visited[i][j] = true;
    int a, b, y;
    int dx[] = {-1, 1, 0, 0, -1, -1, 1, 1};
    int dy[] = {0, 0, 1, -1, -1, 1, 1, -1};
    for (int k = 0; k < 26; k++)
    {
        char c = boggle[i][j] >= 'A' && boggle[i][j] <= 'Z' ? k + 'A' : k + 'a';
        if (root->child[k])
        {
            for (y = 0; y < 8; y++)
            {
                a = i + dx[y];
                b = j + dy[y];
                if (isSafe(a, b, n, m) && !visited[a][b] && boggle[a][b] == c)
                {

                    findWords(root->child[k], a, b, boggle, words, visited, str + c, n, m);
                }
            }
        }
    }
    visited[i][j] = false;
}
int main()
{
    //code
    int t, i, j, x, n, m;
    cin >> t;

    while (t--)
    {
        char boggle[8][8];
        bool visited[8][8];
        string str[11];
        string s;
        set<string> words;
        cin >> x;
        for (i = 0; i < x; i++)
        {
            cin >> str[i];
        }
        cin >> n >> m;
        for (i = 0; i < n; i++)
            for (j = 0; j < m; j++)
                cin >> boggle[i][j];

        TrieNode *root = getNode();

        for (i = 0; i < x; i++)
        {
            Insert(root, str[i]);
        }
        for (i = 0; i < n; i++)
            for (j = 0; j < m; j++)
            {
                char c = boggle[i][j];
                int index = c >= 'A' && c <= 'Z' ? c - 'A' : c - 'a';

                if (root->child[index])
                {
                    s = s + c;
                    findWords(root->child[index], i, j, boggle, words, visited, s, n, m);
                    s = "";
                }
            }
        if (words.size() == 0)
        {
            cout << "-1\n";
            return 0;
        }
        for (auto i : words)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}