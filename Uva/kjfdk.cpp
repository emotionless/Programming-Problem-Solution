#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int day, money, income, cost, bonus_income;
    cin >> day >> money >> income >> cost >> bonus_income;
    for (int i = 0; i < day; i += 1) {
        if ((day - i) * bonus_income > cost and money >= cost) {
            money -= cost;
            income += bonus_income;
        }
        money += income;
    }
    cout << money << '\n';
    return 0;
}
