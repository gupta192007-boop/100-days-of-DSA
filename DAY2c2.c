/*You are given an array prices where prices[i] is the price of a given stock on the iᵗʰ day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction.
If you cannot achieve any profit, return 0.*/
#include <stdio.h>

int maxProfit(int prices[], int pricesSize)
{
    int minPrice = prices[0];
    int maxProfit = 0;

    for (int i = 1; i < pricesSize; i++)
    {
        
        if (prices[i] < minPrice)
        {
            minPrice = prices[i];
        }
        
        else if (prices[i] - minPrice > maxProfit)
        {
            maxProfit = prices[i] - minPrice;
        }
    }

    return maxProfit;
}

int main()
{
    int n;
    printf("Enter number of days: ");
    scanf("%d", &n);

    int prices[n];
    printf("Enter stock prices:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &prices[i]);
    }

    int profit = maxProfit(prices, n);
    printf("Maximum Profit: %d\n", profit);

    return 0;
}
