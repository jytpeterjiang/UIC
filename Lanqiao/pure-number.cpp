#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, sum = 0;
    cin >> n;
    vector<int> a;
    for(int i = 1;i<=n;i++){
        int j = i;
        while(j >= 1){
            a.push_back(j % 10);
            j /= 10;
        }
        int flag = 0;
        for(int k = 0;k<a.size();k++){
            if (a[k] == 2){
                flag = 1;
                break;
            }
        }
        if(flag == 0){
            sum++;
        }
        a.clear();
    }
    cout << sum << endl;
    return 0;
}