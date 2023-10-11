// trees iteration by dfs and bfs
#include <iostream>
#include <queue>
#include<stack>
using namespace std;
class node
{
public:
    int data;
    node *left;
    node *right;
    // function
    node()
    {
    }
    node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};
node *build_tree()
{
    int d;
    cin >> d;
    if (d == -1)
    {
        return NULL;
    }
    node *root = new node(d);
    root->left = build_tree();
    root->right = build_tree();
    return root;
}
void preorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data;
    preorder(root->left);
    preorder(root->right);
    return;
}
void inorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root->data;
    inorder(root->right);
    return;
}
vector<vector<int>> bfs3(node* root)
{
    vector<vector<int>> ans;
    if(root==NULL)
    {
        return ans;
    }
    queue<node*> que;
    que.push(root);
    while(!que.empty())
    {
        vector<int> insert;
        for(int i=0;i<que.size();i++)
        {
            node* store=que.front();
            que.pop();
            if(store->left)
            {
                que.push(store->left);
            }
            if(store->right)
            {
                que.push(store->right);
            }
            insert.push_back(store->data);
        }
        ans.push_back(insert);
    }
}
void postorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->data;
    return;
}
int height(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int left = height(root->left);
    int right = height(root->right);
    return max(left, right) + 1;
}
void printkth(node *root, int k)
{
    if (root == NULL)
    {
        return;
    }
    if (k == 1)
    {
        cout << root->data << " ";
    }
    printkth(root->left, k - 1);
    printkth(root->right, k - 1);
    return;
}
void bfs(node *root)
{
    queue<node *> que;
    que.push(root);
    que.push(NULL);
    while (!que.empty())
    {
        node *store = que.front();
        if (store == NULL)
        {
            cout << endl;
            que.pop();
            if(!que.empty())
            {
                que.push(NULL);
            }
        }
        else
        {
            cout << store->data << " ";
            que.pop();

            if (store->left)
            {
                que.push(store->left);
            }
            if (store->right)
            {
                que.push(store->right);
            }
        }
    }
    return;
}
vector<vector<int>> bfs2(node* root)
{
    vector<vector<int>> ans;
    if(root==NULL)
    {
        return ans;
    }
    queue<node*> queue;
    queue.push(root);
    while(!queue.empty())
    {
        vector<int>level;
        for(int i=0;i<queue.size();i++)
        {
            node* store=queue.front();
            queue.pop();
            level.push_back(store->data);
            if(store->left)
            {
                queue.push(store->left);
            }
            if(store->right)
            {
                queue.push(store->right);
            }
        }
        ans.push_back(level);
    }
    return ans;
        
}
vector<int> preorderite(node*root)
{
    vector<int> ans;
    if(root==NULL)
    {
        return ans;
    }
    stack<node*> stac;
    stac.push(root);
    while(!stac.empty())
    {
        node* store=stac.top();
        stac.pop();
        if(store->right)
        {
            stac.push(store->right);
        }
        if(store->left)
        {
            stac.push(store->left);
        }
        ans.push_back(store->data);
    }

    return ans;
}
int main()
{
    node *root = build_tree();
    preorder(root);
    cout << endl;
    inorder(root);
    cout << endl;
    postorder(root);
    cout << endl;
    cout << height(root);
    cout << endl;
    printkth(root, 3);
    cout<<endl;
    //cout<<"hi"<<endl;
    bfs(root);
    //cout<<endl;
    vector<vector<int>> ans=bfs3(root);
    for(auto p:ans)
    {
        for(auto j:p)
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }
    vector<int>a=preorderite(root);
    for(auto x:a)
    {
        cout<<x<<" ";
    }

    return 0;
}