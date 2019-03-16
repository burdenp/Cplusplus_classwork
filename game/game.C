
#include <typeinfo>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <stdlib.h>
#include <SFML/Graphics.hpp>
using namespace std;
class news;
class player;
class playerObserver;
//create subclass poke
//poke's are "champions"
class poke{
	public:
	string type;
	vector < class news * > views;
	//tired decides if this poke has gone this turn yet
	//if false it has gone
	bool tired;
	int health, strength, armor, x, y, movement, initiative;
	void move(int xx, int yy);
	void attach(news *obs){
		views.push_back(obs);
	}
	int getHealth(){
		return health;
	}
	int getStrength();
	int getArmor();
	void notify();
	void setHealth(int h);
  void setStrength(int h);
  void setArmor(int h);
  void setMovement(int h);
  void setInitiative(int h);
	void toString(){
		int  h = getHealth();
		int  s = getStrength();
		int  a = getArmor();
		cout<<"this "<<getType()<<" has "<<h<<" Health, "<<s<<" Strength, and "<<a<<" armor\n";
	}
	poke(int h, int s, int a, int xx, int yy){
        health = h;
        strength = s;
        armor = a;
        x = xx;
        y = yy;
        tired = true;
	}
	string getType(){
		return type;
	}
  int getMovement();
  int getInitiative();
  int getX();
  int getY();
  int getEnergy();
  void kill();
};
void poke::move(int xx, int yy){
	x = xx;
	y = yy;
}
int poke::getStrength(){
	return strength;
}
int poke::getArmor(){
	return armor;
}
int poke::getInitiative(){
  return initiative;
}
int poke::getMovement(){
  return movement;
}
void poke::setHealth(int h){
	health = h;
}
void poke::setStrength(int h){
  strength = h;
}
void poke::setArmor(int h){
  armor = h;
}
void poke::setInitiative(int h){
  initiative = h;
}
void poke::setMovement(int h){
  movement = h;
}
int poke::getX(){
    return x;
}
int poke::getY(){
    return y;
}
void poke::kill(){
  delete &x;
  delete &y;
  delete &initiative;
  delete &armor;
  delete &strength;
  delete &armor;
  delete &movement;
  delete &type;
}

