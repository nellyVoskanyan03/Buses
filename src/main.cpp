#include <iostream>
#include "city.h"

void test1();
void test2();
void test3();

int main() {
  
	City c;
	c.input();
	//test1();
	//test2();
	//test3();
  
	return 0;
}
void test1() {
	City c;
	c.addCrossRoad("A");
	c.addCrossRoad("B");
	c.addCrossRoad("C");
	c.addCrossRoad("D");
	c.addCrossRoad("E");
	c.addCrossRoad("F");

	c.constructStreet("A", "D", 6);
	c.constructStreet("C", "E", 3);
	c.constructStreet("E", "D", 4);
	c.constructStreet("B", "C", 5);
	c.constructStreet("A", "F", 7);

	c.addBus("A", "C");
	c.addBus("A", "F");
	c.addBus("A", "E");
	c.addBus("D", "E");

	c.constructStreet("A", "B", 2);

	c.busDetails(0);
	c.busDetails(1);
	c.busDetails(2);

	c.constructStreet("D", "B", 1);

	c.busDetails(0);
	c.busDetails(1);
	c.busDetails(2);

}

void test2() {
	City c;
	c.addCrossRoad("A");
	c.addCrossRoad("B");
	c.addCrossRoad("C");
	c.addCrossRoad("D");
	c.addCrossRoad("E");
	c.addCrossRoad("F");

	c.addBus("A", "B");

	
	c.constructStreet("A", "D", 1);
	c.constructStreet("C", "D", 7);
	c.constructStreet("F", "D", 6);
	c.constructStreet("F", "E", 5);
	c.constructStreet("B", "C", 3);
	c.constructStreet("B", "E", 4);
	c.constructStreet("A", "B", 2);

	c.addBus("A", "B");
	c.addBus("D", "F");
	c.addBus("C", "E");
	
	c.constructStreet("C", "F", 1);

	c.busDetails(0);
	c.busDetails(1);
	c.busDetails(2);

	c.constructStreet("C", "E", 2);

	c.busDetails(0);
	c.busDetails(1);
	c.busDetails(2);

	c.addBus("E", "F");

	c.busDetails(3);
}

void test3() {
	City c;
	c.addCrossRoad("A");
	c.addCrossRoad("B");
	c.addCrossRoad("C");
	c.addCrossRoad("D");
	c.addCrossRoad("E");
	c.addCrossRoad("F");
	c.addCrossRoad("G");

	c.constructStreet("A", "F", INT_MAX - 1);
	c.constructStreet("A", "G", 8888);
	c.constructStreet("B", "G", 50000000);
	c.constructStreet("F", "G", 20000);
	c.constructStreet("F", "C", 26543);
	c.constructStreet("E", "C", 2655);
	c.constructStreet("D", "C", 46000);
	c.constructStreet("D", "E", INT_MAX - 1);
	c.constructStreet("B", "E", 3989);


	c.addBus("A", "D");
	c.busDetails(0);
	c.addBus("D", "G");
	c.busDetails(1);
	c.addBus("A", "G");
	c.busDetails(2);

	c.constructStreet("C", "A", 179879);

	c.busDetails(0);
	c.busDetails(1);
	c.busDetails(2);

	c.constructStreet("C", "G", 2987);

	c.busDetails(0);
	c.busDetails(1);
	c.busDetails(2);

	c.addBus("E", "F");

	c.busDetails(3);
}