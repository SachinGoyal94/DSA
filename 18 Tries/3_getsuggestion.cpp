#include<bits/stdc++.h>
using namespace std;

class TrieNode
{
    public:
        char value;
        unordered_map<int,TrieNode*>children;
        bool isTerminal;
        TrieNode(char data)
        {
            value = data;
            isTerminal = false;
        }
};

void insertIntoTrie(TrieNode* root, string word)
{
    if(word.length() == 0)
    {
        root->isTerminal = true;
        return;
    }

    char ch = word[0];
    TrieNode* child;

    if(root->children.count(ch) == 1)
        child = root->children[ch];
    else
    {
        child = new TrieNode(ch);
        root->children[ch] = child;
    }
    insertIntoTrie(child, word.substr(1)); 
}

void storestring(TrieNode* root,vector<string>&ans,string temp)
{
    if(root->isTerminal)
    {
        ans.push_back(temp);
        return;
    }
    for(auto i:root->children)
    {
        char ch=i.first;
        TrieNode* child=i.second;
        temp.push_back(ch);
        storestring(child,ans,temp);
        temp.pop_back();
    }
}

void getwords(TrieNode* root,vector<string>&ans,string prefix)
{
    if(prefix.length()==0)
    {
        string temp="";
        storestring(root,ans,temp);
        return;
    }
    char ch=prefix[0];
    TrieNode*child;
    if(root->children.find(ch)!=root->children.end())
    {
        child=root->children[ch];
    }
    else
    {
        return;
    }
    getwords(child,ans,prefix.substr(1));
}

vector<vector<string>> getsuggestions(TrieNode* root,string prefix)
{
    string temp="";
    vector<vector<string>>ans;
    for(int i=0;i<prefix.length();i++)
    {
        vector<string>tempans;
        char ch=prefix[i];
        temp.push_back(ch);
        getwords(root,tempans,temp);
        for(int j=0;j<tempans.size();j++)
        {
            tempans[j]=temp+tempans[j];
        }
        ans.push_back(tempans);
    }
    return ans;
}

int main()
{
    string prefix="bab";
    TrieNode* root=new TrieNode('-');
    insertIntoTrie(root,"babbar");
    insertIntoTrie(root,"baby");
    insertIntoTrie(root,"ball");
    insertIntoTrie(root,"babes");
    insertIntoTrie(root,"bike");
    insertIntoTrie(root,"tall");

    vector<vector<string>>ans=getsuggestions(root,prefix);

    for(int i=0;i<ans.size();i++)
    {
        for(int j=0;j<ans[i].size();j++)
        {
            cout<<ans[i][j]<<"      ";
        }
        cout<<endl;
    }
}