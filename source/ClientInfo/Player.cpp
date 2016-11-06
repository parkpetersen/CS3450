#include "Player.hpp"

void Player::playCard(std::unique_ptr<Card> card)
{
  this->playerHand.playCard(card->getSuit(), card->getValue());
}