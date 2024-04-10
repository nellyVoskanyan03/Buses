#ifndef BUS_H
#define BUS_H

#include <iostream>
#include <vector>
#include <string>

class Bus {
public:
	int startPoint;
	int endPoint;
	Bus(int s, int e):startPoint(s), endPoint(e){}

};

#endif // BUS_H