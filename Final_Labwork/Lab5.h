#include<iostream>
#include<bits/stdc++.h>

using namespace std;



struct listt
{
    int A[100];
    int ptr;
    int size;
};

struct megalist
{
    int M[10000];
    int ptr;
    int size;
};

struct node
{
    int data;
    node *left;
    node *right;
};

class Unit
{
    public:
        int size;    //size of the array
        int arr[50]; //the array of sorted integers with default size 50.
        int pointer; //pointer to the first index which produces.
        Unit();
};

class Pair
{
    public:
        int Array_id;
        int value;
        Pair(int id, int val) 
        { 
            Array_id = id; 
            value = val; 
        } 
        
        int getARR() const { return Array_id; } 
        int getVAL() const { return value; }  
}; 
  
// To compare two Pairs 
class myComparator 
{ 
    public: 
        int operator() (const Pair& p1, const Pair& p2)
        { 
            return p1.getVAL() > p2.getVAL(); 
        } 
};

struct listt L[100];
//_______________________________________________________________________________
//prob1 algos

//Algo 1
//merging k sorted arrays into a single sorted array using incremental design
struct megalist merge(struct listt t,struct megalist m);


//Algo 2
//merging k sorted arrays into a single sorted array using divide and conquer paradigm
struct listt merge(struct listt e,struct listt r) ;
struct listt mergesort(int ei,int ri);



//Algo 3



//Algo 4
// merging k sorted arrays into a single array using BST(inorder traversal)
node* newnode(int key);
node* insert(node* root,int key);
void inorder(node *root);

//Algo 5
//merging k sorted arrays by maintaining k pointers and using minheap to find min.
vector<int> Sorter(Unit Unit_Array[], int k, int Final_Array_Size);


//_______________________________________________________________________________
//prob 2 algo

//array of size 10^5 is sorted using divide and conquer(two way mergesort) and applying insertion sort when array size is reduced to 10^3 
void inssort(int *arr,int beg,int end); //Insertion Sort
