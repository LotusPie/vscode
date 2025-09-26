#include<iostream>
#include<random>
#include <cstdlib>
#include <ctime>
// #include<Windows.h>
#include<vector>
#include<algorithm>

#include <cstdio>   // 為了 printf
#include <cstdlib>  // 為了 system
#include <chrono>   // 為了時間
#include <thread>   // 為了 sleep_for

using namespace std;


int maze_width, maze_height;
// bool visited[20][20] = { 0 }; // 紀錄有沒有走過
vector<vector <bool>> visited;
// bool mined[20][20] = { 0 }; // 紀錄挖過的
vector<vector <bool>> mined;

// int start_x = 1, start_y = 1; // 起點
int goal_x, goal_y; // 終點
bool goal = false; // 是否走到終點了

// int maze[20][20] = { 0 }; // 初始地圖
vector<vector<int>> maze;
// int sum[20][20] = { 0 };  // 計算步數
vector<vector <int>> sum;

void print_maze() { // 畫圖
    system("clear");
    for (int i = 0; i < maze_height; i++) {
        for (int j = 0; j < maze_width; j++) {
            if (maze[i][j] == 1)
                printf("牆");
            else if (maze[i][j] == 2)
                printf("**");
            else
                printf("  ");
        }
        printf("\n");
    }
    // Sleep(1);
    std::this_thread::sleep_for(std::chrono::milliseconds(10)); // 修改這裡
}


int currentD = 0;
int MaxD = 0;

void miner(int x,int y,int &currentD) { // 生成地圖，打掉牆

    if (currentD > MaxD) {
        MaxD = currentD;
        goal_x = x;
        goal_y = y;
    }

    maze[x][y] = 0; // 挖牆ing 
    mined[x][y] = true;
    vector<int> directions = { 0, 1, 2, 3 }; // 0:右, 1:左, 2:上, 3:下
    random_device rd; 
/* 
    這一行就是宣告了一個叫做 rd 的 random_device 物件。
    之後你可以呼叫 rd()，它就會回傳一個亂數 (通常是 unsigned int 型別)。
*/
    mt19937 g(rd()); 
/* 
    mt 代表 "Mersenne Twister"
    是一種產生高品質偽亂數的演算法。19937 指的是它的一些內部參數
    (rd())：這是把 rd() 作為初始種子傳遞給 mt19937 引擎的建構函式。
*/
    shuffle(directions.begin(), directions.end(), g);
/*
    請 shuffle 函式，把我 directions vector 裡從頭到尾的所有元素，
    利用 g 這個亂數引擎提供的亂數，給我隨機地打亂它們的順序。
*/

    print_maze();

    for (int dir : directions) {
        if(dir==0){
            if (y + 2 >= 1 && y + 2 <= maze_width - 2 && maze[x][y + 2] == 1 && mined[x][y + 2] == false) { /* 往右挖 */
                maze[x][y + 1] = 0; // 挖牆
                mined[x][y + 1] = true; 
                currentD += 1;
                miner(x, y + 2, currentD);
                currentD -= 1;
            }
        }
        else if(dir==1){
            if (y - 2 >= 1 && y - 2 <= maze_width - 2 && maze[x][y - 2] == 1 && mined[x][y - 2] == false) { /* 往左挖 */
                maze[x][y - 1] = 0; // 挖牆
                mined[x][y - 1] = true;
                currentD += 1;
                miner(x, y - 2, currentD);
                currentD -= 1;
            }
        }
        else if (dir == 2) {
            if (x - 2 >= 1 && x - 2 <= maze_height - 2 && maze[x - 2][y] == 1 && mined[x - 2][y] == false) { /* 往上挖 */
                maze[x - 1][y] = 0; // 挖牆
                mined[x - 1][y] = true;
                currentD += 1;
                miner(x - 2, y, currentD);
                currentD -= 1;
            }
        }
        else if(dir==3){
            if (x + 2 >= 1 && x + 2 <= maze_height - 2 && maze[x + 2][y] == 1 && mined[x + 2][y] == false) { /* 往下挖 */
                maze[x + 1][y] = 0; // 挖牆
                mined[x + 1][y] = true;   
                currentD += 1;
                miner(x + 2, y, currentD);
                currentD -= 1;
            }
        }
    }
}


void func(int x, int y) { // 走迷宮邏輯
    visited[x][y] = 1;
    maze[x][y] = 2;
    print_maze();
    if (x == goal_x && y == goal_y) { // 也可以在這裡加 goal == true || 的判斷式
        goal = true;
    }
    if (y + 1 < maze_width && maze[x][y + 1] != 1 && visited[x][y + 1] == false && !goal) { /* 右邊的座標 */
        func(x, y + 1);
    }
    if (y - 1 >= 0 && maze[x][y - 1] != 1 && visited[x][y - 1] == false && !goal) { /* 左邊的座標 */
        func(x, y - 1);
    }
    if (x + 1 < maze_height && maze[x + 1][y] != 1 && visited[x + 1][y] == false && !goal) { /* 下面的座標 */
        func(x + 1, y);
    }
    if (x - 1 >= 0 && maze[x - 1][y] != 1 && visited[x - 1][y] == false && !goal) { /* 上面的座標 */
        func(x - 1, y);
    }
    if (goal)return;
    maze[x][y] = 0;
    print_maze();
}



int main() {
    int sx, sy; // 紀錄起點
    bool check = false;

    while(!check){
        cout << "請輸入迷宮寬度 ( 最大 80 ): ";
        cin >> maze_width;
        cout << "請輸入迷宮高度 ( 最大 80 ): ";
        cin >> maze_height;
        if (maze_width <= 0 || maze_width > 80 || maze_height <= 0 || maze_height > 80) {
            cout << "迷宮大小輸入錯誤！寬高必須介於 1 到 80 之間。" << endl;
            continue;
        }
        check = true;
    }

    maze.resize(maze_height, std::vector<int>(maze_width));
    mined.resize(maze_height, std::vector<bool>(maze_width));
    visited.resize(maze_height, std::vector<bool>(maze_width));
    sum.resize(maze_height, std::vector<int>(maze_width, 0));

    for (int i = 0; i < maze_height; i++) {
        for (int j = 0; j < maze_width; j++) {
            maze[i][j] = 1; // 把原本是 0 的都設成 1 (牆)
        }
    }

    srand(time(0));
    int x = rand() % maze_width;   int y = rand() % maze_height; // 隨機生成開始點
    while (x == 0 || x == maze_width - 1 || y == 0 || y == maze_height - 1) {
        x = rand() % maze_width;   int y = rand() % maze_height;
    }
    
    sx = x; sy = y;

    currentD = 0;
    MaxD = -1;
    miner(x, y, currentD); // 生成好地圖了

    for (int i = 0; i < maze_height; i++) { // 計算步數圖
        for (int j = 0; j < maze_width; j++) {
            if (maze[i][j] == 0) {
                sum[i][j] = { -1 }; // -1 代表沒走過
            }
        }
    }
    

    func(x, y);
    cout << endl;
    cout << "起點 : "<< "( " << sx << " , " << sy << " )" << endl;
    cout << "終點 : " << "( " << goal_x << " , " << goal_y << " )" << endl;
    cout << "最遠路徑 : " << MaxD << " 步" << endl;
}