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
    // base case: string empty hojaye
    if(word.length() == 0){
        root->isTerminal = true;
        return;
    }

    char ch = word[0];
    TrieNode* child;

    // present: waha chle jao
    // absent: create krdo
    if(root->children.count(ch) == 1)
    {
        child = root->children[ch];
    }
    else
    {
        child = new TrieNode(ch);
        root->children[ch] = child;
    }
    insertIntoTrie(child, word.substr(1));//cover ka substr(1) = over 
}


bool searchTrie(TrieNode*root, string word)
{
    // base case
    // check if last character is terminal
    if(word.length() == 0)
    {
        // iska mtlb root me last character pada hua hai
        return root->isTerminal;
    }
    // 1case
    char ch = word[0];
    TrieNode* child;
    if(root->children.find(ch) != root->children.end())
    {
        // present
        child = root->children[ch];
    }
    else
    {
        // absent
        return false;
    }
    bool recAns = searchTrie(child, word.substr(1));
    return recAns;
}

void deleteWord(TrieNode* root, string word)
{
    // base case: word empty hojaye and root me last character hoga
    if(word.length() == 0){
        root->isTerminal = false;
        return;
    }

    // 1case
    char ch = word[0];
    TrieNode* child;
    if(root->children.find(ch) != root->children.end()){
        // present
        child = root->children[ch];
    }
    else{
        // absent
        return;
    }
    // baki rec sambhal lega
    deleteWord(child,word.substr(1));
}

void printit(TrieNode* root,vector<string>&ans,string temp)
{
    if(root->isTerminal)
    {
        ans.push_back(temp);
    }
    for(auto it=root->children.begin();it!=root->children.end();it++)
    {
        temp.push_back(it->first);
        printit(it->second,ans,temp);
        temp.pop_back();
    }
}

int main()
{
    TrieNode* root = new TrieNode('-');

    insertIntoTrie(root,"cover");
    insertIntoTrie(root,"car");
    insertIntoTrie(root,"care");
    insertIntoTrie(root,"snake");
    insertIntoTrie(root,"sundari");
    insertIntoTrie(root,"extremelyWell");
    insertIntoTrie(root,"coward");
    insertIntoTrie(root,"tag");
    insertIntoTrie(root,"take");
    insertIntoTrie(root,"took");
    insertIntoTrie(root,"selfobsessed");

    bool searchAns = searchTrie(root,"take");
    if(searchAns){
        cout << "found"<<endl;
    }
    else{
        cout<<"not found"<<endl;
    }
    deleteWord(root,"take");
    searchAns = searchTrie(root,"take");
    if(searchAns){
        cout << "found"<<endl;
    }
    else{
        cout<<"not found"<<endl;
    }

    cout<<endl<<"printing"<<endl<<endl;
    string temp="";
    vector<string>ans;
    printit(root,ans,temp);
    sort(ans.begin(),ans.end());
    for(auto s:ans)
        cout<<s<<endl;
}