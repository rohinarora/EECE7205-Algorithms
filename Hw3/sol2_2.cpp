#include <algorithm>
#include <iostream>
#include <random>
#include <vector>
#include <list>
#include <set>
#include <chrono>
#include <numeric>
using namespace std;
using namespace std::chrono;
void swap(int *p, int *q)
{
  // helper function
  int x = *p;
  *p = *q;
  *q = x;
}
int deterministic_partition(int A[], int l, int r, int k){
  int z;
  for (z=l;z<r;z++){
    if (A[z]==k){
      break;
    }
  }
  swap(A[z],A[l]);
  int p=A[l];
  int i=l;
  for (int j=l+1;j<r+1;j++){
    if (A[j]<=p){
      i=i+1;
      swap(A[i],A[j]);
    }
  }
  swap(A[i],A[l]);
  // return the pivot position
  return i;
}
int search(int A[], int j)
{
  sort(A, A+j);
  if (j%2==1){
    return A[j/2];
  }
  else{
    return (A[j/2]+ A[(j/2-1)])/2;
  }

}


int select(int A[], int l, int r, int order_statistic)
{
  int number_of_elements=r - l + 1;
  if (order_statistic > 0 && order_statistic <= number_of_elements)
  {
    int num_groups=(number_of_elements+4)/5;
    int arr[num_groups];
    int tmp;
    for (tmp=0; tmp<number_of_elements/5; tmp++){
      arr[tmp] = search(A+l+tmp*5, 5);
    }
    if (tmp*5 < number_of_elements){
      arr[tmp] = search(A+l+tmp*5, number_of_elements%5);
      tmp=tmp+1;
    }
    int centre;
    if (tmp==1){
      centre=arr[tmp-1];
    }
    else{
      centre=select(arr, 0, tmp-1, tmp/2);
    }
    int val = deterministic_partition(A, l, r, centre);
    if (val-l > order_statistic-1){
      return select(A, l, val-1, order_statistic);
    }
    else if (val-l < order_statistic-1){
      return select(A, 1+val, r, l-val-1+order_statistic);
    }
    else {
      return A[val];
    }
  }

  else{
    cout <<"Index larger than size of array"<<endl;
    return 0;
  }
}

int main()
{
  // Create a array with 1-100 numbers
  int A[101];
  for (int i=0; i<101; ++i){
    A[i]=i+1;
  }
  cout <<"Original permutation is ";
  for (int i=0; i<101; ++i){
    cout<<A[i]<<" ";
  }
  cout<<endl;
  random_device rd;
  mt19937 g(rd());
  // Shuffle the array with 1-100 numbers
  shuffle(A, A+100, g);
  cout <<"Shuffled permutation is ";
  for (int i=0; i<101; ++i){
    cout<<A[i]<<" ";
  }
  cout<<endl;
  int number_of_elements = 100;
  // test for different cases
  int order_statistic = 3;
  cout << order_statistic<< "rd order statistic is ";
  cout<<select(A, 0, number_of_elements-1, order_statistic)<<endl;
  order_statistic = 20;
  cout << order_statistic<< "th order statistic is ";
  cout<<select(A, 0, number_of_elements-1, order_statistic)<<endl;
  order_statistic = 42;
  cout << order_statistic<< "nd order statistic is ";
  cout<<select(A, 0, number_of_elements-1, order_statistic)<<endl;
  order_statistic = 98;
  cout << order_statistic<< "th order statistic is ";
  cout<<select(A, 0, number_of_elements-1, order_statistic)<<endl;
  order_statistic = 80;
  cout << order_statistic<< "th order statistic is ";
  cout<<select(A, 0, number_of_elements-1, order_statistic)<<endl;
  return 0;
}
