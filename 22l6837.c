#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <pthread.h> 

#define bsize 3
#define dash '-'

char board[bsize][bsize];
bool game_over = 0;
bool player_turn = 1;
int turn;
bool flag[2] = { 0 };

void initialize_board() {
    for (int i = 0; i < bsize; ++i) {
        for (int j = 0; j < bsize; ++j) {
            board[i][j] = dash;
        }
    }
}

void print_board() {
    printf("   0 1 2\n");
    for (int i = 0; i < bsize; ++i) {
        printf("%d ", i);
        for (int j = 0; j < bsize; ++j) {
            printf(" %c", board[i][j]);
        }
        printf("\n");
    }
}

bool Win(char player) {
    // Check rows and columns
    for (int i = 0; i < bsize; ++i) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player) || 
            (board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
            (board[0][2] == player && board[1][1] == player && board[2][0] == player)) 
        {
            return 1;
        }
    }
    
    return 0;
}

bool Draw() {
    for (int i = 0; i < bsize; ++i) {
        for (int j = 0; j < bsize; ++j) {
            if (board[i][j] == dash) {
                return 0;
            }
        }
    }
    return 1;
}

bool is_valid_move(int row, int col) {
    if (row >= 0 && col >= 0 && row < bsize &&  col < bsize && board[row][col] == dash) {
    return 1;
    }
    return 0;
    
}

void player_move() {
    printf("Player's turn\n");
    print_board();
    int row, col;
    do {
        printf("Enter row and column (e.g., 0 1): ");
        scanf("%d %d", &row, &col);
    } while (!is_valid_move(row, col));
    board[row][col] = 'X';
    if (Win('X')) {
        printf("Congratulations! You win!\n");
        game_over = 1;
    }
    else if (Draw()) {
        printf("It's a draw!\n");
        game_over = 1;
    }
}

void comp_move() {
    if (Win('X'))
    {
        return;
    }
    printf("Computer's turn\n");
    int row, col;
    do {
        row = rand() % bsize;
        col = rand() % bsize;
    } while (!is_valid_move(row, col));
    board[row][col] = 'O';
    if (Win('O')) {
        printf("Computer wins!\n");
        game_over = 1;
    }
    else if (Draw()) {
        printf("It's a draw!\n");
        game_over = 1;
    }
}

void* playerThread(void* arg) {
    while (!game_over) {
        if (player_turn) {
            while (flag[1] && turn == 1);
            flag[0] = 1;
            turn = 1;
            flag[0] = 0;

            player_move();

            flag[0] = 1;
            turn = 1;
            flag[0] = 0;
            player_turn = 0;
        }
    }
    return NULL;
}

void* computerThread(void* arg) {
    while (!game_over) {
        if (!player_turn) {
            while (flag[0] && turn == 0);
            flag[1] = 1;
            turn = 0;
            flag[1] = 0;

            comp_move();

            flag[1] = 1;
            turn = 0;
            flag[1] = 0;
            player_turn = 1;
        }
    }
    return NULL;
}


int main() {
    initialize_board();
    pthread_t player_tid, computer_tid;
    pthread_create(&player_tid, NULL, playerThread, NULL);
    pthread_create(&computer_tid, NULL, computerThread, NULL);
    pthread_join(player_tid, NULL);
    pthread_join(computer_tid, NULL);
    return 0;
}