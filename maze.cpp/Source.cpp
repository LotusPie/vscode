#include<iostream>
#include<Windows.h>

int maze[7][7] = {
        {1, 1, 1, 1, 1, 1, 1},
        {1, 0, 0, 0, 1, 0, 1},
        {1, 0, 1, 1, 1, 0, 1},
        {1, 0, 0, 0, 1, 0, 1},
        {1, 1, 1, 0, 1, 0, 1},
        {1, 0, 0, 0, 0, 0, 1},
        {1, 1, 1, 1, 1, 1, 1} };

void print_maze() {
    system("cls");
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 7; j++) {
            if (maze[i][j] == 1)
                printf("/");
            else if (maze[i][j] == 2)
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }
    Sleep(500);
}

bool visited[7][7] = { 0 }; // �������S�����L
bool goal = false; // �O�_������I�F
int start_x = 1, start_y = 1; // �_�I
int goal_x = 1, goal_y = 5; // ���I

void func(int x, int y) {
    visited[x][y] = true;
    maze[x][y] = 2;
    print_maze();
    if (x == goal_x && y == goal_y) { // �]�i�H�b�o�̥[ goal == true || ���P�_��
        goal = true;
        return;
    }

    if (maze[x][y + 1] != 1 && visited[x][y + 1] == false && !goal) { /* �k�䪺�y�� */
        func(x, y + 1);
    }
    if (maze[x][y - 1] != 1 && visited[x][y - 1] == false && !goal) { /* ���䪺�y�� */
        func(x, y - 1);
    }
    if (maze[x + 1][y] != 1 && visited[x + 1][y] == false && !goal) { /* �U�����y�� */
        func(x + 1, y);
    }
    if (maze[x - 1][y] != 1 && visited[x - 1][y] == false && !goal) { /* �W�����y�� */
        func(x - 1, y);
    }
    visited[x][y] = false;
    maze[x][y] = 0;
    print_maze();
}

using namespace std;

int main() {
    print_maze();
    func(start_x, start_y);
}