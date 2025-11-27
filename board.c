#include "board.h"

const char *player_string(enum chess_player player)
{
    switch (player)
    {
    case PLAYER_WHITE:
        return "white";
    case PLAYER_BLACK:
        return "black";
    }
}

const char *piece_string(enum chess_piece piece)
{
    switch (piece)
    {
    case PIECE_PAWN:
        return "pawn";
    case PIECE_KNIGHT:
        return "knight";
    case PIECE_BISHOP:
        return "bishop";
    case PIECE_ROOK:
        return "rook";
    case PIECE_QUEEN:
        return "queen";
    case PIECE_KING:
        return "king";
    }
}

void board_initialize(struct chess_board *board)
{
    board->next_move_player = PLAYER_WHITE;
    board->board_state = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR";
    board->enpassant = "-";
    board->castling = "KQkq";
}

void board_complete_move(const struct chess_board *board, struct chess_move *move)
{
    // TODO: complete the move.
}

void board_apply_move(struct chess_board *board, const struct chess_move *move)
{
    // TODO: apply a completed move to the board.

    // The final step is to update the the turn of players in the board state.
    switch (board->next_move_player)
    {
    case PLAYER_WHITE:
        board->next_move_player = PLAYER_BLACK;
        break;
    case PLAYER_BLACK:
        board->next_move_player = PLAYER_WHITE;
        break;
    }
}

void board_summarize(const struct chess_board *board)
{
    int character = 0;
    for (size_t i = 0; i < strlen(board->board_state); i++) {
        if (board->board_state[i] >= '0' && board->board_state[i] <= '9') {
            for (int j = 0; j < board->board_state[i] - 48; j++) {
                if (character%2 == 0) {
                    printf("[ ]"); //□
                } else {
                    printf("[ ]"); //■
                }
                character += 1;
            }
        }else {
            if (board->board_state[i] == '/') {
                printf("\n");
                character += 1;
            } else {
                printf("[%c]", board->board_state[i]);
            }
        }
    }
}
