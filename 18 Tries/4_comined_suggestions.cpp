#include<bits/stdc++.h>
using namespace std;
class TrieNode
{
    public:
    unordered_map<char,TrieNode*>children;
    char data;
    bool isterminal;
    TrieNode(char val)
    {
        data=val;
        isterminal=false;
    }
};
void insertit(TrieNode* root,string word)
{
    if(word.length()==0)
    {
        root->isterminal=true;
        return;
    }
    TrieNode* child;
    char ch=word[0];
    if(root->children.count(ch)==1)
    {
        child=root->children[ch];
    }
    else
    {
        child = new TrieNode(ch);
        root->children[ch]=child;
    }
    return insertit(child,word.substr(1));
}
void printit(TrieNode* root,vector<string>&ans,string temp)
{
    if(root->isterminal)
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
bool searchit(TrieNode* root,string word)
{
    if(word.length()==0)
        return root->isterminal;
    TrieNode* child;
    char ch=word[0];
    if(root->children.find(ch)!=root->children.end())
    {
        child=root->children[ch];
    }
    else
        return false;
    return searchit(child,word.substr(1));
}
TrieNode* searchprefix(TrieNode* root,string prefix)
{
    if(!prefix.length())
        return root;
    TrieNode* child;
    char ch=prefix[0];
    if(root->children.find(ch)!=root->children.end())
    {
        child=root->children[ch];
    }
    else
    {
        return NULL;
    }
    return searchprefix(child,prefix.substr(1));
}
void getwords(TrieNode* root,vector<string>&ans,string temp)
{
    if(root->isterminal)
    {
        ans.push_back(temp);
    }
    for(auto it=root->children.begin();it!=root->children.end();it++)
    {
        temp.push_back(it->first);
        getwords(it->second,ans,temp);
        temp.pop_back();
    }
}
int main()
{
    TrieNode* root=new TrieNode('\0');
    insertit(root,"bowl");
    insertit(root,"bowled");
    insertit(root,"bomb");
    insertit(root,"born");
    insertit(root,"bornfire");
    insertit(root,"ball");
    insertit(root,"babes");
    insertit(root,"baby");

    cout<<"printing all strings : "<<endl;
    string temp="";
    vector<string>ans;
    printit(root,ans,temp);
    for(auto s:ans)
        cout<<s<<endl;

    cout<<endl<<endl<<"printing with prefix"<<endl<<endl;

    string prefix="bo";
    TrieNode* prefixroot=searchprefix(root,prefix);
    vector<string>suggestions;
    string sgg;
    getwords(prefixroot,suggestions,sgg);
    for(auto s:suggestions)
    {
        cout<<prefix+s<<endl;
    }
    
    cout<<endl<<endl<<"printing with particular prefix"<<endl<<endl;

    vector<vector<string>>allsuggest;
    for(int i=0;i<prefix.length();i++)
    {
        TrieNode* proot=searchprefix(root,prefix.substr(0,i+1));
        vector<string>suggestnow;
        string temp2;
        getwords(proot,suggestnow,temp2);
        allsuggest.push_back(suggestnow);
    }

    //printing now 
    for(int i=0;i<allsuggest.size();i++)
    {
        cout<<endl<<"prefix = "<<prefix.substr(0,i+1)<<endl<<endl;
        string p=prefix.substr(0,i+1);
        for(int j=0;j<allsuggest[i].size();j++)
        {
            cout<<p+allsuggest[i][j]<<endl;
        }
    }
}

