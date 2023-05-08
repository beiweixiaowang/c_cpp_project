#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>



#define RANK 13
#define SUIT 4
#define CARD 5

typedef struct CardType{
    bool flush;
    bool straight;
    bool four;
    bool three;
    int pair;

    bool cardInHand[SUIT][RANK];
    int numRank[RANK];
    int numSuit[SUIT];
}CardType;

void initCardType(CardType *card);
void readCard(CardType *card);
void analyseCard(CardType *card);
void printResult(CardType * card);

int main(void){
    CardType card;
	for (; ;) {
		initCardType(&card);
		readCard(&card);
		analyseCard(&card);
		printResult(&card);
	}

	return 0;

}

void initCardType(CardType* card) {

	card->flush = false;
	card->straight = false;
	card->four = false;
	card->three = false;
	card->pair = 0;

	int i, j;

	for (i = 0; i < SUIT; i++) {
		card->numSuit[i] = 0;
		for (j = 0; j < RANK; j++) {
			card->cardInHand[i][j] = false;
		}
	}

	for (i = 0; i < RANK; i++) {
		card->numRank[i] = 0;
	}

}


void readCard(CardType *card){
    int card_read = CARD, rank, suit;
    bool bad_card;
    char ch;
    while(card_read){
        bad_card = false;
        printf("Enter a card:");
        ch = getchar();
        switch(ch){
            case'0': exit(0);break;
            case'2': rank = 0;break;
            case'3': rank = 1;break;
            case'4': rank = 2;break;
            case'5': rank = 3;break;
            case'6': rank = 4;break;
            case'7': rank = 5;break;
            case'8': rank = 6;break;
            case'9': rank = 7;break;
            case't':case 'T': rank = 8;break;
            case'j':case 'J': rank = 9;break;
            case'q':case 'Q': rank = 10;break;
            case'a':case 'A': rank = 12;break;
            default:bad_card = true;break;

        }

        ch = getchar();
        switch(ch){
            case 'c': case 'C': suit = 0; break;
			case 'd': case 'D': suit = 1; break;
			case 'h': case 'H': suit = 2; break;
			case 's': case 'S': suit = 3; break;
			default: bad_card = true; break;
        }

        while((ch = getchar()) != '\n'){
            if(ch != ' '){
                bad_card = true;
            }
        }

        if (bad_card){
            printf("Bad card; ignored.\n");
        }
        else if(card->cardInHand[suit][rank]){
            printf("Duplicated card; ignored.\n");
        }
        else{
            ++card->numRank[rank];
            ++card->numSuit[suit];
            card->cardInHand[suit][rank] = true;
            card_read--;
        }
    }
}

void analyseCard(CardType *card){
    int count;
    for (int i = 0; i < SUIT; i++)
    {
        if(card->numSuit[i] == 5){
            card->flush = true;
        }
    }
    int i = 0;
    while (card->numRank[i] == 0)
    {
         i++;
    }

    if(count = CARD){
        card->straight = true;
        return;
    }
    for (i = 0; i < RANK; i++){
        if(card->numRank[i] == 4){
            card->four = true;
        }
        if(card -> numRank[i] == 3){
            card->three = true;
        }
        if(card->numRank[i] == 2){
            ++card->pair;
        }
    }
}

void printResult(CardType* card) {

	if (card->flush && card->straight)
		printf("Stright flush\n");
	else if (card->four)
		printf("Four of a kind\n");
	else if (card->three && card->pair == 1)
		printf("Full house\n");
	else if (card->flush)
		printf("flush\n");
	else if (card->straight)
		printf("straight\n");
	else if (card->three)
		printf("Three of a kind\n");
	else if (card->pair == 2)
		printf("Two pairs\n");
	else if (card->pair == 1)
		printf("pair\n");
	else
		printf("High card\n");
	
	printf("\n\n");
}