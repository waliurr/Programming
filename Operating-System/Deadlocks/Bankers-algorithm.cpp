#include<bits/stdc++.h>
using namespace std;

int n, m, i, j, k;
int alloc[20][20], maximum[20][20], available[20];

int main()
{
    freopen("input.txt","r",stdin);
    cin>>n>>m;

    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
            cin>>alloc[i][j];
        }
    }

    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
            cin>>maximum[i][j];
        }
    }

    for(i=0; i<m; i++)
    {
        cin>>available[i];
    }

    int f[n], safe[n], c = 0;
    for (k = 0; k < n; k++)
    {
        f[k] = 0;
    }
    int need[n][m];
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            need[i][j] = maximum[i][j] - alloc[i][j];
        }
    }

    cout<<"Total process  : "<<n<<endl;
    cout<<"Total resource : "<<m<<endl;

    cout<<"Process Alloc \t Max \t Need"<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<"p"<<i<<"\t";
        for(int j=0; j<m; j++)
        {
            cout<<alloc[i][j]<<" ";
        }
        cout<<"\t";
        for(int j=0; j<m; j++)
        {
            cout<<maximum[i][j]<<" ";
        }
        cout<<"\t";
        for(int j=0; j<m; j++)
        {
            cout<<need[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    cout<<"Available : ";
    for(int i=0; i<m; i++)
    {
        cout<<available[i]<<" ";
    }
    cout<<endl;

    int y = 0;
    for (k = 0; k < 5; k++)
    {
        for (i = 0; i < n; i++)
        {
            if (f[i] == 0)
            {
                int flag = 0;
                for (j = 0; j < m; j++)
                {
                    if (need[i][j] > available[j])
                    {
                        flag = 1;
                        break;
                    }
                }

                if (flag == 0)
                {
                    safe[c++] = i;
                    for (y = 0; y < m; y++)
                    {
                        available[y] += alloc[i][y];
                    }
                    f[i] = 1;
                }
            }
        }
    }

    cout<<endl;
    cout <<"The SAFE Sequence" << endl;
    for (i = 0; i < n - 1; i++)
        cout << " P" << safe[i] << " ->";
    cout << " P" << safe[n - 1] <<endl;

    return (0);
}
