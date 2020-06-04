#pragma once
class chset {
private:
	char* value;
	int count;
public:
	chset() : count(0), value(nullptr) { }
	chset(const chset&);
	~chset();
	inline bool empty() const { return count == 0; }
	inline char getChar(int position) const { return value[position]; }
	inline int size() const { return count; }
	void push(const char item);
	void remove(const char item);
	void print();
	void input(int size);
	bool subset(const char item);
	bool subset(const chset&);

	chset& operator-=(const char);
	chset& operator=(const chset&);
	chset& operator*=(const chset&);
	bool operator<(const chset&);
	friend chset operator-(const chset&, const char);
	friend chset operator*(const chset&, const chset&);
};