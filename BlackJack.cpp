#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

enum rank {	//Значение карты (туз, двойка, тройка и так долее). rank — это перечисление, куда входят все 13 значений
        ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN,
        JACK, QUEEN, KING
    };
enum suit { CLUBS, DIAMONDS, HEARTS, SPADES }; //Масть карты (трефы, бубны, червы и пики). suit — это перечисление, содержащее четыре возможные масти

class Card
{
public:
    enum rank {
        ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN,
        JACK, QUEEN, KING
    };
    enum suit { CLUBS, DIAMONDS, HEARTS, SPADES };
    
    Card(rank r = ACE, suit s = SPADES, bool ifu = true);
    int GetValue() const;  //Возвращает значение карты
    void Flip();  //Переворачивает карту. Может использоваться для того, чтобы перевернуть карту лицом вверх или вниз
    friend ostream& operator<<(ostream& os, const Card& aCard);
	
private:
    rank m_Rank;
    suit m_Suit;
    bool m_IsFaceUp; //Указывает, как расположена карта — вверх лицом или рубашкой. Влияет на то, отображается она или нет
};

Card::Card(rank r, suit s, bool ifu) : m_Rank(r), m_Suit(s), m_IsFaceUp(ifu)
{}

int Card::GetValue() const
{
    int value = 0;
    if (m_IsFaceUp)
    {
        value = m_Rank;
        if (value > 10)
        {
           value = 10;
        }
    }
    return value;
}

void Card::Flip()
{
    m_IsFaceUp = !(m_IsFaceUp);
}


void Card::Flip()
{
    m_IsFaceUp = !(m_IsFaceUp);
}

int Card::GetValue() const
{
    //если карта перевернута лицом вниз, ее значение равно О
    int value = 0;
    if (m_IsFaceUp)
    {
        // значение - это число, указанное на карте
        value = m_Rank;
        // значение равно 10 для JACK, QUEEN и KING
        if (value > 10)
        {
            value = 10;
        }
    }
    return value;
}


class Hand
{
public:
    Hand();
    // виртуальный деструктор
    virtual ~Hand();
    
    // Добавляет карту в руку. Добавляет указатель на объект типа Сard в вектор m_Сards
    void Add(Card* pCard);
    
    // Очищает руку от карт. Удаляет все указатели из вектора m_Сards, устраняя все связанные с ними объекты в куче
    void Clear();
    
    //получает сумму очков карт в руке, присваивая тузу
    // значение 1 или 11 в зависимости от ситуации
    int GetTotal() const;
    
protected:
    vector<Card*> m_Cards; //Коллекция карт. Хранит указатели на объекты типа Сard
};

Hand::Hand()
{
    m_Cards.reserve(7);
}
// деструктор по-прежнему виртуальный
// это уже можно не обозначать
Hand::~Hand()
{
    Clear();
}

void Hand::Add(Card* pCard)
{
    m_Cards.push_back(pCard);
}

void Hand::Clear()
{
    // проходит по вектору, освобождая всю память в куче
    vector<Card*>::iterator iter = m_Cards.begin();
    for (iter = m_Cards.begin(); iter != m_Cards.end(); ++iter)
    {
        delete *iter;
        *iter = 0;
    }
    // очищает вектор указателей
    m_Cards.clear();
}
int Hand::GetTotal() const  //Возвращает сумму очков карт руки
{
    // если карт в руке нет, возвращает значение 0
    if (m_Cards.empty())
    {
        return 0;
    }
    
    //если первая карта имеет значение 0, то она лежит рубашкой вверх:
    // вернуть значение 0
    if (m_Cards[0]->GetValue() == 0)
    {
        return 0;
    }
    
    // находит сумму очков всех карт, каждый туз дает 1 очко
    int total = 0;
    vector<Card*>::const_iterator iter;
    for (iter = m_Cards.begin(); iter != m_Cards.end(); ++iter)
    {
        total += (*iter)->GetValue();
    }
    
    // определяет, держит ли рука туз
    bool containsAce = false;
    for (iter = m_Cards.begin(); iter != m_Cards.end(); ++iter)
    {
        if ((*iter)->GetValue() == Card::ACE)
        {
            containsAce = true;
        }
    }
    
    // если рука держит туз и сумма довольно маленькая, туз дает 11 очков
    if (containsAce && total <= 11)
    {
        // добавляем только 10 очков, поскольку мы уже добавили
        // за каждый туз по одному очку
        total += 10;
    }
    
    return total;
}


class Deck: public Hand {
private:
    
