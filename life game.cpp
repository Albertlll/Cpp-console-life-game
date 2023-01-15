// life game.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <windows.h>
#include <string>

using namespace std;


void copificator(string sym, size_t count) {
	for (int _ = 0; _ < count; _++) {
		cout << sym;
	}
	cout << "\n";
}
class Board {
public:
	vector <vector<int>> board;
	Board(int count_line_cells) {
		board.resize(count_line_cells);

		for (int i = 0; i < count_line_cells; i++) {
			board[i].resize(count_line_cells);
			for (int j = 0; j < count_line_cells; j++) {
				board.at(i).at(j) = 0;
			}
		}
	}

	void print_board() {
		cout << "\n";
		copificator(string("-"), board.capacity() * 2);

		for (int i = 0; i < 10; i++) {
				cout << "|";

			for (int j = 0; j < 10; j++) {
				if (board[j][i]) {
					cout << "#" << "|";
				}
				else {
					cout << " " << "|";
				}
			}
			cout << "\n";

			copificator(string("-"), board.capacity() * 2);
		}
	}

	bool is_in_edge(int(x), int(y)) {
		if (0 <= x and 0 <= y and
			x < board.capacity() and y < board.capacity()){
			return true;
		}
		return false;
	}

	bool is_cell_live(int x, int y) {
		int value = 0;
		for (int i = -1; i <= 1; i++) {
			for (int j = -1; j <= 1; j++) {
				if (i == 0 and j == 0) {
					continue;
				}
				if (is_in_edge(x + i, y + j) and board[x + i][y + j]) {
					value++;
				}
			}

		}


		if ((board[x][y] and (value == 2 or value == 3)) or 
			(!board[x][y] and value == 3)) {
			return true;
		}
		return false;

	}

	void next() {
		vector<vector<int>> new_board;
		new_board.resize(board.capacity());
		for (int i = 0; i < 10; i++) {
			vector<int> col;
			col.resize(board.capacity());
			for (int j = 0; j < 10; j++) {
				if (is_cell_live(i, j)) {
					col[j] = 1;
				}
				else {
					col[j] = 0;
				}
			}
			new_board[i] = col;
		}
		board = new_board;
	}


	void color_cell(int x, int y) {
		board[x][y] = 1;
	}
};

int main(){
	setlocale(LC_ALL, "RUS");
	Board game(10);
	//system("cls");
	bool writing_mode = true;
	while (true) {
		game.print_board();
		cout << "\n";

		if (writing_mode) {
			cout << "Введите координаты точки, которую хотите закрасить(1 координата в одну строчку через пробел)\nДля запуска напишите #\n";

			string x;
			string y;

			cin >> x;
			if (x == "#") {
				writing_mode = false;
			}
			else {
				cin >> y;
				game.color_cell(stoi(x), stoi(y));
			}


		}
		if (!writing_mode) {
			game.next();
		}


		Sleep(200);
		system("cls");
	}
}