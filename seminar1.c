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

int main(){
    p Player1 = {1,1};
    p Player2 = {1,1};

    return 0;

}

int PlayerInteraction(p Player1, p Player2){
    int hand;
    printf("What hand do you want to attack? (1: right, 2: left)");
    scanf("%i", hand);
    HandValidation(Player2, hand);

    printf("With what hand do you want to attack? (1: right, 2: left)");
    scanf("%i", hand);
    HandValidation(Player1, hand);
}

bool HandValidation(p Player,int hand){
    while(hand == 1){
        while(Player.right == 5){
            printf("Invalid Move");
            scanf("%i", hand);
        }
    }
    while(hand == 2){
        while(Player.left == 5){
            printf("Invalid Move");
            scanf("%i", hand);
        }
    }
    hand = 0;
    return true;
}

bool CheckLostGame(p Player){
    if(Player.left == 5 && Player.right == 5){
        return true;
    }
    return false;
}

void GameLoop(p Player1, p Player2, int hand){
    for(int i = 0; i<=20; i++){
        if(i>=4){
            if(CheckLostGame(Player1)){
                printf("Player 2 won!");
            }
            else if(CheckLostGame(Player2)){
                printf("Player 1 won!");
            }
        }
        if(i%2==0){
            PlayerInteraction(Player1,Player2);
        }
        else{
            PlayerInteraction(Player2,Player1);
        }
    }
}