// Question Finding Diameter of Binary Tree 
int diameter(struct Node* tree);


int main() {
    int t;
    scanf("%d\n", &t);
    while (t--) {
        string s;
        getline(cin, s);
        Node* root = buildTree(s);
        cout << diameter(root) << endl;
    }
    return 0;
}

/* Tree node structure  used in the program

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */


int dia(Node * node, int *h){
    

    if (node==NULL)
    
    return 0;
    
    int lh=0, rh=0;
    int ldiameter=dia(node->left, &lh);
    int rdiameter=dia(node->right, &rh);
    *h=max(lh, rh)+1;
    return max(lh+rh+1, max(ldiameter, rdiameter));
    
    
}
int diameter(Node* node) {
    // Your code here
    int h=0;
    return dia(node, &h);
   
}

// Question : Top View of tree

vector<int> topView(struct Node *root)
{vector<int> result;
    if (root==NULL)
    return result;
    map<struct Node*, int> s;
    map<int, int>r;
    queue<struct Node*>q;
    q.push(root);
    int hd=0;
    struct Node* x=root;
   
        s[root]=hd;
        
        
        
        
        
    
    
    while(!q.empty()){
        hd=s[x];
        if(r.count(hd)==0)
        {
            r[hd]=x->data;
            
            
            
        }
        if(x->left){
            s[x->left]=hd-1;
            q.push(x->left);
        }
        if(x->right){
            s[x->right]=hd+1;
            q.push(x->right);
            
        }
        
        q.pop();
        x=q.front();
        
    }
    
    for(auto i=r.begin(); i!=r.end(); i++)
result.push_back(i->second);
return result;
    
}

//Question if BT is BST or not
class Solution
{
    public:
    bool isBSTutil(Node *root, int min, int max)
    {
        if(root==NULL)
        return 1;
        if(root->data < min || root->data>max){
            return 0;
            
            
        }
        return (isBSTutil(root->left , min, root->data-1) && isBSTutil(root->right, root->data+1, max));
        
    }
    bool isBST(Node* root) 
    {
        
        return(isBSTutil(root, INT_MIN, INT_MAX));
        
    }
};


// Question Construct BST from BT
void inorder(Node *root, vector<int> &v, int *preindex )
{
    if(root==NULL)
    return;
    inorder(root->left, v, preindex);
    v[(*preindex)];
    (*preindex)++;
    
    inorder(root->right, v, preindex);
    
}
void binarytree(Node *root, vector<int> &v,  int *preindex)
{
    if(root==NULL){
        return ;
    }
    binarytree(root, v, preindex);
    root->data=v[*preindex];
    (*preindex)++;
    binarytree(root, v, preindex);
    
}
Node *binaryTreeToBST (Node *root)
{
    if (root==NULL){
        return NULL;
        
    }
    vector<int> v(0, 1000);
    int preindex=0;
    inorder(root,v, &preindex);
    sort(v.begin(), v.end());
    preindex=0;
    binarytree(root, v, &preindex);
    return root;
    
    
}

//LCA of two nodes in BST
/* Approach:
For Binary search tree, while traversing the tree from top to bottom the first node which lies in between the two numbers n1 and n2 is the LCA of the nodes, i.e. the first node n with the lowest depth which lies in between n1 and n2 (n1<=n<=n2) n1 < n2. So just recursively traverse the BST in, if node's value is greater than both n1 and n2 then our LCA lies in the left side of the node, if it's is smaller than both n1 and n2, then LCA lies on the right side. Otherwise, the root is LCA (assuming that both n1 and n2 are present in BST).*/