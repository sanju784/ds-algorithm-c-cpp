#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
  int arr[] = {1,3,-1,-3,5,3,6,7};
  int w = 3;
  int n = sizeof(arr)/sizeof(int);
  int *res;
  res = (int*)malloc((n-w+1)*sizeof(int));
  int max = arr[0];
  for(int j = 1;j < w; j++) {
    if(arr[j] > max) {
        max = arr[j];
    }
  }
  int j = 0;
  res[j++] = max;
  for (int i = w;i < n; i++){
    if(arr[i] > max) {
        max = arr[i];
    }
    res[j++] = max;
  }
  cout<<"\nOriginal array is\n";
  for(int i = 0; i < n; i++)
    cout<<arr[i]<<" ";
  cout<<"\n\nThe window size is "<<w<<endl;
  cout<<"\nThe maximum array is\n";
  for(int i = 0; i < (n-w+1); i++)
    cout<<res[i]<<" ";
  return 0;
}
