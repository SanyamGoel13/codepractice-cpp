#include<iostream>
#include<queue>
#include<climits>
#include<stack>
using namespace std;
class node
{
    public:
    //properties
    int data;
    node* left;
    node* right;
    //constructor
    node(int data)
    {
        this->data=data;
        left=NULL;
        right=NULL;
    }
};
void preorderrec(node* head)
{
    if(head==NULL)
    {
        return;
    }
    cout<<head->data<<" ";
    preorderrec(head->left);
    preorderrec(head->right);
}
void inorderrec(node* head)
{
    if(head==NULL)
    {
        return;
    }
    inorderrec(head->left);
    cout<<head->data<<" ";
    inorderrec(head->right);
}
void postorderrec(node* head)
{
    if(head==NULL)
    {
        return;
    }
    postorderrec(head->left);
    postorderrec(head->right);
    cout<<head->data<<" ";
}
node* buildtree()
{
    int d;
    cin>>d;
    if(d==-1)
    {
        return NULL;
    }
    node* head=new node(d);
    head->left=buildtree();
    head->right=buildtree();
    return head;
}
int heightofatree(node*head)
{
    if(head==NULL)
    {
        return 0;
    }
    int left=heightofatree(head->left);
    int right=heightofatree(head->right);
    return max(left,right)+1;
}
void printkth(node*head,int k)
{
    if(head==NULL || k<1)
    {
        return;
    }
    if(k==1)
    {
        cout<<head->data<<" ";
        return;
    }
    printkth(head->left,k-1);
    printkth(head->right,k-1);
}
void bfs1(node* head)
{
    int h=heightofatree(head);
    for(int i=1;i<=h;i++)
    {
        printkth(head,i);
        cout<<endl;
    }
}
void bfs2(node* head)
{
    queue<node*> que;
    que.push(head);
    while(!que.empty())
    {
        node* present=que.front();
        que.pop();
        if(present->left) que.push(present->left);
        if(present->right) que.push(present->right);
        cout<<present->data<<" ";
    }
}
void bfs3(node* head)
{
    queue<node*> que;
    que.push(head);
    que.push(NULL);
    while(!que.empty())
    {
        //int i=que.size();
       
        if(que.front()==NULL)
        {
            cout<<endl;
            que.pop();
            if(!que.empty())
            {
                que.push(NULL);
                
            }
        }
        else{
            node* temp=que.front();
            que.pop();
            if(temp->left) que.push(temp->left);
            if(temp->right) que.push(temp->right);
            cout<<temp->data<<" ";
        }
        //cout<<endl;
    }
}
vector<vector<int>> bfs4(node* head)
{
    vector<vector<int>> ans;
    if(head==NULL)
    {
        return ans;
    }
    queue<node*> que;
    que.push(head);
    while(!que.empty())
    {
        vector<int> mediate;
        int i=que.size();
        for(int j=0;j<i;j++)
        {
            node* temp=que.front();
            que.pop();
            if(temp->left) que.push(temp->left);
            if(temp->right) que.push(temp->right);
            mediate.push_back(temp->data);
        }
        ans.push_back(mediate);
    }
    return ans;
}  
vector<int> preorderstc(node*head)
{
    vector<int> ans;
    stack<node*> stc;
    stc.push(head);
    while(!stc.empty())
    {
        node* top=stc.top();
        stc.pop();
        if(top->right) stc.push(top->right);
        if(top->left) stc.push(top->left);
        ans.push_back(top->data);
    }
    return ans;
}
vector<int> inorderstc(node* head)
{
    vector<int> ans;
    if(head==NULL)
    {
        return ans;
    }
    stack<node*> stc;
    node* top=head;
    while(true)
    {
        if(top!=NULL)
        {
            stc.push(top);
            top=top->left;
        }
        else
        {
            if(stc.empty())
            {
                break;
            }
            top=stc.top();
            ans.push_back(top->data);
            stc.pop();
            top=top->right;
        }
    }
    return ans;
}
int height(node *head)
{
    if (head == NULL)
    {
        return 0;
    }
    int a = height(head->left);
    int b = height(head->right);
    return max(a, b) + 1;
}
vector<int> postorder2stc(node* head)
{
    vector<int> ans;
    if(head==NULL)
    {
        return ans;
    }
    stack<node*> st1,st2;
    st1.push(head);
    while(!st1.empty())
    {
        node* med=st1.top();
        st1.pop();
        st2.push(med);
        if(med->left)
        {
            st1.push(med->left);
        }
        if(med->right)
        {
            st1.push(med->right);
        }
    }
    while(!st2.empty())
    {
        ans.push_back(st2.top()->data);
        st2.pop();
    }
    return ans;
}
vector<int> postorder1stc(node* head)
{
    vector<int> ans;
    stack<node*> stc;
    node* cur=head;
    while(!stc.empty() || cur!=NULL)
    {
        if(cur!=NULL)
        {
            stc.push(cur);
            cur=cur->left;
        }
        else
        {
            node* temp=stc.top()->right;
            if(temp==NULL)
            {
                temp=stc.top();
                stc.pop();
                ans.push_back(temp->data);
                while(!stc.empty() && temp==stc.top()->right)
                {
                    temp=stc.top();
                    stc.pop();
                    ans.push_back(temp->data);
                }

            }
            else
            {
                cur=temp;
            }
        }
    }
    return ans;
}
bool balancedtree1(node* head)
{
    if(head==NULL)
    {
        return true;
    }
    bool b1=balancedtree1(head->left);
    bool b2=balancedtree1(head->right);
    if(!b1)
    {
        return false;
    }
    if(!b2)
    {
        return false;
    }
    
    int h1=heightofatree(head->left);
    int h2=heightofatree(head->right);
    if(abs(h1-h2)>1)
    {
        return false;
    }
    
    return true;
    
}
int maxi=INT_MIN;
int balancedtree2(node* head)
{
    if(head==NULL)
    {
        return 0;
    }
    int lh=balancedtree2(head->left);
    int rh=balancedtree2(head->right);
    if(lh==-1)
    {
        return -1;
    }
    if(rh==-1)
    {
        return -1;
    }
    if(abs(lh-rh)>1)
    {
        return -1;
    }
    return max(lh,rh)+1;

}
int diameter1(node* head)
{
    if(head==NULL)
    {
        return 0;
    }
    int lh=diameter1(head->left);
    int rh=diameter1(head->right);
    maxi=max(maxi,lh+rh);
    return max(lh,rh)+1;
}
int maximum=INT_MIN;
int maximumpathsum(node* head)
{
    if(head==NULL)
    {
        return 0;
    }
    int lsum=max(0,maximumpathsum(head->left));
    int rsum=max(0,maximumpathsum(head->right));
    maximum=max(maximum,lsum+rsum+head->data);
    return head->data+max(lsum,rsum);

}
bool isleaf(node *head)
{
    if(head->left==NULL && head->right==NULL)
    {
        return true;
    }
    return false;
}
void printleft(node* head,vector<int>& ans)
{
    node*cur=head->left;
    while(cur)
    {
        if(!isleaf(cur))
        {
            ans.push_back(cur->data);
        }
        if(cur->left)
        {
            cur=cur->left;
        }
        else
        {
            cur=cur->right;
        }
    }
}
void printleaf(node* head,vector<int>& ans)
{
    if(isleaf(head))
    {
        ans.push_back(head->data);
    }
    if(head->left) printleaf(head->left,ans);
    if(head->right) printleaf(head->right,ans);
}
void printright(node* head,vector<int>& ans)
{
    node* cur=head->right;
    vector<int> mediate;
    while(cur)
    {
        if(!isleaf(cur))
        {
            mediate.push_back(cur->data);
        }
        if(cur->right)
        {
            cur=cur->right;
        }
        else
        {
            cur=cur->left;
        }
    }
    for(int i=mediate.size()-1;i>=0;i--)
    {
        ans.push_back(mediate[i]);
    }
}
vector<int> boundarytransversal(node* head)
{
    vector<int> ans;
    if(head==NULL)
    {
        return ans;
    }
    ans.push_back(head->data);
    printleft(head,ans);
    printleaf(head,ans);
    printright(head,ans);
    return ans;
}
int main()
{
    node* head=new node(2);
    head->left=new node(4);
    head->right=new node(5);
    head->left->left=new node(8);
    head->left->right=new node(9);
    head->right->right=new node(7);
    preorderrec(head);
    cout<<endl;
    inorderrec(head);
    cout<<endl;
    postorderrec(head);
    cout<<endl;
    /*node* head2=buildtree();
    preorder(head2);
    cout<<endl;
    inorder(head2);
    cout<<endl;
    postorder(head2);
    cout<<endl;
    */
   cout<<heightofatree(head)<<endl;
   printkth(head,3);
   cout<<endl;
   bfs1(head);
   bfs2(head);
   cout<<endl;
   bfs3(head);
   vector<vector<int>> vec= bfs4(head);
   for(auto i:vec)
   {
        for(auto j:i)
        {
            cout<<j<<" ";
        }
        cout<<endl;
   }
   vector<int> ans=preorderstc(head);
   for(auto k:ans)
   {
        cout<<k<<" ";
   }
   cout<<endl;
   vector<int> ans2=inorderstc(head);
   for(auto q:ans2)
   {
        cout<<q<<" ";
   }
   cout<<endl;
   vector<int> ans3=postorder2stc(head);
   for(auto x:ans3)
   {
        cout<<x<<" ";
   }
   cout<<endl;
   if(balancedtree2(head))
   {
    cout<<"yes"<<endl;
   }
   else
   {
    cout<<"no"<<endl;
   }
   //cout<<endl;
   vector<int> ans4=postorder1stc(head);
   for(auto y:ans4)
   {
        cout<<y<<" ";
   }
   cout<<endl;
   diameter1(head);
   cout<<maxi<<endl;
   maximumpathsum(head);
   cout<<maximum<<endl;
   vector<int> w=boundarytransversal(head);
   for(int t:w)
   {
    cout<<t<<" ";
   }
   
}