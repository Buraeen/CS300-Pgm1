// Brian Akins Programming Assignment 01 for CS 300.


// Creating a You are the owner of a new store and need to keep track of your inventory.
// Since you are a seasoned C++ programmer, you are going to write a C++ program to  help manage inventory.

#include <iostream>                             // for std::cin and std::cout
#include <fstream>
#include <string>                               // for string type

using namespace std;

class Part
{
        public:
        int partNum;
        string description;
        int quantity;
        float unitPrice;
};

void printAllParts(Part [], int);
void addPart(Part [], int&);
void modPart(Part [], int);
void printCost(Part [], int);
void fileIORead(Part [], int&);
void fileIOWrite(Part [], int);

int main()
{


        // array of size 100

        Part arr[100];          // array to hold objects.
        int count = 0;          // count to tell how many different parts are in the array.
        int partSelect = 0;
        int debug = 0;


        //Read in the inventory.txt file.
        fileIORead(arr, count);


        //Menu


        int choice = 0;
        cout<<  "Store Inventory Menu"<<endl;
         cout<<  "*********************************"<<endl;
        cout<<  "1. Print the part"<<endl;
        cout<<  "2. Create a new part"<<endl;
        cout<<  "3. Modify a part"<<endl;
        cout<<  "4. Print total"<<endl;
        cout<<  "5. Exit the program"<<endl;
        cout<<  "Please make a menu selection.";
        cin>>choice;


        while (choice !=5)
        {

        //Menu switch.
        switch (choice)
                {
                        case 1:
                                printAllParts(arr, count);

                                if(debug==1)
                                {
                                        cout<<endl<<"Count number after printing is "<<count<<endl;
                                }
                                break;

                        case 2:
                                cin.ignore();
                                addPart(arr, count);
                                if(debug==1)
                                {
                                        cout<<endl<<"Count number after addPart is "<<count<<endl;
                                }
                                break;

                        case 3:

                                cout<<"Please select a part number."<<endl;
                                cin>>partSelect;
                                modPart(arr, partSelect);
                                if(debug==1)
                                {
                                        cout<<endl<<"Choice after modPart is "<<partSelect<<endl;
                                }
                                break;

                        case 4:
                                printCost(arr, count);

                                break;

                        // This case sets the program into debug mode and will allow me to check code at certain intervals.
                        // Not full proof, but helpful at times.
                        case 117:
                                debug = 1;
                                cout<<endl<<"Entering debug mode."<<endl;

                                //Debug to check what the value of count is after the file read.
                                //Can only enter debug mode after menu selection of 117, but if done first,
                                //this can give the value of count from the file read.
                                cout<<endl<<"Count number upon entering debug: "<<count<<endl;

                                break;

                        default:
                                cout<<"Invalid choice"<<endl;
                }

                //Debug for knowing when the menu loop restarts.
                if(debug==1)
                {
                        cout<<endl<<"restarting menu loop last entry "<<choice<<endl;
                }

                //Menu re-loop.
                cin.clear();
                cout<<  "Store Inventory Menu"<<endl;
                cout<<  "*********************************"<<endl;
                cout<<  "1. Print the part"<<endl;
                cout<<  "2. Create a new part"<<endl;
                cout<<  "3. Modify a part"<<endl;
                cout<<  "4. Print total"<<endl;
                cout<<  "5. Exit the program"<<endl;
                cout<<endl<<"Please make a new menu selection.";
                cin>>choice;

        }




        // Save data to inventory.txt here
        if(count!=0)
        {
                fileIOWrite(arr, count);
        }

        return 0;
}

//Function for printing all of the parts in inventory.
//Count should not be changed for this function.
void printAllParts(Part arr [], int count)
{

        if(count == 0)
        {
                cout<<"Empty Inventory."<<endl;
                return;
        }
        //cout<<"We are printAllParts!"<<endl;
        for(int i = 0; i < count; i++)
        {
                cout<<endl;
                cout    <<"Part Numbber: "      <<arr[i].partNum                <<endl;
                cout    <<"Description: "       <<arr[i].description    <<endl;
                cout    <<"Quantity: "          <<arr[i].quantity               <<endl;
                cout    <<"Unit Price: "        <<arr[i].unitPrice              <<endl;
        }

}

