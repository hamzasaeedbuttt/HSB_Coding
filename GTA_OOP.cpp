#include <iostream>
#include <ctime>
#include <cmath>
#include <string>
#include <windows.h>
using namespace std;


class Car
{
public:
    string name;
    int price;
    Car(){}
    Car(int price, string name)
    {
        this->price = price;
        this->name = name;
    }
    string car_name()
    {
        return name;
    }
    int car_price()
    {
        return price;
    }       
};

class Weapon
{
public:
    string name;
    int price;
    Weapon(){}
    Weapon(int price, string name)
    {
        this->price = price;
        this->name = name;
    }
    string weapon_name()
    {
        return name; 
    }
    int weapon_price()
    {
        return price;
    }   
};

class Player
{
public:
    int cash;
    int health;
    int posx;
    int posy;
    int damage;
    string wanted;
    Car c;
    Weapon w;
    Player(int cash, int health, int posx, int posy, int damage, string wanted, Car c, Weapon w)
    {
        this->cash=cash;
        this->health=health;
        this->posx=posx;
        this->posy=posy;
        this->damage=damage;
        this->wanted=wanted;
        this->c=c;
        this->w=w;
    }
};


void tutorial(char a, Player &p, int t_health, int t_dmg);
void texter(string a);
bool exception_move(int posx, int posy, char a);
bool out_of_bounds(int posx, int posy, char a);
void wanted(int &t_dmg, string &w);
void movement(Player &p,char m, int &t_health, int &t_dmg);
void weaponcheck(int weapon, string &wpn, int &dmg);
void carcheck(int car, string &caro);
void home(int &health, int t_health);
void barbershop(int &cash);
void cars(int &cash, int &car);
void bank(int &cash, int &t_dmg);
void ammunitions(int &cash, int &weapon, int &t_dmg);
void idlewood(int &cash, int dmg, int &t_dmg, int &health);
void menu(int &cash, int &health, int t_health);
void gym(int health, int &t_health, int &cash);
void interaction(Player &p, int &t_health, int &t_dmg);
int police_encounter (int t_dmg);
bool healthcheck(int i, int j);
void police(int x,int &t_dmg, int damage, int health);
void map(Player &p, int& t_health);

int main()
{
    // Car c1(100, "Bike");
    // Car c2(500, "Ferarri");
    // Car c3(1000, "Bugatti");
    // Weapon w1(1000, "AK-47");
    // Weapon w2(750, "AP Pistol");
    // Weapon w3(200, "Stun Gun");
    // Weapon w4(500, "SNS Pistol");
    Car c1(0, " "), c2(0, " ");
    Weapon w1(0, " "), w2(0, " ");
    Player p(5000, 100, 2, 1, 0, " ", c1, w1);
    Player police(0, 100, 0, 0, 0, " ", c2, w2);
    char a;
    int t_health=100;
    int t_dmg=0;
    char i, m;
    // tutorial(a, p, t_health, t_dmg);
    // map(p, t_health);
    // char m;
    // cin>>m;
    // interaction(p, t_health, t_dmg);
    // movement(p, m, t_health, t_dmg);
    cout<<"Welcome to Grand Theft Auto: San Andreas prototype made in C++ by SHOCKSTAR GAMES.\nIf you would like a tutorial press 1\nif you want to jump straight in press any other button\nto exit press 0:";
    cin>>i;
    if (i=='0')
    {
    return 0;
    }
    else
   {
    tutorial(i, p, t_health, t_dmg);    
   }
   map(p, t_health);
   cin>>m;
   if(m=='0')
   {
    return 0; 
   }
   else 
   {
    movement(p, m, t_health, t_dmg);
   }

}

void texter(string a)
{
    int i=0;
    for(a[i] != '\0'; i<a.length(); i++)
    {
        cout << a[i];
        Sleep(50);
    }
}

void tutorial(char a, Player &p, int t_health, int t_dmg){



    int c=0, b=0 ,h=100,x=100, d=2000;
    string f=" ",g=" ", w=" ";
    
    if(a=='1')
    {
        string tutorial_text1="Here's a quick tutorial for you:\n This is a small map of Los Santos with 9 interactive points of interest\n\0";
        string tutorial_text2="Your position on the map will be indicated by *\n You can move using W A S D keys and exit the game at any point by entering 0\n\0";
        string tutorial_text3="GROVE STREET: Regenerates your health\n REECE'S SALON: you can purchase 1 of 4 haircuts\n WANG CARS: You can purchase 1 of 3 vehicles\n BANK: You can loot the bank for extra money \n AMMU NATIONS: You can purchase 1 of 4 weapons which give you the ability to inflict damage.\n IDLEWOOD: this is enemy territory. You can fight enemies and take their money\n BURGER SHOT: You can restore health by pruchasing food items\n GYM: You can increase your total health by choosing 1 of 3 workouts\n\0";
        texter(tutorial_text1);
        system("pause");
        map(p, t_health);
        system("pause");
        texter(tutorial_text2);
        system("pause");
        texter(tutorial_text3);
        system("pause");
        cout<<"ENJOY : )\n";
        system("pause");
    }
    else
    {
        cout<<"ENJOY : )\n";
        system("pause");

    }
}


