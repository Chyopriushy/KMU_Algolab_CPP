//
// Created by navykid75 on 2024-05-12.
//
#include <iostream>

using namespace std;

int t, n, mid;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t;

    while(t--){
        cin >> n;
        mid = n / 2;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i == mid && j == mid) cout << "*";
                else if(!(i % mid) && !(j % mid)) cout << "+";
                else if(!(i % mid) && (j % mid)) cout << "-";
                else if((i % mid) && !(j % mid)) cout << "|";
                else if(j == i) cout << "\\";
                else if(j == (n - 1) - i) cout << "/";
                else cout << ".";
            }
            cout << "\n";
        }
    }
}