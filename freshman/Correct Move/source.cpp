#include<iostream>
#include<string>

using namespace std;

bool is_verticle(int Qx,int qx,int Qy,int qy){
    if((Qx==qx&&Qy!=qy)||(Qx!=qx&&Qy==qy)){
        return true;
    }
    else return false;
}

bool is_path_block(int Qx,int qx,int Qy,int qy,int Kx,int Ky){
    if(Kx == Qx){
        if((Ky<Qy&&Ky>qy)||(Ky<qy&&Ky>Qy)){
            return true;
        }
    }else if(Ky == Qy){
        if((Kx<Qx&&Kx>qx)||(Kx<qx&&Kx>Qx)){
            return true;
        }
    }
    return false;
}

bool is_king_move_pattern(int kr, int kc, int tr, int tc) {
    int dr = abs(kr - tr);
    int dc = abs(kc - tc);
    return (dr == 1 && dc == 0) || (dr == 0 && dc == 1);
}

bool is_queen_move_pattern(int Qr, int Qc, int qr, int qc) {
    bool is_horizontal_move = (Qr == qr && Qc != qc);
    bool is_vertical_move = (Qc == qc && Qr != qr);
    return is_horizontal_move || is_vertical_move;
}

int main(){
    int a,b,c; // a is king , b is queen 
    while(cin>>a>>b>>c){
        if(a==b){ // condition one
            cout<<"Illegal state"<<endl;
            continue;
        }
        int Qc = b % 8,Qr = b / 8, qc = c % 8,qr = c / 8;
        int kc = a % 8,kr = a / 8;
        if(!is_verticle(Qc,qc,Qr,qr)){ // condition two
            cout<<"Illegal move"<<endl;
            continue;
        }else if(qc == kc&&qr == kr){
            cout<<"Illegal move"<<endl;
            continue;
        }else if(is_path_block(Qc,qc,Qr,qr,kc,kr)){
            cout<<"Illegal move"<<endl;
            continue;
        }
        if (is_king_move_pattern(kr, kc, qr, qc)) {
            cout << "Move not allowed" << endl;
            continue;
        }
        
        bool king_has_an_allowed_move = false;
        int king_move_directions[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}}; // 右, 左, 下, 上

        for (int i = 0; i < 4; ++i) {
            int k_next_r = kr + king_move_directions[i][0];
            int k_next_c = kc + king_move_directions[i][1];

            bool is_king_target_on_board = (k_next_r >= 0 && k_next_r < 8 && k_next_c >= 0 && k_next_c < 8);
            if (!is_king_target_on_board) {
                continue; 
            }
            if (k_next_r == qr && k_next_c == qc) {
                continue; 
            }
            bool queen_can_also_reach_k_next = false; 
            if (is_verticle(qc, k_next_c, qr, k_next_r)) { 
                if (!(k_next_r == kr && k_next_c == kc)) {
                    if (!is_path_block(qc, k_next_c, qr, k_next_r, kc, kr)) { 
                        queen_can_also_reach_k_next = true; 
                    }
                }
            }
            if (!queen_can_also_reach_k_next) {
                king_has_an_allowed_move = true; 
                break;                           
            }
        }
        if (king_has_an_allowed_move) {
            cout << "Continue" << endl;
            continue;
        } else {
            cout << "Stop" << endl;
            continue;
        }
    } 
}