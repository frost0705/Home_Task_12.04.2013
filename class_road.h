///Примечание на будущее для себя: надо бы добавит проверку на отрицательные числа в конструкторе



/**
@class road

@param length длинна дороги
@param maxSpeed макимальная разрешенная скорость
@param weight снаряженная масса автомобиля
@param minTravelTime минимальное время в пути
@param qualityOfRoad качество дороги. Коэффициэнт, научное объяснение которому еще предстоит придумать.


*/

class road
{
private:
	int length;
	int maxSpeed;
	double minTravelTime;
	int qualityOfRoad;

public:

	///Первый конструктор: задаем все кроме времени в пути. Оно вычисляется внутри конструктора
	road(int length, int maxSpeed, int qualityOfRoad)
	{
		road::length = length;
		road::maxSpeed = maxSpeed;	
		road::minTravelTime = length/maxSpeed;
		road::qualityOfRoad = qualityOfRoad;;
	};
	///Второй конструктор. На этой дороге лимит скорости либо неизвестен, либо не задан
	road(int length, int qualityOfRoad)
	{

		road::length = length;
		road::maxSpeed = -1;
		road::minTravelTime = -1;
		road::qualityOfRoad = qualityOfRoad;;
	};
	///Деструктор
	~road()
	{
		road::length = 0;
		road::maxSpeed = 0;			
	};
	///Получить длину дороги
	int get_length()
	{
		return road::length;
	}
	///Получить максимальную разрешенную скорость
	int get_max_speed()
	{
		return road::maxSpeed;
	}
	///Изменить протяженность пути
	void change_length(int lengthChange)
	{
		road::length +=lengthChange;
	};
	///Изменить максимальную скорость.
	void change_max_speed(int maxSpeedChange)
	{
		road::length +=maxSpeedChange;
	};
	///Врея в пути. Зависит от скорости автомобиля.
	double travel_time(int maxSpeedOfCar)
	{
		double answer;
		if ((road::maxSpeed == -1)||(maxSpeedOfCar <= road::maxSpeed))
		{
			answer = (double)((road::length)/maxSpeedOfCar);
		}
		else
		{
			answer = (double)((road::length)/(road::maxSpeed));	
		}
		return answer;
	};
	///Получить минимальное время в пути.
	double get_min_travel_time()
	{
		return minTravelTime;
	};
};