//Function for adding a Part to the array.
//Count should be incremented by 1 after this function.
void addPart(Part arr [], int& count)
{
        cout<<"New part description: ";
        string desc;
        getline(cin, desc);

        cout<<"New part quantity: ";
        int quantity = 0;
        cin>>quantity;

        cout<<"New part unit price: ";
        float price = 0;
        cin>> price;

        arr[count].partNum = count+1;
        arr[count].description = desc;
        arr[count].quantity = quantity;
        arr[count].unitPrice = price;

        count++;

}
//Function for modifying a Part.
//Count should not be changed for this function.
void modPart(Part arr [], int select)
{
        select = select-1;              //To put it in the right location for array position.
        int choice = 0;
        string desc;
        int quantity = 0;
        float price = 0;

        if(select == -1)
        {
                cout<<"Empty Inventory."<<endl;
                return;
        }
        cout<<"Part that has been selected to modify: "<<arr[select].description<<endl;

        cout<<"Part Field modification Menu"<<endl;
        cout<<  "1. Edit Description."<<endl;
        cout<<  "2. Edit Quantity."<<endl;
        cout<<  "3. Edit Cost."<<endl;
        cout<<  "4. Exit menu."<<endl;
        cin>>choice;
        while (choice !=4)
        {
                switch (choice)
                {
                        case 1:
                                        cout<<"New part description: ";
                                        cin.clear();
                                        getline(cin, desc);
                                        arr[select].description = desc;
                                        break;
                        case 2:
                                        cout<<"New part quantity: ";
                                        cin>>quantity;
                                        arr[select].quantity = quantity;
                                        break;
                        case 3:
                                        cout<<"New part unit price: ";
                                        cin>>price;
                                        arr[select].unitPrice = price;
                                        break;

                        default:
                                cout<<"Invalid choice"<<endl;
                }
                cin.clear();
                cout<<"Part Field modification Menu"<<endl;
                cout<<  "1. Edit Description."<<endl;
                cout<<  "2. Edit Quantity."<<endl;
                cout<<  "3. Edit Cost."<<endl;
                cout<<  "4. Exit menu."<<endl;
                cout<<endl<<"Please make a new menu selection.";
                cin>>choice;
        }

}
//Function for outputting the cost of the inventory.
//Count should not be changed for this function.
void printCost(Part arr [], int count)
{
        float inventoryCost = 0;
        for(int i=0; i < count; i++)
        {
                inventoryCost = inventoryCost + (arr[i].quantity*arr[i].unitPrice);
        }
        cout<<endl<<"The cost of the total inventory is $"<< inventoryCost <<endl;

}

//Function for reading the "inventory.txt" file.
//Function will not create an inventory if "inventory.txt" does not exist.
//Count will match the inventory.txt file maximum part number after this
//function or 100, whichever is higher.
void fileIORead(Part arr [], int& count)
{
        fstream file("inventory.txt", ios::in);

        if(file)
        {
                int partNum = 0;
                string description = "";
                int quantity = 0;
                float unitPrice = 0;

                // using a loop to keep reading file.
                // if reading file fails, the loop will end
                while(file >> partNum && count<100)
                {

                        file.ignore();
                        getline(file, description);
                        file >> quantity;
                        file >> unitPrice;

                        arr[count].partNum = count+1;
                        arr[count].description = description;
                        arr[count].quantity = quantity;
                        arr[count].unitPrice = unitPrice;

                        count++;
                }
        }
        else
        {
                cout<<"No inventory file found. One will be created if a new inventory is created."<<endl;
        }

        // close file when done
        file.close();
}

//Function for writing the "inventory.txt" file.
//Function destroys old "inventory.txt" file.
//Count should not be changed for this function.
void fileIOWrite(Part arr [], int count)
{
        // create fstream object
        fstream file("inventory.txt", ios::out);

        //      if file is good, then write to the file
        if(file)
        {
                for(int i = 0; i< count; i++)
                {
                        file <<         arr[i].partNum          <<endl;
                        file <<         arr[i].description      <<endl;
                        file <<         arr[i].quantity         <<endl;
                        file <<         arr[i].unitPrice        <<endl;
                }


                std::cout<<"Writing file \"inventory.txt\" succeed."<<std::endl;

        }
        else
        {
                std::cout<<"Error when writing to file \"inventory.txt\""<<std::endl;
        }

        // close file when done.
        file.close();
}
