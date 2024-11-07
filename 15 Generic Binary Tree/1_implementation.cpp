//here the code is in explanation form to understand basics also like printing null etc in 2_question same content with clean code is there must see 
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

Node * createtree()
{
    int val;
    cout<<endl<<"input value to be entered ";
    cin>>val;
    if(val==-1)
        return NULL;
    else
    {
        Node* root=new Node(val);
        cout<<endl<<"adding value to left of node "<<val<<endl;
        root->left=createtree();
        cout<<endl<<"adding value to right of node "<<val<<endl;
        root->right=createtree();
        return root;
    }
}

void preordertraversal(Node* root)
{
    // while creating tree we denoted -1 for null and when we entered -1 then at that point
    // we returned null so root->left/right=NULL not -1 so check for root==NULL not root->data==-1  
    if(root==NULL)
    {
        cout<<"NULL"<<endl;
        return;
    }
    //NLR  N=Node Left=left R=Right
    
    //N
    cout<<root->data<<endl;
    //L
    cout<<endl<<"printing value of left of root "<<root->data<<"--->";
    preordertraversal(root->left);
    
    //R
    cout<<endl<<"printing value of right of root "<<root->data<<"--->";
    preordertraversal(root->right);
}
void inordertraversal(Node* root)
{
    if(root==NULL)
    {
        cout<<"NULL"<<endl;
        return;
    }
    //LNR  N=Node Left=left R=Right
    
    //L
    inordertraversal(root->left);
    
    //N
    cout<<root->data<<endl;
    
    //R
    inordertraversal(root->right);
}

void postordertraversal(Node* root)
{
    if(root==NULL)
    {
        cout<<"NULL"<<endl;
        return;
    }
    //LRN  N=Node Left=left R=Right
    
    //L
    postordertraversal(root->left);
    
    //R
    postordertraversal(root->right);

    //N
    cout<<root->data<<endl;
}

void levelordertraversal(Node* root)
{
    if(root==NULL)
    {
        cout<<"NULL"<<endl;
        return;
    }
    queue<Node*>q;
    q.push(root);
    q.push(NULL);//root ke baad child nodes aayenge level 1 ki so aagey null pe endl use krke newline enter
    while(!q.empty())
    {
        Node * front=q.front();
        q.pop();
        if(front==NULL)
        {
            cout<<endl;
            if(!q.empty())//if leaf node pr hain hai toh tree khatam ho chuka hai 
            {
                q.push(NULL);
            }
        }
        else
        {
            cout<<front->data<<"    ";
            if(front->left!=NULL)
                q.push(front->left);
            if(front->right!=NULL)
                q.push(front->right);
            /*
            right to left
            if(front->right!=NULL)
                q.push(front->right);
            if(front->left!=NULL)
                q.push(front->left);
            */
        }
    }

}
int maxDepth(Node* root) 
{
    if(root==NULL)
        return 0;
    //using post order traversal
    //first go left then go right and then add current node to answer
    int leftsubtree=maxDepth(root->left);
    int rightsubtree=maxDepth(root->right);
    int maxdepth=max(leftsubtree,rightsubtree);
    return maxdepth+1;
}

//question say find no of edges in longest path not no of nodes 
//time complexity O(N^2) because each node is visted twice during getheight
//Space complexity O(heightoftree) because of recursive call stack
int diameterOfBinaryTree(Node* root) 
{
    if(root==NULL)
        return 0;
    int option1=diameterOfBinaryTree(root->left);
    int option2=diameterOfBinaryTree(root->right);
    int option3=maxDepth(root->left)+maxDepth(root->right);
    int maxedges=max(option1,max(option2,option3));
    return maxedges;
}

int main()
{
    Node* root=createtree();

    //while printing i have put NULL also to be printed if not required can be commented inside if statement
    //while coding we may or may not print null it depends 
    //for better understanding and accuracy use null
    //in case not able to understand null's can be commented 
    cout<<endl<<"----------------------------------"<<endl;
    cout<<endl<<"printing whole binary tree using preorder traversal"<<endl;
    cout<<endl<<"value of root is ";
    preordertraversal(root);

    cout<<endl<<"----------------------------------"<<endl;
    cout<<endl<<"printing whole binary tree using inorder traversal"<<endl;
    inordertraversal(root);
    
    cout<<endl<<"----------------------------------"<<endl;
    cout<<endl<<"printing whole binary tree using postorder traversal"<<endl;
    postordertraversal(root);
    cout<<endl;

    cout<<endl<<"----------------------------------"<<endl;
    cout<<endl<<"printing whole binary tree using levelorder traversal"<<endl;
    levelordertraversal(root);
    cout<<endl;

    cout<<endl<<"----------------------------------"<<endl;
    cout<<endl<<"maxdepth of tree "<<endl;
    cout<<maxDepth(root);
    cout<<endl;

    cout<<endl<<"----------------------------------"<<endl;
    cout<<endl<<"diameter of tree ";
    cout<<diameterOfBinaryTree(root)+1;
    cout<<endl<<"edges in diameter of tree ";
    cout<<diameterOfBinaryTree(root);
    cout<<endl;



}