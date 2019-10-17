#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

class Card {
private:

    rank m_Rank;
    suit m_Suit;
    bool m_IsFaceUp;
    int GetValue();
    void Flip();    
    
public:

};

class Hand {
private:
    
    vector<Card*> m_Cards;
    void Add(Card* pCard);
    void Clear();
    int GetTotal();

public:

};

class Deck: public Hand {
private:
    
    vold Populate();
    void Shuffle();
    vold Deal (Hand& aHand);
    void AddltionalCards (GenericPlayer& aGenerlcPlayer);

public:

};

class GenericPlayer: public Hand {
private:
    
    string m_Name;
    virtual bool IsHitting() const = 0;
    bool IsBoosted() const;
    void Bust() const;  

public:

};

class Player: public GenericPlayer {
private:
    
    virtual bool IsHitting() const;
    void Win() const;
    void Lose() const;
    void Push() const;

public:

};

class House: public GenericPlayer {
private:
    
    virtual bool IsHitting() const;
    void FlipFirstCard();

public:

};

class Game {
private:
    
    Deck m_Deck;
    House m_House;
    vector<Player> m_Players;
    void Play();

public:

};



int main(int argc, char *argv[])  {
    
    cout << "\t\tWelcome to Blackjack!\n\n";
    
    int numPlayers = 0;
    while (numPlayers < 1 || numPlayers > 7)
    {
        cout << "How many players? (1 - 7): ";
        cin >> numPlayers;
    }
    
    vector<string> names;
    string name;
    for (int i = 0; i < numPlayers; ++i)
    {
        cout << "Enter player name: ";
        cin >> name;
        names.push_back(name);
    }
    cout << endl;
    
    // игровой цикл
    Game aGame(names);
    char again = 'y';
    while (again != 'n' && again != 'N')
    {
        aGame.Play();
        cout << "\nDo you want to play again? (Y/N): ";
        cin >> again;
    }

return 0;
}
