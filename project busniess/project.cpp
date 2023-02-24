#include <iostream>
#include <windows.h>
#include <conio.h>
#include <stdio.h>
using namespace std;

// GLOBAL VARIABLES initialization and declaration

// integer type variables

int customerCount = 0;
int adminCount = 0;
int itemsCount = 0;
int feedbackCount = 0;

// constant integer type arrays

const int usernameARRAYsize = 100;
const int itemsArraySize = 10000;
const int adminArraySize = 1000;
const int quantityArraySize = 1000;

// GLOBAL ARRAYS initialization and declaration

float bills[usernameARRAYsize];
int itemsPrice[itemsArraySize];
int itemsQuantity[itemsArraySize];
int quantityUserNeeded[usernameARRAYsize];
string admins[adminArraySize];
string adminPasswords[adminArraySize];
string feedback[usernameARRAYsize];
string users[usernameARRAYsize];
string passwords[usernameARRAYsize];
string items[itemsArraySize];

// All Funtions including ADMIN and CUSTOMER


// VOID DATA-TYPE FUNCTIONS

void printHeader();
void clearScreen();
void customerSignUpPage();
void customerSignInPage();
void availableItems();
void adminSignInPage();
void addItemsAdminMenu();
void itemsUpdateMenu();
void itemsDeleteMenu();
void viewStockAdminMenu();
void viewStockAdminControl();
void selectRequiredItemsMenu();
void customerFeedbackMenu();
void viewCustomerRecordAdminMenu();
void viewCustomerRecordAdminMenuControl();
void customerReviewMenu();
void customerReview();
void adminSignUpMenu();

// STRING DATA-TYPE FUNCTIONS

string headerMainMenu();
string customerMenu();
string customerheaderMainMenu();
string adminheaderMainMenu();
string itemsUpdateControl(string itemName, int priceOfItem, int itemQuantity);
string itemsDeleteControl(string itemName, int priceOfItem, int itemQuantity);
string customerFeedback(string userName, string review);

// BOOL DATA-TYPE FUNCTIONS

bool customerSignUpControl(string username, string password);
bool customerSignInControl(string username, string password);
bool adminSignInControl(string username, string password);
bool addItemsAdminControl(string itemName, int priceOfItem, int itemQuantity);
bool adminSignUpControl(string username, string password);

// FLOAT DATA-TYPE FUNCTIONS

float selectRequiredItemsControl(string itemName, int itemQuantity, float moreSelection);



// MAIN FUNCTION


