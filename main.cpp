#include <list>
#include <string>
#include <iostream>
#include <conio.h>
#include "class_car.h"
#include "class_road.h"
using namespace std ;

typedef list<car> list_car;
typedef list<road> list_road;
///basic task: calculation of fuel for passage ways
int fuel_consumption_on_a_route(int fuelConsumption, int roadLength)
{
	return (roadLength*fuelConsumption/100)+1;
}
///Playing repeatedly asked by the decision. This function handles the input error response.
void choice_way_bad_input(char *choice, char firstWay, char secondWay)
{
	while ((choice[0] != firstWay)&&(choice[0] != secondWay))
	{
		cout << "Invalid input. Please try again. \n y\\n?\n";
		choice[0] = _getch();
	}
}
///demo script
void demo_mode()
{
	list_car::iterator i;
	list_road::iterator j;
	list_car cars;
	list_road roads;
	
	cars.insert(cars.end(),car(1500,182,10.1));
	cars.insert(cars.end(),car(1000,250,6.1));
	cars.insert(cars.end(),car(800,140,15));
	cars.insert(cars.end(),car(1200,60,3000,415,2.3));
	cars.insert(cars.end(),car(600,22,4000,210,6.1));
	cars.insert(cars.end(),car(400,18,2100,120,20.3));

	roads.insert(roads.end(),road(1256,10));
	roads.insert(roads.end(),road(3457,12));
	roads.insert(roads.end(),road(500,110,3));
	roads.insert(roads.end(),road(431,90,5));

	int k,t;
	for (t = 1, i = cars.begin(); i !=cars.end(); i++, t++)
	{
		cout << "Car number"<< t << '\n';
		for (k = 1, j = roads.begin(); j != roads.end(); ++j, k++)
		{
			cout << "On road number" << k << " will be spent " << fuel_consumption_on_a_route(i->get_fuel_consumption(),j->get_length()) <<" liters of fuel\n";
		}
		cout << '\n';
	}

	int g = 0;
}
///Working script
void work_mode()
{
	list_car::iterator i;
	list_road::iterator j;
	list_car cars;
	list_road roads;
	///Preparing input cars
	char choice;
	cout << "Input of cars.";
	choice = 'y';
	cout << "Select the input mode.\n";
	cout << "	1 - power, fuel consumption, weight, full speed, time of acceleration\n";
	cout << "	2 - weight, full speed, time of acceleration (Other params will be calculated utomatically)\n";

	char choice2 = _getch();
	choice_way_bad_input(&choice2,'1','2');
	///Cars add
	while (choice == 'y')
	{
		

		if (choice2 == '1')
		{
			int p,s,w,f,t;
			cout << "power - ";
			cin >> p;
			cout << " fuel consumption - ";
			cin >> f;
			cout << "weight - ";
			cin >> w;
			cout << "full speed - ";
			cin >> s;
			cout << "time of acceleration - ";
			cin >> t;

			cars.insert(cars.end(),car(p,f,w,s,t));

		}
		else
		{
			int w,s,t;
			cout << "weight - ";
			cin >> w;
			cout << "full speed - ";
			cin >> s;
			cout << "time of acceleration";
			cin >> t;
			cars.insert(cars.end(),car(w,s,t));
		}
		cout << "Do you want add new car? \n y\\n\n";
		choice = _getch();
		choice_way_bad_input(&choice,'y','n');

	}
	///Preparing input roads
	cout << "Input of roads.";
	choice = 'y';
	cout << "Select the input mode.\n";
	cout << "	1 - length, max speed\n";
	cout << "	2 - length (Speed will be unlimited)\n";
	choice2 = _getch();
	choice_way_bad_input(&choice,'1','2');
	///Roads add
	while (choice == 'y')
	{
		if (choice2 == '1')
		{
			int l,s,q;
			cout << "length - ";
			cin >> l;
			cout << " max speed - ";
			cin >> s;
			cout << "quality of road - ";
			cin >> q;
			roads.insert(roads.end(),road(l,s,q));
		}
		else
		{
			int l,q;
			cout << "length - ";
			cin >> l;
			cout << "quality of road - ";
			cin >> q;
			roads.insert(roads.end(), road(l,q));
		}
		cout << "Do you want add new road? \n y\\n\n";
		choice = _getch();
		choice_way_bad_input(&choice,'y','n');
	}

	int k,t;
	for (t = 1, i = cars.begin(); i !=cars.end(); i++, t++)
	{
		cout << "Car number"<< t << '\n';
		for (k = 1, j = roads.begin(); j != roads.end(); ++j, k++)
		{
			cout << "On road number" << k << " will be spent " << fuel_consumption_on_a_route(i->get_fuel_consumption(),j->get_length()) <<" liters of fuel\n";
		}
		cout << '\n';
	}

}


int main()
{	
   	char choice;
	
	cout << "Do you want to run in demo mode? y\\n\n";
	choice = getch();

	choice_way_bad_input(&choice,'y','n');

	if (choice == 'y')
	{
		demo_mode();
	}
	else
	{
		work_mode();
	}
}