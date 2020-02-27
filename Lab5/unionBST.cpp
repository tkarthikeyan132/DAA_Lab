#include<iostream> // merging k sorted arrays into a single array using binary search tree(inorder traversal)
#include<stdlib.h>
#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node *left;
    node *right;
};
node* newnode(int key);
node* insert(node* root,int key);
void inorder(node *root);
int main()
{
    node* root=NULL;
    int N=0; //number of arrays
    int S[N]={0}; //size of respective arrays
    cout<<"Enter the number of arrays:";
    cin>>N;
    cout<<"Enter the sizes of respective array:";
    for(int i=0;i<N;i++)
        cin>>S[i];
    int m=*max_element(S,S+N);
    int arr[100][m]={0};
    for(int i=0;i<N;i++) //input
    {
        cout<<"Enter the elements of array "<<i+1<<":";
        for(int j=0;j<S[i];j++)
            cin>>arr[i][j];
    }
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<S[i];j++)
            root=insert(root,arr[i][j]);
    }
    for(int i=0;i<N;i++)
    {
        cout<<"Elements of array "<<i+1<<":";
        for(int j=0;j<S[i];j++)
            cout<<arr[i][j]<<" ";
        cout<<endl;
    }
    cout<<"Union of "<<N<<" arrays:";
    inorder(root);
    return 0;
}
node* newnode(int key)
{
    node *temp=new node;
    temp->data=key;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}
node* insert(node* root,int key)
{
    if(root==NULL)
        return newnode(key);
    else if(key<root->data)
        root->left=insert(root->left,key);
    else
        root->right=insert(root->right,key);
}
void inorder(node *root)
{
    if(root==NULL)
        return;
    else
    {
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}
