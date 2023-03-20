#include <stdio.h>

int main()
{
//Verbs
char verb1[15];
printf("Enter a verb:  ");
scanf("%s", &verb1);

char verb2[15];
printf("Enter a verb:  ");
scanf("%s", &verb2);

//Adjectives
char adjective1[15];
printf("Enter an adjective:  ");
scanf("%s", &adjective1);

char adjective2[15];
printf("Enter an adjective:  ");
scanf("%s", &adjective2);

//Numbers
int number1;
printf("Enter a number:  ");
scanf("%d", &number1);

int number2;
printf("Enter a number:  ");
scanf("%d", &number2);

//Name
char nameA[30];
char nameB[30];
printf("Enter a name:  ");
scanf("%s %s", nameA, nameB);

//Adverbs
char adverb1[15];
printf("Enter an adverb:  ");
scanf("%s", &adverb1);

char adverb2[15];
printf("Enter an adverb:  ");
scanf("%s", &adverb2);

//Nouns
char noun1[10];
printf("Enter a noun:  ");
scanf("%s", &noun1);

char noun2[10];
printf("Enter a noun:  ");
scanf("%s", &noun2);



printf("Hi, welcome to Toronto!. I'm %s %s, your mayor of Toronto. I'm delighted to tour you around this %s city! Our previous mayor did %s things, but we look forward into the future. My favorite place in the city is %s. I go there everyday, the people there %s me. The TTC here is %s, but the people %s to it. Over to your right, we have Queen's Park, where all the %d %s politicians who %s, and conduct", nameA, nameB, adjective1, adjective2, noun1, adjective1, verb1, adjective2, adverb1, adjective2, number2, verb1, adverb2);

return 0;
}
