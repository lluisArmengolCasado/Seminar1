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
// Function prototypes
void PlayerInteraction(p *Player1, p *Player2, m *move);
bool CheckLostGame(p *Player, int i);
void PerformAddition(p *Player1, p *Player2, m *move);
void GameLoop(p *Player1, p *Player2, m *move);
bool AttackedHandValidation(p *Player, m *move);
bool AttackingHandValidation(p *Player, m *move);


void PlayerInteraction(p *Player1, p *Player2, m *move){
    printf("Your current situation: \n");
    printf("       Your hands: Right - %i and Left - %i \n" , (*Player1).right, (*Player1).left);
    
    printf("His current situation: \n");
    printf("       His/Her/Their hands: Right - %i and Left - %i \n" , (*Player2).right, (*Player2).left);


    printf("With what hand do you want to attack? (1: right, 2: left) \n");
    scanf("%i", &(*move).attackingHand);
    AttackingHandValidation(&(*Player1), &(*move)); 
 
    printf("What hand do you want to attack? (1: right, 2: left) \n");
    scanf("%i", &(*move).attackedHand);
    AttackedHandValidation(&(*Player2), &(*move));
    
}

bool AttackedHandValidation(p *Player, m *move) {
    while ((*move).attackedHand == 1 && (*Player).right == 5) {
        printf("Invalid Move: His/Her/Their Right hand is not playable. Choose another hand.\n");
        scanf("%i", &(*move).attackedHand);
    } 
    while ((*move).attackedHand == 2 && (*Player).left == 5) {
        printf("Invalid Move: His/Her/Their Left hand is not playable. Choose another hand.\n");
        scanf("%i", &(*move).attackedHand);
    }
}

bool AttackingHandValidation(p *Player, m *move) {
    while ((*move).attackingHand == 1 && (*Player).right == 5) {
        printf("Invalid Move: Your Right hand is not playable. Choose another hand.\n");
        scanf("%i", &(*move).attackingHand);
    } 
    while((*move).attackingHand == 2 && (*Player).left == 5) {
        printf("Invalid Move: Your Left hand is not playable. Choose another hand.\n");
        scanf("%i", &(*move).attackingHand);
    return true;
    }
}
    


bool CheckLostGame(p *Player, int i){
    if((*Player).left == 5 && (*Player).right == 5){
            return true;
        }
    return false;
}

void PerformAddition(p *Player1, p *Player2, m *move){
    if((*move).attackingHand == 1){
                if((*move).attackedHand == 1){
                    (*Player2).right = (*Player1).right + (*Player2).right;
                }
                else if((*move).attackedHand == 2){
                    (*Player2).left = (*Player1).right + (*Player2).left;
                }
            }
            else if((*move).attackingHand == 2){
                if((*move).attackedHand == 1){
                    (*Player2).right = (*Player1).left + (*Player2).right;
                }
                else if((*move).attackedHand == 2){
                    (*Player2).left = (*Player1).left + (*Player2).left;
                }
            }
            
            if((*Player2).right>5){
                (*Player2).right -= 5;
            }
            else if((*Player2).left>5){
                (*Player2).left -= 5;
            }
}

void GameLoop(p *Player1, p *Player2, m *move){
    for(int i = 0; i<=20; i++){
        if(i%2==0){
            printf("PLAYER 1 TURN \n ===================== \n");
            PlayerInteraction(&(*Player1), &(*Player2), &(*move));
            PerformAddition(&(*Player1), &(*Player2), &(*move));
            if(CheckLostGame(&(*Player2), i) == true){
                printf("Player 1 won!");
                break;
            }
        }
        else{
            printf("PLAYER 2 TURN \n ===================== \n");
            PlayerInteraction(&(*Player2), &(*Player1), &(*move));
            PerformAddition(&(*Player2), &(*Player1), &(*move));
            if(CheckLostGame(&(*Player1),i) == true){
                printf("Player 2 won!");
                break;
            }
        }
       (*move).attackedHand = 0;
       (*move).attackingHand = 0;
    }
}

int main(){
    p Player1 = {1,1};
    p Player2 = {1,1};
    m move;
    GameLoop(&Player1, &Player2, &move);
    return 0;

}