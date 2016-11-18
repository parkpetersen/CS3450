//// Project Includes
//#include "Card.hpp"
//
//// Standard Includes
//#include <memory>
//#include <vector>
//
//class Hand
//{
//private:
//  std::vector<std::shared_ptr<Card>> userHand;
//
//public:
//  /*Rearranges the users hand to be in order of suit and value*/
//  void organizeHand(std::vector<Card>& hand);
//
//  /*Checks if the user doesn't have any cards left to play*/
//  bool isEmpty();
//
//  /*Removes the card from the users Hand and plays it in the
//   *center
//   */
//  std::shared_ptr<Card> playCard(Suit s, Value v);
//};