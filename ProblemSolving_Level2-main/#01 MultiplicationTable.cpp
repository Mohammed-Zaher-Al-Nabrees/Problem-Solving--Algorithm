void printHeaderTable(int from, int to) {
	cout << "	";
	for (int j = from; j <= to;j++) {
		cout << j << "	";
	}
	cout << "\n";
	for (int j = from; j <= to;j++) {
		cout << "---------";
	}
	cout << "\n";
}
void columnSeperator(int i) {
	if (i < 10) {
		cout << "  |	";
	}
	else {
		cout << " |	";
	}
}
void printMultiplicationTable(int from, int to) {
	printHeaderTable(from, to);
	for (int i = from; i <= to;i++) {
		cout << " " << i;
		columnSeperator(i);

		for (int j = from; j <= to;j++) {

			cout << i * j << "	";
		}
		cout << "\n";
	}
}

int main() {
	printMultiplicationTable(1,10);
	return 0;
}
