
#include "Deck_Of_Cards.h"
#include<random>
#include<algorithm>

using namespace std;

void Deck_Of_Cards::Shuffle() {

    for (const string& suit : suits) {
        for (int rank = 1; rank <= 13; ++rank) {
            deck.push_back(pair<string, int>(suit, rank));
        }
    }
    int seed;

    random_shuffle(deck.begin(),deck.end());

}