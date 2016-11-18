#include "Player.hpp"

void Player::playCard(std::unique_ptr<Card> card)
{
  //this->playerHand.playCard(card->getSuit(), card->getValue()); leaving commented for now
}


void Player::insertCardToHand(Card card)
{
	this->playerHand.push_back(card);
}
