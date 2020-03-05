#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;

class PrimeNumber{
    private:
    unsigned int p;

    public:

    PrimeNumber(int i);
    bool IsPrime();
};

PrimeNumber::PrimeNumber(int i){
    p = i;
}

bool PrimeNumber::IsPrime(){

    for(int i = 2;i < p-1;i++){

        if(p % i == 0){
            return false;
        }
    }

    return true;
}


int main()
{
    int n;

    cout << "0~nの自然数の間の素数を列挙します。nを入力してください" << endl;
    cin >> n;

    for(int i = 0;i < n;i++){
        PrimeNumber Prime(i);

        if(Prime.IsPrime()){
            cout << i << endl;
        }
    }

}