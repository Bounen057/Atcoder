/*
*
*  アルゴリズム DFS 深さ優先探索
*  参考：https://atcoder.jp/contests/atc001/tasks/dfs_a
*
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

//　入力
int H,W = 0; //H 縦 / W 横

vector<vector<char>> mapp(600,vector<char>(600));

// 探索用変数
int start_x,start_y = 0;
vector<vector<int> > Isexplored(600,vector<int>(600));


bool Isreturn(int y,int x){

    // マップの外だったらtrue
    if(x < 0 || y < 0 || H <= y || W <= x) {
        if(x >= 0 && y >= 0) Isexplored.at(y).at(x) = 1;
        return true;
    }

    // 一度脚を踏み入れていたらtrue
    if(Isexplored.at(y).at(x) == 1) {
        Isexplored.at(y).at(x) = 1;
        return true;
    }
    Isexplored.at(y).at(x) = 1;

    // 壁だったらtrue
    if(mapp.at(y).at(x) == '#') return true;

    return false;
}

// ゴール
void goal(){
    cout << "Yes" << endl;
    exit(0);
}

// スタートしたのかどうか判定
bool Isstart(int y,int x){
    if(mapp.at(y).at(x) != 's') return false;

    if(y > 0) if(Isexplored.at(y-1).at(x) == 0) return false;
    if(Isexplored.at(y+1).at(x) == 0) return false;
    if(Isexplored.at(y).at(x+1) == 0) return false;
    if(x > 0) if(Isexplored.at(y).at(x-1) == 0) return false;

    return true;
}

// 探索用 再帰関数
void explore(int y,int x){

    // cout << "test  :  " << y << "," << x << endl; デバッグ用

    // returnするかどうか
    if(Isreturn(y,x)) return;

    // スタート地点判定
    if(Isstart(y,x)) return;

    // ゴール判定
    if(mapp.at(y).at(x) == 'g') goal();

    explore(y , x + 1); // 右
    explore(y , x - 1); // 左
    explore(y + 1, x ); // 下
    explore(y - 1, x ); // 上
}


int main(){

    //
    // 入力
    //
    cin >> H;
    cin >> W;

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> mapp.at(i).at(j);

            if(mapp.at(i).at(j) == 's'){
                start_y = i;
                start_x = j;
            }
        }
    }

    explore(start_y,start_x);

    cout << "No" << endl;
}

