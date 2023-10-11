#include <iostream>
#include <algorithm>
#include <climits>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>
#include <math.h>
using namespace std;
class node
{
public:
    // properties
    int data;
    node *left;
    node *right;
    node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};
node *build_tree()
{
    int n;
    cin >> n;
    if (n == -1)
    {
        return NULL;
    }
    node *head = new node(n);
    head->left = build_tree();
    head->right = build_tree();
    return head;
}
void preorder(node *head)
{
    if (head == NULL)
    {
        return;
    }
    cout << head->data << " ";
    preorder(head->left);
    preorder(head->right);
}
void postorder(node *head)
{
    if (head == NULL)
    {
        return;
    }
    postorder(head->left);
    postorder(head->right);
    cout << head->data << " ";
}
void inorder(node *head)
{
    if (head == NULL)
    {
        return;
    }
    inorder(head->left);
    cout << head->data << " ";
    inorder(head->right);
}
int heightofatree(node *head)
{
    if (head == NULL)
    {
        return 0;
    }
    int leftheight = heightofatree(head->left);
    int rightheight = heightofatree(head->right);
    return max(rightheight, leftheight) + 1;
}
void printkth(node *head, int height)
{
    if (head == NULL || height == 0)
    {
        return;
    }
    if (height == 1)
    {
        cout << head->data << " ";
    }
    printkth(head->left, height - 1);
    printkth(head->right, height - 1);
}
void bfs1(node *head)
{
    int height = heightofatree(head);
    for (int i = 1; i <= height; i++)
    {
        printkth(head, i);
        cout << endl;
    }
}
void bfs2(node *head)
{
    queue<node *> que;
    que.push(head);
    while (!que.empty())
    {
        node *front = que.front();
        que.pop();
        cout << front->data << " ";
        if (front->left)
            que.push(front->left);
        if (front->right)
            que.push(front->right);
    }
}
vector<vector<int>> bfs3(node *head)
{
    vector<vector<int>> ans;
    if (head == NULL)
    {
        return ans;
    }
    queue<node *> que;
    que.push(head);
    while (!que.empty())
    {
        int size = que.size();
        vector<int> mediate;
        for (int i = 0; i < size; i++)
        {
            node *front = que.front();
            que.pop();
            mediate.push_back(front->data);
            if (front->left)
                que.push(front->left);
            if (front->right)
                que.push(front->right);
        }
        ans.push_back(mediate);
    }
    return ans;
}
void bfs4(node *head)
{
    queue<node *> que;
    que.push(head);
    que.push(NULL);
    while (!que.empty())
    {
        node *front = que.front();
        if (front == NULL)
        {
            que.pop();
            cout << endl;
            if (!que.empty())
            {
                que.push(NULL);
            }
        }
        else
        {
            que.pop();
            cout << front->data << " ";
            if (front->left)
                que.push(front->left);
            if (front->right)
                que.push(front->right);
        }
    }
}
void preorderite(node *head)
{
    stack<node *> stc;
    stc.push(head);
    while (!stc.empty())
    {
        node *top = stc.top();
        stc.pop();
        if (top->right)
            stc.push(top->right);
        if (top->left)
            stc.push(top->left);
        cout << top->data << " ";
    }
}
void inorderite(node *head)
{
    stack<node *> stc;
    node *cur = head;
    while (true)
    {
        if (cur)
        {
            stc.push(cur);
            cur = cur->left;
        }
        else
        {
            if (stc.empty())
            {
                break;
            }
            node *top = stc.top();
            cout << top->data << " ";
            stc.pop();
            cur = top->right;
        }
    }
}
void postorderitestack2(node *head)
{
    if (head == NULL)
    {
        return;
    }
    stack<node *> stc1;
    stack<node *> stc2;
    stc1.push(head);
    while (!stc1.empty())
    {
        node *top = stc1.top();
        stc1.pop();
        stc2.push(top);
        if (top->left)
        {
            stc1.push(top->left);
        }
        if (top->right)
        {
            stc1.push(top->right);
        }
    }
    while (!stc2.empty())
    {
        cout << stc2.top()->data << " ";
        stc2.pop();
    }
}
void postorderitestc1(node *head)
{
    stack<node *> stc;
    node *cur = head;
    while (!stc.empty() || cur != NULL)
    {
        if (cur != NULL)
        {
            stc.push(cur);
            cur = cur->left;
        }
        else
        {
            node *temp = stc.top()->right;
            if (temp == NULL)
            {
                temp = stc.top();
                stc.pop();
                cout << temp->data << " ";
                while (!stc.empty() && temp == stc.top()->right)
                {
                    temp = stc.top();
                    stc.pop();
                    cout << temp->data << " ";
                }
            }
            else
            {
                cur = temp;
            }
        }
    }
}
bool balanced(node *head)
{
    if (head == NULL)
    {
        return true;
    }
    bool lr = balanced(head->left);
    bool rr = balanced(head->right);
    if (!lr || !rr)
    {
        return false;
    }
    int lh = heightofatree(head->left);
    int rh = heightofatree(head->right);
    if (abs(lh - rh) > 1)
    {
        return false;
    }
    return true;
}
int balanced2(node *head)
{
    if (head == NULL)
    {
        return 0;
    }
    int lh = balanced2(head->left);
    int rh = balanced2(head->right);
    if (lh == -1 || rh == -1)
    {
        return -1;
    }
    if (abs(lh - rh) > 1)
    {
        return -1;
    }
    return max(lh, rh) + 1;
}
int diameterofatree(node *head)
{
    if (head == NULL)
    {
        return 0;
    }
    int rhl = diameterofatree(head->left);
    int rhr = diameterofatree(head->right);
    int maxi = max(rhr, rhl);
    int lh = heightofatree(head->left);
    int rh = heightofatree(head->right);
    return max(maxi, lh + rh);
}
int maxi = INT_MIN;
int diameterofatree2(node *head)
{
    if (head == NULL)
    {
        return 0;
    }
    int lh = diameterofatree2(head->left);
    int rh = diameterofatree2(head->right);
    maxi = max(maxi, lh + rh);
    return max(lh, rh) + 1;
}
int maximum = INT_MIN;
int maximumpathsum(node *head)
{
    if (head == NULL)
    {
        return 0;
    }
    int lh = maximumpathsum(head->left);
    int rh = maximumpathsum(head->right);
    maximum = max(maximum, lh + rh + head->data);
    return max(0, max(lh + head->data, rh + head->data));
}
bool isidentical(node *head1, node *head2)
{
    if (head1 == NULL || head2 == NULL)
    {
        return head1 == head2;
    }
    bool lh = isidentical(head1->left, head2->left);
    bool rh = isidentical(head1->right, head2->right);
    if (!lh || !rh)
    {
        return false;
    }
    if (head1->data == head2->data)
    {
        return true;
    }
    return false;
}
vector<vector<int>> zigzagtrans(node *head)
{
    vector<vector<int>> ans;
    queue<node *> que;
    int flag = 1;
    que.push(head);
    while (!que.empty())
    {
        vector<int> mediate;
        int size = que.size();
        for (int i = 0; i < size; i++)
        {
            node *front = que.front();
            que.pop();
            if (front->left)
                que.push(front->left);
            if (front->right)
                que.push(front->right);
            mediate.push_back(front->data);
        }
        if (flag == 0)
        {
            reverse(mediate.begin(), mediate.end());
            ans.push_back(mediate);
            flag = 1;
        }
        else
        {
            ans.push_back(mediate);
            flag = 0;
        }
    }
    return ans;
}
bool isleaf(node *head)
{
    if (head->left == NULL && head->right == NULL)
    {
        return true;
    }
    return false;
}
void leftboundary(node *head, vector<int> &ans)
{
    node *cur = head->left;
    while (cur)
    {
        // head=head->left;
        if (!isleaf(cur))
        {
            ans.push_back(cur->data);
        }
        if (cur->left)
        {
            cur = cur->left;
        }
        else
        {
            cur = cur->right;
        }
    }
}
void leafs(node *head, vector<int> &ans)
{
    if (isleaf(head))
    {
        ans.push_back(head->data);
    }
    if (head->left)
    {
        leafs(head->left, ans);
    }
    if (head->right)
    {
        leafs(head->right, ans);
    }
}
void rightboundary(node *head, vector<int> &ans)
{
    vector<int> temp;
    node *cur = head->right;
    while (cur)
    {
        if (!isleaf(cur))
        {
            temp.push_back(cur->data);
        }
        if (cur->right)
        {
            cur = cur->right;
        }
        else
        {
            cur = cur->left;
        }
    }
    reverse(temp.begin(), temp.end());
    for (int i = 0; i < temp.size(); i++)
    {
        ans.push_back(temp[i]);
    }
}
vector<int> boundarytranversal(node *head)
{
    vector<int> ans;
    if (head == NULL)
    {
        return ans;
    }
    ans.push_back(head->data);
    leftboundary(head, ans);
    leafs(head, ans);
    rightboundary(head, ans);
    return ans;
}
vector<vector<int>> verticalorder(node *head)
{
    vector<vector<int>> ans;
    map<int, map<int, multiset<int>>> mapi;
    queue<pair<node *, pair<int, int>>> que;
    que.push({head, {0, 0}});
    while (!que.empty())
    {
        node *front = que.front().first;
        int height = que.front().second.first;
        int width = que.front().second.second;
        que.pop();
        if (front->left)
        {
            que.push({front->left, {height + 1, width - 1}});
        }
        if (front->right)
        {
            que.push({front->right, {height + 1, width + 1}});
        }
        mapi[width][height].insert(front->data);
    }
    for (auto it : mapi)
    {
        vector<int> mediate;
        for (auto w : it.second)
        {
            mediate.insert(mediate.end(), w.second.begin(), w.second.end());
        }
        ans.push_back(mediate);
    }
    return ans;
}
vector<int> topview(node *head)
{
    vector<int> ans;
    map<int, int> mapi;
    queue<pair<node *, int>> que;
    que.push({head, 0});
    while (!que.empty())
    {
        node *front = que.front().first;
        int dat = que.front().second;
        que.pop();
        if (front->left)
        {
            que.push({front->left, dat - 1});
        }
        if (front->right)
        {
            que.push({front->right, dat + 1});
        }
        if (!mapi.count(dat))
        {
            mapi[dat] = front->data;
        }
    }
    for (auto j : mapi)
    {
        ans.push_back(j.second);
    }
    return ans;
}
int findBottomLeftValue(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int maxh = heightofatree(root);
    int h = 0;
    queue<node *> que;
    que.push(root);
    while (!que.empty())
    {
        h++;
        int size = que.size();
        for (int i = 0; i < size; i++)
        {
            node *front = que.front();
            que.pop();
            if (front->left)
            {
                que.push(front->left);
            }
            if (front->right)
            {
                que.push(front->right);
            }
            if (h == maxh)
            {
                return front->data;
            }
        }
    }
}
vector<int> bottomview(node *head)
{
    vector<int> ans;
    map<int, int> mapi;
    queue<pair<node *, int>> que;
    que.push({head, 0});
    while (!que.empty())
    {
        node *front = que.front().first;
        int dat = que.front().second;
        que.pop();
        if (front->left)
        {
            que.push({front->left, dat - 1});
        }
        if (front->right)
        {
            que.push({front->right, dat + 1});
        }
        mapi[dat] = front->data;
    }
    for (auto j : mapi)
    {
        ans.push_back(j.second);
    }
    return ans;
}
vector<int> rightview(node *head)
{
    vector<int> ans;
    queue<node *> que;
    que.push(head);
    while (!que.empty())
    {
        int j = 0;
        int size = que.size();
        for (int i = 0; i < size; i++)
        {
            node *front = que.front();
            if (j == size - 1)
            {
                ans.push_back(front->data);
            }
            que.pop();
            if (front->left)
            {
                que.push(front->left);
            }
            if (front->right)
            {
                que.push(front->right);
            }
            j++;
        }
    }
    return ans;
}
bool issymmetrical(node *head1, node *head2)
{
    if (head1 == NULL || head2 == NULL)
    {
        return head1 == head2;
    }
    return (head1->data == head2->data) && issymmetrical(head1->left, head2->right) && issymmetrical(head1->right, head2->left);
}
bool symmetric(node *head)
{
    return head == NULL || issymmetrical(head->left, head->right);
}
bool mapping(node *head, int root, vector<int> &ans)
{
    if (head == NULL)
    {
        return false;
    }
    ans.push_back(head->data);
    if (head->data == root)
    {
        return true;
    }
    bool lh = mapping(head->left, root, ans);
    bool rh = mapping(head->right, root, ans);
    if (!lh && !rh)
    {
        ans.pop_back();
        return false;
    }
    return true;
}
vector<int> roottonode(node *head, int root)
{
    vector<int> ans;
    if (head == NULL)
    {
        return ans;
    }
    // ans.push_back(head);
    mapping(head, root, ans);
    return ans;
}
node *lowestcommonancestor(node *head, node *p, node *q)
{
    if (head == NULL)
    {
        return NULL;
    }
    if (head == p)
    {
        return p;
    }
    if (head == q)
    {
        return q;
    }
    node *l = lowestcommonancestor(head->left, p, q);
    node *r = lowestcommonancestor(head->right, p, q);
    if (l && r)
    {
        return head;
    }
    if (l || r)
    {
        if (l)
        {
            return l;
        }
        return r;
    }
    return NULL;
}
int widthOfBinaryTree(node *head)
{
    if (head == NULL)
    {
        return 0;
    }
    int ans = 0;
    queue<pair<node *, int>> que;
    que.push({head, 1});
    while (!que.empty())
    {
        int size = que.size();
        int fron, last;
        int mmin = que.front().second;
        for (int i = 0; i < size; i++)
        {
            node *front = que.front().first;
            long long int v = que.front().second - mmin;
            que.pop();
            if (front->left)
            {
                que.push({front->left, v * 2});
            }
            if (front->right)
            {
                que.push({front->right, v * 2 + 1});
            }
            if (i == 0)
            {
                fron = v;
            }
            if (i == size - 1)
            {
                last = v;
            }
        }
        ans = max(ans, last - fron + 1);
    }
    return ans;
}
/*int widthOfBinaryTree(node *head)
{
    if (head == NULL)
    {
        return 0;
    }
    queue<pair<node *, int>> que;
    que.push({head, 0});
    int width = 0;
    while (!que.empty())
    {
        int size = que.size();
        int mmin = que.front().second;
        int front, last;
        for (int i = 0; i < size; i++)
        {
            long long int cur_index = que.front().second - mmin;
            node *nd = que.front().first;
            que.pop();
            if (i == 0)
            {
                front = cur_index;
            }
            if (i == size - 1)
            {
                last = cur_index;
            }
            if (nd->left)
            {
                que.push({nd->left, cur_index * 2 + 1});
            }
            if (nd->right)
            {
                que.push({nd->right, cur_index * 2 + 2});
            }
        }
        width = max(width, last - front + 1);
    }
    return width;
}*/
void childrensumproperty(node *head)
{
    if (head == NULL)
        return;
    int child = 0;
    if (head->left)
        child += head->left->data;
    if (head->right)
        child += head->right->data;
    if (head->data > child)
    {
        if (head->left)
            head->left->data = head->data;
        if (head->right)
            head->right->data = head->data;
    }
    childrensumproperty(head->left);
    childrensumproperty(head->right);
    int tot = 0;
    if (head->left)
        tot += head->left->data;
    if (head->right)
        tot += head->right->data;
    if (head->right || head->left)
        head->data = tot;
}
void parentmapping(node *head, unordered_map<node *, node *> &mapi)
{
    queue<node *> que;
    que.push(head);
    while (!que.empty())
    {
        node *front = que.front();
        // node* back=que.front().second;
        que.pop();
        if (front->left)
        {
            que.push(front->left);
            mapi[front->left] = front;
        }
        if (front->right)
        {
            que.push(front->right);
            mapi[front->right] = front;
        }
    }
}
vector<int> nodesatkthdistance(node *head, node *target, int distance)
{
    unordered_map<node *, node *> mapi;
    parentmapping(head, mapi);
    unordered_map<node *, int> check;
    queue<node *> match;
    match.push(target);
    check[target] = 1;
    int j = 0;
    while (!match.empty())
    {
        if (j == distance)
        {
            break;
        }
        j++;
        int size = match.size();
        for (int i = 0; i < size; i++)
        {
            node *front = match.front();
            match.pop();
            if (front->left && check[front->left] == 0)
            {
                match.push(front->left);
                check[front->left] = 1;
            }
            if (front->right && check[front->right] == 0)
            {
                match.push(front->right);
                check[front->right] = 1;
            }
            if (mapi[front] && check[mapi[front]] == 0)
            {
                check[mapi[front]] = 1;
                match.push(mapi[front]);
            }
        }
    }
    vector<int> ans;
    while (!match.empty())
    {
        node *r = match.front();
        match.pop();
        ans.push_back(r->data);
    }
    return ans;
}
int timetoburn(node *head, node *target)
{
    unordered_map<node *, node *> mapi;
    parentmapping(head, mapi);
    unordered_map<node *, int> check;
    queue<node *> match;
    match.push(target);
    check[target] = 1;
    int j = 0;
    while (!match.empty())
    {
        int f = 0;
        int size = match.size();
        for (int i = 0; i < size; i++)
        {
            node *front = match.front();
            match.pop();
            if (front->left && check[front->left] == 0)
            {
                match.push(front->left);
                check[front->left] = 1;
                f = 1;
            }
            if (front->right && check[front->right] == 0)
            {
                match.push(front->right);
                check[front->right] = 1;
                f = 1;
            }
            if (mapi[front] && check[mapi[front]] == 0)
            {
                check[mapi[front]] = 1;
                match.push(mapi[front]);
                f = 1;
            }
        }
        if (f == 1)
            j++;
    }
    return j;
}
int countnodes(node *head)
{
    if (head == NULL)
    {
        return 0;
    }
    int lef = 0;
    node *lefty = head;
    int righ = 0;
    node *righty = head;
    while (lefty)
    {
        lefty = lefty->left;
        lef++;
    }
    while (righty)
    {
        righty = righty->right;
        righ++;
    }
    if (lef == righ)
    {
        return pow(2, lef) - 1;
    }
    int lf = countnodes(head->left);
    int rf = countnodes(head->right);
    return lf + rf + 1;
}
vector<int> morristransversalinorder(node *head)
{
    vector<int> ans;
    node *cur = head;
    while (cur)
    {
        if (!cur->left)
        {
            ans.push_back(cur->data);
            cur = cur->right;
        }
        else
        {
            node *temp = cur->left;
            while (temp->right && temp->right != cur)
            {
                temp = temp->right;
            }
            if (temp->right == NULL)
            {
                temp->right = cur;
                cur = cur->left;
            }
            else
            {
                temp->right = NULL;
                ans.push_back(cur->data);
                cur = cur->right;
            }
        }
    }
    return ans;
}
vector<int> morristransversalpreorder(node *head)
{
    vector<int> ans;
    node *cur = head;
    while (cur)
    {
        if (!cur->left)
        {
            ans.push_back(cur->data);
            cur = cur->right;
        }
        else
        {
            node *temp = cur->left;
            while (temp->right && temp->right != cur)
            {
                temp = temp->right;
            }
            if (temp->right == NULL)
            {
                temp->right = cur;
                ans.push_back(cur->data);
                cur = cur->left;
            }
            else
            {
                temp->right = NULL;
                cur = cur->right;
            }
        }
    }
    return ans;
}
void flatten(node *root)
{
    node *cur = root;
    while (cur)
    {
        if (cur->left && cur->right)
        {
            node *temp = cur->left;
            while (temp->right)
            {
                temp = temp->right;
            }
            temp->right = cur->right;
            cur->right = cur->left;
            cur->left = NULL;
        }
        else if (cur->left)
        {
            cur->right = cur->left;
            cur->left = NULL;
        }
        else
        {
            cur = cur->right;
        }
    }
    // return root;
}
int main()
{
    node *head1 = new node(8);
    head1->left = new node(5);
    head1->right = new node(9);
    head1->left->left = new node(6);
    head1->left->right = new node(1);
    head1->right->right = new node(4);
    head1->right->right->right = new node(2);
    // node* head2=build_tree();
    preorder(head1);
    cout << endl;
    // preorder(head2);
    inorder(head1);
    cout << endl;
    postorder(head1);
    cout << endl;
    cout << heightofatree(head1);
    cout << endl;
    printkth(head1, 3);
    cout << endl;
    bfs1(head1);
    // cout<<endl;
    bfs2(head1);
    cout << endl;
    vector<vector<int>> ans1 = bfs3(head1);
    for (auto q : ans1)
    {
        for (auto w : q)
        {
            cout << w << " ";
        }
        cout << endl;
    }
    cout << "bfs4" << endl;
    bfs4(head1);
    preorderite(head1);
    cout << endl;
    inorderite(head1);
    cout << endl;
    postorderitestack2(head1);
    cout << endl;
    postorderitestc1(head1);
    cout << endl;
    cout << balanced2(head1);
    cout << endl;
    cout << diameterofatree(head1);
    cout << endl;
    diameterofatree2(head1);
    cout << maxi;
    cout << endl;
    maximumpathsum(head1);
    cout << maximum;
    cout << endl;
    cout << isidentical(head1, head1);
    cout << endl;
    vector<vector<int>> ans2 = zigzagtrans(head1);
    for (auto i : ans2)
    {
        for (int j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    vector<int> ans4 = boundarytranversal(head1);
    for (int y : ans4)
    {
        cout << y << " ";
    }
    cout << endl;
    vector<vector<int>> ans5 = verticalorder(head1);
    for (auto qw : ans5)
    {
        for (auto wq : qw)
        {
            cout << wq << " ";
        }
        cout << endl;
    }
    vector<int> h = topview(head1);
    for (auto k : h)
    {
        cout << k << " ";
    }
    cout << endl;
    cout << findBottomLeftValue(head1);
    cout << endl;
    vector<int> hi = bottomview(head1);
    for (auto ki : hi)
    {
        cout << ki << " ";
    }
    cout << endl;
    vector<int> him = rightview(head1);
    for (auto kim : him)
    {
        cout << kim << " ";
    }
    cout << endl;
    cout << symmetric(head1);
    cout << endl;
    vector<int> ansans = roottonode(head1, 2);
    for (auto r : ansans)
    {
        cout << r << "->";
    }
    cout << endl;
    cout << lowestcommonancestor(head1, head1->left->left, head1->right->right)->data;
    cout << endl;
    cout << widthOfBinaryTree(head1);
    cout << endl;
    vector<int> kim = nodesatkthdistance(head1, head1->right, 2);
    cout << "nodes at kth distance";
    cout << endl;
    for (auto yu : kim)
    {
        cout << yu << " " << endl;
    }
    cout << endl;
    cout << timetoburn(head1, head1->left->left);
    vector<int> uv = morristransversalinorder(head1);
    cout << endl;
    for (auto vc : uv)
    {
        cout << vc << " ";
    }
    vector<int> uvi = morristransversalpreorder(head1);
    cout << endl;
    for (auto vci : uvi)
    {
        cout << vci << " ";
    }
}