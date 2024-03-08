#include <stdio.h>

void findCombos(int score);

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
    findCombos(score);
}
    return 0;
}

void findCombos(int score){
    printf("Possible scoring combinations for a score of %d:\n", score);

    for (int td = 0; td * 6 <= score; td++) {
        for (int fg = 0; fg * 3 <= score - td * 6; fg++) {
            for (int safety = 0; safety * 2 <= score - (td * 6 + fg * 3); safety++) {
                for (int td2 = 0; td2 * 8 <= score - (td * 6 + fg * 3 + safety * 2); td2++) {
                    for (int td1fg = 0; td1fg * 7 <= score - (td * 6 + fg * 3 + safety * 2 + td2 * 8); td1fg++) {
                        if (td * 6 + fg * 3 + safety * 2 + td2 * 8 + td1fg * 7 == score) {
                            printf("%d TD(s) + %d FG(s) + %d Safety(s) + %d TD(s) + %d TD(s) + %d FG(s)\n",
                                   td, fg, safety, td2, td1fg, score - (td * 6 + fg * 3 + safety * 2 + td2 * 8 + td1fg));
                        }
                    }
                }
            }
        }
    }
    printf("\n");
}

