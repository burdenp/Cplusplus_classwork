#include <typeinfo>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <math.h>
#include <stdlib.h>
using namespace std;
class news;
class player;
class playerObserver;
string row = ". . . . . . . . . . . . . . .";
vector<string> grid;
void init_grid(){
    for(int i = 0; i < 8; i++){
        grid.push_back(row);
    }
}
const string perm_row = ". . . . . . . . . . . . . . .";
vector<string> perm_grid;
void init_perm_grid(){
    for(int i = 0; i < 8; i++){
        perm_grid.push_back(row);
        }
}
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
	virtual void attack(poke* target);
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
			if(getType() == "s"){
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
			type = "r";
			tired = true;
		}
};
//create sub class paper of type poke.
//paper "champions" are low health, medium strength,
// low armor, high movement, high initiative
class paper: public poke{
	public:
		void attack(poke * target){
			if(getType() == "r"){
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
       		 type = "p";
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
                type = "s";
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
class control{
  player * p_human;
  player * p_player2;
  bool game_on;
  bool turn;
  //for figuring out who goes when
  vector<int> p1, p2;
  public:
  void populate(player* p_player, int i);
  //base initializer
    control(int i){
    player* play1 = new player();
    player* play2 = new player();
    p_human = play1;
    p_player2 = play2;
    game_on = true;
    populate(p_player2,7);
    populate(p_human,0);
    p1;
    p2;
    }
  bool is_game_on(){
    return game_on;
  }
  vector<poke> pickPokes();
  void play();
  void display(vector<string> screen);
  //picks which champions turn it is
  void init_turn_vectors();
  //given two ints finds if the space is occupied and
  // returns a bool, True if occupied false otherwise
  bool is_occupied(int xx, int yy){
    return p_player2->is_occupied(xx, yy) || p_human->is_occupied(xx,yy);
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
    vector<int> v_int2 = p_player2->clear_dead();
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
    return *p_player2;
  }
  vector<int> get_v_int(int i){
    if(i == 1){
      return p1;
    }
    else{
      return p2;
    }
  }
};
//creates computer's champions for the game
void control::populate(player * p_player, int i){
  //first rock type
  rock poke1 = rock(10,2,3,0,5+i);
  poke1.setMovement(2);
  poke1.setInitiative(2);
  p_player->addPoke(poke1);
  //first paper type
  paper poke2 = paper(6,2,2,0,6+i);
  poke2.setMovement(4);
  poke2.setInitiative(7);
  p_player->addPoke(poke2);
  //first scissor type
  scissors poke3 = scissors(8,4,3,0,4+i);
  poke3.setMovement(3);
  poke3.setInitiative(4);
  p_player->addPoke(poke3);
  //second rock type
  rock poke4 = rock(13,2,3,1,4+i);
  poke4.setMovement(2);
  poke4.setInitiative(3);
  p_player->addPoke(poke4);
  //second paper type
  paper poke5 = paper(6,4,1,1, 5+i);
  poke5.setMovement(5);
  poke5.setInitiative(6);
  p_player->addPoke(poke5);
  //second scissor type
  scissors poke6 = scissors(6,5,2,0,2+i);
  poke6.setMovement(2);
  poke6.setInitiative(5);
  p_player->addPoke(poke6);
}
void control::init_turn_vectors(){
  for(int i=0; i < p_human->get_list().size()-1; i++){
    p1[i]= p_human->get_list()[i].getInitiative();
  }
  for(int i=0; i < p_player2->get_list().size()-1; i++){
    p2[i]=p_player2->get_list()[i].getInitiative();
  }
}
void control::play(){
  bool side = true;
  poke* pc;
  if(side = true){
    side = false;
  } else {
    side = true;
  }
  int slot = 0;
  if(side = true){
    while(!p_human->getList()[slot].tired)
    {
        slot++;
    }
  }
  if(side){
    pc = &(p_human->get_list()[slot]);
    int x = pc->getX();
    int y = pc->getY();
    std::string str = "X";
    grid[y].replace(x*2, x*2+1, str);

  }
  else{
    pc = &(p_player2->get_list()[slot]);
    int x = pc->getX();
    int y = pc->getY();
    std::string str = "X";
    grid[y].replace(x*2, x*2+1, str);
  }
  for(int i = 0; i = p_human->get_list().size(); i++){
    int y = p_human->get_list()[i].getY();
    int x = p_human->get_list()[i].getX();
    grid[y].replace(i*2, i*2+1, p_human->get_list()[i].type);
  }
  for(int i = 0; i = p_player2->get_list().size(); i++){
   int y = p_player2->get_list()[i].getY();
   int x = p_player2->get_list()[i].getX();
    if(p_player2->get_list()[i].type == "P"){
        grid[y].replace(i*2, i*2+1, "P");
    }
    else if(p_player2->get_list()[i].getType() == "R"){
        grid[y].replace(i*2, i*2+1, "H");
    } else {
        grid[y].replace(i*2, i*2+1, "G");
    }
  }
  display(grid);
  cout<<"input where you want to move to or attack/n";
  cout<<"input it as 2 ints, X and Y, and separated by a comma/n";
  char* s;
  cin>>s;
  char * token;
  token = strcpy(token, s);
  //tokenize the location
  char* tmp = strtok(token, ",");
  int num = atoi(tmp);
  char * tmp2 = strtok(NULL, ",");
  int num2 = atoi(tmp2);
  while(pc->getMovement()<=
          sqrt(pow(num - pc->getX(),2) + pow(num2 - pc->getY(),2))){
            cout<<"Enter a distance that is within movement range";
            cin>>s;
            token = strcpy(token, s);
            //tokenize the location
            tmp = strtok(token, ",");
            num = atoi(tmp);
            tmp2 = strtok(NULL, ",");
            num2 = atoi(tmp2);
          }
  if(side){
    for(int i = 0; i < p_human->get_list().size(); i++){
        if(num == p_human->get_list()[i].getX() && p_human->get_list()[i].getY() == num2){
            pc->attack(&p_human->get_list()[i]);
        }else{
          std::string str = "X";
          grid[num2].replace(num*2, num*2+1, str);
        }
    }
  }
  else{
    for(int i = 0; i < p_player2->get_list().size(); i++){
        if(num == p_player2->get_list()[i].getX() && p_player2->get_list()[i].getY() == num2){
            pc->attack(&p_player2->get_list()[i]);
        }else{
          std::string str = "X";
          grid[num2].replace(num*2, num*2+1, str);
        }
    }
  display(grid)
  }
  void control::display(vector<string> screen){
        for(int i = 0; i < 8; i++){
            cout<<screen[i];
        }
  }
}
int main(){
    control my_control = control(0);
    cout<<"The game will display a grid based game/n";
    cout<<"A player will control player1 and player2/n";
    cout<<"Player1's pieces will be P, R, S/n";
    cout<<"Player2's pieces will be K, H, G/n";
    cout<<"The currently controlled piece will be switched to an X/n";
    cout<<"P deals double damage to H/n";
    cout<<"K deals double damage to R/n";
    cout<<"R deals double damage to G/n";
    cout<<"H deals double damage to S/n";
    cout<<"S deals double damage to P/n";
    cout<<"G deals double damage to P/n";
    cout<<"Press any key and then enter/n";
    char c;
    cin>>c;
    cout<<"";
    while(my_control.is_game_on()){
        for(int i = 0; i < grid.size(); i++){
            cout<<grid[i];
        }


    }

    return 0;
}