bool exception_move(int posx, int posy, char a)
{
 if((posy==2 || posy==4) && (posx==3 || posx==1 || posx==5))
 {
    if(a=='s' || a=='w')
    {
        return true;
    }
    else
    {
        return false;
    }
 }
 else
 {
    return false;
 }  
}


bool out_of_bounds(int posx, int posy, char a)
{
    if((posy==1 || posy==5) || (posx==1 || posx==5))
    {
        if ((posy==1 && a=='w') || (posy==5 && a=='s') || (posx==1 && a=='a') || (posx==5 && a=='d') )
        {
            return true;
            
        }
        else 
        {
            return false;
        }
    }
    else 
    {
        return false;
    }
}

void wanted(int &t_dmg, string &w)
{
    if (t_dmg>50)
    {
        w="* * * * *";
    }
    else
    {
        switch(t_dmg)
        {
            case 0:
            w=" ";
            break;

            case 10:
            w="*";
            break;

            case 20:
            w="* *";
            break;

            case 30:
            w="* * *";
            break;
            
            case 40:
            w="* * * *";
            break;
            
            case 50:
            w="* * * * *";
            break;
        }
    }
}


void movement(Player &p,char m, int &t_health, int &t_dmg)
{
    char b;
    int cop_h=150;
    cin>>b;
    // movement(p, m, t_health, t_dmg);
    wanted(t_dmg, p.wanted);
    if (exception_move(p.posx,p.posy,b) || out_of_bounds(p.posx,p.posy,b))
    {
        cout<<"invalid move\n";
        cin>>b;
        // movement(p,  m, t_health, t_dmg);
    }
    else
    {
        if(b == '0')
        {
            return;
        }
        else if( b =='s')
        {
            p.posy++;
            map(p, t_health);
        } 
        else if (b=='w') 
        {
            p.posy--;
            map(p, t_health);
        }
        else if (b=='a' || b=='d') 
        {
            if (p.posy==3 || p.posy==5 || p.posy==1)
            {
                cout<<"Invalid move\n";
            }
            else 
            {
                if (b=='a')
                {
                    p.posx--;
                    map(p, t_health);
                }
                else if (b=='d')
                {
                    p.posx++;
                    map(p, t_health);
                }
            }
        }
        int x=police_encounter (t_dmg);
        police(x,t_dmg,p.damage, p.health);
        interaction(p, t_health, t_dmg);
        weaponcheck(p.w.price, p.w.name, p.damage);
        carcheck(p.c.price, p.c.name);
        cin>>b;
        movement(p, b, t_health, t_dmg);
    }
}  


void weaponcheck(int weapon, string &wpn, int &dmg)
{
    switch(weapon)
    {
        case 0 :
        wpn=" ";
        break;

        case 1 :
        wpn="AK-47";
        dmg=75;
        break;

        case 2 :
        wpn="AP Pistol";
        dmg=50;
        break;

        case 3:
        wpn="Stun Gun";
        dmg=10;
        break;

        case 4 :
        wpn="SNS Pistol";
        dmg=20;
        break;
    }
}

void carcheck(int car, string &caro)
{
    switch(car)
    {
        case 0 :
        caro=" ";
        break;

        case 1 :
        caro="Bike";
        break;

        case 2 :
        caro="Ferarri";
        break;

        case 3:
        caro="Bugatti";
        break;
    }
}


void home(int &health, int t_health)
{
    health=t_health;
    cout<<"Welcome Home. Health has been restored.\n";
}

void barbershop(int &cash)
{
    int choice;
    cout<<"Barbershop options\n 1.big afro : $15\n 2.Pop Smoke style braids : $40\n 3.buzzcut : $10\n 4.low-fade : $15\n choose your haircut:";
    cin>>choice;
    switch (choice)
    {
        case 1 :
        cash= cash-15;
        cout<<"nice afro\n";
        break;

        case 2 :
        cash= cash-40;
        cout<<"nice braids\n";
        break;

        case 3 :
        cash= cash-10;
        cout<<"nice cut\n";
        break;

        case 4 :
        cash= cash-15;
        cout<<"nice fade\n";
        break;
    }
}

void cars(int &cash, int &car)
{
    int choice;
    cout<<"WANG CARS\n";
    cout<<"1.bike : $100\n 2.Ferarri : $500\n 3.Bugatti : $1000\n choose your car:";
    cin>>choice;
    switch (choice)
    {
        case 0:
        break;

        case 1 :
        cash= cash-100;
        car=1;
        cout<<"You have bike now\n";
        break;

        case 2 :
        cash= cash-500;
        car=2;
        cout<<"ferarri\n";
        break;

        case 3 :
        cash= cash-1000;
        car=3;
        cout<<"bugatti\n";
        break;
    }
}

void bank(int &cash, int &t_dmg)
{
    int i=0;
    int g;
    int key= rand()%10;
    string a="You have 3 tries to guess the key number(b/w 0 & 9)\n\0", b="Enter your guess:\n\0";
    texter(a);
    do
    {
        texter(b);
        cin>>g;
        i++;
        if (g==key)
        break;
        else
        continue;
    }
    while(i<3);
    if(g==key)
    {
        switch(i)
        {
            case 1:
            cash+=500;
            cout<<"Good heist! $500 obtained\n";
            break;
            
            case 2:
            cash+=250;
            cout<<"Good heist! $250 obtained\n";
            t_dmg+=10;
            break;
            
            case 3:
            cash+=50;
            cout<<"Good heist! $50 obtained\n";
            t_dmg+=20;
            break;
        }
    }
    else
    {
        cout<<"heist failed :(";
        t_dmg+=20;
    }

}

