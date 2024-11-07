#include <bits/stdc++.h>
using namespace std;
class Node
{
    public:
    Node* left;
    Node* right;
    int data;
    Node(int val)
    {
        left=NULL;
        right=NULL;
        data=val;
    }
};
Node* createtree()
{
    int val;
    cin>>val;
    if(val==-1)
        return NULL;
    Node* root=new Node(val);
    root->left=createtree();
    root->right=createtree();
    return root;
}
void preordertraversal(Node* root)
{
    //NLR
    if(root==NULL)
        return ;
    cout<<root->data<<endl;
    preordertraversal(root->left);
    preordertraversal(root->right);
}
void inordertraversal(Node* root)
{
    //LNR
    if(root==NULL)    
        return ;
    inordertraversal(root->left);
    cout<<root->data<<endl;
    inordertraversal(root->right);
}
void postordertraversal(Node* root)
{
    //LRN
    if(root==NULL)
        return ;
    postordertraversal(root->left);
    postordertraversal(root->right);
    cout<<root->data<<endl;
}
void levelordertraversal(Node* root)
{
    if(root==NULL)
        return;
    queue<Node*>q;
    q.push(root);
    q.push(NULL);
    while(!q.empty())
    {
        Node* front=q.front();
        q.pop();
        if(!front)
        {
            cout<<endl;
            if(!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout<<front->data<<"    ";
            if(front->left)
                q.push(front->left);
            if(front->right)
                q.push(front->right);
            /*
            right to left
            if(front->right)
                q.push(front->right);
            if(front->left)
                q.push(front->left);
            */
        }
    }
}
vector<vector<int>> zigzag(Node* root)
{
    vector<vector<int>>ans;
    queue<Node*>q;
    q.push(root);
    bool lefttoright=true;
    while(!q.empty())
    {
        int width=q.size();
        vector<int>one(width);
        for(int i=0;i<width;i++)
        {
            Node* front=q.front();
            q.pop();
            int index=lefttoright ? i :width-i-1;
            one[index]=front->data;
            if(front->left)
                q.push(front->left);
            if(front->right)
                q.push(front->right);
        }
        lefttoright=!lefttoright;
        ans.push_back(one);
    }
    return ans;
}
int heightoftree(Node*root)
{
    if(!root)
        return 0;
    int lefty=heightoftree(root->left);
    int righty=heightoftree(root->right);
    int maxheight=max(lefty,righty);
    return maxheight+1;
}

int diameteroftree(Node* root)
{
    if(!root)
        return 0;
    int option1=diameteroftree(root->left);
    int option2=diameteroftree(root->right);
    int option3=heightoftree(root->left)+heightoftree(root->right);
    int maxi=max(option1,max(option2,option3));
    return maxi;

}


int main()
{
    Node* root=createtree();
    cout<<"-----------------"<<endl;
    preordertraversal(root);
    cout<<"-----------------"<<endl;
    inordertraversal(root);
    cout<<"-----------------"<<endl;
    postordertraversal(root);
    cout<<"-----------------"<<endl;
    levelordertraversal(root);
    cout<<"-----------------"<<endl;
    vector<vector<int>>ans;
    ans=zigzag(root);
    for(int i=0;i<ans.size();i++)
    {
        for(int j=0;j<ans[i].size();j++)
        {
            cout<<ans[i][j]<<"    ";
        }
        cout<<endl;
    }

    cout<<endl<<"max depth/height of tree is "<<heightoftree(root)<<endl;

    cout<<endl<<"no of edges maximum diameter of tree is "<<diameteroftree(root)<<endl;
    cout<<endl<<"no of nodes in maximum diameter of tree is "<<diameteroftree(root)+1<<endl;


}
//10 20 40 -1 -1 80 90 -1 -1 100 -1 -1  30 50 -1 -1 60 -1 -1
