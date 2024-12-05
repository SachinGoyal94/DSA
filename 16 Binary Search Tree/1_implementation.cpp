//100 50 20 60 150 130 180 -1 
#include<bits/stdc++.h>
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
void buildBST(int val,Node* &root)
{
    if(root==NULL)
    {
        root=new Node(val);
    }
    else
    {
        if(val<root->data)
        {
            buildBST(val,root->left);
        }
        else
            buildBST(val,root->right);
    }
}
Node* createtree()
{
    int val;
    cin>>val;
    Node* root=NULL;
    while(val!=-1)
    {
        buildBST(val,root);
        cin>>val;
    }
    return root;
}
void preordertraversal(Node* root)
{
    if(root==NULL)
        return ;
    cout<<root->data<<"    ";
    preordertraversal(root->left);
    preordertraversal(root->right);
}
void inordertraversal(Node* root)
{
    //In the Binary Tree, the Inorder successor of a node is the next node 
    //in the Inorder traversal of the Binary Tree.
    // Inorder Successor is NULL for the last node in Inorder traversal. 
    
    //Inorder preceedor is the previous node in a inorder traversal
    if(root==NULL)
    {
        return;
    }
    inordertraversal(root->left);
    cout<<root->data<<"    ";
    inordertraversal(root->right);
}
void postordertraversal(Node* root)
{
    if(root==NULL)
        return ;
    postordertraversal(root->left);
    postordertraversal(root->right);
    cout<<root->data<<"    ";
}
void levelordertraversal(Node* root)
{
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
                q.push(NULL);
        }
        else
        {
            cout<<front->data<<"     ";
            if(front->left)
                q.push(front->left);
            if(front->right)
                q.push(front->right);
        }
    }
}
int findmin(Node* root)
{
    while(root->left)
        root=root->left;
    return root->data;
}
int findmax(Node* root)
{
    while(root->right)
        root=root->right;
    return root->data;
}
bool findvalue(Node* root,int val)
{
    if(!root)
        return 0;
    if(val==root->data)
        return true;
    if(val<root->data)
        findvalue(root->left,val);
    else
        findvalue(root->right,val);   
}
//Leetcode 450 
Node* deletenode(Node* root,int val)
{
    if(!root)
        return NULL;
    if(root->data==val) //delete this node
    {
        //1 no child leaf node
        if(!root->left && !root->right)
        {
            delete root;
            return NULL;//as leaf node so previousnode->next pe null ho jayega
        }
        //left child present
        if(root->left && !root->right)
        {
            Node* leftchild=root->left;
            delete root;
            return leftchild;//coz left child bach gya so previous node of deleted one se attach hoga
        }
        //right child present
        if(!root->left && root->right)
        {
            Node* rightchild=root->right;
            delete root;
            return rightchild;//previous node ka right 
        }
        //dono present
        //either root ke left subtree ki max value se root ki value replace krke 
        //uss max value node ko delete kro
        //or
        //root ke rightt subtree ki min value se root ki value replace krke 
        //uss min value node ko delete kro
        else
        {
            //thorugh leftmax 
            int leftmaxvalue=findmax(root->left);
            root->data=leftmaxvalue;
            root->left=deletenode(root->left,leftmaxvalue);
            return root;
            /*
            through rightmin
            int rightminvalue=findmin(root->right);
            root->data=rightminalue;
            root->rightt=deletenode(root->right,rightminalue);
            return root;
            */
        }
    }
    else
    {
        if(val < root->data)
            root->left=deletenode(root->left,val);
        else
            root->right=deletenode(root->right,val);
    }
}
int main()
{
    Node * root=createtree();
    levelordertraversal(root);
    cout<<endl;
    preordertraversal(root);
    cout<<endl;
    inordertraversal(root);
    cout<<endl;
    postordertraversal(root);
    cout<<"min value will be at extreme left ";
    cout<<findmin(root)<<endl;
    cout<<"max value will be at extreme right ";
    cout<<findmax(root)<<endl;
    cout<<"time complexity of finding node is O(log N) "<<endl;
    cout<<"find value 130 "<<findvalue(root,130)<<endl;
    deletenode(root,20);
    levelordertraversal(root);
}