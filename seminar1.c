#include <stdio.h>
#include <string.h>
#include <stdbool.h>
/*
4. Alice and Bob are playing an arithmetical game which works as follows:
    1.  The game starts with exactly one finger UP in each hand (left and right for Alice and Bob).
    2.  In every turn, the main player adds the fingers of its left or right hand, to the fingers of the right or
        left hand of the adversary. If the resulting operation is higher than five fingers, subtract 5.
    3.  The adversary loses one hand (i.e., that hand does not play anymore), if it has 5 fingers UP in any
        given moment.
    4.  The players alternate their roles at the end of the turn.
    5.  The game terminates when a player loses both hands. The winner is the player with at least one
        playable hand wins.
    Given T turns with Alice and Bob plays, decide whether Alice wins, Bob wins, or None if
    the game has not finished yet. The program should contain and do the following:
        (a) Create a data structure Player, with the player name, and two integers left and right to denote
            the number of UP fingers. Also, create two instances of Player, one for Alice and one for Bob.
        (b) Read the input, and update the corresponding Player instance in each turn.
        (c) At the end of the input, print the winner (i.e., "Alice wins" or "Bob wins"), or "None" if the game
            has not finished yet.
    Constraints
    • T ∈ [4, 20]
    • The plays are always valid, and hands with 5 fingers UP are not playable.
*/
typedef struct{
    int left;
    int right;
} p;

typedef struct{
    int attackedHand;
    int attackingHand;
} m;

int main(){
    p Player1 = {1,1};
    p Player2 = {1,1};
    m move;
    return 0;
    GameLoop(Player1, Player2, move);
}

int PlayerInteraction(p Player1, p Player2, m move){
    printf("What hand do you want to attack? (1: right, 2: left)");
    scanf("%i", move.attackedHand);
    HandValidation(Player2, move);

    printf("With what hand do you want to attack? (1: right, 2: left)");
    scanf("%i", move.attackingHand);
    HandValidation(Player1, move);

}

bool HandValidation(p Player, m move){
    if(move.attackedHand == 1){
        while(Player.right == 5){
            printf("Invalid Move");
            scanf("%i", move.attackedHand);
        }
    }
    while(move.attackingHand == 2){
        while(Player.left == 5){
            printf("Invalid Move");
            scanf("%i", move.attackingHand);
        }
    }
    return true;
}

bool CheckLostGame(p Player, int i){
    if(i>=4){
        if(Player.left == 5 && Player.right == 5){
            return true;
        }
    }
    return false;
}

void PerformAddition(p Player1, p Player2, m move){
    if(move.attackingHand == 1){
                if(move.attackedHand == 1){
                    Player2.right = Player1.right + Player2.right;
                }
                else if(move.attackedHand == 2){
                    Player2.left = Player1.right + Player2.left;
                }
            }
            else if(move.attackingHand == 2){
                if(move.attackedHand == 1){
                    Player2.right = Player1.left + Player2.right;
                }
                else if(move.attackedHand == 2){
                    Player2.left = Player1.left + Player2.left;
                }
            }
            
            if(Player2.right>5){
                Player2.right -= 5;
            }
            else if(Player1.left>5){
                Player2.left -= 5;
            }
}

void GameLoop(p Player1, p Player2, m move){
    for(int i = 0; i<=20; i++){
        if(i%2==0){
            PlayerInteraction(Player1,Player2, move);
            PerformAddition(Player1, Player2, move);
            if(CheckLostGame(Player2, i)){
                printf("Player 1 won!");
            }
        }
        else{
            PlayerInteraction(Player2,Player1, move);
            PerformAddition(Player2,Player1, move);
            if(CheckLostGame(Player1,i)){
                printf("Player 2 won!");
            }
        }
        move = {0,0};
    }
}