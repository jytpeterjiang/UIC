#include <iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i = 0;i<n;i++){
        cin >> a[i];
    }
    int ans = 0;
    for(int i = 0;i<n-1;i++){
        if (a[i] != i+1){
            for(int j = i;j<n;j++){
                if (a[j] == i+1){
                    int temp = a[i];
                    a[i] = a[j];
                    a[j] = temp;
                    ans++;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}