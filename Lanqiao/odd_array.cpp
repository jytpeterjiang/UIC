#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s1,s2; //个数+具体数字 
    int n;
    cin>>s1>>n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<s1.size();j++)
        {
            int sign=1;
            while(s1[j]==s1[j+1])
            {
                sign++; //个数 
                j++;
            }
            s2+=(to_string(sign)+s1[j]); //个数+具体数字  
        }
        s1=s2;
        s2.clear();
    }
    cout<<s1<<endl;
    return 0;
}