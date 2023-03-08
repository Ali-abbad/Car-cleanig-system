#include <iomanip>
#include <string>
#include <iostream>
#include <fstream>
using namespace std;
int x = 1000;
class dcar
// for cleaner processes
{
public:
    string type;
    string location;
    string color;
    int plate;
    bool avr;
    string with;

    void setDcar()
     // To add cleaner information 
    {
        cout << "\ngive information about the car \n what is type of car: ";
        cin >> this->type;
        cout << "what is color of the car: ";
        cin >> this->color;
        cout << "what is plate number: ";
        cin >> this->plate;
        cout << "what is location of the car: ";
        cin >> this->location;
        avr = false;
        with = "-";
    }
    void print()
    //To print information about cleaners
    {
        cout << "\nType of car is: " << type << "\n";
        cout << "Color of car is: " << color << "\n";
        cout << "Plate of car is: " << plate << "\n";
        cout << "Location of car is: " << location << "\n";
        if (avr||with=="-"){
            cout << "the cleaner is available\n";
        }
        else{
            cout << "the cleaner is unavailable\nThe cleaner cleaning : " << with << "\n";
        }
    }
};
class pcleaner
// for cleaner processes
{
public:
    string name;
    int phone;
    int price;
    bool avr;
    string with;
    void setCleaner()
    // To add cleaner information 
    {
        cout << "\ngive information about the cleaner \n what is cleaner's name: ";
        cin >> name;
        cout << "what is cleaner's phone: ";
        cin >> phone;
        cout << "how much is it cost: ";
        cin >> price;
        avr = true;
        with = "-";
    }
    void print()
    //To print information about cleaners
    {
        cout << "\nname of cleaner is: " << name << "\n";
        cout << "phone of cleaner is: " << phone << "\n";
        cout << "price of cleaner is: " << price << "\n";
        if (avr||with=="-")
            cout << "the cleaner is available\n";
        else
            cout << "the cleaner is unavailable\nThe cleaner cleaning : " << with << "\n";
    }
};
void menu()
{
    
    int cnt = -1;
    int ncnt = -1;
    int c, l;
    char w = 'E', o;
    dcar Car[x];
    pcleaner cleaners[x];
    ifstream ifcar;
    // to get information from file
    ifcar.open("car.txt",ios::in);
    if(ifcar.is_open()){
        while(!ifcar.eof()){
            cnt++;
            ifcar>>Car[cnt].type>>Car[cnt].color>>Car[cnt].location>>Car[cnt].plate>>Car[cnt].with>>Car[cnt].avr;
        }
        ifcar.close();
    }
    ifstream ifcleaner;
    ifcleaner.open("cleaner.txt",ios::in);
    if(ifcleaner.is_open()){
        while(!ifcleaner.eof()){
            ncnt++;
            ifcleaner>>cleaners[ncnt].name>>cleaners[ncnt].phone>>cleaners[ncnt].price>>cleaners[ncnt].with>>cleaners[ncnt].avr;
            
        }
        ifcleaner.close();
    }
    
    do
    // To make code in loop
    {
        // The menu
        cout << "what do you want?\n[A] Add car\n[B] Add cleaner\n[C] Assign cleaner to car\n[S] Separating cleaner from car\n[U] Update\n[D] Delete\n[L] Show list\n[R] Search \n[E] Finish\n";
        cin >> w;
        switch (toupper(w))
        {
        case 'A':
        // Add car function
            do
            {
                if (cnt < x)
                {
                    cnt++;
                    Car[cnt].setDcar();
                    Car[cnt].print();
                }
                else
                {
                    for (int h = 0; h < x; h++)
                    {
                        if (Car[h].type == "")
                        {
                            Car[h].setDcar();
                            Car[h].print();
                        }
                    }
                }
                cout << "Enter 'Y' to return to the menu or enter anything to continue:";
                cin >> o;
            } while (toupper(o) != 'Y');
            break;
        case 'B':
        // Add cleaner function
            do
            {
                if (ncnt != x)
                {
                    ncnt++;
                    cleaners[ncnt].setCleaner();
                    cleaners[ncnt].print();
                }
                else
                {
                    for (int h = 0; h < x; h++)
                    {
                        if (cleaners[h].name == "")
                        {
                            cleaners[h].setCleaner();
                            cleaners[h].print();
                        }
                    }
                }
                cout << "Enter 'Y' to return to the menu or enter anything to continue: ";
                cin >> o;
            } while (toupper(o) != 'Y');
            break;
        case 'C':
        // Assign function
            do
            {
                cout << "cleaner:  ";
                for (int i = 0; i <= ncnt; i++)
                {
                    if (cleaners[i].avr == true && cleaners[i].name != "")
                        cout << i + 1 << "--" << cleaners[i].name << setw(5);
                }
                cout << "\nCar:  ";
                for (int i = 0; i <= cnt; i++)
                {
                    if (Car[i].with == "-" && Car[i].type != "")
                        cout << i + 1 << "--" << Car[i].type << setw(5);
                }
                cout << "\n";
                cout << "Choose number for cleaner and car : ";
                cin >> l >> c;
                Car[c - 1].with = cleaners[l - 1].name;
                cleaners[l - 1].with = Car[c - 1].type;
                Car[c-1].avr=false;
                cleaners[l - 1].avr = false;
                cout << "Enter 'Y' to return to the menu or enter anything to continue: ";
                cin >> o;
            } while (toupper(o) != 'Y');
            break;
        case 'S':
        // Separating function
            do
            {
                for (int i = 0; i <= ncnt; i++)
                {
                    if (cleaners[i].avr != true)
                    {
                        for (int g = 0; g <= cnt; g++)
                        {
                            if (Car[g].type == cleaners[i].with)
                                cout << i + 1 << "-- the cleaner is: " << cleaners[i].name << setw(8) << g + 1 << "-- the car is: " << Car[g].type << endl;
                        }
                    }
                }
                cout << "Choose number for cleaner and car: ";
                cin >> l >> c;
                if (Car[c-1].type == cleaners[l-1].with)
                {
                    Car[c - 1].with = "-";
                    Car[c - 1].avr = true;
                    cleaners[l - 1].with = "-";
                    cleaners[l - 1].avr = true;
                }
                else
                    cout << "wrong try again!\n";
                cout << "Enter 'Y' to return to the menu or enter anything to continue: ";
                cin >> o;
            } while (toupper(o) != 'Y');
            break;
        case 'U':
        // Update function
            do
            {
                cout << "What do you want to update: A- Cleaner " << setw(8) << "B- Car: ";
                cin >> w;
                if (toupper(w) == 'A')
                {
                    for (int i = 0; i <= ncnt; i++)
                    {
                        if (cleaners[i].name != "")
                            cout << i + 1 << "--" << cleaners[i].name << setw(5);
                    }
                    cout << "\nChose the number of cleaner: ";
                    cin >> l;
                    cleaners[l - 1].setCleaner();
                    cleaners[l - 1].print();
                }
                else if (toupper(w) == 'B')
                {
                    for (int i = 0; i <= cnt; i++)
                    {
                        if (Car[i].type != "")
                            cout << i + 1 << "--" << Car[i].type << setw(5);
                    }
                    cout << "\nChose the number of car: ";
                    cin >> l;
                    Car[l - 1].setDcar();
                    Car[l - 1].print();
                }
                cout << "Enter 'Y' to return to the menu or enter anything other to continue: ";
                cin >> o;
            } while (toupper(o) != 'Y');
            break;
        case 'D':
        // Delete function
            do
            {
                cout << "What do you want Delete: A- Cleaner " << setw(8) << "B- Car: ";
                cin >> w;
                if (toupper(w) == 'A')
                {
                    for (int i = 0; i < ncnt; i++)
                    {
                        if (cleaners[1].name != "")
                            cout << i + 1 << "--" << cleaners[i].name << setw(15);
                    }
                    cout << "\nChose the number of cleaner: ";
                    cin >> l;
                    cleaners[l - 1].name = "";
                    
                }
                else if (toupper(w) == 'B')
                {
                    for (int i = 0; i < cnt; i++)
                    {
                        if (Car[i].type != "")
                            cout << i + 1 << "--" << Car[i].type << setw(5);
                    }
                    cout << "\nChose the number of car: ";
                    cin >> l;
                    Car[l - 1].type = "";
                }
                cout << "Enter 'Y' to return to the menu or enter anything to continue: ";
                cin >> o;
            } while (toupper(o) != 'Y');
            break;
        case 'L':
        // List function
            do
            {
                cout << "What do you want to show: A- Cleaner " << setw(8) << "B- Car: ";
                cin >> w;
                if (toupper(w) == 'B')
                {
                    for (int h = 0; h < x; h++)
                    {
                        if (Car[h].type != "")
                        {
                            Car[h].print();
                            cout << "\n";
                        }
                    }
                }
                else if (toupper(w) == 'A')
                {
                    for (int h = 0; h < x; h++)
                    {
                        if (cleaners[h].name != "")
                        {
                            cleaners[h].print();
                            cout << "\n";
                        }
                    }
                }
                cout << "Enter 'Y' to return to the menu or enter anything to continue: ";
                cin >> o;
            } while (toupper(o) != 'Y');
            break;
        case 'R':
        // Search function
            do
            {
                cout << "What do you want to show: A- Cleaner " << setw(8) << "B- Car: ";
                cin >> w;
                if (toupper(w) == 'A')
                {
                    cout << "cleaner:  ";
                    for (int i = 0; i <= ncnt; i++)
                    {
                        if (cleaners[i].name != "")
                            cout << i + 1 << "--" << cleaners[i].name << setw(5);
                    }
                    cout << "\n";
                    cout << "Choose number for cleaner: ";
                    cin >> l;
                    cleaners[l - 1].print();
                }
                else if (toupper(w) == 'B')
                {
                    cout << "\nCar:  ";
                    for (int i = 0; i <= cnt; i++)
                    {
                        if (Car[i].type != "")
                            cout << i + 1 << "--" << Car[i].type << setw(5);
                    }
                    cout << "\n";
                    cout << "Choose number for car: ";
                    cin >> l;
                    Car[l - 1].print();
                }
                cout << "Enter 'Y' to return to the menu or enter anything to continue: ";
                cin >> o;
            } while (toupper(o) != 'Y');
            break;
        case 'E':
        // To finish the programme
            cout << "Thank you for using our programme";
            break;
        default:
            cout << "please enter character from the menu!\n";
            break;
        }
    } while (toupper(w) != 'E');
    //to put information for file
    ofstream fcar;
    fcar.open("car.txt",ios::out);
    for(int x=0;x<=cnt-1;x++)
        fcar<<Car[x].type<<" "<<Car[x].color<<" "<<Car[x].location<<" "<<Car[x].plate<<" "<<Car[x].with<<" "<<Car[x].avr<<"\n";
    fcar<<Car[cnt].type<<" "<<Car[cnt].color<<" "<<Car[cnt].location<<" "<<Car[cnt].plate<<" "<<Car[cnt].with<<" "<<Car[cnt].avr;
    fcar.close();
    ofstream fcleaner;
    fcleaner.open("cleaner.txt",ios::out);
    for(int x=0;x<=ncnt-1;x++)
    fcleaner<<cleaners[x].name<<" "<<cleaners[x].phone<<" "<<cleaners[x].price<<" "<<cleaners[x].with<<" "<<cleaners[x].avr<<"\n";
    fcleaner<<cleaners[ncnt].name<<" "<<cleaners[ncnt].phone<<" "<<cleaners[ncnt].price<<" "<<cleaners[ncnt].with<<" "<<cleaners[ncnt].avr;
    fcleaner.close();
}
int main()
{
    menu();
    return 0;
}
