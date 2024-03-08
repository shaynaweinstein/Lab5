#include <stdio.h>

void findCombos(int score, int touchdowns, int fieldGoals, int safeties, int tdConversions, int fgTdConversions);
void findComboshelp(int score, int touchdowns, int fieldGoals, int safeties, int tdConversions, int fgTdConversions);
int main(){
    int score;



while (1) {
    printf("Enter 0 or 1 to STOP\n");
    printf("Enter the NFL score: ");
    scanf("%d", &score);

    if (score <= 1){
        printf("Program ended. \n");
        break;
    }

    printf("Possible scoring combinations for a score of %d:\n", score);
    findCombos(score, 0, 0, 0, 0, 0);
    printf("\n");
}
    return 0;
}
void findCombos(int score, int touchdowns, int fieldGoals, int safeties, int tdConversions, int fgTdConversions){
    findComboshelp(score, touchdowns, fieldGoals, safeties, tdConversions, fgTdConversions);
}
void findComboshelp(int score, int touchdowns, int fieldGoals, int safeties, int tdConversions, int fgTdConversions){
    if (score == 0) {
        printf("%d TD(s) + %d FG(s) + %d Safety(s) + %d TD(s) + %d TD(s) + %d FG(s)\n",
               touchdowns, fieldGoals, safeties, tdConversions, fgTdConversions, score);
        return;
    }

    if (score >= 6) {
        findComboshelp(score - 6, touchdowns + 1, fieldGoals, safeties, tdConversions, fgTdConversions);
    }

    if (score >= 3) {
        findComboshelp(score - 3, touchdowns, fieldGoals + 1, safeties, tdConversions, fgTdConversions);
    }

    if (score >= 2) {
        findComboshelp(score - 2, touchdowns, fieldGoals, safeties + 1, tdConversions, fgTdConversions);
    }

    if (score >= 8) {
        findComboshelp(score - 8, touchdowns, fieldGoals, safeties, tdConversions + 1, fgTdConversions);
    }

    if (score >= 7) {
        findComboshelp(score - 7, touchdowns, fieldGoals, safeties, tdConversions, fgTdConversions + 1);
    }
}


