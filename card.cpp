#include "card.h"

using namespace std;
//Constructor
Card::Card(string card_name, int mana_cost, int defense_value, int attack_value){
	name = card_name;
	manaCost = mana_cost;
	defense = defense_value;
	attack = attack_value;
}
//Print Card
string Card::render(int line) {
    switch(line){
        case 0: return ".___________.";
        case 1: return "|           |";
        case 2: return "|           |";
        case 3: return "|           |";
        case 4: return "|           |";
        case 5: return "|           |";
        case 6: return "|           |";
        case 7: return "|___________|";
        default:
                return " ";
    }
}
//Get Name
string Card::getName(void) {
	return name;
}
//Mana Cost of Card
int Card::getManaCost(void) {
	return manaCost;
}
//Attack
int Card::getAttack(void) {
	return attack;
}
//Defence
int Card::getDefense(void) {
	return defense;
}
//Exhausted
bool Card::isExhausted(void) {
	return exhausted;
}
void Card::exhaust(void) {
	exhausted = true;
}
//UnExhausted
void Card::unExhaust(void) {
	exhausted = false;
}
