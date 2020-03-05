#include <iostream>
#include <string>

using namespace std;

int N;
int A[300];


// 全ての値が偶数かチェック
// true = 全て偶数 / false = 何かが奇数
bool IsEven(){
    for(int i = 0;i < N;i++){
        if(A[i] % 2 == 1){
            return false;
        }
    }

    return true;
}

// 全て2で割る
void Devide(){
    for(int i = 0;i < N;i++){
        A[i] = A[i] / 2;
    }
}

int main(){

    int re = 0;

    // 入力
    cin >> N;
    for(int i = 0;i < N;i++) cin >> A[i];


    while(IsEven()){
        Devide();

        re++;
    }

    cout << re << endl;

}