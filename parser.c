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
        case 'O':{
            if(getc(stdin) != '-' || getc(stdin) != 'O'){
                panicf("parse error at character '%c'\n", c);
            }
            c = getc(stdin);
            if(c == '-'){
                if(getc(stdin) != 'O'){
                    (*move).castleQueens = true;
                } 
            } else {
                unget(c,stdin);
                (*move).castleKing = true;
            }
            (*move).piece = King;
            return true;
        }
        case 'K':{
            (*move).piece = King;
            break;
        }
        case 'Q':{
            (*move).piece = Queen;
            break;
        }
        case 'R':{
            (*move).piece = Rook;
            break;
        }
        case 'B':{
            (*move).piece = Bishop;
            break;
        }
        case 'N':{
            (*move).piece = Knight;
            break;
        }
    }
    default:
        if(c == 'a' || c == 'b' || c == 'c' || c == 'd' || c == 'e' || c == 'f' || c == 'g' || c == 'h'){
        (*move).piece = Pawn;
        (*move).x0 = c - 'a';
        } else{
            panicf("parse error at character '%c'", c);
        }
    c = getc(stdin);
    switch(c){
        case '1':{
            (*move).y0 = c - '1';
            c = getc(stdin);
            break;
        }
        case '2':{
            (*move).y0 = c - '1';
            c = getc(stdin);
            break;
        }
        case '3':{
            (*move).y0 = c - '1';
            c = getc(stdin);
            break;
        }
        case '4':{
            (*move).y0 = c - '1';
            c = getc(stdin);
            break;
        }
        case '5':{
            (*move).y0 = c - '1';
            c = getc(stdin);
            break;
        }
        case '6':{
            (*move).y0 = c - '1';
            c = getc(stdin);
            break;
        }
        case '7':{
            (*move).y0 = c - '1';
            c = getc(stdin);
            break;
        }
        case '8':{
            (*move).y0 = c - '1';
            c = getc(stdin);
            break;
        }
    }
    }

