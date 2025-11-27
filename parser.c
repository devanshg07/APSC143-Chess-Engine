#include "parser.h"
#include <stdio.h>
#include <ctype.h>
#include "panic.h"

bool parse_move(struct chess_move *move)
{
    char c;
    do
    {
        c = getc(stdin);
    } while (c == ' ');

    // Check if we are at the end of input.
    if (c == '\n' || c == '\r')
        return false;
    
    //switch for the first character
    switch (c)
    {
        case 'O':
            if(getc(stdin) != '-' || getc(stdin) != 'O'){
                panicf("parse error at character '%c'\n", c);
            }
            c = getc(stdin);
            if(c == '-'){
                if(getc(stdin) != '0'){
                    (*move).castleQueens = true;
                } 
            } else {
                unget(c,stdin);
                (*move).castleKing = true;
            }
            (*move).piece = King;
            return true;
    }
    default:
        panicf("parse error at character '%c'\n", c);
    }
}
