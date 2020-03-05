#include <iostream>
#include <string>
#include <algorithm>
#include <functional>

using namespace std;

int N;
int d[110];

int main(){

    int layer = 1;

    cin >> N;
    for(int i= 0;i < N;i++) cin >> d[i];

    // 降順に配列をソート
    sort(d,d + N,greater<int>());

    // 最大で何層か数える
    for(int i = 0;i < N-1;i++){
        
        if(d[i] > d[i+1]){
            layer++;
        }

    }

    cout << layer << endl;
}