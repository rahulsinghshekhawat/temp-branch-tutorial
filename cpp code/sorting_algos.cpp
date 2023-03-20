#include<bits/stdc++.h>
#define read_array(arr,n) for(int i=0;i<n;i++) cin>>arr[i];
#define read_2darray(arr,r,c) for(int i=0;i<r;i++){ for(int j=0;j<c;j++){ cin>>arr[i][j];} cout<<endl;} 
#define printarray(arr,length) for(int i=0;i<length;i++){ cout<<arr[i]<<" "; }
#define print2darray(arr,r,c) for(int i=0;i<r;i++){ for(int j=0;j<c;j++){ cout<<arr[i][j]<<" ";} cout<<endl;}
#define printvector(arr) for(auto i:arr) cout<<i<<" ";
using namespace std;


// selection sort means fetch the smallest element from unsorted part of the array(select)
// and add to the sorted part of the array (sort)
void selection_sort(int arr[], int n){
    for(int i=0;i<n;i++){
        int minindex = i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<=arr[minindex]){
                minindex=  j;
                }
        }
        swap(arr[minindex], arr[i]);
    }
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}


void bubble(int arr[], int n){
    for(int i=0;i<n-1;i++){
        for(int j=1;j<(n-i);j++){
            if(arr[j]<arr[j-1])
                swap(arr[j],arr[j-1]);
        }
    }
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

void insertion(int arr[], int n){
    int j;
    for(int i=0;i<n-1;i++){
        j=i+1;
        if(arr[j]<arr[i]){
            while(arr[j]<arr[j-1] && j>0){
                swap(arr[j],arr[j-1]);
                j--;
            }
        }
    }
}

void merge(int arr[], int left, int mid, int right){
    if(left>=right)
        return;
    // cout<<"Merging started from "<<left<<" to "<<right<<" and mid is "<<mid<<endl;
    // cout<<"And both array are "<<" ";
    // for(int i=left;i<=right;i++)
        // cout<<arr[i]<<" ";
    // cout<<endl;

    int i=left, j=mid+1;
    int aux_n = right-left+1;
    int aux[aux_n];
    int k=0;
    while(i<=mid && j<=right){
        if(arr[i]>arr[j]){
            // cout<<arr[j]<<" ";
            aux[k] = arr[j];
            j++;
        }
        else{
            // cout<<arr[i]<<" ";
            aux[k] = arr[i];
            i++;
        }
        k++;
    }
    for(int p = i;p<=mid;p++){
        // cout<<arr[p]<<" ";
        aux[k++] = arr[p];
    }
    for(int q = j;q<=right;q++){
        // cout<<arr[q]<<" ";
        aux[k++] = arr[q];
    }
    for(int i=left;i<=right;i++){
        arr[i] = aux[i-left];
        // cout<<arr[i]<<" ";
    }
    // for(int i=0;i<aux_n;i++)
        // cout<<aux[i]<<" ";
    // cout<<endl;
    // cout<<"Merged from "<<left<<" to "<<right<<endl;
    // for(int i=left;i<=right;i++)
    //     cout<<arr[i]<<" ";
    // cout<<endl;
}

void split(int arr[], int left, int right){
    if(left>=right){
        // cout<<"can't be splitted further"<<endl;
        return;
    }
        
    // cout<<"Splitting from "<<left<<" to "<<right<<endl;
    int mid = (right+left)/2;
    split(arr,left,mid);
    split(arr,mid+1,right);
    merge(arr,left,mid,right);
}

void mergesort(int arr[], int n){
    split(arr,0,n-1);
    // printarray(arr,n);
}

void bubble_rec1(int arr[], int i, int n){
    if(i+1==n) 
        return;
    if(arr[i]>arr[i+1])
        swap(arr[i],arr[i+1]);
    bubble_rec1(arr,i+1,n);
}

void bubble_rec2(int arr[], int n){
    if(n==1)
        return;
    bubble_rec1(arr,0,n);
    bubble_rec2(arr,n-1);
}


void bubble_recursive(int arr[], int n){
    bubble_rec2(arr,n);
}

void insertion_rec(int arr[], int i, int n){
    if(i+1==n)
        return;
    int j=i+1;
    while(arr[j]<arr[j-1] && j>0){
        swap(arr[j],arr[j-1]);
        j--;
    }
    insertion_rec(arr,i+1,n);
}

int pivotstart(int arr[], int st, int end){
    int p = st, m=p;
    for(int i=p+1;i<=end;i++){
        if(arr[i]<arr[p]){
            m++;
            swap(arr[i],arr[m]);
        }
    }
    swap(arr[p],arr[m]);
    return m;
}

int pivotend(int arr[], int st, int end){
    int p = end, m=st-1;
    for(int i=st;i<end;i++){
        if(arr[i]<arr[p]){
            m++;
            swap(arr[i],arr[m]);
        }
    }
    m++;
    swap(arr[p],arr[m]);
    return m;
}

void quicksort(int arr[], int st, int end){
    if(st>=end){
        return ;
    }
    int p = pivotend(arr,st,end);
    quicksort(arr,st,p-1);
    quicksort(arr,p+1,end);
}

int seclar(int arr[], int n){
    if(n<=2)
        return 1;
    int i=1;
    while(arr[i]>=arr[i-1] && i<n){
        i++;
    }
    cout<<"Breakign point or i is ";
    cout<<i<<endl;
    if(i==n)
        return 1;
    for(int j=0;j<n-1;j++){
        if(arr[(i+j)%n] > arr[(i+j+1)%n])
            return 0;
    }
    return 1;
}





int main(){
    // cout<<(5%5);
    int n;
    cin>>n;
    int arr[n];
    read_array(arr,n);
    cout<<seclar(arr,n);
    // quicksort(arr,0,n-1); 
    // insertion_rec(arr,0,n);
    // bubble_recursive(arr,n);
    // mergesort(arr,n);
    // insertion(arr,n);
    // printarray(arr,n);
    // int n,m;
    // cin>>n>>m;
    // int arr[n][m];
    // read_2darray(arr,n,m);
    // print2darray(arr,n,m);
    // int n=12;
    // int arr[] = {9,8,7,6,3,4,9,5,4,3,2,1};
    // for(int i=0)
    // selection_sort(arr,n);
    // bubble(arr,n);
}
