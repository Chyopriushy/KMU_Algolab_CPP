#include <iostream>

using namespace std;

int t, cnt, row, col, b, w;
char board[8][8];

int dx[8] = {-1, 1, 0, 0, -1, -1, 1, 1};
int dy[8] = {0, 0, -1, 1, -1, 1, -1, 1};

void placeStone(char my_s, int x, int y);
bool flipCheck(char my_s, int x, int y, int di);
void flipStone(char my_s, int x, int y, int di);


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t;

    while(t--){
        cin >> cnt;
        fill(&board[0][0], &board[7][8], '+');
        board[3][3] = 'O', board[4][4] = 'O';
        board[4][3] = 'X', board[3][4] = 'X';

        for(int i = 0; i < cnt; i++){
            cin >> row >> col;
            if(i % 2 == 0) placeStone('X', row - 1, col - 1);
            else placeStone('O',row - 1, col - 1);
        }

        b = 0, w = 0;

        for(auto& i : board){
            for(auto& j : i){
                if(j == 'X') b++;
                else if(j == 'O') w++;
            }
        }
        cout << b << " " << w << "\n";

        for(auto& i : board){
            for(auto& j : i) cout << j;
            cout << "\n";
        }
    }
}

void placeStone(char my_s, int x, int y){
    int nx , ny;
    board[x][y] = my_s;
    for(int i = 0; i < 8; i++){
        nx = x + dx[i], ny = y + dy[i];
        if(0 <= nx && nx < 8 && 0 <= ny && ny < 8 && board[nx][ny] != '+' && board[nx][ny] != my_s){
            if (flipCheck(my_s,nx, ny, i)) flipStone(my_s,nx, ny, i);
        }
    }
}
bool flipCheck(char my_s, int x, int y, int di){

    int nx, ny;

    nx = x + dx[di], ny = y + dy[di];

    while(nx >= 0 && nx < 8 && ny >= 0 && ny < 8){
        if(board[nx][ny] == my_s) return true;
        nx += dx[di], ny += dy[di];
    }
    return false;
}
void flipStone(char my_s, int x, int y, int di){
    int nx = x, ny = y;
    while(true){
        nx += dx[di];
        ny += dy[di];
        if(nx < 0 || nx >= 8 || ny < 0 || ny >= 8 || board[nx][ny] == '+')
            break;
        if(board[nx][ny] == my_s){
            while(nx != x || ny != y){
                nx -= dx[di];
                ny -= dy[di];
                board[nx][ny] = my_s;
            }
            break;
        }
    }
}