#pragma once
class Student {
	string _name = "";
	string _surname = "";
	double _score = 0;
public:
	Student() = default;
	Student(string name, string surname, double score)
	{
		_name = name;
		_surname = surname;
		_score = score;
	}

	bool operator>(const Student& other) {
		if (_score > other._score) return true;
		return false;
	}

	bool operator<(const Student& other) {
		if (_score < other._score) return true;
		return false;
	}

	bool operator==(const Student& other) {
		if (_score == other._score) return true;
		return false;
	}

	friend ostream& operator<<(ostream& out, const Student& s);
	friend istream& operator>>(istream& input, Student& s);
};

ostream& operator<<(ostream& out, const Student& s) {
	out << "Name: " << s._name << endl << "Surname: " << s._surname << endl << "Score: " << s._score << endl;
	return out;
}

istream& operator>>(istream& out, Student& s) {
	cout << "Name: ";
	getline(out, s._name);

	cout << "Surname: ";
	getline(out, s._surname);

	cout << "Score: ";
	out >> s._score;

	cin.ignore();
	return out;
}