main()
{
    // LOCAL VARIABLES

    string option = "0";

    // COUNTER LOOPS

    while (option != "3")
    {
        option = headerMainMenu();
        if (option == "1")
        {
            bool isValid;
            string username;
            string password;
            system("cls");
            adminSignInPage();
            cout << "User Name : ";
            cin >> username;
            cout << "Password : ";
            cin >> password;
            isValid = adminSignInControl(username, password);
            if (isValid)
            {
                // ADMIN' MAIN MENU
                string adminheaderMainMenuOption = "0";
                while (adminheaderMainMenuOption != "10")
                {
                    system("cls");
                    adminheaderMainMenuOption = adminheaderMainMenu();
                    // FOR ADDING NEW ITEMS
                    if (adminheaderMainMenuOption == "1")
                    {
                        bool isfound;
                        string itemName;
                        int priceOfItem, itemQuantity;
                        system("cls");
                        addItemsAdminMenu();
                        cout << "Enter name of item : ";
                        cin >> itemName;
                        cout << "Enter Price of item : ";
                        cin >> priceOfItem;
                        cout << "Enter quantity of item in KG's : ";
                        cin >> itemQuantity;
                        isfound = addItemsAdminControl(itemName, priceOfItem, itemQuantity);
                        if (isfound)
                        {
                            cout << "Item Added Successfully :) " << endl;
                            clearScreen();
                            adminheaderMainMenuOption = "0";
                        }
                        if (!isfound)
                        {
                            cout << "ITEM ALREADY EXIST ! " << endl;
                            clearScreen();
                            adminheaderMainMenuOption = "0";
                        }
                        adminheaderMainMenuOption = "0";
                    }
                    // FOR UPDATING THE ITEMS
                    if (adminheaderMainMenuOption == "2")
                    {
                        int priceOfItem, itemQuantity;
                        string itemName, result;
                        system("cls");
                        itemsUpdateMenu();
                        cout << "Enter name of item you want to update : ";
                        cin >> itemName;
                        cout << "Enter price of that item you want to update : ";
                        cin >> priceOfItem;
                        cout << "Enter Quantity of that item you want to update : ";
                        cin >> itemQuantity;
                        result = itemsUpdateControl(itemName, priceOfItem, itemQuantity);
                        if (result == "true")
                        {
                            cout << "Item updated successfully !" << endl;
                            clearScreen();
                        }
                        if (result == "false")
                        {
                            cout << "Item does not exist" << endl;
                            clearScreen();
                        }
                        adminheaderMainMenuOption = "0";
                    }
                    // FOR DELETING ITEMS
                    if (adminheaderMainMenuOption == "3")
                    {
                        int priceOfItem, itemQuantity;
                        string itemName, result;
                        system("cls");
                        itemsDeleteMenu();
                        cout << "Enter name of item you want to delete : ";
                        cin >> itemName;
                        cout << "Enter price of that item you want to delete : ";
                        cin >> priceOfItem;
                        cout << "Enter Quantity of that item you want to delete : ";
                        cin >> itemQuantity;
                        result = itemsDeleteControl(itemName, priceOfItem, itemQuantity);
                        if (result == "true")
                        {
                            cout << "Item deleted successfully !" << endl;
                            clearScreen();
                        }
                        if (result == "false")
                        {
                            cout << "Item does not exist" << endl;
                            clearScreen();
                        }
                        adminheaderMainMenuOption = "0";
                    }
                    // FOR VIEWING STOCK
                    if (adminheaderMainMenuOption == "4")
                    {
                        system("cls");
                        viewStockAdminMenu();
                        viewStockAdminControl();
                        clearScreen();
                    }
                    // FOR VIEWING SIGNED UP USERS
                    if (adminheaderMainMenuOption == "5")
                    {
                        system("cls");
                        viewCustomerRecordAdminMenu();
                        cout << "\tUSERNAME\tPASSWORD" << endl;
                        viewCustomerRecordAdminMenuControl();
                        clearScreen();
                        adminheaderMainMenuOption = "0";
                    }
                    // FOR VIEWING FEEDBACK
                    if (adminheaderMainMenuOption == "6")
                    {
                        system("cls");
                        customerReviewMenu();
                        cout << "\tUSERNAME\tFEEDBACK" << endl;
                        customerReview();
                        clearScreen();
                        adminheaderMainMenuOption = "0";
                    }
                    // FOR ADDING ADMIN
                    if (adminheaderMainMenuOption == "7")
                    {
                        string username, password;
                        bool isValid;
                        system("cls");
                        adminSignUpMenu();
                        cout << "User Name : ";
                        cin >> username;
                        cout << "Password : ";
                        cin >> password;
                        isValid = adminSignUpControl(username, password);
                        if (isValid)
                            cout << "Signed Up ! successfully" << endl;
                        if (!isValid)
                            cout << "Not Signed Up ! ADMIN LIMIT EXCEED" << endl;
                        clearScreen();
                        adminheaderMainMenuOption = "0";
                    }
                    // FOR DELETING ADMIN
                    if (adminheaderMainMenuOption == "8")
                    {
                        string deleterName;
                        cout << "Enter the username for delete: ";
                        cin >> deleterName;
                        for (int i = 0; i < adminCount; i++)
                        {
                            if(deleterName == admins[adminCount])
                            {
                                admins[adminCount] = " ";
                                adminPasswords[adminCount] = " ";
                            }
                        }
                    }
                    // FOR VIEWING ADMIN
                    if (adminheaderMainMenuOption == "9")
                    {
                        for (int i = 0 ; i < adminCount; i++)
                        {
                            cout << admins[adminCount] << endl;
                        }
                    }
                    // ADMIN RETURN MAIN MENU
                    if (adminheaderMainMenuOption == "10")
                    {
                        break;
                        system("cls");
                    }
                }
            }
            if (!isValid)
            {
                cout << "...YOU ENTERED WRONG USERNAME OR PASSWORD..." << endl;
            }
            cout << "...PRESS ANY KEY TO CONTINUE...";
            getch();
        }
        if (option == "2")
        {
            string customerMO = "0";
            while (customerMO != "3")
            {
                system("cls");
                customerMO = customerMenu();
                // SIGN IN CUSTOMER
                if (customerMO == "1")
                {
                    bool isValid;
                    string username, password;
                    system("cls");
                    customerSignInPage();
                    cout << "User Name: ";
                    cin >> username;
                    cout << "Password: ";
                    cin >> password;
                    isValid = customerSignInControl(username, password);

                    // CUSTOMER MAIN MENU

                    if (isValid)
                    {

                        system("cls");

                        // HMO header main menu option
                        // CMO customer menu option

                        string customerHMO = "0";
                        while (customerHMO != "5")
                        {
                            customerHMO = customerheaderMainMenu();
                            // AVAILABLE ITEMS
                            if (customerHMO == "1")
                            {
                                system("cls");
                                viewStockAdminMenu();
                                viewStockAdminControl();
                                clearScreen();
                            }
                            // SELECT REQUIRED ITEM
                            if (customerHMO == "2")
                            {
                                string selectRequiredItemsOption = "0";
                                system("cls");
                                float moreSelection = 0;
                                selectRequiredItemsMenu();
                                while (selectRequiredItemsOption != "n")
                                {

                                    int itemQuantity;
                                    string itemName;
                                    float bills;
                                    cout << "Enter name of items you want to select: ";
                                    cin >> itemName;
                                    cout << "Enter Quantity of item you want : ";
                                    cin >> itemQuantity;
                                    bills = selectRequiredItemsControl(itemName, itemQuantity, moreSelection);
                                    cout << "Your bills is : " << bills << endl;
                                    cout << "To Select more items Press 'm' :" << endl;
                                    cout << "To return to customer menu, press 'r' :" << endl;
                                    cout << "enter your option : ";
                                    cin >> selectRequiredItemsOption;
                                    cout << "**************************************************" << endl;

                                    if (selectRequiredItemsOption == "m")
                                    {
                                        selectRequiredItemsOption = "0";
                                    }
                                    if (selectRequiredItemsOption == "r")
                                    {
                                        clearScreen();
                                    }
                                }
                            }
                            // CUSTOMER'S REVIEW
                            if (customerHMO == "3")
                            {
                                string userName;
                                string review;
                                string isfound;
                                system("cls");
                                customerFeedbackMenu();
                                cout << "Enter your userName : ";
                                cin >> userName;
                                cout << "Enter review only in one word no space or special character : ";
                                cin >> review;
                                isfound = customerFeedback(userName, review);
                                if (isfound == "true")
                                {
                                    cout << "...ThankYou For your feedback... " << endl;
                                    clearScreen();
                                }
                                if (isfound == "false")
                                {
                                    cout << "...You entered wrong username..." << endl;
                                    clearScreen();
                                }
                                customerHMO = "0";
                            }
                            // CUSTOMER'S PAYMENT METHOD
                            if (customerHMO == "4")
                            {
                                string paymentMethod;
                                cout << "Enter your payment method (COD , CreditCards , EasyPaisa / Jazzcash): ";
                                cin >> paymentMethod;

                                if (paymentMethod == "Jazzcash")
                                {
                                    cout << "ThankYou for using Jazzcash";
                                }
                                else if (paymentMethod == "EasyPaisa")
                                {
                                    cout << "ThankYou for using EasyPaisa";
                                }
                                else if (paymentMethod == "CreditCards")
                                {
                                    cout << "ThankYou for using CreditCard";
                                }
                                else if (paymentMethod == "COD")
                                {
                                    cout << "ThankYou for using Cash On Delivery method";
                                }
                                else
                                {
                                    cout << "You entered wrong payment method...";
                                    customerheaderMainMenu();
                                }

                            }
                            // CUSTOMER ITEM EXCHANGE REQUEST
                            if (customerHMO == "5")
                            {
                                string itemExchange;
                                int modelnumber;
                                string usage;
                                string warranty;
                                cout << "Enter the name of phone you want to exchange: ";
                                cin >> itemExchange;
                                cout << "Enter the model number: ";
                                cin >> modelnumber;
                                cout << "Is it used or new ? ";
                                cin >> usage;
                                cout << "Is it is in warranty (yes) or not ? ";
                                cin >> warranty;
                                cout << endl << endl;
                                cout << "ThankYou !! Your request has been processed. We'll response you soon!!";
                            }
                            // FOR SELLING AN ITEM
                            if (customerHMO == "6")
                            {
                                string itemName;
                                string aIos;
                                string usage;
                                int model;
                                string price;
                                string color;
                                cout << "Are you want to sale Android or Ios ? ";
                                cin >> aIos;
                                cout << "Enter the name of phone: ";
                                cin >> itemName;
                                cout << "Enter the model number: ";
                                cin >> model;
                                cout << "Enter color of your phone: ";
                                cin >> color;
                                cout << "Is it new or used ? ";
                                cin >> usage;
                                cout << "Enter the suitable price: ";
                                cin >> price;
                                cout << endl << endl;
                                cout << "ThankYou !! Your request has been processed. We'll response you soon!!";
                            }
                            // CUSTOMER'S COMPLAINT
                            if (customerHMO == "7")
                            {
                                string complaint;
                                cout << "Please give your complaint : ";
                                getline(cin, complaint);
                                cout << endl << endl;
                                cout << "ThankYou !! Your request has been processed. We'll response you soon!!";
                            }
                            // CUSTOMER MENU CLOSER
                            if (customerHMO == "10")
                            {
                                break;
                                customerHMO = "0";
                            }
                        }
                    }
                    if (!isValid)
                    {
                        cout << "...YOU ENTERED WRONG USERNAME OR PASSWORD..." << endl;
                    }
                    cout << "...PRESS ANY KEY TO CONTINUE...";
                    getch();
                    customerMO = "0";
                }
                // SIGN UP CUSTOMER
                if (customerMO == "2")
                {
                    string username;
                    string password;
                    bool isValid;
                    customerSignUpPage();
                    cout << "User Name : ";
                    cin >> username;
                    cout << "Password : ";
                    cin >> password;
                    isValid = customerSignUpControl(username, password);
                    if (isValid)
                    {
                        cout << "Signed Up ! successfully" << endl;
                    }
                    if (!isValid)
                    {
                        cout << "Not Signed Up ! CUSTOMER'S LIMIT EXCEEDED" << endl;
                    }
                    cout << "PRESS ANY KEY TO CONTINUE...";
                    getch();
                    customerMO = "0";
                }
                // RETURN MAIN MENU
                if (customerMO == "3")
                {
                    option = "0";
                }
            }
        }
    }
}

