/*
*
*  アルゴリズム bit全検索
*  https://atcoder.jp/contests/abc079/tasks/abc079_c
*  この問題を使ってbit全検索を練習します。
*
*/

#include <iostream>
#include <vector>
#include <stdio.h>
#include <string>
using namespace std;

int main(){
    string s;
    cin >> s;

    vector<int> c(4);

    for(int i = 0;i < s.length();i++) c[i] = s[i] - '0';

    int res; // 計算結果
    string res_sentence; //出力用

    for (int i = 0; i < (1 << 3) ;i++){
        res = c[0];
        res_sentence = to_string(c[0]); 

        for(int j = 0;j < 3;j++){
            // 右からj番目の値が1であれば+ 0であれば-
            if(i & (1 << j)){
                res = res + c[j+1];
                res_sentence = res_sentence + '+' + to_string(c[j+1]);
            }else{
                res = res - c[j+1];
                res_sentence = res_sentence + '-' + to_string(c[j+1]);
            }
        }

        if(res == 7){
            cout << res_sentence << "=7" << endl;
            return 0;
        }

    }
            // 問題の仕様上ここにはたどり着かないはず
        return -1;
}