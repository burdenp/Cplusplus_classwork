#include <iostream>
#include <string>
using namespace std;

//Class for pokemon
class Pokemon
{
private:
	string name;
	double power;
	double height;
	double weight;
	int hit_points;
	
public:
	Pokemon();			//constructor with no parameters
	Pokemon(string n);	//constructor with one parameter
	Pokemon(string n, double p, double h, double w, int hp);	//constructor with multiple parameters
    void set(string n, double p, double h,double w, int hp);
    void set(string n);
    void set(int hp);
    void set();
    void stats() const; 
	string squeal() const; 
};

int main( )
{
    Pokemon poke1, poke2;
    cout << "Pokemon\n";
    poke1.set("charmeleon");
    cout << "poke1 initial statement:\n";
    poke1.stats();
    poke2.set("mewtwo");
    cout << poke2.squeal() << endl;	

    return 0;
}


Pokemon::Pokemon(string n, double p, double h,double w, int hp)
{
    if (!n.empty())
    {
        name=n;
    }
    if (power>0)
    {
        power=p;
    }
    if (height>0)
    {
        height=h;
    }    
	if (weight>0)
    {
        weight=w;
    }    
	if (hit_points>0)
    {
        hit_points=hp;
    }
	
}

Pokemon::Pokemon(string n)
{
    if (!n.empty())
    {
        name=n;
    }
        power=0.0;
        height=0.0;
        weight=0.0;
        hit_points=0;
		
}

Pokemon::Pokemon()
{
        name="Pokemon";
        power=0.0;
        height=0.0;
        weight=0.0;
        hit_points=0;
		
}

void Pokemon::set(string n, double p, double h,double w, int hp)
{
    if (!n.empty())
    {
        name=n;
    }
    if (power>0)
    {
        power=p;
    }
    if (height>0)
    {
        height=h;
    }    
	if (weight>0)
    {
        weight=w;
    }    
	if (hit_points>0)
    {
        hit_points=hp;
    }
	
}

void Pokemon::set(string n)
{
    if (!n.empty())
    {
        name=n;
    }
        power=0.0;
        height=0.0;
        weight=0.0;
        hit_points=0;
	
}

void Pokemon::set()
{
        name="Pokemon";
        power=0.0;
        height=0.0;
        weight=0.0;
        hit_points=0;
		
}

void Pokemon::stats() const
{
        cout<< "name " << name << endl;
        cout<< "power " << power << endl;
        cout<< "height " << height << endl;
        cout<< "weight " << weight << endl;
        cout<< "hit_points " << hit_points << endl;

}

	 
string Pokemon::squeal() const
{

	return name+" Oink, Oink";
}