void ammunitions(int &cash, int &weapon, int &t_dmg)
{
    int choice;
    cout<<"Ammunitions options\n";
    cout<<"1.AK-47 : $1000\n";
    cout<<"2.AP Pistol : $750\n";
    cout<<"3.Stun Gun : $200\n";
    cout<<"4.SNS Pistol : $500\n";
    cin>>choice;
    switch (choice)
    {
        case 1 :
        cash= cash-1000;
        weapon=1;
        cout<<"AK-47 equipped\n";
        break;

        case 2 :
        cash= cash-750;
        weapon=2;
        cout<<"AP Pistol equipped\n";
        break;

        case 3 :
        cash= cash-200;
        weapon=3;
        cout<<"Stun Gun equipped\n";
        break;

        case 4 :
        cash= cash-500;
        weapon=4;
        cout<<"SNS Pistol equipped\n";
        break;
    }
}

void idlewood(int &cash, int dmg, int &t_dmg, int &health)
{
    int y;
    int opp_h=150;
    int player=health;
    string a="You are fighting an opp\n\0"; 
    texter(a);
    
    
    do
    {
        int d=rand()%3;
        cout<< "OPP HEALTH= "<<opp_h<<"       "<<"YOUR HEALTH= "<<player<<endl;
        cout<<"Press a number from 0 to 2 to attack!!\n";
        cin>>y;
        if(y==d)
        {

            string c="You hit the opp for \0"; 
            opp_h-=dmg;
            t_dmg+=10;
            texter(c);
            cout<<dmg<<endl;
        }
        else
        {
            player-=20;
            string b="You took 20 damage!\n\0";
            texter(b);
        }

    }
    while(healthcheck(opp_h, player)==0);
    
    health=player;
    if(health==0)
    {
        cout<<"WASTED\n";
        exit(0);
    }
    else if(opp_h==0)
    {
        cout<<"you win!!! $1000 obtained press W to move back up\n";
        cash+=1000;
        return;
    }
}

void menu(int &cash, int &health, int t_health)
{
    int choice;
    if (health<t_health)
    {
        cout<<"Burger Shot Menu \n 1.chicken burger : $30\n 2.fries : $15\n 3.nuggets : $10\n 4.chocolate milkshake : $20\n";
        cin>>choice;
        switch (choice)
        {
            case 1 :
            cash= cash-30;
            health= health+30;
            cout<<"30 health restored\n";
            break;
            
            case 2 :
            cash= cash-15;
            health+=15;
            cout<<"15 health restored\n";
            break;

            case 3 :
            cash= cash-10;
            health+=10;
            cout<<"10 health restored\n";
            break;
            
            case 4 :
            cash= cash-20;
            health+=20;
            cout<<"20 health restored\n";
            break;
        }
    }
    else
    {
        cout<<"You have sufficient health\n";
    }
}

void gym(int health, int &t_health, int &cash)
{
    int c;
    if(health<t_health)
    {
        cout<<"You need to restore health to work out\n";
    }
    else
    {
        cout<<"1.Light Workout $10\n 2.Medium Workout $25\n 3.Heavy Workout $50\n";
        cin>>c;
        switch(c)
        {
            case 1:
            cash-=10;
            t_health+=10;
            health+=10;
            cout<<" Total Health increased by 10\n";
            break;

            case 2:
            cash-=25;
            t_health+=25;
            health+=25;
            cout<<" Total Health increased by 25\n";
            break;

            case 3:
            cash-=50;
            t_health+=50;
            health+=50;
            cout<<" Total Health increased by 50\n";
            break;
        }
    }
}


void interaction(Player &p, int &t_health, int &t_dmg)
{
    string m="moving\n";
    char c;
    if (p.posy==1 && p.posx==2)
    {
        string a="Press q to enter barbershop. Press e to keep moving\n";
        texter(a);
        cin>>c;
        if(c =='q' )
        {
            barbershop(p.cash);
        }
        else if(c=='e')
        {
            texter(m);
            movement(p, c, t_health, t_dmg);
        }
    }
    else if (p.posy==1 && p.posx==4)
    {
        string a="Press q to enter your home. Press e to keep moving\n";
        texter(a);
        cin>>c;
        if (c == 'q')
        {
            home(p.health, t_health);
        }
        else if (c == 'e')
        {
            texter(m);
            
        }
    }
    else if (p.posy==3 && p.posx==2)
    {
        string a="You are between Wang Cars and The Bank\n Press l to enter Wang Cars. Press r to enter The Bank\n Press e to keep moving\n";
        texter(a);
        cin>>c;
        if (c =='l')
        {
            cars(p.cash, p.c.price);
        }
        else if (c =='r')
        {
            bank(p.cash, t_dmg);
        }
        else if (c == 'e')
        {
            texter(m);
            
        }
    }
    else if (p.posy==3 && p.posx==4)
    {
        string a="You are between The Bank and Ammunitions\n Press l to enter The Bank. Press r to enter Ammunitions\n Press e to keep moving\n";
        texter (a);
        cin>>c;
        if (c == 'l')
        {
            bank(p.cash, t_dmg);
        }
        else if (c == 'r')
        {
            ammunitions(p.cash, p.w.price, t_dmg);
        }
        else if (c == 'e')
        {
            texter(m);
        }
    }
    else if (p.posy==5 && p.posx==2)
    {
        string a="You are between Idlewood and Burger Shot\n Press l to enter enemy territory. Press r to enter Burger Shot\n Press e to keep moving\n";
        texter(a);
        cin>>c;
        if (c == 'l')
        {
            idlewood(p.cash, p.damage, t_dmg, p.health);
        }
        else if (c == 'r')
        {
            menu(p.cash,p.health, t_health);
        }
        else if (c == 'e')
        {
            texter(m);
        }
    }
    else if (p.posy==5 && p.posx==4)
    {
        string a="You are between the Gym and Burger Shot\n Press r to enter the gym. Press l to enter Burger Shot.\n Press e to keep moving\n";
        texter (a);
        cin>>c;
        if (c == 'r')
        {
            gym(p.health, t_health, p.cash);
        }
        else if (c == 'l')
        {
            menu(p.cash,p.health, t_health);
        }
        else if (c == 'e')
        {
            texter(m);
        }
    }


}

