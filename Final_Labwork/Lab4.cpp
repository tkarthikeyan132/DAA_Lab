#include "Lab1.h"
#include "Lab4.h"



int countneg(int arr[],int l,int h)
{
    if(l==h)
    {
        if(arr[l]<0)
            return 1;
        else
            return 0;
    }
    else if(h-l==1)
    {
        if(arr[l]<0)
        {
            if(arr[h]<0)
                return 2;
            else
                return 1;
        }
        else
        {
            if(arr[h]<0)
                return 1;
            else
                return 0;
        }
    }
    else
    {
        int mid=(l+h)/2;
        return countneg(arr,l,mid)+countneg(arr,mid+1,h);
    }
}

int countone(int arr[],int l,int h)
{
    if(l==h)
        return arr[l];
    else if(h-l==1)
    {
        if(arr[l]==1)
        {
            if(arr[h]==1)
                return 2;
            else
                return 1;
        }
        else
        {
            if(arr[h]==1)
                return 1;
            else
                return 0;
        }
    }
    else
    {
        int mid=(l+h)/2;
        return countone(arr,l,mid)+countone(arr,mid+1,h);
    }
}

int gcda(int arr[],int l,int h)
{
    if(l==h)
        return abs(arr[l]);
    else if(h-l==1)
        return gcd2_rec(abs(arr[l]),abs(arr[h]));
    else
    {
        int mid=(l+h)/2;
        return gcd2_rec(gcda(arr,l,mid),gcda(arr,mid+1,h));
    }
}

long lcm(int m,int n)
{
    if(m==0||n==0)
    {
        cout<<"not defined"<<endl;
        exit(0);
    }
    else
    {
        int g=gcd2_rec(m,n);
        int mul=m*n;
        int res=mul/g;
        return res;
    }
}

int lcma(int arr[],int l,int h)
{
    if(l==h)
        return abs(arr[l]);
    else if(h-l==1)
        return lcm(abs(arr[l]),abs(arr[h]));
    else
    {
        int mid=(l+h)/2;
        return lcm(lcma(arr,l,mid),lcma(arr,mid+1,h));
    }
}

void threewaymergesort(int arr[],int beg,int end)
{
    if(beg==end)
        return;
    else if(end-beg==1)
    {
        if(arr[beg]>arr[end])
        {
            arr[beg]=arr[beg]^arr[end];
            arr[end]=arr[beg]^arr[end];
            arr[beg]=arr[beg]^arr[end];
        }
        return;
    }
    else
    {
        int mid1=(end-beg)/3;
        int mid2=2*(end-beg)/3;
        int nf=mid1-beg+1; //size of first array
        int ns=mid2-mid1; //size of second array
        int nt=end-mid2; //size of third array
        int F[nf];
        int S[ns];
        int T[nt];
        for(int i=0;i<nf;i++)
            F[i]=arr[beg+i];
        for(int j=0;j<ns;j++)
            S[j]=arr[mid1+1+j];
        for(int k=0;k<nt;k++)
            T[k]=arr[mid2+1+k];
        threewaymergesort(F,0,nf-1);
        threewaymergesort(S,0,ns-1);
        threewaymergesort(T,0,nt-1);
        threewaymerge(F,nf,S,ns,T,nt,arr);
    }
}

void threewaymerge(int frr[],int fs,int srr[],int ss,int trr[],int ts,int acrr[])
{
    int i=0,j=0,k=0,w=0;
    while(i<fs&&j<ss&&k<ts)
    {
        int flag=0;
        int tem=frr[i];
        if(srr[j]<tem)
        {
            flag=1;
            tem=srr[j];
        }
        if(trr[k]<tem)
        {
            flag=2;
            tem=trr[k];
        }
        acrr[w]=tem;
        if(flag==0)
            i++;
        else if(flag==1)
            j++;
        else
            k++;
        w++;
    }
    while(i<fs&&j<ss)
    {
        if(frr[i]<srr[j])
        {
            acrr[w]=frr[i];
            i++;
        }
        else
        {
            acrr[w]=srr[j];
            j++;
        }
        w++;
    }
    while(i<fs&&k<ts)
    {
        if(frr[i]<trr[k])
        {
            acrr[w]=frr[i];
            i++;
        }
        else
        {
            acrr[w]=trr[k];
            k++;
        }
        w++;
    }
    while(j<ss&&k<ts)
    {
        if(srr[j]<trr[k])
        {
            acrr[w]=srr[j];
            j++;
        }
        else
        {
            acrr[w]=trr[k];
            k++;
        }
        w++;
    }
    while(i<fs)
    {
        acrr[w]=frr[i];
        i++;
        w++;
    }
    while(j<ss)
    {
        acrr[w]=srr[j];
        j++;
        w++;
    }
    while(k<ts)
    {
        acrr[w]=trr[k];
        k++;
        w++;
    }
}

void twowaymergesort(int arr[],int beg,int end)
{
    if(beg==end)
        return;
    else
    {
        int mid=(beg+end)/2;
        int n1=mid-beg+1; //size of larray
        int n2=end-mid; //size of rarray
        int L[n1];
        int R[n2];
        for(int i=0;i<n1;i++)
            L[i]=arr[beg+i];
        for(int j=0;j<n2;j++)
            R[j]=arr[mid+1+j];
        twowaymergesort(L,0,n1-1);
        twowaymergesort(R,0,n2-1);
        twowaymerge(L,n1,R,n2,arr);
    }
}

void twowaymerge(int lrr[],int lsize,int rrr[],int rsize,int acrr[])
{
    int i=0,j=0,k=0;
    while(i<lsize&&j<rsize)
    {
        if(lrr[i]<rrr[j])
        {
            acrr[k]=lrr[i];
            i++;
        }
        else
        {
            acrr[k]=rrr[j];
            j++;
        }
        k++;
    }
    while(i<lsize)
    {
        acrr[k]=lrr[i];
        i++;
        k++;
    }
    while(j<rsize)
    {
        acrr[k]=rrr[j];
        j++;
        k++;
    }
}

void tower(int a,char from,char aux,char to)  //tower of hanoi
{
    if(a==1)
        cout<<"Move disc "<<a<<" from "<<from<<" to "<<to<<endl;
    else
    {
        tower(a-1,from,to,aux);
        cout<<"Move disc "<<a<<" from "<<from<<" to "<<to<<endl;
        tower(a-1,aux,from,to);
    }
}


   