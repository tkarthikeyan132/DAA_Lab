#include<iostream>
#include<bits/stdc++.h>

using namespace std;


int countneg(int arr[],int l,int h);   // to print no. of negative numbers
int countone(int arr[],int l,int h);   // to print no. of 1's 
int gcda(int arr[],int l,int h);       //  to print GCD using (D&C)
long lcm(int m,int n);
int lcma(int arr[],int l,int h);      //to print LCM


void twowaymergesort(int arr[],int beg,int end);
void twowaymerge(int lrr[],int lsize,int rrr[],int rsize,int acrr[]);
void threewaymergesort(int arr[],int beg,int end);
void threewaymerge(int frr[],int fs,int srr[],int ss,int trr[],int ts,int acrr[]);
void tower(int a,char from,char aux,char to); //towers of hanoi.