int police_encounter (int t_dmg)
{
    int x=0;
    if(t_dmg>50)
    {
        x=1;
    }
       switch(t_dmg)
        {
            case 0:
            x=0;
            break;

            case 10:
            x=rand()%5;
            break;

            case 20:
            x=rand()%5;
            break;

            case 30:
            x=rand()%4;
            break;
            
            case 40:
            x=rand()%3;
            break;
            
            case 50:
            x=rand()%2;
            break;
        }
        return x;
}


bool healthcheck(int i, int j)
{
    if(i==0 || j==0)
    {
        return 1;
    }
    else
    {
        return 0;
    }


}

void police(int x,int &t_dmg, int damage, int health)
{
    int cop_h=150;
    int player=health;
    int y;
    do
    {
        if(x==1)
        {
            string v="You have run in to the police\n\0";
            texter(v);
            cout<< "COP HEALTH= "<<cop_h<<"       "<<"YOUR HEALTH= "<<player<<endl;
            int d=rand()%3;
            cout<<"Press a number from 0 to 2 to attack!!\n\0";
            
            cin>>y;
            if(y==d)
            {
                string c="You hit the cop for \0"; 
                cop_h-=damage;
                t_dmg+=10;
                texter(c);
                cout<<damage<<endl;
            }
            else
            {
                player-=20;
                string b="You took 20 damage!\n\0";
                texter(b);
            }
        }
        else
        {
            return;
        }
    }
    while(healthcheck(cop_h, health)==0);

    health=player;

    if(player==0)
    {
        cout<<"BUSTED\n";
        exit(0);
    }
    else if(cop_h==0)
    {
        cout<<"you got away!\n";
        return;
    }
}


