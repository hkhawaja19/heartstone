#include "board.h"
#include "card.h"
#include<cstdlib>
using namespace std;

Board::Board(void){
	hp = 2000;
}
//Add Card to deck
void Board::addToDeckList(Card* card){ 
	deck.push_back(card);
}
//Add Card to hand and remove deck
void Board::draw(int cardsToDraw) {
	for(int i=0; i < cardsToDraw; i++){
		hand.push_back(deck[deck.size() - 1]);
		deck.pop_back();
	}
}
//Add Card to field and erase from hand.
void Board::playCardFromHand(Board board, int i) {
	int manaCost = hand[i]->getManaCost();
 	mana = mana - manaCost;
	field.push_back(hand[i]);
	hand.erase(hand.begin()+i);
}
//index of card at field
Card* Board::getCardOnField(int index) {
	return field.at(index);
}
//index of card at hand
Card* Board::getCardInHand(int index) {
	return hand.at(index);
}
//get HP
int Board::getHP(void) {
	return hp;
}
//Set new HP
void Board::setHP(int new_hp) {
	hp = new_hp;
}
int Board::getDeckSize(void) {
	return deck.size();
}
//Hand Size
int Board::getHandSize(void) {
	return hand.size();
}
//Field Size
int Board::getFieldSize(void) {
	return field.size();
}
//Mana
int Board::getMana(void) {
	return mana;
}
//New Mana
void Board::setMana(int new_mana) {
	mana = new_mana;
}
//MaxMana
int Board::getMaxMana(void) {
	return maxMana;
}
//New Max Mana
void Board::setMaxMana(int mana) {
	maxMana = mana;
}
//erase card from field
void Board::discardCardFromField(int index) {
	field.erase(field.begin() + index);
}
//UnExhaustField
void Board::unExhaustField(void) {
	for(std::vector<Card>::size_type i = 0; i != field.size(); i++) {
		field[i]->unExhaust();	
	}
}
//Shuffle 
void Board::shuffleDeck(void){
    Card * temp;
    int numOfShuffles = 100;
    int idx1, idx2;
    for(int i = 0; i < numOfShuffles; i++){
        idx1 = rand() % deck.size();
        idx2 = rand() % deck.size();
        temp = deck[idx1];
        deck[idx1] = deck[idx2];
        deck[idx2] = temp;
    }
}
//Print Mana
void Board::renderMana(void){
    cout << "MANA: ";
    for(int i = 1; i <= maxMana; i++){
        if(i <= mana) {
          	cout << "@ ";
        }
       	else {
          	cout << "O ";
 				}
	}	
				cout << endl;
}
//Print Cards on Hand
void Board::renderHand(void){
    if(hand.size() > 0){
        for(int i = 0; i <= 7; i++){
            for(int j = 0; j < hand.size(); j++){
                cout << hand[j]->render(i) <<" ";
            }
            cout << endl;
        }
    } else {
        for(int i = 0; i <= 7; i++)
            cout << endl;
    }
}
//Print Cards on Hand
void Board::renderField(void){
    if(field.size() > 0){
        for(int i = 0; i <= 7; i++){
            for(int j = 0; j < field.size(); j++){
                cout << field[j]->render(i) << " ";
            }
            cout << endl;
        }
    } else {
        for(int i = 0; i <= 7; i++)
            cout << endl;
    }
}
