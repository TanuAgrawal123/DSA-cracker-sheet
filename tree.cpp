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

