#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include "board.h"
#include "goblin.h"
#include "card.h"
#include "dragon.h"
#include "alien.h"
#include "bat.h"
#include "demon.h"
#include "warrior.h"
#include "penguin.h"
#include "rock.h"
#include "phoneix.h"
#include "eye.h"
using namespace std;

void getOpponentAction(Board&, Board&);
void renderBoard(Board&, Board&);
void createDeck(Board &board);
void getPlayerAction(Board&, Board&);
void askOptions(Board &pb, Board &ob);
void showAttackOptions(Board &pb, Board &ob);
int toss = 0;

int main(int argc, char * argv[]){

    srand(time(0));
    
    // Set up Player board
    Board pb;
    // Create player deck and draw initial hand here:
		createDeck(pb);
		pb.draw(5);
    // Set up opponent board
    Board ob;
    // Create opponent deck and draw initial hand here:
    createDeck(ob);
    ob.draw(5);

    int turn = 1;    

    while(pb.getHP() > 0 && ob.getHP() > 0) {
    toss = rand()%2;
    // Take turns here:
    ob.setMaxMana(turn);
	  pb.setMaxMana(turn);
	  ob.setMana(turn);
   	pb.setMana(turn);    	
    if(toss == 0 && turn > 1) {
    	cout << "Opponent won the toss and attacked." << endl;
			getOpponentAction(pb,ob);
    } else if (toss != 0 && turn > 1) {
    	cout << "You won the toss. Select options" << endl;
    }
    
		if(turn > 1) {
			for(int i = 0; i< pb.getFieldSize(); i++) {
				pb.getCardOnField(i)->unExhaust();
			}
		}
  	renderBoard(pb,ob);
    askOptions(pb, ob);
    turn++;
    }
    
    if(pb.getHP() < 0) {
    	cout << "You lost." << endl;
    } else if(ob.getHP() < 0) {
    	cout << "You won." << endl;
    }
    return 0;
}

//Ask Option to execute the task
void askOptions(Board &pb, Board &ob) {
	
	int input = -1;
  int selectCard;
	cout<<"What Would You Like To Do"<<endl;
	cout<<"0: Play Cards From Hand"<<endl;
  cout<<"1: Attack With a Creature"<<endl;
  cout<<"2: End Your Turn"<<endl;
  cin>>input;
  if (input < 0 || input > 2) {
  	cout << "Please enter correct choice." << endl;
  }
	else if(input==0){
  
	  int handSize = pb.getHandSize();  
	  for(int i=0; i<handSize; i++) {
	  	cout<< i <<": Play "<<pb.getCardInHand(i)->getName()<<" "<<"("<<pb.getCardInHand(i)->getManaCost()<<" @)"<<endl;
	  }
 		cout<< handSize <<": Back"<<endl;
		cin >> selectCard;

		if(selectCard == handSize) {
			askOptions(pb, ob);
		}		
	
		else {
			
			int manaDiff = pb.getMana() - pb.getCardInHand(selectCard)->getManaCost();
	
			if(manaDiff < 0) {
				cout << "You do not have enough mana." << endl;
				askOptions(pb, ob);
			} 
			
			pb.playCardFromHand(pb, selectCard);
			pb.getCardOnField(pb.getFieldSize() -1 )->exhaust();
			renderBoard(pb,ob);
			askOptions(pb,ob);
			}
		}
		
  else if(input == 1) {
		//Attack with a creature. 
	  showAttackOptions(pb,ob);
	  //getOpponentAction(pb, ob);
	  askOptions(pb, ob);
  } else if(input == 2) {
	  //End current turn.
	  if(toss != 0) {
	  	getOpponentAction(pb,ob);
	  }
	  if(pb.getDeckSize() > 0) {
	  	pb.draw(1);
  	}
	  return;
  }
}

