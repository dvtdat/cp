#include <bits/stdc++.h>
using namespace std;
int coins = 50;

struct Players
{
	int flc = 0, vnindex = 0;
} player;


enum items { FLC = 10,
             VNINDEX = 60,
             FLAG = 100000 };

void win(){
    //REDACTED
    exit(0);
}

void buy() {
    int choice;
    do {
        cout << "What do you want to buy?\n";
        cout << "1. FLC stock - 10 coins\n";
        cout << "2. VNINDEX - 60 coins\n";
        cout << "3. Flag - 100000 coins\n";
        cout << "4. Exit\n";
        cin >> choice;
		if(choice < 1 || choice > 4) {
			cout << "Invalid choice\n";
			continue;
		}
        if (choice != 4) {
            int quantity;

            if (choice == 1) {
                cout << "How many do you want to buy?\n";
                cin >> quantity;
                if (coins >= FLC * quantity) {
                    coins -= FLC * quantity;
					player.flc += quantity;
                    cout << "You have bought " << quantity << " FLC stock\n";
                } else {
                    cout << "You don't have enough coins\n";
                }
            } else if (choice == 2) {
                cout << "How many do you want to buy?\n";
                cin >> quantity;
                if (coins >= VNINDEX * quantity) {
                    coins -= VNINDEX * quantity;
					player.vnindex += quantity;
                    cout << "You have bought " << quantity << " VNINDEX\n";
                } else {
                    cout << "You don't have enough coins\n";
                }
            } else if (choice == 3) {
                if (coins >= FLAG) {
                    coins -= FLAG;
                    win();
                } else {
                    cout << "You don't have enough coins\n";
                }
            }
        }
    } while (choice != 4);
}

void sell() {
	int choice;
	do {
		cout << "What do you want to sell?\n";
		cout << "1. FLC stock - 10 coins - " << player.flc << " in stock\n";
		cout << "2. VNINDEX - 60 coins - " << player.vnindex << " in stock\n";
		cout << "3. Exit\n";
		cin >> choice;
		if (choice < 1 || choice > 3) {
			cout << "Invalid choice\n";
			continue;
		}
		if (choice != 3) {
			int quantity;
			if (choice == 1) {
				cout << "How many do you want to sell?\n";
				cin >> quantity;
				if (quantity > player.flc) {
					cout << "You don't have enough FLC stock\n";
					continue;
				}
				coins += FLC * quantity;
				player.flc -= quantity;
				cout << "You have sold " << quantity << " FLC stock\n";
			} else if (choice == 2) {
				cout << "How many do you want to sell?\n";
				cin >> quantity;
				if (quantity > player.vnindex) {
					cout << "You don't have enough VNINDEX\n";
					continue;
				}
				coins += VNINDEX * quantity;
				player.vnindex -= quantity;
				cout << "You have sold " << quantity << " VNINDEX\n";
			}
		}
	} while (choice != 3);
}

int main() {
    int choice;
    cout << "Welcome to LHPOJ stock market!\n";
    cout << "You can buy or sell anything you want here!\n";
    cout << "You will have 50 coins at the beginning.\n";
    cout << "You can buy or sell items to earn coins.\n";
    cout << "You can also use the coins to buy flags.\n";
    cout << "Good luck!\n";
    do {
        cout << "=======================================\n";
        cout << "You have " << coins << " coins\n";
        cout << "1. Buy items\n";
        cout << "2. Sell items\n";
        cout << "3. Exit\n";
        cin >> choice;
		if(choice < 1 || choice > 3) {
			cout << "Invalid choice\n";
			continue;
		}
        if (choice == 1) {
			buy();
        }
		else if(choice == 2) {
			sell();
		}
    } while (choice != 3);
}