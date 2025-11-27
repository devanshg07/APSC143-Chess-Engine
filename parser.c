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
        case = 'a':{
            if((*move).piece != Pawn){
                (*move).x0 = c - 'a';
                c= getc(stdin);
                break;
            }
        }
        case = 'b':{
            if((*move).piece != Pawn){
                (*move).x0 = c - 'a';
                c= getc(stdin);
                break;
            }
        }
        case = 'c':{
            if((*move).piece != Pawn){
                (*move).x0 = c - 'a';
                c= getc(stdin);
                break;
            }
        }
        case = 'd':{
            if((*move).piece != Pawn){
                (*move).x0 = c - 'a';
                c= getc(stdin);
                break;
            }
        }
        case = 'e':{
            if((*move).piece != Pawn){
                (*move).x0 = c - 'a';
                c= getc(stdin);
                break;
            }
        }
        case = 'f':{
            if((*move).piece != Pawn){
                (*move).x0 = c - 'a';
                c= getc(stdin);
                break;
            }
        }
        case = 'g':{
            if((*move).piece != Pawn){
                (*move).x0 = c - 'a';
                c= getc(stdin);
                break;
            }
        }
        case = 'h':{
            if((*move).piece != Pawn){
                (*move).x0 = c - 'a';
                c= getc(stdin);
                break;
            }
        }
        case = 'x':{
            (*move).capture = true;
            c = getc(stdin);
            break;

        default:
            break;
        }
    }
    if(!(c == 'a' || c == 'b' || c == 'c' || c == 'd' || c == 'e' || c == 'f' || c == 'g' || c == 'h')){
         panicf("parse error at character '%c'", c);
    }
    (*move).x1 = c -'a';

    c = getc(stdin);
    if(!(c == '1' || c == '2' || c == '3' || c == '4' || c == '5' || c == '6' || c == '7' || c == '8')){
        panicf("parse error at character '%c'", c);
    }
    (*move).y1 = c - '1';

    c = getc(stdin);
    if(c == '='){
        c = getc(stdin);
        switch(c){
            case 'Q':{
            (*move).promotion = Queen;
            break;
            }
        case 'R':{
            (*move).promotion = Rook;
            break;
            }
        case 'B':{
            (*move).promotion = Bishop;
            break;
            }
        case 'N':{
            (*move).promotion = Knight;
            break;
            }
        default:
            panicf("parse error at character '%c'", c);
            break;
    }
    } else if(c != ' ' && c != '\n' && c != '\r'){
        ungetc(c,stdin);
    }
    return true;
}

