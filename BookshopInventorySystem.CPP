#include <iostream.h>
#include <string.h>
#include<stdlib.h>
#include<conio.h>

class Bookshop {                   
public:
    char author[20];
    char title[20];
    char publisher[20];
    int price;
    int copies;
    int req_cop;

    void feedData();                  
    void display();                 
};

void Bookshop::feedData() {       
    cout << "\n\n\n Please Enter The Following Details to feed data :\n";
    cout << "\n Title:";
    cin >> title;
    cout << "\n Author's Name:";
    cin >> author;
    cout << "\n Publisher:";
    cin >> publisher;
    cout << "\n Price:";
    cin >> price;
    cout << "\n Number of copies available:";
    cin >> copies;
    cout << "\n\n-------------------------------------------------------------------------";
    cout << "\n\t\t\t Books data successfully saved.";
    cout << "\n-------------------------------------------------------------------------";
}

void Bookshop::display() {          
    char aut[20];
    cout << "\n\n\n Please Enter The Following Details To Search For Book Is Available Or Not:\n";
    cout << "\n Title of the book:";
    cin >> title;
    cout << "\n Enter Author's Name:";
    cin >> aut;
    if (strcmp(author, aut) == 0) {
        cout << "\n Number of copies required:";
        cin >> req_cop;
    }

    if ((strcmp(author, aut) == 0) && (req_cop <= copies)) {
	cout << "\n\n-------------------------------------------------------------------------";
        cout << "\n\t\t Book is available in store.\n\t\t Price=" << req_cop * price;
	cout << "\n-------------------------------------------------------------------------";
    } else if (req_cop > copies) {
	cout << "\n-------------------------------------------------------------------------";
	cout << "\n\n\t\t Sorry!\n\n\t\t\t Book is out of stock. \n\t\t\t Books are falling short=" << req_cop - copies;
	cout << "\n-------------------------------------------------------------------------";
    } else {
	cout << "\n-------------------------------------------------------------------------";
	cout << "\n\t\t Sorry!\n\n\t\t We do not have the author's book.";
	cout << "\n-------------------------------------------------------------------------";
    }
}

int main() {
    getch();
    Bookshop bk;
    int choice;
    while (1) {
	cout << "\n\n\t\t\t\t Main MENU"
	     << "\n\n1. Entry of New Book"
	     << "\n2. Search For Book"
	     << "\n3. Exit"
	     << "\n\n Please Enter Your Choice: ";
	cin >> choice;

	switch (choice) {
	    case 1:
		bk.feedData();
		break;

	    case 2:
		bk.display();
		break;

	    case 3:
		exit(0);

	    default:
		cout << "Error! Please choose a number between 1 to 3.";
		break;
	}
    }
    return 0;
    clrscr();
}