//Attack Options.
void showAttackOptions(Board &pb, Board &ob) {
		int option = -1;

		
		int fieldSize = pb.getFieldSize();
		do {
			cout << "Attack with which creature" << endl;
			for(int i=0; i<fieldSize; i++) {
				cout << i << ": " << pb.getCardOnField(i)->getName() << endl;
			}
			cout << fieldSize <<": Back" << endl;
			cin >> option;
			if(option == fieldSize) {
				return;
			} else if(option > fieldSize || option < 0) {
				cout << "Pleaase select a valid option" << endl;
				showAttackOptions(pb, ob);			
			} else if(pb.getCardOnField(option)->isExhausted()){
				cout << pb.getCardOnField(option)->getName() << " is exhausted and cannot attack." << endl;
				showAttackOptions(pb, ob);
			} else {
				int target = -1;
				int oponentFieldSize = ob.getFieldSize();
				cout << "Select your target" << endl;
				for(int i=0; i<oponentFieldSize; i++) {
					cout << i << ": " << ob.getCardOnField(i)->getName() << endl;
				}
				cout << oponentFieldSize << ": Opponent" << endl;
				cin >> target;
				if(target == oponentFieldSize) {
					cout << "Your " << pb.getCardOnField(option)->getName() << " attack opponent directly for " << pb.getCardOnField(option)->getAttack() << " damage!" << endl;
		      ob.setHP(ob.getHP() - pb.getCardOnField(option)->getAttack());
		      renderBoard(pb, ob);
		      pb.getCardOnField(option)->exhaust();
				} else if (target < 0 || target > oponentFieldSize) {
					cout << "Select an option between 0 and " << oponentFieldSize << endl; 
					showAttackOptions(pb, ob);
				} else {
					cout << "Players's " << pb.getCardOnField(option)->getName() << " destoryed opponent's " << ob.getCardOnField(target)->getName() << "!" << endl;
					ob.discardCardFromField(target);
		      renderBoard(pb, ob);
					pb.getCardOnField(option)->exhaust();
				}
			}
		}while(option == fieldSize);
		return;
}

//Create Deck
void createDeck(Board &board) {
	int count=0;
	for(int i = 0; i <10; i++) {
		int random_number = rand()%10;
		
		switch(random_number){
			case 0:{
				Alien *alien = new Alien(); 
				board.addToDeckList(alien);	
				break;}
			case 1:{
				Bat *bat = new Bat();
				board.addToDeckList(bat);	
				break;}
			case 2:{
				Demon *demon = new Demon(); 
				board.addToDeckList(demon);	
				break;}
			case 3:{
				Dragon *dragon = new Dragon(); 
				board.addToDeckList(dragon);	
				break;}
			case 4:{
				Eye *eye = new Eye(); 
				board.addToDeckList(eye);	
				break;}
			case 5:{
				Goblin *goblin = new Goblin(); 
				board.addToDeckList(goblin);	
				break;}
			case 6:{
				Penguin *penguin = new Penguin(); 
				board.addToDeckList(penguin);	
				break;}
			case 7:{
				Phoneix *phoneix = new Phoneix(); 
				board.addToDeckList(phoneix);	
				break;}
			case 8:{
				Rock *rock = new Rock(); 
				board.addToDeckList(rock);	
				break;}
			case 9:{
				Warrior *warrior = new Warrior();
				board.addToDeckList(warrior);	
				break;}
		}
	}
}

// Render Board
void renderBoard(Board & pb, Board & ob){

    ob.renderField();
    cout << endl;
    // Render player field
    pb.renderField();
    pb.renderHand();
    cout<<"Player's Hand"<<endl;
    pb.renderMana();
    cout << "HP: " << pb.getHP() << " Opponent's HP: " << ob.getHP() << endl;
    //clearScreen(1);
}

//Opponents Actions
void getOpponentAction(Board & playerBoard, Board & opponentBoard){
    // Go through hand and play cards that the opponent can afford to play
    for(int i = 0; i < opponentBoard.getHandSize(); i++){
        if(opponentBoard.getCardInHand(i)->getManaCost() <= opponentBoard.getMana()){
            opponentBoard.playCardFromHand(opponentBoard, i);
        }
        renderBoard(playerBoard, opponentBoard);
    }
    // Attack with all creatures not exhausted
    for(int i = 0; i < opponentBoard.getFieldSize(); i++){
        if(!opponentBoard.getCardOnField(i)->isExhausted()){
            // get target for attack
            // look through all cards on player's board. If the card is capable of killing one of those, it will chose the first one as its target
            int targetIndex = -1;
            for(int j = 0; j < playerBoard.getFieldSize(); j++){
                if(opponentBoard.getCardOnField(i)->getAttack() > opponentBoard.getCardOnField(j)->getDefense()){
                    targetIndex = j;
                    break;
                }
            }
            if(targetIndex != -1){
                // destory creature
                cout << "Opponent's " << opponentBoard.getCardOnField(i)->getName() << " destoryed your " << playerBoard.getCardOnField(targetIndex)->getName() << "!" << endl;
                playerBoard.discardCardFromField(targetIndex);
                renderBoard(playerBoard, opponentBoard);
            } else {
                // opponent's creature attacks player directly
                cout << "Opponent's " << opponentBoard.getCardOnField(i)->getName() << " attacks you directly for " << opponentBoard.getCardOnField(i)->getAttack() << " damage!" << endl;
                playerBoard.setHP(playerBoard.getHP() - opponentBoard.getCardOnField(i)->getAttack());
            }
        }
                
    }
}

/*
Known issues:
- Mana issue
- Bug when targeting Opponent.
Remaining functionality:
- Toss (complete).
*/
