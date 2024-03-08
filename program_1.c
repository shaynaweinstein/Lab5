#include <stdio.h>
#define num_months 12

void genSalesReport(float salesData[], int n);
void genSalesSumm(float salesData[], int n);

int main(){
    float salesData[num_months];
    char filename[100];
    // Get the filename from the user
    printf("Enter the filename with monthly sales numbers: ");
    scanf("%s", filename);

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file. Make sure the file exists.\n");
        return 1; // Return error code
    }

    // Read monthly sales numbers from the file
    for (int i = 0; i < num_months; i++) {
        if (fscanf(file, "%f", &salesData[i]) != 1) {
            printf("Error reading sales data from the file.\n");
            fclose(file);
            return 1; // Return error code
        }
    }

    fclose(file);
    genSalesReport(salesData, num_months);
    genSalesSumm(salesData, num_months);

    return 0;
}

void genSalesReport(float salesData[], int n){
    printf("\nSales Report:\n");
    printf("%-15s %-15s\n", "Month", "Sales");
    const char *months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

    for (int i = 0; i < n; i++) {
        printf("%-15s $%-14.2f\n", months[i], salesData[i]);
    }
}


void genSalesSumm(float salesData[], int n){
    const char *months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
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
        printf("%-15s $%-14.2f\n",months[i], movingAverage);
    }

    // Sort and display monthly sales from highest to lowest
    printf("\nMonthly Sales Report (Highest to Lowest):\n");
    printf("%-15s %-15s\n", "Month", "Sales");

    // Create an array of indices and sort it based on sales data
    int indices[num_months];
    for (int i = 0; i < num_months; i++) {
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
        printf("%-15s $%-14.2f\n",months[i], salesData[indices[i]]);
    }
}