#include<iostream>
#include<fstream>
#include<cstdio>

using namespace std;

class Shop{
    private:
        string productName;
        int productCode;
        float productPrice;
        float productDiscount;

    public:
        void menu();
        void administrator();
        void buyer();
        void add();
        void edit();
        void remove();
        void list();
        void receipt();
};

void Shop :: menu(){
    // the call for goto will made and we will return to the next line of the function
    m:

    int choice;
    string email;
    string adminId;
    string password;

    cout << "\t\t\t -------------------------------------------- \n";
    cout << "\t\t\t -----------SuperMarket Main Menu------------ \n";
    cout << "\t\t\t -------------------------------------------- \n";
    cout << "                                             \n";

    cout << "\t\t\t\t 1. Administrator Login \n";
    cout << "\t\t\t\t 2. Customer Login \n";
    cout << "\t\t\t\t 3. Exit \n";

    cout << "                                             \n";
    cout << "                                             \n";
    cout << "\t\t\t\t Please enter an option from above!  \n";
    cin >> choice;

    switch(choice){
        case 1:
            cout << "Please enter Administrator Id:  \n";
            cin >> adminId;
            cout << "Enter Password: \n";
            cin >> password;

            if(adminId == "kj646" && password == "kj@646"){
                administrator();
            } else {
                cout << "Id and password does not match! \n";
            }
        case 2:
            buyer();
        case 3:
            exit(0);
        default:
            cout << "Please select from given option! \n";
    }

    goto m;
}

void Shop :: administrator(){
    m:

    int choice;

    cout << "\n\n\n\t\t\t Adminstrator Menu";
    cout << "\n\t\t\t____ 1. Add product: ";
    cout << "\n\t\t\t";
    cout << "\n\t\t\t____ 2. Modify product: ";
    cout << "\n\t\t\t";
    cout << "\n\t\t\t____ 3. Delete product: ";
    cout << "\n\t\t\t";
    cout << "\n\t\t\t____ 4. Back to main menu: ";


    cout << "\n\t\t Enter your choice: ";
    cin >> choice;

    switch(choice){
        case 1:
            add();
            break;
        case 2:
            edit();
            break;
        case 3:
            remove();
            break;
        case 4:
            menu();
            break;
        default:
            cout << "\n\t\t\t |||| Invalid Choice ||||| ";
    }

    goto m;
}

void Shop :: buyer(){

    m:

    int choice;

    cout << "\n\t\t\t____ Buyer Menu ";
    cout << "\n\t\t\t";
    cout << "\n\t\t\t____ 1. Buy Product: ";
    cout << "\n\t\t\t";
    cout << "\n\t\t\t____ 2. Go back: ";
    cout << "\n\t\t\t";
    
    cout << "\n\t\t Enter your choice: ";
    cin >> choice;

    switch(choice){
        case 1:
            receipt();
            break;
        case 2:
            menu();
            break;
        default:
            cout << "\n\t\t\t |||| Invalid Choice ||||| ";    
    }

    goto m;
}

void Shop :: add(){

    m:

    fstream data;
    int c;
    int token = 0;
    float p;
    float d;
    string n;

    cout << "\n\n\t\t\t------- Add new product --------";
    cout << "\n\n\t Product code: ";
    cin >> productCode;
    cout << "\n\n\t Product name: ";
    cin >> productName;
    cout << "\n\n\t Product price: ";
    cin >> productPrice;
    cout << "\n\n\t Product discount: ";
    cin >> productDiscount;

    // we will put all this data in the file for the customer
    data.open("productDB.txt", ios :: in);

    if(!data){
        data.open("productDB.txt", ios :: app | ios :: out);
        data << " " << productCode << " " << productName << " " << productPrice << " " << productDiscount;
        data.close();
    } else {
        data >> c >> n >> p >> d;

        while(!data.eof()){
            if(c == productCode){
                token++;
            }
            data << c << n << p << d;
        }
        data.close();

        if(token == 1){
            goto m;
        } else {
            data.open("productDB.txt", ios :: app | ios :: out);
            data << " " << productCode << " " << productName << " " << productPrice << " " << productDiscount;
            data.close();
        }
    }
    cout << "-------------------- Product Recorded ----------------- " << endl;
} 


