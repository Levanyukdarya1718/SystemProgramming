#include <iostream>
using namespace std;

#define MIN_TANK_CAPACITY 20
#define MAX_TANK_CAPACITY 120
class Tank
{
	double fuel_level;
public:
	const  int CAPACITY;
	double get_fuel_level()const
	{
		return fuel_level;
	}
	Tank(int  capacity):CAPACITY
		(
		capacity < MIN_TANK_CAPACITY ? MIN_TANK_CAPACITY:
		capacity > MAX_TANK_CAPACITY ? MAX_TANK_CAPACITY:
		capacity
		)
	{
		if (capacity < MIN_TANK_CAPACITY)cout << "Min capacity was applied" << endl;
		if (capacity > MAX_TANK_CAPACITY)cout << "Max capacity was applied " << endl;
		//this->CAPACITY = capacity;
		this->fuel_level = 0;
		cout << "Tank is ready" << endl;
	}
	~Tank()
	{
		cout << "Tank is over" << endl;
		//My Darkest Days -Come undone
	}
	double fill(double amount)
	{
		if (amount < 0)return fuel_level;
		fuel_level += amount;
		if (fuel_level > CAPACITY)
		{
			fuel_level = CAPACITY;
			cout << "Full Tank" << endl;
		}
		return fuel_level;
	}
	double give_fuel(double amount)
	{
		fuel_level -= amount;
		if (fuel_level < 0)fuel_level = 0;
		return fuel_level;
	}
	void info()const

	{
		cout << "Capacity:\t" << CAPACITY<<"liters/\n";
		cout << "Fuel level:\t" << fuel_level << "liters.\n";
	}
};
#define MIN_ENGINE_CONSUMPTION	5
#define MAX_ENGINE_CONSUMPTION	50
class Engine
{
	double consumption_ls;
	bool running;
public:
	const double CONSUMPTION;

	double get_consuption_ls()const
	{
		return consumption_ls;
	}
	Engine(double consumption) :CONSUMPTION
	(

		consumption < MIN_ENGINE_CONSUMPTION ? MIN_ENGINE_CONSUMPTION :
		consumption > MAX_ENGINE_CONSUMPTION ? MAX_ENGINE_CONSUMPTION :
		consumption

	), running(false)
	{
		
		consumption_ls = CONSUMPTION * 0.0003;
		cout << "Engine is ready:" << endl;
	}
	~Engine()
	{
		cout << "Engine is over"  << endl;
	}
	void engine_start()
	{
		running = true;
	}
	void engine_stop()
	{
		running = false;
	}
	void info()const
	{
		cout << CONSUMPTION << " l/100km" << endl;
		cout << consumption_ls << " l/s" << endl;
	}

};

void main()
{
	setlocale(LC_ALL, "");
	Tank tank(80);
	tank.info();
	Engine engine(10);
	engine.info();
	double fuel;
	do
	{
		cout << "На сколько заправляемся?"; cin >> fuel;
		tank.fill(fuel);
		tank.info();
	} while (true);


}