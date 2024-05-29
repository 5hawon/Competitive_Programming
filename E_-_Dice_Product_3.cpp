#include<bits/stdc++.h>
using namespace std;
int main()
{
    char s[3][3];
    string goal [3][3];
    int i,j;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
            cin>>s[i][j];
    }
    
   
    for(i=0;i<3;i++)
        {
            for(j=0;j<3;j++)
                cin>>goal[i][j];
        }
     for(i=0;i<3;i++)
        {
            for(j=0;j<3;j++)
            {
                cout<<goal[i][j]<<" ";
            }
            cout<<endl;
        }
    int total_misplaced=0;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            if(goal[i][j]!=s[i][j])
            {
                total_misplaced++;
            }
        }
    }
     cout<<"Total misplaced ="<<total_misplaced<<endl;
    
    cout<<"Total misplaced ="<<total_misplaced<<endl;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            cout<<"Manhattan distance for "<<s[i][j]<<" =";
            int k,l;
            int f=0;
            for(k=0;k<3;k++)
            {
                for(l=0;l<3;l++)
                {
                    if(s[i][j]==goal[k][l])
                    {
                        cout<<abs(i-k)+abs(j-l)<<endl;
                        f=1;
                        break;
                    }
                }
                if(f==1)
                    break;
            }
        }
    }
    
}