void map(Player &p, int& t_health)
{
    system("cls");
    if (p.posy==0 && p.posx==0)
    {
     cout<<" ______________________________________________  HEALTH = "<<p.health<<"/"<<t_health<<endl;
     cout<<"|  REECE'S | |                    | |          | $$ = "<<p.cash<<endl;
     cout<<"|   HAIR   | |     LOS SANTOS     | |  GROVE   | Vehicle = "<<p.c.car_name()<<endl;
     cout<<"| & FACIAL | |  POLICE DEPARTMENT | |  STREET  | Weapon = "<<p.w.weapon_name()<<endl;
     cout<<"|  SALON   | |                    | |          | Wanted = "<<p.wanted<<endl;
     cout<<"|__________| |____________________| |__________|\n";
     cout<<"|                                              |\n";
     cout<<"|__________   ____________________   __________|\n";
     cout<<"|          | |                    | |          |\n";
     cout<<"|  WANG    | |      B A N K       | |  AMMU    |\n";
     cout<<"|  CARS    | |         $$         | | NATIONS  |\n";
     cout<<"|__________| |____________________| |__________|\n";
     cout<<"|                                              |\n";
     cout<<"|__________   ____________________   __________|\n";
     cout<<"|          | |                    | |          |\n";
     cout<<"| IDLEWOOD | |    BURGER SHOT     | |   GYM    |\n";
     cout<<"|__________|_|____________________|_|__________|\n";

    }
    if (p.posy==1)
    {
        if(p.posx==2)
        {
         cout<<" ______________________________________________  HEALTH = "<<p.health<<"/"<<t_health<<endl;
         cout<<"|  REECE'S | |                    | |          | $$ = "<<p.cash<<endl;
         cout<<"|   HAIR   | |     LOS SANTOS     | |  GROVE   | Vehicle = "<<p.c.car_name()<<endl;
         cout<<"| & FACIAL |*|  POLICE DEPARTMENT | |  STREET  | Weapon = "<<p.w.weapon_name()<<endl;
         cout<<"|  SALON   | |                    | |          | Wanted = "<<p.wanted<<endl;
         cout<<"|__________| |____________________| |__________|\n";
         cout<<"|                                              |\n";
         cout<<"|__________   ____________________   __________|\n";
         cout<<"|          | |                    | |          |\n";
         cout<<"|  WANG    | |      B A N K       | |  AMMU    |\n";
         cout<<"|  CARS    | |         $$         | | NATIONS  |\n";
         cout<<"|__________| |____________________| |__________|\n";
         cout<<"|                                              |\n";
         cout<<"|__________   ____________________   __________|\n";
         cout<<"|          | |                    | |          |\n";
         cout<<"| IDLEWOOD | |    BURGER SHOT     | |   GYM    |\n";
         cout<<"|__________|_|____________________|_|__________|\n";
        }
        else if(p.posx==4)
        {
         cout<<" ______________________________________________  HEALTH = "<<p.health<<"/"<<t_health<<endl;
         cout<<"|  REECE'S | |                    | |          | $$ = "<<p.cash<<endl;
         cout<<"|   HAIR   | |     LOS SANTOS     | |  GROVE   | Vehicle = "<<p.c.car_name()<<endl;
         cout<<"| & FACIAL | |  POLICE DEPARTMENT |*|  STREET  | Weapon = "<<p.w.weapon_name()<<endl;
         cout<<"|  SALON   | |                    | |          | Wanted = "<<p.wanted<<endl;
         cout<<"|__________| |____________________| |__________|\n";
         cout<<"|                                              |\n";
         cout<<"|__________   ____________________   __________|\n";
         cout<<"|          | |                    | |          |\n";
         cout<<"|  WANG    | |      B A N K       | |  AMMU    |\n";
         cout<<"|  CARS    | |         $$         | | NATIONS  |\n";
         cout<<"|__________| |____________________| |__________|\n";
         cout<<"|                                              |\n";
         cout<<"|__________   ____________________   __________|\n";
         cout<<"|          | |                    | |          |\n";
         cout<<"| IDLEWOOD | |    BURGER SHOT     | |   GYM    |\n";
         cout<<"|__________|_|____________________|_|__________|\n";
        }
        
    }
    else if (p.posy==3)
    {
        if(p.posx==2)
        {
         cout<<" ______________________________________________  HEALTH = "<<p.health<<"/"<<t_health<<endl;
         cout<<"|  REECE'S | |                    | |          | $$ = "<<p.cash<<endl;
         cout<<"|   HAIR   | |     LOS SANTOS     | |  GROVE   | Vehicle = "<<p.c.car_name()<<endl;
         cout<<"| & FACIAL | |  POLICE DEPARTMENT | |  STREET  | Weapon = "<<p.w.weapon_name()<<endl;
         cout<<"|  SALON   | |                    | |          | Wanted = "<<p.wanted<<endl;
         cout<<"|__________| |____________________| |__________|\n";
         cout<<"|                                              |\n";
         cout<<"|__________   ____________________   __________|\n";
         cout<<"|          | |                    | |          |\n";
         cout<<"|  WANG    |*|      B A N K       | |  AMMU    |\n";
         cout<<"|  CARS    | |         $$         | | NATIONS  |\n";
         cout<<"|__________| |____________________| |__________|\n";
         cout<<"|                                              |\n";
         cout<<"|__________   ____________________   __________|\n";
         cout<<"|          | |                    | |          |\n";
         cout<<"| IDLEWOOD | |    BURGER SHOT     | |   GYM    |\n";
         cout<<"|__________|_|____________________|_|__________|\n";
        }
        else if(p.posx==4)
        {
         cout<<" ______________________________________________  HEALTH = "<<p.health<<"/"<<t_health<<endl;
         cout<<"|  REECE'S | |                    | |          | $$ = "<<p.cash<<endl;
         cout<<"|   HAIR   | |     LOS SANTOS     | |  GROVE   | Vehicle = "<<p.c.car_name()<<endl;
         cout<<"| & FACIAL | |  POLICE DEPARTMENT | |  STREET  | Weapon = "<<p.w.weapon_name()<<endl;
         cout<<"|  SALON   | |                    | |          | Wanted = "<<p.wanted<<endl;
         cout<<"|__________| |____________________| |__________|\n";
         cout<<"|                                              |\n";
         cout<<"|__________   ____________________   __________|\n";
         cout<<"|          | |                    | |          |\n";
         cout<<"|  WANG    | |      B A N K       |*|  AMMU    |\n";
         cout<<"|  CARS    | |         $$         | | NATIONS  |\n";
         cout<<"|__________| |____________________| |__________|\n";
         cout<<"|                                              |\n";
         cout<<"|__________   ____________________   __________|\n";
         cout<<"|          | |                    | |          |\n";
         cout<<"| IDLEWOOD | |    BURGER SHOT     | |   GYM    |\n";
         cout<<"|__________|_|____________________|_|__________|\n";
        }
        
    }
    else if (p.posy==5)
    {
        if(p.posx==2)
        {
         cout<<" ______________________________________________  HEALTH = "<<p.health<<"/"<<t_health<<endl;
         cout<<"|  REECE'S | |                    | |          | $$ = "<<p.cash<<endl;
         cout<<"|   HAIR   | |     LOS SANTOS     | |  GROVE   | Vehicle = "<<p.c.car_name()<<endl;
         cout<<"| & FACIAL | |  POLICE DEPARTMENT | |  STREET  | Weapon = "<<p.w.weapon_name()<<endl;
         cout<<"|  SALON   | |                    | |          | Wanted = "<<p.wanted<<endl;
         cout<<"|__________| |____________________| |__________|\n";
         cout<<"|                                              |\n";
         cout<<"|__________   ____________________   __________|\n";
         cout<<"|          | |                    | |          |\n";
         cout<<"|  WANG    | |      B A N K       | |  AMMU    |\n";
         cout<<"|  CARS    | |         $$         | | NATIONS  |\n";
         cout<<"|__________| |____________________| |__________|\n";
         cout<<"|                                              |\n";
         cout<<"|__________   ____________________   __________|\n";
         cout<<"|          | |                    | |          |\n";
         cout<<"| IDLEWOOD |*|    BURGER SHOT     | |   GYM    |\n";
         cout<<"|__________|_|____________________|_|__________|\n";
        }
        else if(p.posx==4)
        {
         cout<<" ______________________________________________  HEALTH = "<<p.health<<"/"<<t_health<<endl;
         cout<<"|  REECE'S | |                    | |          | $$ = "<<p.cash<<endl;
         cout<<"|   HAIR   | |     LOS SANTOS     | |  GROVE   | Vehicle = "<<p.c.car_name()<<endl;
         cout<<"| & FACIAL | |  POLICE DEPARTMENT | |  STREET  | Weapon = "<<p.w.weapon_name()<<endl;
         cout<<"|  SALON   | |                    | |          | Wanted = "<<p.wanted<<endl;
         cout<<"|__________| |____________________| |__________|\n";
         cout<<"|                                              |\n";
         cout<<"|__________   ____________________   __________|\n";
         cout<<"|          | |                    | |          |\n";
         cout<<"|  WANG    | |      B A N K       | |  AMMU    |\n";
         cout<<"|  CARS    | |         $$         | | NATIONS  |\n";
         cout<<"|__________| |____________________| |__________|\n";
         cout<<"|                                              |\n";
         cout<<"|__________   ____________________   __________|\n";
         cout<<"|          | |                    | |          |\n";
         cout<<"| IDLEWOOD | |    BURGER SHOT     |*|   GYM    |\n";
         cout<<"|__________|_|____________________|_|__________|\n";
        }
        
    }
    else if (p.posy==2)
    {
        if(p.posx==1)
        {
         cout<<" ______________________________________________  HEALTH = "<<p.health<<"/"<<t_health<<endl;
         cout<<"|  REECE'S | |                    | |          | $$ = "<<p.cash<<endl;
         cout<<"|   HAIR   | |     LOS SANTOS     | |  GROVE   | Vehicle = "<<p.c.car_name()<<endl;
         cout<<"| & FACIAL | |  POLICE DEPARTMENT | |  STREET  | Weapon = "<<p.w.weapon_name()<<endl;
         cout<<"|  SALON   | |                    | |          | Wanted = "<<p.wanted<<endl;
         cout<<"|__________| |____________________| |__________|\n";
         cout<<"|     *                                        |\n";
         cout<<"|__________   ____________________   __________|\n";
         cout<<"|          | |                    | |          |\n";
         cout<<"|  WANG    | |      B A N K       | |  AMMU    |\n";
         cout<<"|  CARS    | |         $$         | | NATIONS  |\n";
         cout<<"|__________| |____________________| |__________|\n";
         cout<<"|                                              |\n";
         cout<<"|__________   ____________________   __________|\n";
         cout<<"|          | |                    | |          |\n";
         cout<<"| IDLEWOOD | |    BURGER SHOT     | |   GYM    |\n";
         cout<<"|__________|_|____________________|_|__________|\n";
        }
        else if(p.posx==2)
        {
         cout<<" ______________________________________________  HEALTH = "<<p.health<<"/"<<t_health<<endl;
         cout<<"|  REECE'S | |                    | |          | $$ = "<<p.cash<<endl;
         cout<<"|   HAIR   | |     LOS SANTOS     | |  GROVE   | Vehicle = "<<p.c.car_name()<<endl;
         cout<<"| & FACIAL | |  POLICE DEPARTMENT | |  STREET  | Weapon = "<<p.w.weapon_name()<<endl;
         cout<<"|  SALON   | |                    | |          | Wanted = "<<p.wanted<<endl;
         cout<<"|__________| |____________________| |__________|\n";
         cout<<"|           *                                  |\n";
         cout<<"|__________   ____________________   __________|\n";
         cout<<"|          | |                    | |          |\n";
         cout<<"|  WANG    | |      B A N K       | |  AMMU    |\n";
         cout<<"|  CARS    | |         $$         | | NATIONS  |\n";
         cout<<"|__________| |____________________| |__________|\n";
         cout<<"|                                              |\n";
         cout<<"|__________   ____________________   __________|\n";
         cout<<"|          | |                    | |          |\n";
         cout<<"| IDLEWOOD | |    BURGER SHOT     | |   GYM    |\n";
         cout<<"|__________|_|____________________|_|__________|\n";
        }
        else if(p.posx==3)
        {
         cout<<" ______________________________________________  HEALTH = "<<p.health<<"/"<<t_health<<endl;
         cout<<"|  REECE'S | |                    | |          | $$ = "<<p.cash<<endl;
         cout<<"|   HAIR   | |     LOS SANTOS     | |  GROVE   | Vehicle = "<<p.c.car_name()<<endl;
         cout<<"| & FACIAL | |  POLICE DEPARTMENT | |  STREET  | Weapon = "<<p.w.weapon_name()<<endl;
         cout<<"|  SALON   | |                    | |          | Wanted = "<<p.wanted<<endl;
         cout<<"|__________| |____________________| |__________|\n";
         cout<<"|                      *                       |\n";
         cout<<"|__________   ____________________   __________|\n";
         cout<<"|          | |                    | |          |\n";
         cout<<"|  WANG    | |      B A N K       | |  AMMU    |\n";
         cout<<"|  CARS    | |         $$         | | NATIONS  |\n";
         cout<<"|__________| |____________________| |__________|\n";
         cout<<"|                                              |\n";
         cout<<"|__________   ____________________   __________|\n";
         cout<<"|          | |                    | |          |\n";
         cout<<"| IDLEWOOD | |    BURGER SHOT     | |   GYM    |\n";
         cout<<"|__________|_|____________________|_|__________|\n";
        }
        else if(p.posx==4)
        {
         cout<<" ______________________________________________  HEALTH = "<<p.health<<"/"<<t_health<<endl;
         cout<<"|  REECE'S | |                    | |          | $$ = "<<p.cash<<endl;
         cout<<"|   HAIR   | |     LOS SANTOS     | |  GROVE   | Vehicle = "<<p.c.car_name()<<endl;
         cout<<"| & FACIAL | |  POLICE DEPARTMENT | |  STREET  | Weapon = "<<p.w.weapon_name()<<endl;
         cout<<"|  SALON   | |                    | |          | Wanted = "<<p.wanted<<endl;
         cout<<"|__________| |____________________| |__________|\n";
         cout<<"|                                  *           |\n";
         cout<<"|__________   ____________________   __________|\n";
         cout<<"|          | |                    | |          |\n";
         cout<<"|  WANG    | |      B A N K       | |  AMMU    |\n";
         cout<<"|  CARS    | |         $$         | | NATIONS  |\n";
         cout<<"|__________| |____________________| |__________|\n";
         cout<<"|                                              |\n";
         cout<<"|__________   ____________________   __________|\n";
         cout<<"|          | |                    | |          |\n";
         cout<<"| IDLEWOOD | |    BURGER SHOT     | |   GYM    |\n";
         cout<<"|__________|_|____________________|_|__________|\n";
        }
        else if(p.posx==5)
        {
         cout<<" ______________________________________________  HEALTH = "<<p.health<<"/"<<t_health<<endl;
         cout<<"|  REECE'S | |                    | |          | $$ = "<<p.cash<<endl;
         cout<<"|   HAIR   | |     LOS SANTOS     | |  GROVE   | Vehicle = "<<p.c.car_name()<<endl;
         cout<<"| & FACIAL | |  POLICE DEPARTMENT | |  STREET  | Weapon = "<<p.w.weapon_name()<<endl;
         cout<<"|  SALON   | |                    | |          | Wanted = "<<p.wanted<<endl;
         cout<<"|__________| |____________________| |__________|\n";
         cout<<"|                                        *     |\n";
         cout<<"|__________   ____________________   __________|\n";
         cout<<"|          | |                    | |          |\n";
         cout<<"|  WANG    | |      B A N K       | |  AMMU    |\n";
         cout<<"|  CARS    | |         $$         | | NATIONS  |\n";
         cout<<"|__________| |____________________| |__________|\n";
         cout<<"|                                              |\n";
         cout<<"|__________   ____________________   __________|\n";
         cout<<"|          | |                    | |          |\n";
         cout<<"| IDLEWOOD | |    BURGER SHOT     | |   GYM    |\n";
         cout<<"|__________|_|____________________|_|__________|\n";
        }
        
    }
    else if (p.posy==4)
    {
        if(p.posx==1)
        {
         cout<<" ______________________________________________  HEALTH = "<<p.health<<"/"<<t_health<<endl;
         cout<<"|  REECE'S | |                    | |          | $$ = "<<p.cash<<endl;
         cout<<"|   HAIR   | |     LOS SANTOS     | |  GROVE   | Vehicle = "<<p.c.car_name()<<endl;
         cout<<"| & FACIAL | |  POLICE DEPARTMENT | |  STREET  | Weapon = "<<p.w.weapon_name()<<endl;
         cout<<"|  SALON   | |                    | |          | Wanted = "<<p.wanted<<endl;
         cout<<"|__________| |____________________| |__________|\n";
         cout<<"|                                              |\n";
         cout<<"|__________   ____________________   __________|\n";
         cout<<"|          | |                    | |          |\n";
         cout<<"|  WANG    | |      B A N K       | |  AMMU    |\n";
         cout<<"|  CARS    | |         $$         | | NATIONS  |\n";
         cout<<"|__________| |____________________| |__________|\n";
         cout<<"|    *                                         |\n";
         cout<<"|__________   ____________________   __________|\n";
         cout<<"|          | |                    | |          |\n";
         cout<<"| IDLEWOOD | |    BURGER SHOT     | |   GYM    |\n";
         cout<<"|__________|_|____________________|_|__________|\n";
        }
        else if(p.posx==2)
        {
         cout<<" ______________________________________________  HEALTH = "<<p.health<<"/"<<t_health<<endl;
         cout<<"|  REECE'S | |                    | |          | $$ = "<<p.cash<<endl;
         cout<<"|   HAIR   | |     LOS SANTOS     | |  GROVE   | Vehicle = "<<p.c.car_name()<<endl;
         cout<<"| & FACIAL | |  POLICE DEPARTMENT | |  STREET  | Weapon = "<<p.w.weapon_name()<<endl;
         cout<<"|  SALON   | |                    | |          | Wanted = "<<p.wanted<<endl;
         cout<<"|__________| |____________________| |__________|\n";
         cout<<"|                                              |\n";
         cout<<"|__________   ____________________   __________|\n";
         cout<<"|          | |                    | |          |\n";
         cout<<"|  WANG    | |      B A N K       | |  AMMU    |\n";
         cout<<"|  CARS    | |         $$         | | NATIONS  |\n";
         cout<<"|__________| |____________________| |__________|\n";
         cout<<"|           *                                  |\n";
         cout<<"|__________   ____________________   __________|\n";
         cout<<"|          | |                    | |          |\n";
         cout<<"| IDLEWOOD | |    BURGER SHOT     | |   GYM    |\n";
         cout<<"|__________|_|____________________|_|__________|\n";
        }
        else if(p.posx==3)
        {
         cout<<" ______________________________________________  HEALTH = "<<p.health<<"/"<<t_health<<endl;
         cout<<"|  REECE'S | |                    | |          | $$ = "<<p.cash<<endl;
         cout<<"|   HAIR   | |     LOS SANTOS     | |  GROVE   | Vehicle = "<<p.c.car_name()<<endl;
         cout<<"| & FACIAL | |  POLICE DEPARTMENT | |  STREET  | Weapon = "<<p.w.weapon_name()<<endl;
         cout<<"|  SALON   | |                    | |          | Wanted = "<<p.wanted<<endl;
         cout<<"|__________| |____________________| |__________|\n";
         cout<<"|                                              |\n";
         cout<<"|__________   ____________________   __________|\n";
         cout<<"|          | |                    | |          |\n";
         cout<<"|  WANG    | |      B A N K       | |  AMMU    |\n";
         cout<<"|  CARS    | |         $$         | | NATIONS  |\n";
         cout<<"|__________| |____________________| |__________|\n";
         cout<<"|                       *                      |\n";
         cout<<"|__________   ____________________   __________|\n";
         cout<<"|          | |                    | |          |\n";
         cout<<"| IDLEWOOD | |    BURGER SHOT     | |   GYM    |\n";
         cout<<"|__________|_|____________________|_|__________|\n";
        }

        else if(p.posx==4)
        {
         cout<<" ______________________________________________  HEALTH = "<<p.health<<"/"<<t_health<<endl;
         cout<<"|  REECE'S | |                    | |          | $$ = "<<p.cash<<endl;
         cout<<"|   HAIR   | |     LOS SANTOS     | |  GROVE   | Vehicle = "<<p.c.car_name()<<endl;
         cout<<"| & FACIAL | |  POLICE DEPARTMENT | |  STREET  | Weapon = "<<p.w.weapon_name()<<endl;
         cout<<"|  SALON   | |                    | |          | Wanted = "<<p.wanted<<endl;
         cout<<"|__________| |____________________| |__________|\n";
         cout<<"|                                              |\n";
         cout<<"|__________   ____________________   __________|\n";
         cout<<"|          | |                    | |          |\n";
         cout<<"|  WANG    | |      B A N K       | |  AMMU    |\n";
         cout<<"|  CARS    | |         $$         | | NATIONS  |\n";
         cout<<"|__________| |____________________| |__________|\n";
         cout<<"|                                  *           |\n";
         cout<<"|__________   ____________________   __________|\n";
         cout<<"|          | |                    | |          |\n";
         cout<<"| IDLEWOOD | |    BURGER SHOT     | |   GYM    |\n";
         cout<<"|__________|_|____________________|_|__________|\n";
        }
        else if(p.posx==5)
        {
         cout<<" ______________________________________________  HEALTH = "<<p.health<<"/"<<t_health<<endl;
         cout<<"|  REECE'S | |                    | |          | $$ = "<<p.cash<<endl;
         cout<<"|   HAIR   | |     LOS SANTOS     | |  GROVE   | Vehicle = "<<p.c.car_name()<<endl;
         cout<<"| & FACIAL | |  POLICE DEPARTMENT | |  STREET  | Weapon = "<<p.w.weapon_name()<<endl;
         cout<<"|  SALON   | |                    | |          | Wanted = "<<p.wanted<<endl;
         cout<<"|__________| |____________________| |__________|\n";
         cout<<"|                                              |\n";
         cout<<"|__________   ____________________   __________|\n";
         cout<<"|          | |                    | |          |\n";
         cout<<"|  WANG    | |      B A N K       | |  AMMU    |\n";
         cout<<"|  CARS    | |         $$         | | NATIONS  |\n";
         cout<<"|__________| |____________________| |__________|\n";
         cout<<"|                                        *     |\n";
         cout<<"|__________   ____________________   __________|\n";
         cout<<"|          | |                    | |          |\n";
         cout<<"| IDLEWOOD | |    BURGER SHOT     | |   GYM    |\n";
         cout<<"|__________|_|____________________|_|__________|\n";
        }
        
    }
}
