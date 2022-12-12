//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long int merge(long long arr[],int beg,int mid,int end)
    {
      int n1=mid-beg+1;
      int n2=end-mid;
      long long left[n1];
      long long right[n2];
      int i,j,k;
      long long int inversion_count=0;
      for(i=0;i<n1;i++)
      {
          left[i]=arr[beg+i];
      }
      for(j=0;j<n2;j++)
      {
          right[j]=arr[mid+1+j];
      }
      i=0;j=0;k=beg;
      while(i<n1 && j<n2)
      {
         if(left[i]<=right[j])
          {
             
             arr[k++]=left[i++];
          }
          else
          {
              inversion_count+=n1-i;
           arr[k++]=right[j++];
          }
      }
      while(i<n1)
       arr[k++]=left[i++];
      while(j<n2)
       arr[k++]=right[j++];
      return inversion_count; 
    }
    long long int merge_sort(long long arr[],int l,int r)
    {
        long long int inversion_count=0;
        if(l<r)
        {
            int mid=l+(r-l)/2;
            inversion_count=merge_sort(arr,l,mid);
            inversion_count+=merge_sort(arr,mid+1,r);
            inversion_count+=merge(arr,l,mid,r);
        }
        return inversion_count;
    }
    
    long long int inversionCount(long long arr[], long long N)
    {
       return merge_sort(arr,0,N-1);
       
    }

};

//{ Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}

// } Driver Code Ends
