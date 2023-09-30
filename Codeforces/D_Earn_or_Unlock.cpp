#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int maxVictoryPoints(int n, vector<int>& cards) {
    priority_queue<int> unlockedCards;
    int victoryPoints = 0;

    for (int i = 0; i < n; i++) {
        unlockedCards.push(cards[i]);

        while (!unlockedCards.empty()) {
            int topCardValue = unlockedCards.top();
            unlockedCards.pop();

            if (topCardValue > 0) {
                victoryPoints += topCardValue;

                while (topCardValue > 0 && !unlockedCards.empty()) {
                    unlockedCards.pop();
                    topCardValue--;
                }
            }
        }
    }

    return victoryPoints;
}

int main() {
    int n;
    cin >> n;

    vector<int> cards(n);
    for (int i = 0; i < n; i++) {
        cin >> cards[i];
    }

    int result = maxVictoryPoints(n, cards);
    cout << result << endl;

    return 0;
}
