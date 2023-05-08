// #include <stdio.h>
// int main(void){
//     int digit_seen[10] = {0};
//     int digit;
//     unsigned int i;
//     scanf("%u",&i);
//     while(i > 0){
//         digit = i % 10;
//         i = i / 10;
//         digit_seen[digit] += 1;
//     }
//     for(i = 0; i < 10; i++){
//         if(digit_seen[i] > 1){
//             printf("(%d, %d)\n",i, digit_seen[i]);
//         }
//     }
//     return 0;
// }

// #include <stdio.h>
// #define NUM_RATES (int)sizeof(value) / sizeof(value[0])
// #define INITIAL_BALANCE 100.00

// int main(void){
//     int rate;
//     int year;
//     double value[5];
//     scanf("%d", &rate);
//     scanf("%d", &year);
//     printf("\nYears");
//     for(int i = 0; i < NUM_RATES; i++){
//         printf("%7d%%", rate + i);
//         value[i] = INITIAL_BALANCE;
//     }
//     printf("\n");
//     for(int i = 0; i < year; i++){
//         printf("%3d  ", i);
//         for (int i = 0; i < NUM_RATES; i++)
//         {
//             value[i] = value[i] + value[i] * (rate + i) / 100;
//             printf("%8.2f", value[i]);
//         }
//         printf("\n");
//     }
//     return 0;
// }

// #include <stdio.h>
// #include <stdbool.h>
// bool is_prime(int n);

// int main(void){
//     int n;
//     scanf("%d", &n);
//     if (is_prime(n)){
//         printf("%d is a prime number.\n", n);
//     }
//     else{
//         printf("%d is not a prime number.\n", n);
//     }
//     return 0;
    
// }

// bool is_prime(int n){
//     if (n <= 1){
//         return false;
//     }
//     else if (n == 2){
//         return true;
//     }
//     else if (n % 2 == 0){
//         return false;
//     }
//     else{
//         for (int i = 3; i * i <= n; i = i + 2){
//             if (n % i == 0){
//                 return false;
//             }
//         }
//         return true;
//     }
// }

// #include<stdio.h>

// int fact(int n);

// int main(void){
//     // int arr[] = {1, 2,3, 4, 5};
//     // int size = sizeof(arr) / sizeof(arr[0]);
//     // printf("%d\n", sum_arrat(arr, size));
//     // return 0;
//     int i;
//     i = fact(3);
//     printf("%d\n", i);

// }

// int fact(int n){
//     if (n <= 1)
//     {
//         return 1;
//     }
//     else
//         return n * fact(n -1);
// }



// #include <stdio.h>
// void sum_array(int arr[], int len);

// int main(void){
//     int arr[] = {2, 4, 1, 5};
//     int len = sizeof(arr)/sizeof(arr[0]);

//     sum_array(arr, len);
//     return 0;
// }


// void sum_array(int arr[], int len){
//     int sum = 0;
//     // len = sizeof(arr) / sizeof(arr[0]);
//     for (int i = 0; i < len; i++)
//     {
//         sum += arr[i];
//     }
//     printf("%d\n%d", sum, len);
// }

// #include <stdio.h>
// #include<stdlib.h>
// #include<time.h>

// #define MAX 100

// int generate_random_number();
// void guess_number(int random_number);

// int main(void){
//     int random_number = generate_random_number();
//     guess_number(random_number);

// }

// int generate_random_number(){
//     srand((unsigned)time(NULL));
//     int random_number = rand() % MAX + 1;
//     return random_number;
// }

// void guess_number(int random_number){
//     int guess, count = 0;
//     for(;;){
//         scanf("%d", &guess);
//         count++;
//         if(guess == random_number){
//             printf("You won in %d guesses.\n", count);
//             break;
//         }
//         else if(guess < random_number){
//             printf("Too samll\n");
//         }
//         else if(guess > random_number){
//             printf("Too big\n");
//         }
//     }
// }

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



