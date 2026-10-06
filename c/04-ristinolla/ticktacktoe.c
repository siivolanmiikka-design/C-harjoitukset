#include <stdio.h>
#include <stdint.h>

int8_t tictactoe_check(int8_t * gameboard, int win_len);

int8_t tictactoe_check(int8_t * gameboard, int win_len) {
    int x_wins = 0;
    int o_wins = 0;
    int size = 10;
    
    //Directions on the gameboard: Horizontal step, vertical step, diagonal (right), diagonal (left)
    int dr[4] = {0, 1, 1, 1}; // r stands for rows
    int dc[4] = {1, 0, 1, -1}; // c stands for columns

    for(int r = 0; r < size; r++) {
        for(int c = 0; c < size; c++) {
            int player = gameboard[r * size + c];
            if (player == 0) {
                continue;
            }

            for (int d = 0; d < 4; d++) {
                int streak = 1;
                int nr = r + dr[d];
                int nc = c + dc[d];

                while (nr >= 0 && nr < size && nc >= 0 && nc < size 
                    && gameboard[nr * size + nc] == player) {
                        streak++;
                        nr += dr[d];
                        nc += dc[d];
                    }
                if (streak >= win_len) {
                    if (player == 1) x_wins = 1;
                    else if (player == 2) o_wins = 1;
                }
            }
        }
    }

    if (x_wins && o_wins) {
        return 0;
    }
    else if (x_wins)
    {
        return 1;
    }
    else if (o_wins)
    {
        return 2;
    } 
    else return 0;
}