#include <iostream>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
#include <stack>
#include <climits>
#include <vector>
using namespace std;
int maximum = 0;
int maxi = INT_MIN; // global variable
class node
{
    // properties
public:
    int data;
    node *left;
    node *right;
    // constructor
    node(int d)
    {
        data = d;
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
    node *head = new node(d);
    head->left = build_tree();
    head->right = build_tree();
    return head;
}
void preorderrec(node *head)
{
    if (head == NULL)
    {
        return;
    }
    cout << head->data;
    preorderrec(head->left);
    preorderrec(head->right);
    return;
}
void inorderrec(node *head)
{
    if (head == NULL)
    {
        return;
    }
    inorderrec(head->left);
    cout << head->data;
    inorderrec(head->right);
    return;
}
void postorderrec(node *head)
{
    if (head == NULL)
    {
        return;
    }
    postorderrec(head->left);
    postorderrec(head->right);
    cout << head->data;
    return;
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
void printkth(node *head, int k)
{
    if (head == NULL)
    {
        return;
    }
    if (k == 1)
    {
        cout << head->data << " ";
        return;
    }
    printkth(head->left, k - 1);
    printkth(head->right, k - 1);
}
void bfs2(node *head)
{
    queue<node *> que;
    que.push(head);
    que.push(NULL);
    while (!que.empty())
    {
        if (que.front() == NULL)
        {
            cout << endl;
            que.pop();
            if (!que.empty())
            {
                que.push(NULL);
            }
        }
        else
        {
            node *temp = que.front();
            que.pop();
            if (temp->left)
            {
                que.push(temp->left);
            }
            if (temp->right)
            {
                que.push(temp->right);
            }
            cout << temp->data << " ";
        }
    }
}
void bfs(node *head)
{
    queue<node *> que;
    que.push(head);
    while (!que.empty())
    {
        node *temp = que.front();
        que.pop();
        if (temp->left)
        {
            que.push(temp->left);
        }
        if (temp->right)
        {
            que.push(temp->right);
        }
        cout << temp->data << " ";
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
            node *temp = que.front();
            que.pop();
            if (temp->left != NULL)
            {
                que.push(temp->left);
            }
            if (temp->right != NULL)
            {
                que.push(temp->right);
            }
            mediate.push_back(temp->data);
        }
        ans.push_back(mediate);
    }
    return ans;
}
vector<int> preorderite(node *head)
{
    vector<int> ans;
    if (head == NULL)
    {
        return ans;
    }
    stack<node *> stac;
    stac.push(head);
    while (!stac.empty())
    {
        node *front = stac.top();
        stac.pop();
        if (front->right)
        {
            stac.push(front->right);
        }
        if (front->left)
        {
            stac.push(front->left);
        }
        ans.push_back(front->data);
    }
    return ans;
}
vector<int> inorderite(node *head)
{
    vector<int> ans;
    stack<node *> stac;
    node *top = head;
    while (true)
    {
        if (top != NULL)
        {
            stac.push(top);
            top = top->left;
        }
        else
        {
            if (stac.empty())
            {
                break;
            }
            top = stac.top();
            stac.pop();
            ans.push_back(top->data);
            top = top->right;
        }
    }
    return ans;
}
vector<int> postorder2stack(node *head)
{
    vector<int> ans;
    stack<node *> stac1, stac2;
    stac1.push(head);
    while (!stac1.empty())
    {
        node *cu = stac1.top();
        stac1.pop();
        stac2.push(cu);
        if (cu->left)
        {
            stac1.push(cu->left);
        }
        if (cu->right)
        {
            stac1.push(cu->right);
        }
    }
    while (!stac2.empty())
    {
        node *cu = stac2.top();
        stac2.pop();
        ans.push_back(cu->data);
    }
    return ans;
}
vector<int> postorder1stack(node *head)
{
    vector<int> ans;
    stack<node *> stac;
    node *cur = head;
    while (!stac.empty() || cur != NULL)
    {
        if (cur != NULL)
        {
            stac.push(cur);
            cur = cur->left;
        }
        else
        {
            node *temp = stac.top()->right;
            if (temp == NULL)
            {
                temp = stac.top();
                stac.pop();
                ans.push_back(temp->data);
                while (!stac.empty() && temp == (stac.top()->right))
                {
                    temp = stac.top();
                    stac.pop();
                    ans.push_back(temp->data);
                }
            }
            else
            {
                cur = temp;
            }
        }
    }
    return ans;
}
bool balanced1(node *head)
{
    if (head == NULL)
    {
        return true;
    }
    bool b1 = balanced1(head->left);
    bool b2 = balanced1(head->right);
    if (!b2)
    {
        return false;
    }
    if (!b1)
    {
        return false;
    }
    int lh = height(head->left);
    int rh = height(head->right);
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
    if (abs(lh - rh) > 1)
    {
        return -1;
    }
    if (lh == -1)
    {
        return -1;
    }
    if (rh == -1)
    {
        return -1;
    }
    return max(lh, rh) + 1;
}
void diameter1(node *head)
{
    if (head == NULL)
    {
        return;
    }
    diameter1(head->left);
    diameter1(head->right);
    int lh = height(head->left);
    int rh = height(head->right);
    maximum = max(lh + rh, maximum);
}
int diameter2(node *head)
{
    if (head == NULL)
    {
        return 0;
    }
    int lh = diameter2(head->left);
    int rh = diameter2(head->right);
    maximum = max(lh + rh, maximum);
    return max(lh, rh) + 1;
}
int maximumpathsum(node *head)
{
    if (head == NULL)
    {
        return 0;
    }
    int lm = max(0, maximumpathsum(head->left));
    int rm = max(0, maximumpathsum(head->right));
    maxi = max(maxi, head->data + lm + rm);
    return max(lm, rm) + head->data;
}
bool isleaf(node *head)
{
    if (head->right == NULL && head->left == NULL)
    {
        return true;
    }
    return false;
}
void printleft(node *head, vector<int> &ans)
{
    node *cur = head->left;
    while (cur)
    {
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
void printleaf(node *head, vector<int> &ans)
{
    if (isleaf(head))
    {
        ans.push_back(head->data);
        // return;
    }
    if (head->left)
        printleaf(head->left, ans);
    if (head->right)
        printleaf(head->right, ans);
}
void printright(node *head, vector<int> &ans)
{
    node *cur = head->right;
    vector<int> temp;
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
    for (int i = temp.size(); i >= 1; i--)
    {
        ans.push_back(temp[i - 1]);
    }
}
vector<int> boundarytransversal(node *head)
{
    vector<int> ans;
    if (head == NULL)
    {
        return ans;
    }
    ans.push_back(head->data);
    printleft(head, ans);
    printleaf(head, ans);
    printright(head, ans);
    return ans;
}
vector<vector<int>> verticalorder(node *head)
{
    map<int, map<int, multiset<int>>> nodes;
    queue<pair<node *, pair<int, int>>> que;
    vector<vector<int>> ans;
    que.push({head, {0, 0}});
    while (!que.empty())
    {
        auto value = que.front();
        que.pop();
        node *n = value.first;
        int vert = value.second.first;
        int level = value.second.second;
        if (n->left)
            que.push({n->left, {vert - 1, level + 1}});
        if (n->right)
            que.push({n->right, {vert + 1, level + 1}});
        nodes[vert][level].insert(n->data);
    }
    for (auto p : nodes)
    {
        vector<int> col;
        for (auto q : p.second)
        {
            col.insert(col.end(), q.second.begin(), q.second.end());
        }
        ans.push_back(col);
    }
    return ans;
}
vector<int> topview(node *head)
{
    map<int, int> nodes;
    vector<int> ans;
    queue<pair<node *, int>> que;
    que.push({head, 0});
    while (!que.empty())
    {
        auto ni = que.front();
        que.pop();
        int x = ni.second;
        node *n = ni.first;
        if (n->left)
            que.push({n->left, x - 1});
        if (n->right)
            que.push({n->right, x + 1});
        if (nodes.find(x) == nodes.end())
        {
            nodes[x] = n->data;
        }
    }
    for (auto p : nodes)
    {
        ans.push_back(p.second);
    }
    return ans;
}
vector<int> bottomview(node *head)
{
    map<int, int> nodes;
    vector<int> ans;
    queue<pair<node *, int>> que;
    que.push({head, 0});
    while (!que.empty())
    {
        auto ni = que.front();
        que.pop();
        int x = ni.second;
        node *n = ni.first;
        if (n->left)
            que.push({n->left, x - 1});
        if (n->right)
            que.push({n->right, x + 1});
        nodes[x] = n->data;
    }
    for (auto p : nodes)
    {
        ans.push_back(p.second);
    }
    return ans;
}
void recursion(node *head, int level, vector<int> &ans)
{
    if (head == NULL)
    {
        return;
    }
    if (level == ans.size())
    {
        ans.push_back(head->data);
    }
    recursion(head->right, level + 1, ans);
    recursion(head->left, level + 1, ans);
}
vector<int> rightview(node *head)
{
    vector<int> ans;
    recursion(head, 0, ans);
    return ans;
}
bool symmetric(node *left, node *right)
{
    if (left == NULL || right == NULL)
    {
        return left == right;
    }
    if (left->data != right->data)
    {
        return false;
    }
    return symmetric(left->left, right->right) && symmetric(left->right, right->left);
}
bool issymmetrical(node *head)
{
    return head == NULL || symmetric(head->left, head->right);
}
bool rootnode(node *head, vector<int> &ans, int find)
{
    if (head == NULL)
    {
        return false;
    }
    ans.push_back(head->data);
    if (head->data == find)
    {
        return true;
    }
    if (rootnode(head->left, ans, find) || rootnode(head->right, ans, find))
    {
        return true;
    }
    ans.pop_back();
    return false;
}
vector<int> roottonode(node *head, int find)
{
    vector<int> ans;
    if (head == NULL)
    {
        return ans;
    }
    rootnode(head, ans, find);
    return ans;
}
node *lcancestor(node *head, node *p, node *q)
{
    if (head == NULL || head == p || head == q)
    {
        return head;
    }
    node *left = lcancestor(head->left, p, q);
    node *right = lcancestor(head->right, p, q);
    if (left == NULL)
    {
        return right;
    }
    else if (right == NULL)
    {
        return left;
    }
    else
    {
        return head;
    }
}
int maximumwidth(node *head)
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
}
void childrensumproperty(node *root)
{
    if (root == NULL)
        return;
    int sum = 0;
    if (root->left)
    {
        sum += root->left->data;
    }
    if (root->right)
    {
        sum += root->right->data;
    }
    if (sum >= root->data)
    {
        root->data = sum;
    }
    else
    {
        if (root->left)
            root->left->data = root->data;
        if (root->right)
            root->right->data = root->data;
    }
    childrensumproperty(root->left);
    childrensumproperty(root->right);
    int cou = 0;
    if (root->left)
    {
        cou += root->left->data;
    }
    if (root->right)
    {
        cou += root->right->data;
    }
    if (root->left || root->right)
        root->data = cou;
}
void parentmapping(unordered_map<node *, node *>& parent, node *root)
{
    queue<node *> que;
    que.push(root);
    while (!que.empty())
    {
        node *current = que.front();
        que.pop();
        if (current->left)
        {
            parent[current->left] = current;
            que.push(current->left);
        }
        if (current->right)
        {
            parent[current->right] = current;
            que.push(current->right);
        }
    }
}
vector<int> nodesatkthdistance(node *root, node *target, int k)
{
    unordered_map<node *, node *> parent;
    parentmapping(parent, root);
    unordered_map<node *, bool> visited;
    queue<node *> distanc;
    distanc.push(target);
    visited[target] = true;
    int count = 0;
    while (!distanc.empty())
    {
        int size = distanc.size();
        if (count++ == k)
            break;
        for (int i = 0; i < size; i++)
        {

            node *current = distanc.front();
            distanc.pop();
            if (current->left && !visited[current->left])
            {
                distanc.push(current->left);
                visited[current->left] = true;
            }
            if (current->right && !visited[current->right])
            {
                distanc.push(current->right);
                visited[current->right] = true;
            }
            if (parent[current] && !visited[parent[current]])
            {
                distanc.push(parent[current]);
                visited[parent[current]] = true;
            }
        }
    }
    vector<int> ans;
    while(!distanc.empty())
    {
        node* front=distanc.front();
        distanc.pop();
        ans.push_back(front->data);
    }
    return ans;
}
int leftheight(node* root)
{
    int count=0;
    while(root)
    {
        root=root->left;
        count++;
    }
    return count;
}
int rightheight(node* root)
{
    int count=0;
    while(root)
    {
        root=root->right;
        count++;
    }
    return count;
}
int countnode(node* root)
{
    if(root==NULL) return 0;
    int lh=leftheight(root);
    int rh=rightheight(root);
    if(lh==rh)
    {
        return (1<<lh)-1;
    }
    return 1+countnode(root->left)+countnode(root->right);
}
/*void buildtree(vector<int>&preorder,int prestart,int prend,vector<int>&inorder,int instart,int inend,)*/
/*node* preintree(vector<int> &preorder,vector<int> & inorder)
{
    node* root;
    buildtree(preorder)
}*/
int main()
{
    // node *head1 = build_tree();
    node *head2 = new node(5);
    head2->left = new node(3);
    head2->right = new node(6);
    head2->left->left = new node(7);
    head2->right->left = new node(1);
    head2->right->right = new node(2);
    // head2->right->right->right=new node(7);
    // head2->right->right->right->right= new node(1);
    //  preorderrec(head1);
    //  cout << endl;
    preorderrec(head2);
    cout << endl;
    // inorderrec(head1);
    // cout << endl;
    inorderrec(head2);
    cout << endl;
    // postorderrec(head1);
    // cout << endl;
    postorderrec(head2);
    cout << endl;
    cout << height(head2);
    int h = height(head2);
    cout << endl;
    // printkth(head2,3);
    for (int i = 1; i <= h; i++)
    {
        printkth(head2, i);
        cout << endl;
    }
    bfs(head2);
    cout << endl;
    bfs2(head2);
    vector<vector<int>> ans = bfs3(head2);
    for (auto p : ans)
    {
        for (auto j : p)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    // preorderite(node* head);
    vector<int> ans2 = preorderite(head2);
    for (auto q : ans2)
    {
        cout << q << " ";
    }
    cout << endl;
    cout << "next" << endl;
    vector<int> ans3 = inorderite(head2);
    for (auto y : ans3)
    {
        cout << y << " ";
    }
    cout << endl;
    vector<int> ans4 = postorder2stack(head2);
    for (auto u : ans4)
    {
        cout << u << " ";
    }
    cout << endl;
    vector<int> ans5 = postorder1stack(head2);
    for (auto b : ans4)
    {
        cout << b << " ";
    }
    cout << endl;
    cout << balanced1(head2) << "hi" << endl;
    diameter1(head2);
    cout << maximum << endl;
    maximumpathsum(head2);
    cout << maxi << endl;
    vector<int> ans6 = boundarytransversal(head2);
    for (int t : ans6)
    {
        cout << t << " ";
    }
    cout << endl;
    vector<vector<int>> ans7 = verticalorder(head2);
    cout << "vertical order" << endl;
    for (auto b : ans7)
    {
        for (auto c : b)
        {
            cout << c << " ";
        }
    }
    cout << endl;
    vector<int> f = topview(head2);
    for (auto r : f)
    {
        cout << r << " ";
    }
    cout << endl;
    vector<int> w = bottomview(head2);
    for (auto u : w)
    {
        cout << u << " ";
    }
    cout << endl;
    vector<int> qwerty = rightview(head2);
    cout << "right view ";
    for (auto uwt : qwerty)
    {
        cout << uwt << " ";
    }
    cout << endl;
    cout << issymmetrical(head2);
    vector<int> ans8 = roottonode(head2, 7);
    cout << endl;
    for (auto uwtr : ans8)
    {
        cout << uwtr << " ";
    }
    cout << endl;
    node *lca = lcancestor(head2, head2->left, head2->right->right);
    cout << lca->data << endl;
    cout << "maximum width " << maximumwidth(head2);
    cout << endl;
    /*childrensumproperty(head2);
    vector<vector<int>> anss = bfs3(head2);
    for (auto pp : anss)
    {
        for (auto jj : pp)
        {
            cout << jj << " ";
        }
        cout << endl;
    }
    cout<<endl;*/
    vector<int> kthdistance=nodesatkthdistance(head2,head2->left->left,4);
    for(auto kthdis:kthdistance)
    {
        cout<<kthdis<<" ";
    }
    cout<<endl;
    cout<<countnode(head2);
}