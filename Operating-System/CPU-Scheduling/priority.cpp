#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,tmp,tmp2,p[10],bt[10],pr[10],wt[10],tt[10];
    float avwt=0,avtt=0;

    cout<<"Enter No. of process: ";
    cin>>n;
    cout<<"Enter burst time and Priority of process"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<"p"<<i+1<<": ";
        cin>>bt[i];
        cin>>pr[i];
        p[i]=i+1;
    }

    cout<<"Total Process = "<<n<<endl;
    cout<<"Arrival time  = 0"<<endl;
    cout<<"-----------------------------------------"<<endl;
    cout<<"Process\t\tBurst time\tPriority"<<endl;
    cout<<"-----------------------------------------"<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<"P"<<p[i]<<"\t\t"<<bt[i]<<"\t\t"<<pr[i]<<endl;
    }
    cout<<"-----------------------------------------"<<endl;


    for(int i=0;i<n;i++)
    {
        tmp=i;
        for(int j=i+1;j<n;j++)
        {
            if(pr[tmp]>pr[j])
            {
                tmp=j;
            }
        }
        tmp2 = p[i];
        p[i] = p[tmp];
        p[tmp] = tmp2;

        tmp2 = pr[i];
        pr[i] = pr[tmp];
        pr[tmp] = tmp2;

        tmp2 = bt[i];
        bt[i] = bt[tmp];
        bt[tmp] = tmp2;
    }


    wt[0]=0;
    for(int i=1; i<n; i++)
    {
        wt[i]=0;
        for(int j=0; j<i; j++)
        {
            wt[i]+=bt[j];
        }
    }

    for(int i=0;i<n;i++)
    {
        tt[i]=wt[i]+bt[i];
        avwt+=wt[i];
        avtt+=tt[i];
    }

    avwt/=n;
    avtt/=n;

    cout<<"\nApplying Priority scheduling algorithm"<<endl<<endl;

    cout<<"Process sequence is: ";
    for(int i=0;i<n;i++)
    {
        cout<<"p"<<p[i]<<" ";
    }
    cout<<endl;
    cout<<"-------------------------------------------------------------------------------"<<endl;
    cout<<"Process\t\tBurst time\tPriority\tWaiting time\tTurnaround time"<<endl;
    cout<<"-------------------------------------------------------------------------------"<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<"P"<<p[i]<<"\t\t"<<bt[i]<<"\t\t"<<pr[i]<<"\t\t"<<wt[i]<<"\t\t"<<tt[i]<<endl;
    }
    cout<<"-------------------------------------------------------------------------------"<<endl;
    cout<<endl;
    cout<<"Average waiting time = "<<avwt<<endl;
    cout<<endl;
    cout<<"Average turnaround time = "<<avtt<<endl;

    cout<<endl;
    return 0;
}
