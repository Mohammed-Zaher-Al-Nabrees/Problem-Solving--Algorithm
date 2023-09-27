		bool isValidDate(sDate date) {
			return(date.day > 1 && date.day <= countDaysInMonth(date.year, date.month));
		}
    sDate readDate() {
			calendar::sDate date;
			bool first = true;
			do {
				if (!first) cout << "\nWrong entering please reenter the date :\n";else first = false;
				date.day = read::readNumberMsg("Please enter a day :");
				date.month = read::readNumberMsg("Please enter a month :");
				date.year = read::readPositiveNumberMsg("Please enter a year :");
				cout << "\n";
			} while (!isValidDate(date));

			return date;
		}


int main() {
	sDate date = readDate();

	return 0;
}
