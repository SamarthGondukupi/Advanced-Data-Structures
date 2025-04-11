// Study of  Binary search tree as a non-linear Data Structure

// C++ Program to implement binary search tree 
#include <iostream> 
#include <cstring> 
using namespace std; 
// Node structure for a Binary Search Tree 
struct Node { 
int bookno; 
char name[30]; 
char pub[30]; 
int pages; 
Node* left; 
Node* right; 
}; 
// Function to create a new Node 
Node* createNode(int bookno, char * const name, char * const pub, int pages) 
{ 
Node* newNode = new Node(); 
newNode->bookno = bookno; 
strcpy(newNode->name , name); 
strcpy(newNode->pub , pub); 
newNode->pages = pages; 
newNode->left = newNode->right = nullptr; 
return newNode; 
} 
// Function to insert a node in the BST 
Node* insertNode(Node* root, int bookno, char * const name, char * const pub, int pages) 
{ 
if (root == nullptr) { // If the tree is empty, return a 
// new node 
return createNode(bookno, name, pub, pages); 
} 
    // Otherwise, recur down the tree 
    if (bookno< root->bookno) { 
        root->left = insertNode(root->left, bookno, name, pub, pages); 
    } 
    else if (bookno > root->bookno) { 
        root->right = insertNode(root->right, bookno, name, pub, pages); 
    } 
 
    // return the (unchanged) node pointer 
    return root; 
} 
 
// Function to do inorder traversal of BST 
void inorderTraversal(Node* root) 
{ 
    if (root != nullptr) { 
        inorderTraversal(root->left); 
         cout << "\n"; 
        cout << root->bookno << " "; 
        cout << root->name << " "; 
        cout << root->pub << " "; 
        cout << root->pages << " "; 
        cout << "\n"; 
        inorderTraversal(root->right); 
    } 
} 
void preorderTraversal(Node* root) 
{ 
    if (root != nullptr) { 
        
         cout << "\n"; 
        cout << root->bookno << " "; 
        cout << root->name << " "; 
        cout << root->pub << " "; 
        cout << root->pages << " "; 
        cout << "\n"; 
         preorderTraversal(root->left); 
        preorderTraversal(root->right); 
    } 
} 
void postorderTraversal(Node* root) 
{ 
    if (root != nullptr) { 
        postorderTraversal(root->left); 
        postorderTraversal(root->right); 
         cout << "\n"; 
        cout << root->bookno << " "; 
        cout << root->name << " "; 
        cout << root->pub << " "; 
        cout << root->pages << " "; 
        cout << "\n"; 
         
    } 
} 
 
// Function to search a given key in a given BST 
Node* searchNode(Node* root, char * key) 
{ 
    // Base Cases: root is null or key is present at root 
    if (root == nullptr || strcmp(root->name, key)==0) { 
        return root; 
    } 
 
    // Key is greater than root's key 
    if (strcmp(root->name, key)>0) { 
        return searchNode(root->right, key); 
    } 
 
    // Key is smaller than root's key 
    return searchNode(root->left, key); 
} 
 
Node* updateNode(Node* root, char * key) 
{ 
    Node* found = searchNode(root, (char *)"bbb"); 
    
    cout<<"Enter the title of book"; 
    cin>>found->name; 
    cout<<"Enter the publication of book"; 
    cin>>found->pub; 
    cout<<"Enter the number of pages of book"; 
    cin>>found->pages; 
    return found; 
} 
 
 
// Function to find the inorder successor 
Node* minValueNode(Node* node) 
{ 
    Node* current = node; 
    // loop down to find the leftmost leaf 
    while (current && current->left != nullptr) { 
        current = current->left; 
    } 
    return current; 
} 
 
// Function to delete a node 
Node* deleteNode(Node* root, int bookno) 
{ 
    if (root == nullptr) 
        return root; 
 
    // If the data to be deleted is smaller than the root's 
    // data, then it lies in the left subtree 
    if (bookno < root->bookno) { 
        root->left = deleteNode(root->left, bookno); 
    } 
    // If the data to be deleted is greater than the root's 
    // data, then it lies in the right subtree 
    else if (bookno > root->bookno) { 
        root->right = deleteNode(root->right, bookno); 
    } 
    // if data is same as root's data, then This is the node 
    // to be deleted 
    else { 
        // node with only one child or no child 
        if (root->left == nullptr) { 
            Node* temp = root->right; 
            delete root; 
            return temp; 
        } 
        else if (root->right == nullptr) { 
            Node* temp = root->left; 
            delete root; 
            return temp; 
        } 
 
        // node with two children: Get the inorder successor 
        // (smallest in the right subtree) 
        Node* temp = minValueNode(root->right); 
 
        // Copy the inorder successor's content to this node 
        root->bookno = temp->bookno; 
 
        // Delete the inorder successor 
        root->right = deleteNode(root->right, temp->bookno); 
    } 
    return root; 
} 
 
// Main function to demonstrate the operations of BST 
int main() 
{ 
 
    Node* root = nullptr; 
    // create a BST 
    root = insertNode(root, 50,(char *)"aaa", (char *)"zzz", 100); 
    root = insertNode(root, 30,(char *)"bbb", (char *)"yyy", 100); 
    root = insertNode(root, 20,(char *)"ccc", (char *)"xxx", 100); 
    root = insertNode(root, 40,(char *)"ddd", (char *)"vvv", 100); 
    root = insertNode(root, 70,(char *)"eee", (char *)"www", 100); 
    root = insertNode(root, 60,(char *)"fff", (char *)"qqq", 100); 
    root = insertNode(root, 80,(char *)"ggg", (char *)"rrr", 100); 
 
    // Print the inorder traversal of a BST 
    cout << "Inorder traversal of the given Binary Search " 
            "Tree is: "; 
    inorderTraversal(root); 
    cout << endl; 
 
    // delete a node in BST 
    root = deleteNode(root, 20); 
    cout << "After deletion of 20: "; 
    inorderTraversal(root); 
    cout << endl; 
 
    // Insert a node in BST 
    root = insertNode(root, 25,(char *)"iii", (char *)"ttt", 100); 
    cout << "After insertion of 25: "; 
    preorderTraversal(root); 
    cout << endl; 
    inorderTraversal(root); 
    cout << endl; 
    postorderTraversal(root); 
    cout << endl; 
 
 
    // Search a key in BST 
    Node* found = searchNode(root, (char *)"bbb"); //by title 
 
    // check if the key is found or not 
    if (found != nullptr) { 
        cout << "Node bbb found in the BST." << endl; 
    } 
    else { 
        cout << "Node bbb not found in the BST." << endl; 
    } 
     
    found = updateNode(root, (char *)"bbb"); 
    cout << endl; 
    inorderTraversal(root); 
    cout << endl; 
 
    return 0; 
}