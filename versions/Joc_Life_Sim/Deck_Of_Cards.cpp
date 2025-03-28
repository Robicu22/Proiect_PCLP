
#include "Deck_Of_Cards.h"


void Deck_Of_Cards::Shuffle() {

    for (const string& suit : suits) {
        for (int rank = 1; rank <= 13; ++rank) {
            deck.push_back(pair<string, int>(suit, rank));
        }
    }

    cout << "Deck of cards:" << endl;
    for (const auto& card : deck) {
        cout << card.first << " " << card.second << endl;
    }
}