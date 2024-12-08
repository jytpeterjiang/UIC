#include <iostream>
using namespace std;
int ans(int n){
    if (n<3){
        return 0;
    }
    int left = n % 3;
    int award = n / 3;
    return award + ans(award + left);
}
int main()
{
  int n;
  cin >> n;
  cout << n+ans(n) << endl;
  return 0;
}