//create sub class rock of type poke.
//rock "champions" are higher health, lower strength,
// higher armor, lower movement, medium initiative
class rock: public poke{
	public:
		void attack(poke * target){
			if(getType() == "scissors"){
				target->setHealth(target->getHealth() - this->getStrength());
			}
			else{
				target->setHealth(target->getHealth()
					 - (this->getStrength() - target->getArmor()));
			}
		}
		rock(int h, int s, int a, int xx, int yy) : poke(h,s,a,xx,yy){
            health = h;
            strength = s;
            armor = a;
            x = xx;
            y = yy;
			type = "rock";
			tired = true;
		}
};
//create sub class paper of type poke.
//paper "champions" are low health, medium strength,
// low armor, high movement, high initiative
class paper: public poke{
	public:
		void attack(poke * target){
			if(getType() == "rock"){
				target->setHealth(target->getHealth() - this->getStrength());
			}
			else{
				target->setHealth(target->getHealth() -
					(this->getStrength() - target->getArmor()));
			}
		}
		paper(int h, int s, int a, int xx, int yy) : poke(h,s,a,xx,yy){
		 health = h;
        	 strength = s;
       		 armor = a;
       		 x = xx;
       		 y = yy;
       		 type = "paper";
       		 tired = true;
		}
};
//create sub class scissors of type poke.
//scissors "champions" are medium/low health, high strength,
// low armor, medium movement, medium initiative
class scissors: public  poke{
	public:
		void attack(poke * target){
			if(getType() == "paper"){
				target->setHealth(target->getHealth() - this->getStrength());
			}
			else{
				target->setHealth(target->getHealth()
					 - (this->getStrength() - target->getArmor()));
			}
		}
		scissors(int h, int s, int a, int xx, int yy): poke(h,s,a,xx,yy){
		        health = h;
        		strength = s;
                armor = a;
                x = xx;
        	    y = yy;
                type = "scissors";
                tired = true;
		}
};
class player{
//list of 'pokes' that the player has
   vector<poke> list;
   vector<playerObserver*> views;
   public:
    vector<poke> getList(){
      return list;
    }
  //addPoke function adds a poke to the list
    void addPoke(rock  poke){
      list.push_back(poke);
      notify();
    }
		void addPoke(paper poke){
			list.push_back(poke);
			notify();
		}
		void addPoke(scissors poke){
			list.push_back(poke);
			notify();
		}
    int listSize(){
      return list.size();
    }
    void notify();
    player(vector<poke> pokes){
    list = pokes;
    }
		void attach(playerObserver *obs){
                	views.push_back(obs);
       		 }
		void toString(){
			for(int i = 0; i < list.size(); i++){
				list[i].toString();
			}
		}
    player(){}
    vector<poke> get_list(){
      return list;
    }
    bool is_occupied(int xx, int yy){
      for(int i = 0; i < list.size(); i++){
        if(list[i].getX() == xx && list[i].getY() == yy){
          return true;
        }
      }
    }
  vector<int> clear_dead(){
    for(int i = 0; i < list.size(); i++){
      //vector of the locations in the v_int that are dead
      vector<int> dead_loc;
      if(list[i].getHealth() < 1){
       //TODO decide on death animation
       dead_loc.push_back(i);
       //removes the poke
       kill(i);
      }
    }
  }
  void kill(int i){
    list.erase(list.begin()+(i-1));
  }
};
//observer class
class news{
	poke *model;
	public:
		news(poke * mod){
			model = mod;
			model->attach(this);
		}
		void update(){
			model->toString();
		}
		poke *getSubject(){
			return model;
		}
};
void poke::notify(){
	for(int i = 0; i < views.size(); i++){
	views[i] -> update();
	}
}
class playerObserver{
	player * model;
	public:
		playerObserver(player * mod){
			model = mod;
			model->attach(this);
		}
		void update(){
			 model->toString();
		}
		player *getsubject(){
			return model;
		}
};
void player::notify(){
        for(int i = 0; i < views.size(); i++){
        views[i] -> update();
        }
}
//shop class
class shop{
  int gold;
  vector<poke> v1, v2;
  vector<int> v_int;
  public:
    //TODO build shop
  void purchase(int loc);
  void assemble();
  //TODO display
  void display(int poke_int);
  //for when player is done buying even if they still have points
  void empty_pockets();
  int getGold();
  vector<poke> get_v1();
  vector<poke> get_v2();
};
int shop::getGold(){
  return gold;
}
vector<poke> shop:: get_v1(){
  return v1;
}
vector<poke> shop:: get_v2(){
  return v2;
}
//purchase is called when the player clicks to buys his "champ"
//loc stands for its place in the array in v1
void shop::purchase(int loc){
  v2.push_back(v1[loc]);
  gold =- v_int[loc];
}
//creates the poke's that will be in v1 and assigns their values in v_int
void shop::assemble(){
  gold = 100;
  //first rock type
  rock poke1 = rock(8,1,3,0,5);
  poke1.setMovement(2);
  poke1.setInitiative(2);
  //first paper type
  paper poke2 = paper(4,2,2,0,6);
  poke2.setMovement(4);
  poke2.setInitiative(7);
  //first scissor type
  scissors poke3 = scissors(6,3,3,0,4);
  poke3.setMovement(3);
  poke3.setInitiative(4);
  //second rock type
  rock poke4 = rock(9,2,3,1,4);
  poke4.setMovement(2);
  poke4.setInitiative(3);
  //second paper type
  paper poke5 = paper(3,4,1,1, 5);
  poke5.setMovement(5);
  poke5.setInitiative(6);
  //second scissor type
  scissors poke6 = scissors(6,4,2,0,2);
  poke6.setMovement(2);
  poke6.setInitiative(5);
//moving pokes into v1
  v1.push_back(poke1);
  v1.push_back(poke4);
  v1.push_back(poke2);
  v1.push_back(poke5);
  v1.push_back(poke3);
  v1.push_back(poke6);
//assigning pokes worth in gold to v_int
  v_int.push_back(20);
  v_int.push_back(15);
  v_int.push_back(5);
  v_int.push_back(10);
  v_int.push_back(25);
  v_int.push_back(20);
}
//needs to have cocos2dx or SFML2.1 to work
//TODO displays the current poke, i.e the given one
void shop::display(int poke_int){
  poke display_poke = v1[poke_int];
  int cost = v_int[poke_int];
//TODO handle the rest
}
void shop::empty_pockets(){
  gold = 0;
}
class control{
  player * p_human;
  player * p_comp;
  bool gameOn;
  //for figuring out who goes when
  vector<int> p1, p2;
  public:
  void populate(player* p_player);
  //base initializer
    control(int i){
    player* play1 = new player();
    player* play2 = new player();
    p_human = play1;
    p_comp = play2;
    gameOn = true;
    populate(p_comp);
    p1;
    p2;
    }
  vector<poke> pickPokes();
  //TODO display needs cocos2dx or SFML
  void display();
  //TODO playGame()
  // need to finish all display function then create key handlers
  void playGame();
  //picks which champions turn it is
  poke* turn();
  void init_turn_vectors();
  //given two ints finds if the space is occupied and
  // returns a bool, True if occupied false otherwise
  bool is_occupied(int xx, int yy){
    return p_comp->is_occupied(xx, yy) || p_human->is_occupied(xx,yy);
  }
  //function to free a player
  void free_player(player p){
    //TODO Free the rest of the data in player
    for(int i=0; i < p.get_list().size(); i++){
      delete &(p.get_list()[i]);
    }
    delete &p;
  }
//clears the poke's with 0 hp.
  void clear_dead(){
    vector<int> v_int = p_human->clear_dead();
    vector<int> v_int2 = p_comp->clear_dead();
    for(int i = 0; i < v_int.size(); i++){
      p1.erase(p1.begin()+(v_int[i]));
    }
    for(int i = 0; i < v_int2.size(); i++){
      p2.erase(p2.begin()+(v_int2[i]));
    }
  }
  void set_p_human(player* p){
    p_human = p;
  }
  player get_p_human(){
    return *p_human;
  }
  player get_p_comp(){
    return *p_comp;
  }
  vector<int> get_v_int(int i){
    if(i == 1){
      return p1;
    }
    else{
      return p2;
    }
  }
  //ai functions
  void ai(poke p);
};
//creates computer's champions for the game
void control::populate(player * p_player){
  //first rock type
  rock poke1 = rock(10,2,3,0,5);
  poke1.setMovement(2);
  poke1.setInitiative(2);
  p_player->addPoke(poke1);
  //first paper type
  paper poke2 = paper(6,2,2,0,6);
  poke2.setMovement(4);
  poke2.setInitiative(7);
  p_player->addPoke(poke2);
  //first scissor type
  scissors poke3 = scissors(8,4,3,0,4);
  poke3.setMovement(3);
  poke3.setInitiative(4);
  p_player->addPoke(poke3);
  //second rock type
  rock poke4 = rock(13,2,3,1,4);
  poke4.setMovement(2);
  poke4.setInitiative(3);
  p_player->addPoke(poke4);
  //second paper type
  paper poke5 = paper(6,4,1,1, 5);
  poke5.setMovement(5);
  poke5.setInitiative(6);
  p_player->addPoke(poke5);
  //second scissor type
  scissors poke6 = scissors(6,5,2,0,2);
  poke6.setMovement(2);
  poke6.setInitiative(5);
  p_player->addPoke(poke6);
}
//creates the shop and allows the palyer to pick his pokes
//also calls init_turn_vectors();
vector<poke> control::pickPokes(){
  //TODO finish pickPokes()
  //needs rendering
  shop s1;
  s1.assemble();
  int i = 0;
  while(s1.getGold() > 0){
    s1.display(i);
    //functions here to detect clicks to change i as needed and to change points
  }

//initializes p1 and p2
  init_turn_vectors();
  return s1.get_v2();
}
//decides which poke's turn it is
poke* control::turn(){
//if it is the computers poke then it calls the ai functions
//and returns a null;
//where in the vector it is
  int slot;
//who is in control true= player false = computer
  bool side = true;
//max is the max initiative seen
  int max = 0;
  for(int i =0; i < p1.size(); i++){
    if(p1[i] > max){
      max = p1[i];
      slot = i;
      p1[i] = -2*max;
    }
    else{
      p1[i] =+ p_human->get_list()[i].getInitiative();
    }
  }
  for(int x =0; x < p2.size(); x++){
    if(p2[x] > max){
      max = p2[x];
      slot = x;
      side = false;
      p2[x] = -2 * max;
    }
    else{
      p2[x] =+ p_comp->get_list()[x].getInitiative();
   }
  }
  if(side){
    return &p_human->get_list()[slot];
  }
  else{
    ai(p_comp->get_list()[slot]);
    return NULL;
  }
}
void control::init_turn_vectors(){
  for(int i=0; i < p_human->get_list().size()-1; i++){
    p1[i]= p_human->get_list()[i].getInitiative();
  }
  for(int i=0; i < p_comp->get_list().size()-1; i++){
    p2[i]=p_comp->get_list()[i].getInitiative();
  }
}
void control::ai(poke p){

}
int main(int argc, const char* argv[]){
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}
