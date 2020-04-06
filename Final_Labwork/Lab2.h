#include<iostream>
#include<bits/stdc++.h>

using namespace std;


bool bruteforcesum(int arr[],int n,int sum);//Logic1
bool leftrightsum(int arr[],int n,int sum); //Logic2
bool hashsum(int arr[],int n,int sum);      //Logic3
bool binschsum(int arr[],int n,int sum);    //Logic4
//helper for Logic4
bool bs(int arr[],int y,int beg,int end);

int binmark(int arr[]) ; //exponential marking         //Logic1
int fibmark(int arr[]) ; //Fibonacci jumping marking   //Logic2
int binminone(int arr[],int beg,int end);
int linminone(int arr[]);                              //Logic3

void pattern1(int);
void pattern2(int);
void pattern3(int);
void pattern4(int);
void pattern5(int);