#include<iostream>
#include<bits/stdc++.h>
#include<cmath>

using namespace std;

struct node
{
    int data;
    int index;
};

stack<int> h[10000];
int z;

//Algo 1
//convert the given decimal number into binary number and then multiplication is performed
// yields logn^2 running time
int bm(int b1,int b2);
int ba(int b1,int b2);
int dectobin(int n);


//Algo 2
//Given an array of size n, finding k smallest elements
void quicksort(int A[],int p,int r,int k);
int partition(int A[],int p,int r);

//Algo 3
//min-max

//Algo 4
bool divide1(int n,int d);  ///To check whether a given number is prime number or not in theta(nlogn)s

//Algo 5
bool divide2(int n,int d);  //To check whether a given number is prime number using theta(n^1.5)


//Algo 6
struct node tourna(struct node arr[],int n);//to find the second maximum(or minimum) in an array
// in (n+logn-2) comparisons
void showstack(stack<int> temp);
int findmax(stack<int> temp);
