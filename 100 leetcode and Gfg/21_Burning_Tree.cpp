class Solution {
  public:
    int time=0;
    int findans(unordered_map<Node*,Node*>&parent,Node* root,Node* targetnode)
    {
        unordered_map<Node*,bool>isburned;
        queue<Node*>q;
        q.push(targetnode);
        int t=0;
        isburned[targetnode]=1;
        while(!q.empty())
        {
            int size=q.size();
            bool firespreaded=0;
            for(int i=0;i<size;i++)
            {
                Node* front=q.front();
                q.pop();
                if(front->left && !isburned[front->left])
                {
                    q.push(front->left);
                    isburned[front->left]=1;
                    firespreaded=1;
                }
                if(front->right && !isburned[front->right])
                {
                    q.push(front->right);
                    isburned[front->right]=1;
                    firespreaded=1;
                }
                if(parent[front] && !isburned[parent[front]])
                {
                    q.push(parent[front]);
                    isburned[parent[front]]=1;
                    firespreaded=1;
                }
            }
            if(firespreaded)
                    t++;
        }
        return t;
    }
    Node* findmap(unordered_map<Node*,Node*>&parent,Node* root,int target)
    {
        queue<Node*>q;
        Node* targetnode=nullptr;
        q.push(root);
        parent[root]=0;
        while(!q.empty())
        {
            Node* front=q.front();
            q.pop();
            if(front->data==target)
                targetnode=front;
            if(front->left)
            {
                q.push(front->left);
                parent[front->left]=front;
            }
            if(front->right)
            {
                q.push(front->right);
                parent[front->right]=front;
            }
        }
        return targetnode;
    }
    int minTime(Node* root, int target) 
    {
        unordered_map<Node*,Node*>parent;
        Node* targetnode= findmap(parent,root,target);
        return findans(parent,root,targetnode);
    }
};