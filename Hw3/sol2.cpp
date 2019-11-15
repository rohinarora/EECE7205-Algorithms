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
int randomized_partition(int A[], int l, int r){
  // find random pivot
  srand(time(NULL));
  int random_ind = l + rand() % (r - l);
  // swap it with first  element
  swap(A[random_ind],A[l]);
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

int rand_select(int A[], int l, int r, int i){
  if (l==r){
    return A[l];
  }
  int q=randomized_partition(A,l,r);
  int k=q-l+1;
  if (k==i){
    return A[q];
  }
  else if (i<k){
    return rand_select(A,l,q-1,i);
  }else{
    return rand_select(A,q+1,r,i-k);
  }
}

int main()
{
  // Create a array with 1-100 numbers
  int A[101];
  for (int i=0; i<100; ++i){
    A[i]=i+1;
  }
  cout <<"Original permutation is ";
  for (int i=0; i<100; ++i){
    cout<<A[i]<<" ";
  }
  cout<<endl;
  random_device rd;
  mt19937 g(rd());
  // Shuffle the array with 1-100 numbers
  shuffle(A, A+100, g);
  cout <<"Shuffled permutation is ";
  for (int i=0; i<100; ++i){
    cout<<A[i]<<" ";
  }
  cout<<endl;
  int number_of_elements = 100;
  // test for different cases
  int order_statistic = 3;
  cout << order_statistic<< "rd order statistic is ";
  cout<<rand_select(A, 0, number_of_elements-1, order_statistic)<<endl;
  order_statistic = 20;
  cout << order_statistic<< "th order statistic is ";
  cout<<rand_select(A, 0, number_of_elements-1, order_statistic)<<endl;
  order_statistic = 42;
  cout << order_statistic<< "nd order statistic is ";
  cout<<rand_select(A, 0, number_of_elements-1, order_statistic)<<endl;
  order_statistic = 98;
  cout << order_statistic<< "th order statistic is ";
  cout<<rand_select(A, 0, number_of_elements-1, order_statistic)<<endl;
  order_statistic = 80;
  cout << order_statistic<< "th order statistic is ";
  cout<<rand_select(A, 0, number_of_elements-1, order_statistic)<<endl;
  return 0;
}
