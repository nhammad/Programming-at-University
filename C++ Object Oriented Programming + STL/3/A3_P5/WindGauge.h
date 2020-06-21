/*
CH08-320143
a3_p5.cpp
nhammad
n.hammad@jacobs-university.de
*/
#include <vector>
#include <deque>

using namespace std;

class WindGauge
{
public:
    WindGauge(unsigned int period = 10);
    void currentWindSpeed(int speed);
    int highest() const;
    int lowest() const;
    int average() const;
    void print();
    deque<int> getter();

private:
    deque <int> gauge;
    unsigned int period;
    int speed;

};

//I changed the int to unsigned int
//to make valid comparisons and avoid warnings
//alternative method is to use ((int)d.size() == period)
//in cpp section
