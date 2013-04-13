///@author Morozov Nikolay IU8-21

///Примечание на будущее для себя: надо бы добавит проверку на отрицательные числа в конструкторе
/**
@class road

@param length length of the road
@param maxSpeed red line speed
@param weight curb weight of the vehicle
@param minTravelTime minimum travel time
@param qualityOfRoad the quality of the road. Factor, a scientific explanation has yet to come up.
*/

class road
{
private:
	int length;
	int maxSpeed;
	double minTravelTime;
	int qualityOfRoad;

public:

	///The first constructor: ask all but the travel time. It is calculated within the constructor
	road(int length, int maxSpeed, int qualityOfRoad)
	{
		road::length = length;
		road::maxSpeed = maxSpeed;	
		road::minTravelTime = length/maxSpeed;
		road::qualityOfRoad = qualityOfRoad;;
	};
	///The second constructor. On this road the speed limit either unknown or unspecified
	road(int length, int qualityOfRoad)
	{

		road::length = length;
		road::maxSpeed = -1;
		road::minTravelTime = -1;
		road::qualityOfRoad = qualityOfRoad;;
	};
	///destructor
	~road()
	{
		road::length = 0;
		road::maxSpeed = 0;			
	};
	///Get the length of the road
	int get_length()
	{
		return road::length;
	}
	///Get speed limit
	int get_max_speed()
	{
		return road::maxSpeed;
	}
	///Change the length of the path
	void change_length(int lengthChange)
	{
		road::length +=lengthChange;
	};
	///Change the maximum speed.
	void change_max_speed(int maxSpeedChange)
	{
		road::length +=maxSpeedChange;
	};
	///Travel time. Depends on the speed of the car.
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
	///Minimal time on the road.
	double get_min_travel_time()
	{
		return minTravelTime;
	};
};

