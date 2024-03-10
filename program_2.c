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

    printf("Possible scoring combinations for a score of %d:\n", score);
    findCombos(score);
    printf("\n");
}
    return 0;
}
void findCombos(int score){
for (int td2 = 0; td2 * 8 <= score; td2++){
        for (int tdp = 0; tdp * 7 + td2 * 8 <= score; tdp++){
            for (int td = 0; td * 6 + tdp * 7 + td2 * 8 <= score; td++){
                for (int fg = 0; fg * 3 + td * 6 + tdp * 7 + td2 * 8 <= score; fg++){
                    for (int sf = 0; sf * 2 + fg * 3 + td * 6 + tdp * 7 + td2 * 8 <= score; sf++){
                        if (+ sf * 2 + fg * 3 + td * 6 + tdp * 7 + td2 * 8 == score){
                            printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", td2, tdp, td, fg, sf);
            }
                    }
                }
            }
}
}
}


