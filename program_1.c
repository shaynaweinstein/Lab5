#include <stdio.h>
#define months 12

void genSalesReport(float salesData[], int n);
void genSalesSumm(float salesData[], int n);

int main(){
    float salesData[months];
    char filename[100];
}

void genSalesReport(float salesData[], int n){
    printf("\nSales Report:\n");
    printf("%-10s %-15s\n", "Month", "Sales");
    for (int i = 0; i < n; i++) {
        printf("%-10s $%-14.2f\n", (i + 1 == 10) ? "Month 10" : (i + 1 == 11) ? "Month 11" : (i + 1 == 12) ? "Month 12" : "Month", salesData[i]);
    }
}


void genSalesSumm(float salesData[], int n){
    printf("\nSales Summary Report:\n");
    
    // Calculate minimum, maximum, and average sales
    float minSales = salesData[0];
    float maxSales = salesData[0];
    float avgSales = salesData[0];
    
    for (int i = 1; i < n; i++) {
        if (salesData[i] < minSales) {
            minSales = salesData[i];
        }
        if (salesData[i] > maxSales) {
            maxSales = salesData[i];
        }
        avgSales += salesData[i];
    }
    
    avgSales /= n;

    printf("Minimum Sales: $%.2f\n", minSales);
    printf("Maximum Sales: $%.2f\n", maxSales);
    printf("Average Sales: $%.2f\n", avgSales);

    // Calculate six-month moving averages
    printf("\nSix-Month Moving Averages:\n");
    for (int i = 5; i < n; i++) {
        float movingAverage = 0;
        for (int j = i - 5; j <= i; j++) {
            movingAverage += salesData[j];
        }
        movingAverage /= 6;
        printf("%-10s $%-14.2f\n", (i + 1 == 10) ? "Month 10" : (i + 1 == 11) ? "Month 11" : (i + 1 == 12) ? "Month 12" : "Month", movingAverage);
    }

    // Sort and display monthly sales from highest to lowest
    printf("\nMonthly Sales Report (Highest to Lowest):\n");
    printf("%-10s %-15s\n", "Month", "Sales");

    // Create an array of indices and sort it based on sales data
    int indices[months];
    for (int i = 0; i < months; i++) {
        indices[i] = i;
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (salesData[indices[i]] < salesData[indices[j]]) {
                int temp = indices[i];
                indices[i] = indices[j];
                indices[j] = temp;
            }
        }
    }

    // Display sorted monthly sales
    for (int i = 0; i < n; i++) {
        printf("%-10s $%-14.2f\n", (indices[i] + 1 == 10) ? "Month 10" : (indices[i] + 1 == 11) ? "Month 11" : (indices[i] + 1 == 12) ? "Month 12" : "Month", salesData[indices[i]]);
    }
}