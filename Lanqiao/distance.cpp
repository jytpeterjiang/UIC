#include<bits/stdc++.h>
using namespace std;

// locate the row
int row(int w, int n){
    if (n % w != 0){
        return(n/w + 1);
    }else{
        return(n/w);
    }
}

// locate the column
int column(int w, int n, int x){
    if (x % 2 != 0){ // if it is in the odd row
        if(n % w == 0){ // if it can be divided by the number of rows
            return(w);
        }else{
            return(n % w);
        }
    }else{ // if it is in the even row
        return(w - (n % w) + 1);
    }
}

int main(){
    int w = 0,n = 0,m = 0;
    cin >> w >> n >> m;
    int x1 = 0,y1 = 0,x2 = 0,y2 = 0;
    x1 = row(w,n);
    x2 = row(w,m);
    y1 = column(w,n,x1);
    y2 = column(w,m,x2);
    cout << abs(x1 - x2) + abs(y1 - y2) << endl;
    return 0;
}