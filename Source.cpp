#include <iostream>
#include <lll.h>
using namespace std;
int main() {

	setlocale(LC_ALL, "rus");

	char field[3][3];
	unit_field(field);
	print_field(field);
	while (true) {
		player_turn(field);
		print_field(field);
		if (check_win(field, 'o')) {
			cout << "победа х" << endl;
		}
	}
	if (check_draw(field)) {
		cout << "ничья" << endl;
	}
	//основной цикл игры
	while (true) {
		
	}

	return 0;
}

void unit_field(char field[3][3]) {
	for (int i = 0; i < 3; i ++) {
		for (int j = 0; j < 3; j++) {
			field[i][j] = ' ';
		}
	}
}

void print_field(char field[3][3]) {
	for (int i = 0; i < 3; i++) {
		cout << "|---|---|---|" << endl;
		for (int j = 0; j < 3; j++) {
			cout << "| " << field[i][j] << ' ';
		}
		cout << "|" << endl;
	}
	cout << "|---|---|---|" << endl;
}

void player_turn(char field[3][3]) {
	int row, col;
	char sign;
	do {
		cout << "Введите номер строки поля ";
		cin >> row;
	} while (row < 0 || row > 2);
	do {
	cout << "Введите номер столбца поля ";
	cin >> col;
	} while (col < 0 || col > 2);
	do {
	cout << "Введите знак ";
	cin >> sign;
	} while (sign != 'x' && sign != 'o');
}
bool check_win(char field[3][3], char sign) {
	char sign;
	if (field[0][0] == sign && field[0][1] == sign && field[0][2] == sign) { cout << "победа" << endl; }
	if (field[1][0] == sign && field[1][1] == sign && field[1][2] == sign) { cout << "победа" << endl; }
	if (field[2][0] == sign && field[2][1] == sign && field[2][2] == sign) { cout << "победа" << endl; }

	if (field[0][0] == sign && field[1][0] == sign && field[2][0] == sign) { cout << "победа" << endl; }
	if (field[0][1] == sign && field[1][1] == sign && field[2][1] == sign) { cout << "победа" << endl; }
	if (field[0][2] == sign && field[1][2] == sign && field[2][2] == sign) { cout << "победа" << endl; }

	if (field[0][0] == sign && field[1][1] == sign && field[2][2] == sign) { cout << "победа" << endl; }
	if (field[2][0] == sign && field[1][1] == sign && field[0][2] == sign) { cout << "победа" << endl; }
	return false;
}
bool check_draw(char field[3][3]) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (field[i][j] = ' ') return false;
		}
	}
	return true;
}