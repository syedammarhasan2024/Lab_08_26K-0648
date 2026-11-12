# include <stdio.h>

int main(){
    double costPrice, sellPrice, quantity;
    double *ptrCost = &costPrice;
    double *ptrSell = &sellPrice;
    double *ptrQty = &quantity;

    double totalCost, totalSales, profitLoss, profitPercentage;
    double *ptrTotalCost = &totalCost;
    double *ptrTotalSales = &totalSales;
    double *ptrProfitLoss = &profitLoss;
    double *ptrProfitPercentage = &profitPercentage;

    double *ptrLarger;

    printf("Enter cost price: ");
    scanf("%lf", ptrCost);
    printf("Enter selling price: ");
    scanf("%lf", ptrSell);
    printf("Enter quantity sold: ");
    scanf("%lf", ptrQty);

    *ptrTotalCost = (*ptrCost) * (*ptrQty);
    *ptrTotalSales = (*ptrSell) * (*ptrQty);
    *ptrProfitLoss = (*ptrTotalSales) - (*ptrTotalCost);

    if (*ptrProfitLoss > 0){
        printf("\nResult: Profit\n");
    }
    else if (*ptrProfitLoss < 0){
        printf("\nResult: Loss\n");
    }
    else {
        printf("\nResult: No profit no loss\n");
    }

    if (*ptrCost > 0){
        *ptrProfitPercentage = ((*ptrSell - *ptrCost) / *ptrCost) * 100;
    }
    else {
        *ptrProfitPercentage = 0;
    }
    printf("Profit Percentage: %.2f%%\n", *ptrProfitPercentage);

    if (*ptrCost >= *ptrSell){
        ptrLarger = ptrCost;
        printf("Larger value is costPrice with value: %.2f\n", *ptrLarger);
    }
    else {
        ptrLarger = ptrSell;
        printf("Larger value is sellPrice with value: %.2f\n", *ptrLarger);
    }

    printf("\n==================================================\n");
    printf("%-20s | %-20s\n", "Variable / Pointer", "Address");
    printf("--------------------------------------------------\n");
    printf("%-20s | %p\n", "costPrice", (void*)&costPrice);
    printf("%-20s | %p\n", "sellPrice", (void*)&sellPrice);
    printf("%-20s | %p\n", "quantity", (void*)&quantity);
    printf("%-20s | %p\n", "ptrCost", (void*)&ptrCost);
    printf("%-20s | %p\n", "ptrSell", (void*)&ptrSell);
    printf("%-20s | %p\n", "ptrQty", (void*)&ptrQty);
    printf("%-20s | %p\n", "ptrLarger", (void*)&ptrLarger);
    printf("==================================================\n");

    return 0;
}