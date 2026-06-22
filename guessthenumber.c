#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
int main()
{
    srand(time(NULL));
    int x, guess, difficulty, win = 0, loss = 0, mode, randommessage;
    float score, maxtries, count;
    time_t initialtime, finaltime;
    double timetaken;
    char name[50], choice[10], again[10];
    char *lowmessage[] = {
    "Too low. That guess has the same energy as a deflated balloon.",
    "Higher... unless you want to keep disappointing me.",
    "Nope. That number is so low it's basically underground.",
    "Raise your guess. It's not digging its own grave.",
    "Higher. This guess is so low it needs a ladder."
};
char *lossmessage[] = {
    "Out of tries! The number survives. You don't.",
    "Game over. The number watches you fail silently.",
    "No tries left. The number remains undefeated.",
    "Your attempts expired... like milk.",
    "Out of tries! The number is laughing from the shadows."
};
char *winmessage[] = {
    "Correct! Even a broken soul gets lucky sometimes.",
    "You got it! Miracles still happen, apparently.",
    "Correct. The universe must be glitching.", 
    "Congratulation... the number finally gave up hiding.",
    "You did it! I'll pretend I'm impressed."
};
char *highmessage[] = {
    "Too high. Calm down, astronaut.",
    "Lower... this isn't a NASA launch.",
    "Bro, that number is so high it needs oxygen.",
    "Lower. You overshot the target into the afterlife.",
    "Too high. Even ghosts can't reach that."
};
    enum difficulty {Easy, Medium, Hard, Blind, Luck, Chaos};
    printf(" \n Enter your name");
    scanf("%s", name);
    play:
    printf(" \n Generating number ########----------");
    printf("\n GUESS THE NUMBER \n Choose the difficulty mode \n Easy \n Medium  \n Hard \n Blind  \n Luck  \n Chaos ");
    scanf("%s", choice);
    if ( strcmp( choice, "Easy") == 0)
    {
        mode = Easy;
    }
    else if ( strcmp( choice, "Medium") == 0)
    {
        mode = Medium;
    }
    else if ( strcmp( choice, "Hard") == 0)
    {
        mode = Hard;
    }
    else if ( strcmp( choice, "Blind") == 0)
    {
        mode = Blind;
    }
    else if ( strcmp( choice, "Luck") == 0)
    {
        mode = Luck;
    }
    else if ( strcmp( choice, "Chaos") == 0)
    {
        mode = Chaos;
    }
    switch (mode)
    {
    case Easy:
    x = ( rand() % 20) + 1;
    count = 0;
    time(&initialtime);
    maxtries = 10;
    printf("\nGuess a number between 1 to 20\n You have %f tries", maxtries);
    scanf("%d", &guess);
    play1:
    if (guess>0 && guess < 21)
    {
        if ( guess > x )
        {
            randommessage = rand() % 5;
            printf("\n %s", highmessage[randommessage]);
            count ++;
            if (count == 10)
            {
                randommessage = rand() % 5;
                printf("\n %s", lossmessage[randommessage]);
                loss += 1;
                win = 0;
                printf(" \n You are on a %d losing streak",loss);
                goto again;
            }
            printf("\nYou have %f tries", maxtries - count  );
            scanf("%d", &guess);
            goto play1;
        }
        else if (guess < x)
        {
            randommessage = rand() % 5;
            printf("\n %s", lowmessage[randommessage]);
            count ++;
            if (count == 10)
            {
                randommessage = rand() % 5;
                printf("\n %s", lossmessage[randommessage]);
                    loss += 1;
                    win = 0;
                    printf("You are on a %d losing streak",loss);
                    goto again;
                }
                printf("\nYou have %f tries", maxtries - count );
                scanf("%d", &guess);
                goto play1;
            }
        if (guess == x)
        {
            time(&finaltime);
            timetaken = difftime(finaltime, initialtime);
            randommessage = rand() % 5;
            printf("%s", winmessage[randommessage]);
            printf("\n Your guess is correct on %f attempt", count + 1.00);
            printf("\n Time taken was %.2f", timetaken);
            win += 1;
            loss = 0 ;
            printf(" \n You are on a %d winning streak", win);
            goto again;
        }
    }
    else 
    {
        printf("\nPlease select between 1 to 20 ");
        goto play1;
    }
    break;
    case Medium:
    count = 0;
    time(&initialtime);
    x = ( rand() % 100 ) + 1;
    maxtries = 7;
    printf("\nGuess a number between 1 to 100 \n You have %f tries", maxtries - count);
    scanf("%d", &guess);
    play2:
    if (guess >0 && guess < 101)
    {
        if ( guess > x )
        {
            randommessage = rand() % 5;
            printf("\n %s", highmessage[randommessage]);
            count ++;
            if (count == 7)
            {
                randommessage = rand() % 5;
                printf("\n %s", lossmessage[randommessage]);
                loss += 1;
                win = 0;
                printf(" \n You are on a %d losing streak",loss);
                goto again;
            }
            printf("\nYou have %f tries \n",  maxtries - count  );
            scanf("%d", &guess);
            goto play2;
        }
        else if (guess < x)
        {
            randommessage = rand() % 5;
            printf("\n %s", lowmessage[randommessage]);
            count ++;
          
            if (count == 7)
            {
                randommessage = rand() % 5;
                printf("\n %s", lossmessage[randommessage]);
                loss += 1;
                win = 0;
                printf(" \n You are on a %d losing streak",loss);
                goto again;
            }
            printf("\nYou have %f tries", maxtries - count  );
            scanf("%d", &guess);
            goto play2;
        }
        if (guess == x)
        {
            time(&finaltime);
            timetaken = difftime(finaltime, initialtime);
            randommessage = rand() % 5;
            printf(" \n %s", winmessage[randommessage]);
            printf("\n Your guess is correct on %d attempt", count + 1.00 );
            printf("\n Time taken was %.2f", timetaken);
            win += 1;
            loss = 0;
            printf(" \n You are on a %d winning streak", win);
            goto again;
        }
    }
    else 
    {
        printf("\nPlease guess a number between 1 to 100");
        goto play2;
    }
    break;
    case Hard:
    count = 0;
    time(&initialtime);
    x = ( rand() % 1000 ) + 1;
    maxtries = 5;
    printf("\nGuess a number between 1 to 1000\n You have %d tries", maxtries - count);
    scanf("%d", &guess);
    play3:
    if( guess >0 && guess <1001)
    {
        if ( guess > x )
        {
            randommessage = rand() % 5;
            printf("\n %s", highmessage[randommessage]);
            count ++;
            if (count == 5)
            {
                randommessage = rand() % 5;
                printf("\n %s", lossmessage[randommessage]);
                loss += 1;
                win = 0;
                printf(" \n You are on a %d losing streak",loss);
                goto again;
            }
            printf("\nYou have %f tries ", maxtries - count  );
            scanf("%d", &guess);
            goto play3;
        }
        else if (guess < x)
        {
            randommessage = rand() % 5;
            printf("\n %s", lowmessage[randommessage]);
            count ++;
            if (count == 5)
            {
                randommessage = rand() % 5;
                printf("\n %s", lossmessage[randommessage]);
                loss += 1;
                win = 0;
                printf(" \n You are on a %d losing streak",loss);
                goto again;
            }
             printf("\nYou have %f tries ", maxtries - count  );
            scanf("%d", &guess);
            goto play3;
        }
        if (guess == x)
        {
            time(&finaltime);
            timetaken = difftime(finaltime, initialtime);
            randommessage = rand() % 5;
            printf("%s",winmessage[randommessage]);
            printf("\n Your guess is correct on %f attempt", count + 1.00 );
            printf("Time taken was %.2f", timetaken);
            win += 1;
            loss = 0;
            printf(" \n You are on a %d winning streak", win);
            goto again;
        }
    }
    else
    {
        printf("\nPlease guess a number between 1 to 1000");
        goto play3;
    }
    break;
    case Blind:
    count = 0;
    time(&initialtime);
    x = ( rand() % 100 ) + 1;
    maxtries = 7;
    printf("\nGuess a number between 1 to 100 \n You have %f tries", maxtries - count);
    scanf("%d", &guess);
    play4:
    if( guess >0 && guess <101)
    {
        if ( guess != x)
        {
            printf("\nIncorrect! But at least you pressed enter correctly!");
            count ++;
            if (count == 7)
            {
                randommessage = rand() % 5;
                printf("\n %s", lossmessage[randommessage]);                
                loss += 1;
                win = 0;
                printf(" \n You are on a %d losing streak",loss);
                goto again;
            }
            printf("\nYou have %f tries\n Try again", maxtries - count  );
            scanf("%d", &guess);
            goto play4;
        }
        else
        {
            time(&finaltime); 
            timetaken = difftime(finaltime, initialtime);          
            randommessage = rand() % 5;
            printf("%s", winmessage[randommessage]);
            printf("\n Your guess is correct on %d attempt", count + 1.00 );
            printf("\n Time taken was %.2f", timetaken);
            win += 1;
            loss = 0;
            printf(" \n You are on a %d winning streak", win);
            goto again;
        }
    }
    else
    {
        printf("\nPlease guess a number between 1 to 50");
        scanf("%d", &guess);
        goto play4;
    }
    break;
    case Luck:
    time(&initialtime);
    count = 0;
    x = ( rand() % 50 ) + 1;
    maxtries = 3;
    printf("\nGuess a number between 1 to 50\n You have %f tries", maxtries - count);
    scanf("%d", &guess);
    play5:
    if( guess > 0 && guess <51)
    {
        if ( guess > x )
        {
            randommessage = rand() % 5;
            printf("\n %s", highmessage[randommessage]);
            count ++;
            if (count == 3)
            {
                randommessage = rand() % 5;
                printf("\n %s", lossmessage[randommessage]);
                loss += 1;
                win = 0;
                printf(" \n You are on a %d losing streak",loss);
                goto again;
            }
             printf("\nYou have %f tries ", maxtries - count  );
            scanf("%d", &guess);
            goto play5;
        }
        else if (guess < x)
        {
            randommessage = rand() % 5;
            printf("\n %s", lowmessage[randommessage]);
            count ++;
            if (count == 3)
            {
                randommessage = rand() % 5;
                printf("\n %s", lossmessage[randommessage]);                
                loss += 1;
                win = 0;
                printf(" \n You are on a %d losing streak",loss);
                goto again;
            }
             printf("\nYou have %f tries ", maxtries - count  );
            scanf("%d", &guess);
            goto play5;
        }
        if (guess == x)
        {
            time(&finaltime);
            timetaken = difftime(finaltime, initialtime);
            randommessage = rand() % 5;
            printf(" \n %s", winmessage[randommessage]);
            printf("\n Your guess is correct on %f attempt", count + 1.00 );
            printf("\n Time taken was %.2f", timetaken);
            win += 1;
            loss = 0;
            printf("\nYou are on a %d winning streak", win);
            goto again;
        }
    }
    else
    {
        printf("\nPlease guess a number between 1 to 50");
        goto play5;
    }
    break;
    case Chaos:
    x = ( rand() % 500) + 1;
    count = 0;
    time(&initialtime);
    maxtries = 5;
    printf("\nGuess a number between 1 to 500\n You have %f tries", maxtries - count);
    scanf("%d", &guess);
    play6:
    if (guess>0 && guess < 501)
    {
        if ( guess > x )
        {
            randommessage = rand() % 5;
            printf("\n %s",highmessage[randommessage]);
            count ++;
            if (count == 5)
            {
                randommessage = rand() % 5;
                printf("\n %s", lossmessage[randommessage]);
                loss += 1;
                win = 0;
                printf("\nYou are on a %d losing streak",loss);
                goto again;
            }
            if ( x == 498)
            {
                x = 1;
            }
            else if ( x == 499)
            {
                x = 2;
            }
            else if ( x == 500)
            {
                x = 3;
            }
            else
            {
                x += 3;
            }
            printf("\nYou have %f tries", maxtries - count  );
            scanf("%d", &guess);
            goto play6;
        }
        else if (guess < x)
        {
            randommessage = rand() % 5;
            printf("\n %s", lowmessage[randommessage]);
            count ++;
            if (count == 6)
            {
                randommessage = rand() % 5;
                printf("\n %s", lossmessage[randommessage]);
                loss += 1;
                win = 0;
                printf("\nYou are on a %d losing streak",loss);
                goto again;
            }
             if ( x == 498)
            {
                x = 1;
            }
            else if ( x == 499)
            {
                x = 2;
            }
            else if ( x == 500)
            {
                x = 3;
            }
            else
            {
                x -= 3;
            }
            printf("\nYou have %f tries", maxtries - count  );
            scanf("%d", &guess);
            goto play6;
        }
        if (guess == x)
        {
            time(&finaltime);
            timetaken = difftime(finaltime, initialtime);
            randommessage = rand() % 5;
            printf("%s", winmessage[randommessage]);
            printf("\n Your guess is correct on %f attempt", count + 1.00 );
            printf("\n Time taken was %.2f", timetaken);
            win += 1;
            loss = 0 ;
            printf("\nYou are on a %d winning streak", win);
            goto again;
        }
    }
    else 
    {
        printf("\nPlease select between 1 to 500 ");
        goto play6;
    }
    break;
    default:
    printf("\nInvalid choice");
    goto play;
    }
    again:
    if ( mode == Easy)
    {
        score = ( 100 * 1 ) * (( maxtries - count +1 ) / maxtries);
        if ( count == 1)
        {
            score *= 2;
        }
        if ( timetaken <= 10)
        {
            score *= 1.3;
        }
        else if ( timetaken <= 20)
        {
            score *= 1.1;
        }
        else if ( timetaken > 20)
        {
            score *= 0.9;
        }
    }
    else if ( mode == Medium )
    {
        score = (100 * 1.5) * (( maxtries - count + 1) / maxtries);
        if ( count == 1)
        {
            score *= 2;
        }
        if ( timetaken <= 15)
        {
            score *= 1.3;
        }
        else if ( timetaken <= 30)
        {
            score *= 1.1;
        }
        else if ( timetaken > 30)
        {
            score *= 0.9;
        }
    
    }
    else  if( mode == Hard)
    {
        score = ( 100 * 2 ) * (( maxtries - count + 1) / maxtries);
        if ( count == 1 )
        {
            score *= 2;
        }
        if ( timetaken <= 25)
        {
            score *= 1.3;
        }
        else if ( timetaken <= 45)
        {
            score *= 1.1;
        }
        else if ( timetaken > 45)
        {
            score *= 0.9;
        }
    }
    else if( mode == Blind )
    {
        score = ( 100 * 2.5 ) * (( maxtries - count + 1) / maxtries);
        if ( count == 1 )
        {
            score *= 2;
        }
        if ( timetaken <= 30)
        {
            score *= 1.3;
        }
        else if ( timetaken <= 60)
        {
            score *= 1.1;
        }
        else if ( timetaken > 60)
        {
            score *= 0.9;
        }
    }
    else if( mode == Luck )
    {
        score = ( 100 * 3 ) * (( maxtries - count + 1) / maxtries);
        if ( count == 1)
        {
            score *= 2;
        }
        if ( timetaken <= 35)
        {
            score *= 1.3;
        }
        else if ( timetaken <= 70)
        {
            score *= 1.1;
        }
        else if ( timetaken > 70)
        {
            score *= 0.9;
        }
    }
    else if ( mode == Chaos)
    {
        score = (100 * 3.5 ) * (( maxtries - count + 1) / maxtries);
        if ( count == 1)
        {
            score *= 2;
        }
        if ( timetaken <= 40)
        {
            score *= 1.3;
        }
        else if ( timetaken <= 80)
        {
            score *= 1.1;
        }
        else if ( timetaken > 80)
        {
            score *= 0.9;
        }
    }
    score = score + ( win * 0.1);
    printf("\n Your score is %.2f \n Would you like to play again %s? \n Yes or No?", score, name);
    scanf("%s", again);
    if ( strcmp( again, "Yes") == 0)
    {
        goto play;
    }
    else if ( strcmp(again, "No") == 0)
    {
        printf("\n Thanks for Playing %s", name);
    }
    return 0;
}