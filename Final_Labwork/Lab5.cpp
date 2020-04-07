#include "Lab5.h"


struct megalist merge(struct listt t,struct megalist m)//merging k sorted arrays into a single sorted array using incremental design
{
    struct megalist temp;
    int x=t.size;
    int y=m.size;
    temp.size=0;
    int i=0,j=0,k=0;
    while(i<x&&j<y)
    {
        if(t.A[i]<m.M[j])
        {
            temp.M[k]=t.A[i];
            i++;
        }
        else
        {
            temp.M[k]=m.M[j];
            j++;
        }
        k++;
    }
    while(i<x)
    {
        temp.M[k]=t.A[i];
        i++;
        k++;
    }
    while(j<y)
    {
        temp.M[k]=m.M[j];
        j++;
        k++;
    }
    temp.size=k;
    return temp;
}

//____________________________________________________________________________

struct listt merge(struct listt e,struct listt r) //merging k sorted arrays into a single sorted array using divide and conquer paradigm
{
    struct listt temp;
    temp.size=e.size+r.size;
    int i=0,j=0,k=0;
    while(i<e.size&&j<r.size)
    {
        if(e.A[i]<r.A[j])
        {
            temp.A[k]=e.A[i];
            i++;
        }
        else
        {
            temp.A[k]=r.A[j];
            j++;
        }
        k++;
    }
    while(i<e.size)
    {
        temp.A[k]=e.A[i];
        i++;
        k++;
    }
    while(j<r.size)
    {
        temp.A[k]=r.A[j];
        j++;
        k++;
    }
    return temp;
}
struct listt mergesort(int ei,int ri)
{
    if(ei==ri)
        return L[ei];
    else if(ri-ei==1)
        return merge(L[ei],L[ri]);
    else
    {
        int mid=(ri+ei)/2;
        return merge(mergesort(ei,mid),mergesort(mid+1,ri));
    }
}

//______________________________________________________________________________

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

//______________________________________________________________________________

vector<int> Sorter(Unit Unit_Array[], int k, int Final_Array_Size)
{
    int j = 0;
    vector<int> Final_vector(Final_Array_Size);
    priority_queue<Pair, vector<Pair>, myComparator> Heap;
    for(int i = 0; i < k; i++)
    {
        Heap.push(Pair(i, Unit_Array[i].arr[Unit_Array[i].pointer]));
    } 
    
    while(j < Final_Array_Size)
    {
        Pair P = Heap.top(); 
        Heap.pop();
        Final_vector[j] = P.getVAL();
        j++; 
        if(Unit_Array[P.getARR()].pointer < Unit_Array[P.getARR()].size)
        {
            Unit_Array[P.getARR()].pointer = Unit_Array[P.getARR()].pointer + 1;
            P.Array_id = P.getARR();
            if(Unit_Array[P.getARR()].pointer < Unit_Array[P.getARR()].size)
            {
                P.value = Unit_Array[P.getARR()].arr[Unit_Array[P.getARR()].pointer];
                Heap.push(P);
            }
        } 
    }
    return Final_vector;    
}

Unit::Unit()
{
    pointer = 0;
}

//_______________________________________________________________________________

void inssort(int *arr,int beg,int end) //Insertion Sort
{
    int key,i;
    for(int j=beg+1;j<=end;j++)
    {
        key=arr[j];
        i=j-1;
        while(i>=0&&arr[i]>key) 
        {
            arr[i+1]=arr[i];
            i--;
        }
        arr[i+1]=key;
    }
}