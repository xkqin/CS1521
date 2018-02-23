#include <iostream>
using namespace std;
void sort(int A[], int left, int right);
int main()
{
  int A[]={2,-3,4,-2,-3,0};
  int left = 0, right = 5;
  sort(A,0,5);
  for(int i=0; i< 6; ++i)
    {
      cout <<' ' <<A[i];
    }
  cout << endl;
}
void sort(int A[], int left, int right)
{
  if(left<right)
    {
      for(left; A[left] <0; ++left);
      for(right; A[right] >0; --right);
        int temp;
      temp = A[left];
      A[left] = A[right];
      A[right] = temp;
      sort(A,++left,--right);
    }
}
