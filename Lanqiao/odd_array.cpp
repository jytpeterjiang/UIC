#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
  int num=1,n;
  string str;
  cin>>str>>n;
  while(n--){ 
    str+='@';
    string ans;
    for(int i=0;i<str.size()-1;i++){
      if(str[i]==str[i+1])num++;
      if(str[i]!=str[i+1]){
        ans+=(char)('0'+num);
        ans+=str[i];
        num=1;
      }
    }
    str=ans;
  }
  cout<<str;

  return 0;
}