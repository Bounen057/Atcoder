/*
*
*  アルゴリズム 再帰関数
*  参考：https://qiita.com/drken/items/23a4f604fa3f505dd5ad
*
*/

#include <iostream>
using namespace std;

int func(int i){
    if(i == 0) return 0;
    return i + func(i-1);
}

int main(){
    int n;
    cout << endl;
    cout << "nまでの値の和を表示します：nの値を入力してください" << endl;
    cin >> n;

    cout << n << "までの値の和 : " << func(n) << endl;
}