#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

struct menu
{
    string name;
    string type;
    string description;
    bool VEGAN;
    double price;
};

void readMenu(menu* info);
void writeMenu(menu* info);
void sortMenu(menu* info);
bool searchMenu(menu* info);
void displayMenu(menu* info);
void addMenu(menu* info);
void delMenu(menu* info);

int main()
{
    menu info[50];

    readMenu(info);
    addMenu(info);
    delMenu(info);
    sortMenu(info);
    if (!searchMenu(info))
    {
       displayMenu(info);
    }
    writeMenu(info);

}

void readMenu(menu* info)
{
    ifstream b_file ("menu.txt");

    string str;
    int i = 0;

    while (b_file.good())
    {
        getline(b_file, str);
        int div = str.find('`');
        info[i].name = str.substr(0,div);
        str.erase(0,div+1);
        div = str.find('`');
        info[i].type = str.substr(0,div);
        str.erase(0,div+1);
        div = str.find('`');
        info[i].description = str.substr(0,div);
        str.erase(0,div+1);
        div = str.find('`');
        info[i].VEGAN = (str[0] == '1');
        str.erase(0,div+1);
        info[i].price = atof(str.c_str());
        ++i;

    }

}
void writeMenu(menu* info)
{

    ofstream b_file ("menu.txt");

    int i = 0;
    while (i < 50)
    {
        if (info[i].name == "")
        {
            break;
        }

        b_file << info[i].name << '`';
        b_file << info[i].type << '`';
        b_file << info[i].description << '`';
        b_file << info[i].VEGAN << '`';
        b_file << info[i].price << endl;
        ++i;
    }
}
void sortMenu(menu* info)
{
    string a;

    cout << "How would you like to sort the menu? By name or by price? (case sensitive) ";
    cin >> a;

    if (a == "name")
    {
        for(int i = 0; i < 50; i++)
        {
            for(int j = 0; j < 50; j++)
            {
                if(info[j + 1].name == "")
                {
                    break;
                }
                if(info[j + 1].name < info[j].name)
                {
                    menu tempInfo = info[j + 1];
                    info[j + 1] = info[j];
                    info[j] = tempInfo;

                }
            }
        }
    }

    if (a == "price")
    {
        for(int i = 0; i < 50; i++)
        {
            for(int j = 0; j < 50; j++)
            {
                if(info[j + 1].name == "")
                {
                    break;
                }
                if(info[j + 1].price < info[j].price)
                {
                    menu tempInfo = info[j + 1];
                    info[j + 1] = info[j];
                    info[j] = tempInfo;

                }
            }
        }
    }

}
bool searchMenu(menu* info)
{
    string a;
    cout << "Would you like to search for a particular item? ";
    cin >> a;
    if (a != "yes" && a != "YES" && a != "Yes")
    {
        return false;
    }
    cout << "What dish are you searching for? ";
    cin.ignore();
    getline(cin,a);
    int i = 0;
    while (i < 50)
    {
        if (info[i].name == a)
        {
            break;
        }
        ++i;
    }

    if (i == 50)
    {
        cout << "Could not find entry." << endl;
        return true;
    }
    cout << "Dish: " << info[i].name << endl;
    cout << "Type: " << info[i].type << endl;
    cout << "Description: " << info[i].description << endl;
    if(info[i].VEGAN)
    {
        cout << "Vegan: Yes" << endl;
    }
    else
    {
        cout << "Vegan: No" << endl;
    }

    cout << "Price: " << info[i].price << endl << endl;

    return 1;
}
void displayMenu(menu* info)
{
    int i = 0;
    while (i < 50)
    {
        if (info[i].name == "")
        {
            break;
        }

        cout << "Dish: " << info[i].name << endl;
        cout << "Type: " << info[i].type << endl;
        cout << "Description: " << info[i].description << endl;
        if(info[i].VEGAN)
        {
            cout << "Vegan: Yes" << endl;
        }
        else
        {
            cout << "Vegan: No" << endl;
        }

        cout << "Price: " << info[i].price << endl << endl;
        ++i;
    }


}

void addMenu(menu* info)
{
    int i =0;
    string a;

    cout << "Would you like to add to the menu? ";
    cin >> a;

    if (a != "yes" && a != "YES" && a != "Yes")
    {
        return;
    }

    while (i < 50)
    {
        if (info[i].name == "")
        {
            break;
        }
        ++i;
    }

    cin.ignore();
    cout << "Please enter the name of dish: ";
    getline(cin,a);
    info[i].name = a;
    cout << "Please enter the type of dish: ";
    getline(cin,a);
    info[i].type = a;
    cout << "Please enter the description of dish: ";
    getline(cin,a);
    info[i].description = a;
    cout << "Please enter if the dish is VEGAN or not: ";
    getline(cin,a);
    info[i].VEGAN = (a[0] == '1' || a[0] == 'y' ||a[0] == 'Y');
    cout << "Please enter the price of dish: ";
    getline(cin,a);
    info[i].price = atof(a.c_str());
}
void delMenu(menu* info)
{
    int i =0;
    string a;

    cout << "Would you like to remove from the menu? ";
    cin >> a;

    if (a != "yes" && a != "YES" && a != "Yes")
    {
        return;
    }

    cout << "Which entry would you like to remove? ";
    cin.ignore();
    getline(cin,a);

    while (i < 50)
    {
        if (info[i].name == a)
        {
            break;
        }
        ++i;
    }

    if (i == 50)
    {
        cout << "Could not find entry." << endl;
        return;
    }

    while ( i < 49)
    {
        info[i] = info [i + 1];
        ++i;
    }

    info[49].name = "";
}
