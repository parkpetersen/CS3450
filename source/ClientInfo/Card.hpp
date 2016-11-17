
enum Suit
{
  HEARTS,
  SPADES,
  CLUBS,
  DIAMONDS,
  JOKER,
  UNDEFINED
};

enum Value
{
  TWO = 2,
  THREE = 3,
  FOUR = 4,
  FIVE = 5,
  SIX = 6,
  SEVEN = 7,
  EIGHT = 8,
  NINE = 9,
  TEN = 10,
  JACK = 11,
  QUEEN = 12,
  KING = 13,
  ACE = 14
};

/*The Card class represents the suit and value of
 * a card to enable to client to interact with the
 * Server
 */
class Card
{
private:
  Suit suit;
  Value value;

public:
  Suit getSuit() const;
  Value getValue() const;
  Card(Suit s, Value v);
};

bool operator<(const Card& card, const Card& otherCard);