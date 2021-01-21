#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,tmp,tmp2,quantum,p[10],bt[10],rt[10],wt[10],tt[10];
    float avwt=0,avtt=0;
    bool process_done;
    int t=0;

    cout<<"Enter No. of process: ";
    cin>>n;
    cout<<"Enter Quantum time: ";
    cin>>quantum;
    cout<<"Enter burst time of process"<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<"p"<<i+1<<": ";
        cin>>bt[i];
        rt[i]=bt[i];
        p[i]=i+1;
        wt[i]=0;
        tt[i]=0;
    }

    cout<<"Total Process = "<<n<<endl;
    cout<<"Arrival time  = 0"<<endl;
    cout<<"Quantum time  = "<<quantum<<endl;
    cout<<"--------------------------"<<endl;
    cout<<"Process\t\tBurst time"<<endl;
    cout<<"--------------------------"<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<"P"<<p[i]<<"\t\t"<<bt[i]<<endl;
    }
    cout<<"--------------------------"<<endl;

    cout<<"\nApplying Round Robin scheduling algorithm"<<endl<<endl;
    cout<<""<<endl;
    cout<<"---------------------------------------------------------------------"<<endl;
    cout<<"Process\t\tBurst time\tRemaining time\tWaiting time\tTime"<<endl;
    cout<<"---------------------------------------------------------------------"<<endl;
    while(1)
    {
        process_done=true;
        for(int i=0; i<n; i++)
        {
            if(rt[i]>0)
            {
                process_done=false;
                tmp2=rt[i];
                if(rt[i]>quantum)
                {
                    t+=quantum;
                    rt[i]-=quantum;
                }
                else
                {
                    t+=rt[i];
                    rt[i]=0;

                    wt[i]=t-bt[i];
                    tt[i]=wt[i]+bt[i];

                    avwt+=wt[i];
                    avtt+=tt[i];
                }
                cout<<"P"<<p[i]<<"\t\t"<<tmp2<<"\t\t"<<rt[i]<<"\t\t"<<wt[i]<<"\t\t"<<t<<endl;
            }

        }
        if(process_done == true)
            break;
    }

    avwt/=n;
    avtt/=n;

    cout<<endl;
    cout<<"---------------------------------------------------------------"<<endl;
    cout<<"Process\t\tBurst time\tWaiting time\tTurnaround time"<<endl;
    cout<<"---------------------------------------------------------------"<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<"P"<<p[i]<<"\t\t"<<bt[i]<<"\t\t"<<wt[i]<<"\t\t"<<tt[i]<<endl;
    }
    cout<<"---------------------------------------------------------------"<<endl;
    cout<<endl;
    cout<<"Average waiting time = "<<avwt<<endl;
    cout<<endl;
    cout<<"Average turnaround time = "<<avtt<<endl;

    cout<<endl;
    return 0;
}
