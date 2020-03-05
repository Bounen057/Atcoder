#include <iostream>
#include <string>

using namespace std;

int N;
int Y;

// N枚でY円に達するかチェック
bool check(){
    int x,y,z = 0; // 1000,5000,10000 円札
    int total_money = 0;//合計金額

    for(int x=0 ;x <= N;x++){
        for(int y=0 ;y <= N;y++){
            int z = N - ( x + y ); 

            if( z < 0 ) continue;

            total_money = x*1000 + y*5000 + z*10000;

            // 合計金額がY円で、合計枚数がN枚であればtrue
            if(total_money == Y){
                if(x + y + z == N){
                    cout << z << " " << y << " " << x << endl;

                    return true;
                }
            }


        }
    }

    return false;
}

int main(){
    cin >> N;
    cin >> Y;

    if(!check()){
        cout << "-1 -1 -1" << endl;
    }
}