#include "Lab5.h"

struct listt Li[100];

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
        return Li[ei];
    else if(ri-ei==1)
        return merge(Li[ei],Li[ri]);
    else
    {
        int mid=(ri+ei)/2;
        return merge(mergesort(ei,mid),mergesort(mid+1,ri));
    }
}
//_________________________________________________________________________________

struct megalist union_of_array(struct listt List[],int N)
{
    int flag=1;
    int maxi; //positive infinity
    struct megalist Mega;
    Mega.ptr=0;
    Mega.size=0;
    cout<<"Enter the size of respective arrays:";
    for(int i=0;i<N;i++)
        cin>>List[i].size;
    for(int x=0;x<N;x++)
    {
        cout<<"Enter array "<<x+1<<":";
        List[x].ptr=0;
        for(int y=0;y<List[x].size;y++)
            cin>>List[x].A[y];
    }
    maxi=List[0].A[0];
    for(int x=0;x<N;x++)
        for(int y=0;y<List[x].size;y++)
            if(List[x].A[y]>maxi)
                maxi=List[x].A[y];
    maxi++;
    while(flag)
    {
        flag=0;
        int mini=maxi;
        int indmin=-1;
        for(int k=0;k<N;k++)
        {
            if(List[k].ptr<List[k].size)
            {
                if(List[k].A[List[k].ptr]<mini)
                {
                    mini=List[k].A[List[k].ptr];
                    indmin=k;
                }
            }
        }
        List[indmin].ptr++;
        Mega.M[Mega.ptr]=mini;
        Mega.ptr++;
        Mega.size++;
        for(int i=0;i<N;i++)
        {
            if(List[i].ptr<List[i].size)
                flag++;
        }
    }
    return Mega;
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

void inssort(int *arr,int beg,int end) //Insertion Sort //Problem 2
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

