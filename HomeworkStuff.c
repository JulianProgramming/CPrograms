#include <stdio.h>
#include <stdlib.h>


/*
The string struct, getLine method, and append_string method are all related.
string struct -> s will hold characters read in from standard input. getLine
method will be called to read in characters from standard input. append_String
method will be used to append these characters to struct string -> s.

*/
typedef struct string {
    char *s;
    long len, cap;
} String;


String *append_string(String *s, char c) {
    if (s->cap == s->len) {
        s->cap <<= 1;
        s->s = (char *) realloc(s->s, s->cap);
    }
    s->s[s->len++] = c;
    s->s[s->len] = 0;
    return s;
}

char *getLine(String *s) {
    s->len = 0;
    char c;
    while (1) {
        c = getchar();
        if (c == -1 || c == '\n') return s->s;
        append_string(s, c);
    }
}

// Person struct to represent each person in line

struct person{
    int personNumber;   // 1st person in line, 2nd, etc
    int amountOfMoneyWanted;
};

/*
A comparator function which will take two pointers to persons, compare
the persons based on the amount of times they need to get to the ATM
in order to satisfy the amount of money they need.

E.x. If you need 30 dollars, and each visit to the ATM yields 10 dollar,s
you will visit the ATM 3 times.
*/

int comparator(const void * person1ptr, const void * person2ptr){
    struct person person1 = *(struct person *)(person1ptr);
    struct person person2 = *(struct person *)(person2ptr);

    int comparisonOnAmountOfMoney = person1.amountOfMoneyWanted - person2.amountOfMoneyWanted;

    if(comparisonOnAmountOfMoney == 0){
        int comparisonBasedOnPersonNumber = person1.personNumber - person2.personNumber;
        return comparisonBasedOnPersonNumber;
    }
    else{
        return comparisonOnAmountOfMoney;
    }


}
int main(){

    unsigned long numTests = 0; // number of tests

    unsigned int numPeople = 0;    //number of people in this test

    unsigned long maxWithdrawal = 0;    // the amount withdrawn per visit to ATM

    scanf("%lu", &numTests);    // Read in number of tests

    printf("numTests is: %lu \n", numTests);

    // For loop to handle number of tests
    for(unsigned long numTestsPerformed = 0; numTestsPerformed < numTests; numTestsPerformed++){

    printf("Test # %lu \n", numTestsPerformed);    // print number of tests performed thus far

    scanf("%d %lu", &numPeople, &maxWithdrawal); // First will be num people and maxWithdrawal on one line
    //Write some logic to read in the A values for each person. Heh.

    printf("numPeople is %d and maxWithdrawal is %lu for this specific test \n", numPeople, maxWithdrawal);

    // Make an array of people
    struct person (* arrayofPeople) = (struct person *) malloc(sizeof(struct person) * numPeople);

    printf("Reached here # 1 \n");
    // S will store the numbers representing the A values for each person. Will be total numPeople values

    printf("Reached here # 2 \n");

    //scanF will read in the A values and make string. s will point to this string.
   // getLine(&s);

   //testing
    String (* pointerToString) = (struct string (*)) malloc((sizeof(String)));


    int c;
    while ((c = getchar()) != '\n' && c != EOF);

     printf("Prior to char* assignment \n");

      // getLine(pointerToString);





    char * temp = getLine(pointerToString);

     printf("%c", temp[0]);

     printf("After  char* assignment \n");



    /*
    int index = 0;
     char a = temp[index];

     while(a != 0){
        printf("%c ", a);
        index = index + 1;
        a = temp[index];
     }

     */


   //testing ends

    printf("Reached here #3 \n");

    int q;
    int sum = 0;
    int n;

    for(int i = 0; i < numPeople; i++){

        printf("\n");

        printf("Running! \n");

        sscanf(temp + sum, "%d %n", &q, &n);
        sum = sum + n;
        printf("q is: %d \n", q);   // q will be each token
        printf("sum is: %d \n", sum);

        printf("The following is i %d and the following is q %d \n", i, q);
        (arrayofPeople[i]).personNumber = i + 1;    // Set person number

        int numVisitsToATMRequired = (q/maxWithdrawal);

        if((numVisitsToATMRequired * maxWithdrawal) < q){
            // Imagine that q is 10 and maxWithdrawal is 7. 10/7 = 1, but the numberOfATMVisits required is really 2.
            // So we will use an if statement to fx this
            numVisitsToATMRequired++;
        }

        (arrayofPeople[i]).amountOfMoneyWanted = numVisitsToATMRequired; // Set amount of money

          printf("\n");
    }

    printf("Successfully completed parsing of String containing moneyWanted values! \n");

    qsort(arrayofPeople, numPeople, sizeof(struct person), comparator);

    printf("The order of persons is as follows: \n");
    int caseNumber = 0;

    printf("Case #%lu: ", numTestsPerformed + 1);

    for(int i = 0; i < numPeople; i++){
        printf("%d ", arrayofPeople[i].personNumber);
    }

    printf("End of current test \n \n");

    free(arrayofPeople);    // Free to make sure next call to malloc wont corrupt
    free((pointerToString -> s));   // Could possibly be free temp...
    free(pointerToString);

}
}

// Implement a comparator method that will take two nodes, and will compare them based off of their A value. If their A value is
// equal, then go ahead and return based off of their order.