void Shop :: edit(){
    fstream data, data1;
    int productKey;
    int token = 0;
    int c;
    float p;
    float d;
    string n;

    cout << "\n\t\t\t Modify the record!!!!";
    cout << "\n\t\t\t Product code: ";
    cin >> productKey;

    data.open("productDB.txt", ios :: in);
    if(!data){
        cout << "\n\t\t File doesn't exist!!!";
    } else {
        data1.open("productDB2.txt", ios :: app | ios :: out);
        data >> productCode >> productName >> productPrice >> productDiscount;

        while(!data.eof()){
            if(productKey == productCode){
                cout << "\n\n\t Product new code: ";
                cin >> c;
                cout << "\n\n\t Product name: ";
                cin >> n;
                cout << "\n\n\t Product price: ";
                cin >> p;
                cout << "\n\n\t Product discount: ";
                cin >> d;
                data1 << c << " " << n << " " << p << " " << d;

                cout << "\n\t\t\t Record edited!" << endl;
                token++;
            } else {
                data1 << " " << productCode << " " <<productName << " " << productPrice << " " << " " << productDiscount << endl;
            }

            data >> productCode >> productName >> productPrice >> productDiscount;
        }
        data.close();
        data1.close();

        // string tempString = "productDB.txt";
        // remove(tempString);
        rename("productDB.txt", "trash.txt");
        rename("productDB2.txt", "productDB.txt");

        if(token == 0){
            cout << "Record doesn't exist!!! Try correct product code" << endl; 
        }
    }
}


void Shop :: remove(){
    fstream data, data1;
    int productKey;
    int token = 0;

    cout << "---------------------Deleting Product----------" << endl;
    cout << "\n\n\t\t\t Enter product key of the product: " ;
    cin >> productKey;

    data.open("productDB.txt", ios :: in);
    if(!data){
        cout << "\n\t\t File doesn't exist!!!";
    } else {
        data1.open("productDB2.txt", ios :: app | ios :: out);
        data >> productCode >> productName >> productPrice >> productDiscount;

        while(!data.eof()){
            if(productCode == productKey){
                cout << "\n\t\t\t Product Deleted!" << endl;
                token++;
            } else {
                data1 << " " << productCode << " " <<productName << " " << productPrice << " " << " " << productDiscount << endl;
            }
            data >> productCode >> productName >> productPrice >> productDiscount;
        }
        data.close();
        data1.close();

        rename("productDB.txt", "trash2.txt");
        rename("productDB2.txt", "productDB.txt");

        if(token == 0){
            cout << "Record doesn't exist!!! Try correct product code!!!" << endl; 
        }
    }

}

void Shop :: list(){
    fstream data;
    data.open("productDB.txt", ios :: in);
    cout << "\n\n\t -------------------------------------------------------\t";
    cout << "\n\t Product Code \t\t Product Name \t\t Price \n";
    cout << "\n\n\t -------------------------------------------------------\t";
    data >> productCode >> productName >> productPrice >> productDiscount;

    while(!data.eof()){
        cout << "\n\t " << productCode <<" \t\t " << productName << " \t\t " << productPrice << " \n";
        data >> productCode >> productName >> productPrice >> productDiscount;
    }
    data.close();

}

void Shop :: receipt(){
    m:

    fstream data;
    int codes[100];
    int quantities[100];
    char choice;
    int count = 0;
    float amount = 0;
    float disc = 0;
    float total = 0;

    cout << "\n ------------------------ Generate the cart -------------------- \n";
    data.open("productDB.txt", ios :: in);
    if(!data){
        cout << "\n\t\t File doesn't exist!!!";
    } else {
        data.close();

        list();

        cout << "\n\n\t -------------------------------------------------------\t";

        cout << "\n Start placing the order! \n";

        cout << "\n\n\t -------------------------------------------------------\t";


        do{
            cout << "\n\n\t\t\t Enter product code: ";
            cin >> codes[count];
            cout << "\n\t\t\t Enter product quantity: ";
            cin >> quantities[count];
            for (int i = 0; i < count; i++){
                if(codes[count] == codes[i]){
                    cout << "\n\n Duplicate product code! Please try again!";
                    goto m;
                }
            }
            count++;
            cout << "\n\n\t\t\t Want to add another product? ";
            cin >> choice;
        } while(choice == 'y');
    }
    
    cout << "\n ------------------------ RECEIPT -------------------- \n";
    cout << "\n\t Product Code \t Product Name \t Product Quantity \t Product Price \t Amount \t Amount after Discount \n";

    for(int i = 0; i < count; i++){
        data.open("productDB.txt", ios :: in);
        data >> productCode >> productName >> productPrice >> productDiscount;
        while(!data.eof()){
            if(productCode == codes[i]){
                amount += productPrice*quantities[i];
                disc = amount - (amount*productDiscount/100);
                total += disc;
                cout << "\n\t " << productCode << " \t "  << productName << " \t " << quantities[i] << " \t " << productPrice << " \t " << amount << " \t " << disc; 
            }
            data >> productCode >> productName >> productPrice >> productDiscount;
        } 
        ////////////////////////////////////////// might give error
        data.close();
    }

    cout << " --------------------------------------------" << endl;
    cout << "Total: " << total;
}


int main(){
    Shop s;
    s.menu();
}