// ALL FUNCTION DEFINITIONS

void printHeader()
{
    cout << "                     **************************************" << endl;
    cout << "                     *                                    *" << endl;
    cout << "                     *   Mobile Store Management system   *" << endl;
    cout << "                     *                                    *" << endl;
    cout << "                     **************************************" << endl;
}
void clearScreen()
{
    cout << "...PRESS ANY KEY TO CONTINUE ...";
    getch();
    system("cls");
}

string headerMainMenu()
{
    string option;
    system("cls");
    printHeader();
    cout << "                              Welcome to the store         " << endl;
    cout << endl
         << endl;
    cout << "... Please enter the user-type ... " << endl
         << endl;
    cout << "Press 1-For Admin Sign In : " << endl;
    cout << "Press 2-For Customer(sign-in or sign-up) : " << endl;
    cout << "Press 3-Exit Program : " << endl
         << endl;
    cout << "Enter your Option : ";
    cin >> option;
    return option;
}
string customerMenu()
{
    system("cls");
    string option;
    printHeader();
    cout << "                                   Customer's Login        " << endl;
    cout << endl
         << endl;
    cout << "Choose the anyone of the following options " << endl
         << endl;
    cout << "Press 1-For Sign In : " << endl;
    cout << "press 2-For sign Up : " << endl;
    cout << "Press 3-For Main Menu : " << endl;
    cout << "Enter your Option : ";
    cin >> option;
    return option;
}
void customerSignUpPage()
{
    system("cls");
    printHeader();
    cout << "                                 Customer's Sign up        " << endl;
    cout << endl
         << endl;
    cout << "...Please Enter your username and password for Sign Up ..." << endl
         << endl;
}
bool customerSignUpControl(string username, string password)
{
    bool isPresent = false;
    for (int index = 0; index < usernameARRAYsize; index++)
        if (users[index] == username && passwords[index] == password)
        {
            isPresent = true;
            break;
        }

    if (isPresent == true)
    {
        return 0;
        cout << "...Username or password Already exists...Try Again";
    }
    else if (customerCount < usernameARRAYsize)
    {
        users[customerCount] = username;
        passwords[customerCount] = password;
        customerCount++;
        return true;
    }
    else
    {
        return false;
    }
}
void customerSignInPage()
{
    system("cls");
    printHeader();
    cout << "                                 Customer's Sign in        " << endl;
    cout << endl
         << endl;
    cout << "...Please Enter your username and password for login..." << endl
         << endl;
}
bool customerSignInControl(string username, string password)
{
    bool isPresent = false;
    for (int index = 0; index < customerCount; index++)
    {
        if ((users[index] == username) && (passwords[index] == password))
        {
            isPresent = true;
        }
    }
    if (isPresent == true)
    {
        return true;
    }
    else
    {
        return false;
    }
}
string customerheaderMainMenu()
{
    string option;
    printHeader();
    cout << "                                 Customer's Service        " << endl;
    cout << endl
         << endl;
    cout << "...Select your desired option...PRESS one following key " << endl;
    cout << "                                   " << endl;
    cout << "1-View the available items  " << endl;
    cout << "2-Select the Required items  " << endl;
    cout << "3-Feedback  " << endl;
    cout << "4-Payment option " << endl;
    cout << "5-Exchange policy" << endl;
    cout << "6-Sell items" << endl;
    cout << "7-Complaint" << endl;
    cout << "10-Return to Main Menu" << endl;
    cout << "Enter the Option: ";
    cin >> option;
    return option;
}
void availableItems()
{
    printHeader();
    cout << "                                 Available items           " << endl;
    cout << endl
         << endl;
    cout << "...Choose your option... " << endl
         << endl;
    cout << "ITEMS"
         << "\t"
         << "PRICE"
         << "\t" << endl;
}
void adminSignInPage()
{
    system("cls");
    printHeader();
    cout << "                                 Admin's Login             " << endl;
    cout << endl
         << endl;
    cout << "...Enter your username and password to login..." << endl
         << endl;
}
bool adminSignInControl(string username, string password)
{
    //  ADMIN'S DATA DEFAULT
    admins[adminCount] = ("Wahab");
    adminPasswords[adminCount] = ("123");

    bool isPresent = false;
    for (int index = 0; index <= adminCount; index++)
    {
        if ((admins[index] == username) && (adminPasswords[index] == password))
        {
            isPresent = true;
        }
    }
    if (isPresent == true)
    {
        return true;
    }
    else
    {
        return false;
    }
}
string adminheaderMainMenu()
{
    string option;
    printHeader();
    cout << "                                Admin's Main Menu          " << endl;
    cout << endl
         << endl;
    cout << "...Choose one of the following option...Press one key " << endl
         << endl;
    cout << "1-add new items : " << endl;
    cout << "2-update items : " << endl;
    cout << "3-delete items :" << endl;
    cout << "4-view stock : " << endl;
    cout << "5-view customer record : " << endl;
    cout << "6-view customer feedback : " << endl;
    cout << "7-add admin : " << endl;
    cout << "8-delete admin : " << endl;
    cout << "9-to view admins : " << endl;
    cout << "10-for Return to Main Menu : " << endl;
    cout << "Enter your Option: ";
    cin >> option;
    return option;
}
void addItemsAdminMenu()
{
    printHeader();
    cout << "                                Admin's Main Menu          " << endl;
    cout << endl
         << endl;
    cout << "...Add your desired Items... " << endl
         << endl;
}
bool addItemsAdminControl(string itemName, int priceOfItem, int itemQuantity)
{
    bool isPresent = false;
    for (int index = 0; index < itemsCount; index++)
    {
        if (items[index] == itemName && itemsPrice[index] == priceOfItem && itemsQuantity[index] == itemQuantity)
        {
            isPresent = true;
            break;
        }
    }
    if (isPresent == true)
    {
        return 0;
        cout << "Item Already Present ! ";
    }
    else if (itemsCount < itemsArraySize)
    {
        items[itemsCount] = itemName;
        itemsPrice[itemsCount] = priceOfItem;
        itemsQuantity[itemsCount] = itemQuantity;
        itemsCount++;
        return true;
    }
    else
    {
        return false;
    }
}
void itemsUpdateMenu()
{
    printHeader();
    cout << "                                    Add items              " << endl;
    cout << endl
         << endl;
    cout << "...Update your desired Item... " << endl
         << endl;
}
string itemsUpdateControl(string itemName, int priceOfItem, int itemQuantity)
{
    string isPresent = "false";
    for (int index = 0; index < itemsCount; index++)
    {
        if (items[index] == itemName && itemsPrice[index] == priceOfItem && itemsQuantity[index] == itemQuantity)
        {
            isPresent = "true";
            if (isPresent == "true")
            {
                int newPriceOfItem, newitemQuantity;
                string newitemName;
                cout << "Enter new name of item : ";
                cin >> newitemName;
                cout << "Enter new price of that item : ";
                cin >> newPriceOfItem;
                cout << "Enter new Quantity of that item : ";
                cin >> newitemQuantity;
                items[index] = newitemName;
                itemsPrice[index] = newPriceOfItem;
                itemsQuantity[index] = newitemQuantity;
                break;
            }
        }
    }
    return isPresent;
}
void itemsDeleteMenu()
{
    printHeader();
    cout << "                                   Delete items            " << endl;
    cout << endl
         << endl;
    cout << "...Delete your desired Item... " << endl
         << endl;
}
string itemsDeleteControl(string itemName, int priceOfItem, int itemQuantity)
{
    string isPresent = "false";
    for (int index = 0; index < itemsCount; index++)
    {
        if (items[index] == itemName && itemsPrice[index] == priceOfItem && itemsQuantity[index] == itemQuantity)
        {
            isPresent = "true";
            if (isPresent == "true")
            {

                items[index] = "0";
                itemsPrice[index] = 0;
                itemsQuantity[index] = 0;
                break;
            }
        }
    }
    return isPresent;
}
void viewStockAdminMenu()
{
    printHeader();
    cout << "                                     View Stock            " << endl;
    cout << endl
         << endl;
    cout << "\t"
         << "ITEM"
         << "\t"
         << "PRICE"
         << "\t"
         << "QUANTITY" << endl;
}
void viewStockAdminControl()
{
    for (int index = 0; index < itemsCount; index++)
    {
        if (items[index] == "0" && itemsPrice[index] == 0 && itemsQuantity[index] == 0)
        {
            continue;
        }
        cout << "\t" << items[index] << "\t" << itemsPrice[index] << "\t" << itemsQuantity[index] << endl;
    }
}
void selectRequiredItemsMenu()
{
    printHeader();
    cout << "                                     Add items             " << endl;
    cout << endl
         << endl;
    cout << "...Select your desired Item... " << endl
         << endl;
}
float selectRequiredItemsControl(string itemName, int itemQuantity, float moreSelection)
{
    float result;
    for (int index = 0; index < itemsCount; index++)
    {

        if (items[index] == itemName)
        {
            bills[index] = itemsPrice[index] * itemQuantity;
            result = bills[index];
        }
    }
    moreSelection = moreSelection + result;
    return moreSelection;
}
void customerFeedbackMenu()
{
    printHeader();
    cout << "                              Customer's FeedBack          " << endl;
    cout << endl
         << endl;
    cout << "...Enter the feedback... " << endl
         << endl;
}
string customerFeedback(string userName, string review)
{
    string isPresent = "false";
    for (int index = 0; index < customerCount; index++)
    {

        if (users[index] == userName)
        {
            isPresent = "true";
            feedback[index] = review;
            feedbackCount++;
        }
    }
    return isPresent;
}
void viewCustomerRecordAdminMenu()
{
    printHeader();
    cout << "                               Customer's Record           " << endl;
    cout << endl
         << endl;
    cout << "...Here are all users who signed up..." << endl
         << endl;
}
void viewCustomerRecordAdminMenuControl()
{
    for (int index = 0; index < customerCount; index++)
    {
        cout << "\t" << users[index] << "\t" << passwords[index] << endl;
    }
}
void customerReviewMenu()
{
    printHeader();
    cout << "                                  FeedBack Menu            " << endl;
    cout << "...Here are user's feedbacks..." << endl
         << endl;
}
void customerReview()
{
    for (int index = 0; index < customerCount; index++)
    {
        cout << "\t" << users[index] << "\t" << feedback[index] << endl;
    }
}
void adminSignUpMenu()
{
    printHeader();
    cout << "                                 Admin's Sign Up           " << endl;
    cout << endl
         << endl;
    cout << "...Enter the following information..." << endl
         << endl;
}
bool adminSignUpControl(string username, string password)
{
    bool isPresent = false;
    for (int index = 0; index < adminArraySize; index++)
        if (admins[index] == username && adminPasswords[index] == password)
        {
            isPresent = true;
            break;
        }

    if (isPresent == true)
    {
        return 0;
        cout << "...Admin's username or password Already exist...Try Again";
    }
    else if (adminCount < adminArraySize)
    {
        admins[adminCount] = username;
        adminPasswords[adminCount] = password;
        adminCount++;
        return true;
    }
    else
    {
        return false;
    }
}