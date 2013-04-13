
///@author Morozov Nikolay IU8-21





/**
@class car

@param power мощность двигатея
@param fuelConsumtion расход топлива на 100 км пути
@param weight снаряженная масса автомобиля
@param fullSpeed максимальная скорость автомобиля
@param timeOfAcceleration время разгона 0-100 км/ч


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

	///Конструктор, принимающий все параметры класса
	car(int power, int fuelConsumption, int weight, int fullSpeed, double timeOfAcceleration)
	{
		car::power = power;
		car::fullSpeed = fullSpeed;
		car::weight = weight;
		car::fuelConsumption = fuelConsumption;
		car::timeOfAcceleration = timeOfAcceleration;
	};
	///Конструктор, принимающий часть параметром и вычисляющий остальные через имеющиеся
	car(int weight, int fullSpeed, double timeOfAcceleration)
	{
		car::weight = weight;
		car::fullSpeed = fullSpeed;
		car::timeOfAcceleration = timeOfAcceleration;
		car::power = (weight/timeOfAcceleration);
		car::fuelConsumption = (car::power)/11.5;
	};
	///Деструктор
	~car()
	{
		car::weight = 0;
		car::fullSpeed = 0;
		car::timeOfAcceleration = 0;
		car::power = 0;
		car::fuelConsumption = 0;
	};
	///Получение массы автомобиля
	int get_weight()
	{
		return car::weight;
	};
	///Получение максимальной скорости
	int get_full_speed()
	{
		return fullSpeed;
	};
	///Получение времени разгона 0-100 км/ч
	double get_time_of_acceleration()
	{
		return car::timeOfAcceleration;
	};
	///Получение пощности автомобиля
	int get_power()
	{
		return car::power;
	};
	///Получение расхода топлива л/100км
	int get_fuel_consumption()
	{
		return car::fuelConsumption;
	};
	///Тюнинг двигателя
	void engine_tuning(int powerChange, int fuelConsumptionChange)
	{
		car::power += powerChange;
		car::fuelConsumption += fuelConsumptionChange;
	};
	///Тюнинг двигателя часть 2
	void engine_tuning(int powerChange)
	{
		car::power += powerChange;
		car::fuelConsumption = (car::power)/11.5;
	};
};