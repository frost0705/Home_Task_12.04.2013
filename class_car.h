
///@author Morozov Nikolay IU8-21





/**
@class car

@param power �������� ��������
@param fuelConsumtion ������ ������� �� 100 �� ����
@param weight ����������� ����� ����������
@param fullSpeed ������������ �������� ����������
@param timeOfAcceleration ����� ������� 0-100 ��/�


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

	///�����������, ����������� ��� ��������� ������
	car(int power, int fuelConsumption, int weight, int fullSpeed, double timeOfAcceleration)
	{
		car::power = power;
		car::fullSpeed = fullSpeed;
		car::weight = weight;
		car::fuelConsumption = fuelConsumption;
		car::timeOfAcceleration = timeOfAcceleration;
	};
	///�����������, ����������� ����� ���������� � ����������� ��������� ����� ���������
	car(int weight, int fullSpeed, double timeOfAcceleration)
	{
		car::weight = weight;
		car::fullSpeed = fullSpeed;
		car::timeOfAcceleration = timeOfAcceleration;
		car::power = (weight/timeOfAcceleration);
		car::fuelConsumption = (car::power)/11.5;
	};
	///����������
	~car()
	{
		car::weight = 0;
		car::fullSpeed = 0;
		car::timeOfAcceleration = 0;
		car::power = 0;
		car::fuelConsumption = 0;
	};
	///��������� ����� ����������
	int get_weight()
	{
		return car::weight;
	};
	///��������� ������������ ��������
	int get_full_speed()
	{
		return fullSpeed;
	};
	///��������� ������� ������� 0-100 ��/�
	double get_time_of_acceleration()
	{
		return car::timeOfAcceleration;
	};
	///��������� �������� ����������
	int get_power()
	{
		return car::power;
	};
	///��������� ������� ������� �/100��
	int get_fuel_consumption()
	{
		return car::fuelConsumption;
	};
	///������ ���������
	void engine_tuning(int powerChange, int fuelConsumptionChange)
	{
		car::power += powerChange;
		car::fuelConsumption += fuelConsumptionChange;
	};
	///������ ��������� ����� 2
	void engine_tuning(int powerChange)
	{
		car::power += powerChange;
		car::fuelConsumption = (car::power)/11.5;
	};
};