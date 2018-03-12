#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, i,j,k;
    cout<<"Enter the no. of process : ";
    cin>>n;
    queue <int> q;
    vector<int> arrivalTime, burstTime,tempBurstTime, completionTime, waitingTime(n), turnOverTime(n);
    cout<<"Enter arrival and corresponding burst time "<<n<<" times : \n";
    for(i=0;i<n;i++)
    {
        int a, b;
        cin>>a>>b;
        arrivalTime.push_back(a);
        burstTime.push_back(b);
        q.push(i);
    }
    completionTime = burstTime;
    tempBurstTime = burstTime;

    int qTime;
    cout<<"Enter Time Quantum : ";
    cin>>qTime;

    int current;
    int currentTime = 0;
    while(!q.empty())
    {
        current = q.front();
        q.pop();
        if(tempBurstTime[current] > qTime)
        {
            currentTime += qTime;
            completionTime[current] += currentTime;
            tempBurstTime[current] -= qTime;
            q.push(current);
        }
        else{
                currentTime += tempBurstTime[current];
                completionTime[current] = currentTime;
        }       

    }

    cout<<endl;
   
    for(i=0;i<n;i++)
    {
        cout<<completionTime[i]<<endl;
    }
    for(i=0;i<n;i++)
    {
        turnOverTime[i] = completionTime[i] - arrivalTime[i];
    }

    for(i=0;i<n;i++)
    {
        waitingTime[i] = turnOverTime[i]- burstTime[i];
    }

    cout<<"A.T  B.T  C.T  T.O.T  W.T\n";
    for(i=0;i<n;i++)
    {
        printf("%3d%5d%5d%7d%5d\n", arrivalTime[i],burstTime[i],completionTime[i], turnOverTime[i], waitingTime[i] );
    }

}