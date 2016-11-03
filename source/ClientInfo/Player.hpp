// Project Includes
#include "Hand.hpp"

// Standard Includes
#include <memory>

class Player
{
private:
  Hand playerHand;

public:
  void playCard(std::unique_ptr<Card>);
};