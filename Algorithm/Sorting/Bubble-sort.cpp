#include<bits/stdc++.h>
using namespace std;

void BubbleSort(int a[],int n)
{
    int temp;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<(n-i-1);j++)
        {
            if(a[j]>a[j+1])
                {
                    temp = a[j];
                    a[j] = a[j+1];
                    a[j+1] = temp;
                }
        }
    }
}

int main()
{
    int n,arr[50];

    cout<<"Enter array size: ";
    cin>>n;

    for(int i=0; i<n; i++)
    {
        cout<<"arr["<<i<<"] = ";
        cin>>arr[i];
    }
    cout<<endl;

    cout<<"Your entered array is: ";
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl<<endl;

    BubbleSort(arr,n);

    cout<<"After sorted array is: ";
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }

    cout<<endl;
    return 0;
}
