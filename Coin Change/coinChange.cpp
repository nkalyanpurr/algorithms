#include <iostream>

using namespace std;
int count;
int makeChange(int amount, int coins[4])
{
    const char *denomination[4] = {"penny", "nickel", "dime", "quarter"};
    if (amount == 0)
    {
        return 0;
    }
    for (int i = 4; i > 0; i--)
    {
        int coin = coins[i - 1];
        //If the next largest coin is found, print out its value.
        if (amount == coin || amount >= coin)
        {
            printf("coin: %i %s \n", coin, denomination[i - 1]);
            count++;
            return 1 + makeChange(amount - coin, coins);
        }
    }
    printf("Cannot make change ");
    printf("cents remaining: %i", amount);
    return 0;
}

int main()
{
    int coins[4] = {1, 5, 10, 25};
    int amount = 75;
    printf("Amount: %i \n", amount);
    makeChange(amount, coins);
    printf("Total number of coins: %i", count);
    return 0;
}
