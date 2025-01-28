/*
when we type anything in chrome search bar it provides suggestion 
like    c it can gives chess chrome caught ...
        ch ->   chess chrome chats
        cha->   chat

there are two ways do to so

get suggestions for any particular string ex bab 
get suggestion for every particular input like b   then for ba  then bab
*/

#include<bits/stdc++.h>
using namespace std;
class TrieNode{
    public:
        char value;
        unordered_map<int,TrieNode*>children;
        bool isTerminal;
        //is terminal means that "cover" r is term. char. so the word is completed 
        //whenever term.=true it means word present else absent
        TrieNode(char data)
        {
            value = data;
            isTerminal = false;
        }
};

void insertIntoTrie(TrieNode* root, string word)
{
    if(word.length() == 0){
        root->isTerminal = true;
        return;
    }

    char ch = word[0];
    TrieNode* child;

    if(root->children.count(ch) == 1)
    {
        child = root->children[ch];
    }
    else
    {
        child = new TrieNode(ch);
        root->children[ch] = child;
    }
    insertIntoTrie(child, word.substr(1));
}


bool searchTrie(TrieNode*root, string word)
{
    if(word.length() == 0)
        return root->isTerminal;
    char ch = word[0];
    TrieNode* child;
    if(root->children.find(ch) != root->children.end())
        child = root->children[ch];
    else
        return false;
    bool recAns = searchTrie(child, word.substr(1));
    return recAns;
}

void deleteWord(TrieNode* root, string word)
{
    if(word.length() == 0)
    {
        root->isTerminal = false;
        return;
    }

    char ch = word[0];
    TrieNode* child;
    if(root->children.find(ch) != root->children.end())
        child = root->children[ch];
    else
        return;
    deleteWord(child,word.substr(1));
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

int main()
{
    string prefix="bab";
    TrieNode* root=new TrieNode('-');
    insertIntoTrie(root,"babbar");
    insertIntoTrie(root,"baby");
    insertIntoTrie(root,"ball");
    insertIntoTrie(root,"babes");
    vector<string>ans;

    getwords(root,ans,prefix);

    for(int i=0;i<ans.size();i++)
    {
        ans[i]=prefix+ans[i];
        cout<<ans[i]<<endl;
    }

    //for every particular input
    //check 3_getsuggestions

}