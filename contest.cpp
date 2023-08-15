#include<bits/stdc++.h>
using namespace std;

int main()
{
  int n,q;
  cin >> n >> q;
  int arr[n],i,arr2[q];
  for(i=0;i<n;i++)
   cin >> arr[i];
  for(i=1;i<n;i++)
   {
     arr[i] += arr[i-1];
   }
//     for(i=0;i<n;i++)
 // cout << arr[i] << " ";
   
  for(i=0;i<q;i++)
  {
    int a,b;
    cin >> a >>b;
    if(a==1)arr2[i] = arr[b-1];
    else
    arr2[i] = arr[b-1]-arr[a-2] ;

  }
  for(i=0;i<q;i++)
    cout << arr2[i] << endl;
  


}