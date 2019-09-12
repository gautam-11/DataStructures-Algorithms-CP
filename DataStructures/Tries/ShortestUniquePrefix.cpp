
#include <bits/stdc++.h>
using namespace std;

struct TrieNode
{
    int cnt;
    TrieNode *children[26];
};
TrieNode *getNode()
{

    int i;
    TrieNode *node = new TrieNode();
    node->cnt = 0;

    for (int i = 0; i < 26; i++)
        node->children[i] = NULL;

    return node;
}

void insertTrie(TrieNode *curr, string s)
{

    TrieNode *root = curr;
    for (int i = 0; i < s.size(); i++)
    {

        int idx = s[i] - 'a';
        if (!root->children[idx])
            root->children[idx] = getNode();

        root->children[idx]->cnt += 1;

        root = root->children[idx];
    }
}

string uniquePrefix(TrieNode *root, string s)
{

    string temp = "";

    int i;

    for (i = 0; i < s.size(); i++)
    {

        temp += s[i];
        int idx = s[i] - 'a';
        if (root->children[idx]->cnt == 1)
            break;
        root = root->children[idx];
    }

    return temp;
}
int main()
{

    vector<string> words = {"zebra", "dog", "duck", "dove"};

    TrieNode *root = getNode();

    int i;
    for (i = 0; i < words.size(); i++)
    {
        insertTrie(root, words[i]);
    }
    vector<string> ans;

    for (i = 0; i < words.size(); i++)
    {
        string temp = uniquePrefix(root, words[i]);
        cout << words[i] << "   ->   " << temp << endl;
    }

    return 0;
}
