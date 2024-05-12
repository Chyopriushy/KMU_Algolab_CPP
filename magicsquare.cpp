//
// Created by navykid75 on 2024-04-27.
//
#include <iostream>
#include <vector>
using namespace std;

int t, num, size_, r, c;
pair<int, int> l;
vector<vector<int>> board;

void make(int s);
pair<int, int> move(int row, int col);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t;

    while(t--){
        cin >> size_;
        if(size_ == 1){
            cout << 1 << "\n";
            continue;
        }
        board = {};
        board.resize(size_);
        for(auto& i : board) i.resize(size_);
        make(size_);

        for(auto & i : board){
            for(auto j : i) cout << j <<" ";
            cout << "\n";
        }
    }
}

void make(int s){
    int cnt = s * s;
    r = 0, c = s / 2;
    board[r][c] = 1;
    for(int i = 2; i < cnt + 1; i++){
        l = move(r, c);
        r = l.first, c = l.second;
        board[r][c] = i;
    }
}

pair<int, int> move(int row, int col){
    r = row - 1, c = col + 1;

    r = (r < 0)? size_ -1 : r;
    c = (c >= size_)? 0 : c;

    if(board[r][c]) r = row + 1, c = col;
    return make_pair(r, c);
}


