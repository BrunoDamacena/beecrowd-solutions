#include <iostream>
#include <vector>
#include <unordered_map>

std::vector<char> allCards() {
    return {'A', '2', '3', '4', '5', '6', '7', '8', '9', 'D', 'Q', 'J', 'K'};
}

int handContainsCard(std::string hand, char card) {
    if (card == 'X') {
        return 5;
    }
    int times = 0;
    for (char c: hand) {
        if (c == card) {
            times++;
        }
    }
    return times;
}

std::string removeCardFromHand(std::string hand, char card) {
    std::string newHand = "";
    bool removed = false;
    for (char c: hand) {
        if (!removed && card == c) {
            removed = true;
        }
        else {
            newHand += c;
        }
    }
    return newHand;
}

bool isOnWinningState(std::string hand) {
    std::unordered_map<char, int> cardCount;
    for (char card: hand) {
        cardCount[card]++;
        if (cardCount[card] == 4) {
            return true;
        }
    }
    return false;
}

int findWinner(int n, std::vector<std::string>& hands, int firstPlayer) {
    std::vector<int> joker(n, 0);
    joker[firstPlayer] = 1;
    int winner = -1;
    int currentPlayer = firstPlayer;
    bool firstHand = true; // aparently you cant win on the first hand
    while (winner == -1) {
        // std::cout << "Current player: " << currentPlayer + 1 << std::endl;
        // std::cout << "Current hand: " << hands[currentPlayer] << std::endl;
        // std::cout << "Joker status: " << joker[currentPlayer] << std::endl;
        // case 1: current player won, ends the game
        if (isOnWinningState(hands[currentPlayer]) && !firstHand) {
            // std::cout << "Current player won!" << std::endl;
            // std::cout << "Hand: " << hands[currentPlayer];
            // if ((bool) joker[currentPlayer]) {
            //     std::cout << " and the joker";
            // }
            // std::cout << std::endl;
            winner = currentPlayer;
            break;
        }
        firstHand = false;
        // case 2: has to give away the joker
        int nextPlayer = (currentPlayer + 1) % n;
        if (joker[currentPlayer] == 2) {
            // std::cout << "Current player will pass on the joker to the next player" << std::endl;
            joker[currentPlayer] = 0;
            joker[nextPlayer] = 1;
            currentPlayer = nextPlayer;
            continue;
        }
        // case 3: has just received the joker
        else if (joker[currentPlayer] == 1) {
            joker[currentPlayer] = 2;
        }
        // general case: has to give away a card
        bool passedCard = false;
        char repeatedCard = 'X'; // X represents an invalid value
        for (char card: allCards()) {
            // have only one of that card
            if (handContainsCard(hands[currentPlayer], card) == 1) {
                if (passedCard) {
                    continue;
                }
                hands[currentPlayer] = removeCardFromHand(hands[currentPlayer], card);
                hands[nextPlayer] += card;
                passedCard = true;
                // std::cout << "Current player will pass on the " << card << " to the next player (reason: he only has one of it)" << std::endl;
            }
            else if (handContainsCard(hands[currentPlayer], card) > 1) {
                if (passedCard) {
                    continue;
                }
                if (handContainsCard(hands[currentPlayer], repeatedCard) > handContainsCard(hands[currentPlayer], card)) {
                    repeatedCard = card;
                }
            }
        }
        // if not passed a card, its because it have two sets of the same card
        // on this case, we will pass the card that is doubled
        if (!passedCard) { 
            hands[currentPlayer] = removeCardFromHand(hands[currentPlayer], repeatedCard);
            hands[nextPlayer] += repeatedCard;
            // std::cout << "Current player will pass on the " << repeatedCard << " to the next player (reason: he has the least of them and its the lower value)" << std::endl;

        }
        currentPlayer = nextPlayer;
    }
    return winner + 1;
}

int main() {

    int N, K;
    std::cin >> N >> K;
    std::vector<std::string> players(N);
    for (int i = 0; i < N; i++) {
        std::cin >> players[i];
        if (i != K - 1 && isOnWinningState(players[i])) {
            std::cout << i + 1 << std::endl;
            return 0;
        }
    }

    std::cout << findWinner(N, players, K - 1) << std::endl;

    return 0;
}