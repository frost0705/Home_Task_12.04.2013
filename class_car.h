///@author Morozov Nikolay IU8-21
/**
@class car

@param power engine power
@param fuelConsumtion fuel consumption per 100 kilometers
@param weight curb weight of the vehicle
@param fullSpeed top speed
@param timeOfAcceleration the acceleration of 0-100 km / h
*/
class car
{
private:
	int power;
	int fuelConsumption;
	int weight;
	int fullSpeed;
	double timeOfAcceleration;

public:

	///Constructor that takes all parameters class
	car(int power, int fuelConsumption, int weight, int fullSpeed, double timeOfAcceleration)
	{
		car::power = power;
		car::fullSpeed = fullSpeed;
		car::weight = weight;
		car::fuelConsumption = fuelConsumption;
		car::timeOfAcceleration = timeOfAcceleration;
	};
	///Constructor that takes a parameter and calculates the portion remaining in the existing
	car(int weight, int fullSpeed, double timeOfAcceleration)
	{
		car::weight = weight;
		car::fullSpeed = fullSpeed;
		car::timeOfAcceleration = timeOfAcceleration;
		car::power = (weight/timeOfAcceleration);
		car::fuelConsumption = (car::power)/11.5;
	};
	///destructor
	~car()
	{
		car::weight = 0;
		car::fullSpeed = 0;
		car::timeOfAcceleration = 0;
		car::power = 0;
		car::fuelConsumption = 0;
	};
	///Getting the car weight
	int get_weight()
	{
		return car::weight;
	};
	///Getting the maximum speed
	int get_full_speed()
	{
		return fullSpeed;
	};
	///Obtaining acceleration 0-100 km / h
	double get_time_of_acceleration()
	{
		return car::timeOfAcceleration;
	};
	///Getting powered car
	int get_power()
	{
		return car::power;
	};
	///Getting fuel l/100km
	int get_fuel_consumption()
	{
		return car::fuelConsumption;
	};
	///engine tuning
	void engine_tuning(int powerChange, int fuelConsumptionChange)
	{
		car::power += powerChange;
		car::fuelConsumption += fuelConsumptionChange;
	};
	///Engine tuning part 2
	void engine_tuning(int powerChange)
	{
		car::power += powerChange;
		car::fuelConsumption = (car::power)/11.5;
	};
};