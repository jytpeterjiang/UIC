#include<iostream>
using namespace std;
int main(){
    int n, a, b, c, sum = 0;
    cin >> n >> a >> b >> c;
    for(int i = 1;i<=n;i++){
        if (i % a != 0){
            if (i % b != 0){
                if(i % c != 0){
                    sum++;
                }
            }
        }
    }
    cout << sum << endl;
    return 0;
}