    vold Populate();  //Создает стандартную колоду из 52 карт
    void Shuffle();		//Тасует карты
    vold Deal (Hand& aHand);	//Раздает в руку одну карту
    void AddltionalCards (GenericPlayer& aGenerlcPlayer);	//Раздает игроку дополнительные карты до тех пор, пока он может и хочет их получать

public:

};

class GenericPlayer : public Hand
{
    friend ostream& operator<<(ostream& os, const GenericPlayer& aGenericPlayer);
    
public:
    GenericPlayer(const string& name = "");
    
    virtual ~GenericPlayer();
    
    // показывает, хочет ли игрок продолжать брать карты
    // Для класса GenericPlayer функция не имеет своей реализации,
    // т.к. для игрока и дилера это будут разные функции
    virtual bool IsHitting() const = 0;
    
    // возвращает значение, если у игрока перебор -
    // сумму очков большую 21
    // данная функция не виртуальная, т.к. имеет одинаковую реализацию
    // для игрока и дилера
    bool IsBusted() const;
    
    // объявляет, что игрок имеет перебор
    // функция одинакова как для игрока, так и для дилера
    void Bust() const;
    
protected:
    string m_Name;
};
GenericPlayer::GenericPlayer(const string& name) :
m_Name(name)
{}
GenericPlayer::~GenericPlayer()
{}
bool GenericPlayer::IsBusted() const
{
    return (GetTotal() > 21);
}
void GenericPlayer::Bust() const
{
    cout << m_Name << " busts.\n";
}


class Player : public GenericPlayer
{
public:
    Player(const string& name = "");
    
    virtual ~Player();
    
    // показывает, хочет ли игрок продолжать брать карты
    virtual bool IsHitting() const;
    
    // объявляет, что игрок победил
    void Win() const;
    
    // объявляет, что игрок проиграл
    void Lose() const;
    
    // объявляет ничью
    void Push() const;
};

bool Player::IsHitting() const
{
    cout << m_Name << ", do you want a hit? (Y/N): ";
    char response;
    cin >> response;
    return (response == 'y' || response == 'Y');
}
void Player::Win() const
{
    cout << m_Name << " wins.\n";
}

void Player::Lose() const
{
    cout << m_Name << " loses.\n";
}

void Player::Push() const
{
    cout << m_Name << " pushes.\n";
}

class House : public GenericPlayer
{
public:
    House(const string& name = "House");
    
    virtual ~House();
    
    // показывает, хочет ли дилер продолжать брать карты
    virtual bool IsHitting() const;
    
    // переворачивает первую карту
    void FlipFirstCard();
};
bool House::IsHitting() const
{
    return (GetTotal() <= 16);
}
bool House::IsHitting() const
{
    return (GetTotal() <= 16);
}
void House::FlipFirstCard()
{
    if (!(m_Cards.empty()))
    {
        m_Cards[0]->Flip();
    }
    else
    {
        cout << "No card to flip!\n";
    }
}

class Game {
private:
    
    Deck m_Deck;	//Колода карт
    House m_House;	//Рука дилера
    vector<Player> m_Players;	//Группа игроков-людей. Вектор, содержащий объекты типа Player
    void Play();			//Проводит кон игры Blackjack

public:

};


// перегружает оператор <<, чтобы получить возможность отправить
// объект типа Card в поток cout
ostream& operator<<(ostream& os, const Card& aCard)
{
    const string RANKS[] = { "0", "A", "2", "3", "4", "5", "6", "7", "8", "9","10", "J", "Q", "K" };
    const string SUITS[] = { "c", "d", "h", "s" };
    
    if (aCard.m_IsFaceUp)
    {
        os << RANKS[aCard.m_Rank] << SUITS[aCard.m_Suit];
    }
    else
    {
        os << "XX";
    }
    
    return os;
}

ostream& operator<<(ostream& os, const GenericPlayer& aGenericPlayer)
{
    os << aGenericPlayer.m_Name << ":\t";
    
    vector<Card*>::const_iterator pCard;
    if (!aGenericPlayer.m_Cards.empty())
    {
        for (pCard = aGenericPlayer.m_Cards.begin();
             pCard != aGenericPlayer.m_Cards.end();
             ++pCard)
        {
            os << *(*pCard) << "\t";
        }
        
        
        if (aGenericPlayer.GetTotal() != 0)
        {
            cout << "(" << aGenericPlayer.GetTotal() << ")";
        }
    }
    else
    {
        os << "<empty>";
    }
    
    return os;
}


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
