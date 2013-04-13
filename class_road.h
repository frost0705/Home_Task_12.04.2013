class road
{
private:
	int length;
	int maxSpeed;
	double minTravelTime;
	int qualityOfRoad;

public:
	road(int length, int maxSpeed, int qualityOfRoad)
	{
		road::length = length;
		road::maxSpeed = maxSpeed;	
		road::minTravelTime = length/maxSpeed;
		road::qualityOfRoad = qualityOfRoad;;
	};

	road(int length, int qualityOfRoad)
	{

		road::length = length;
		road::maxSpeed = -1;
		road::qualityOfRoad = qualityOfRoad;;
	};

	~road()
	{
		road::length = 0;
		road::maxSpeed = 0;			
	};

	int get_length()
	{
		return road::length;
	}

	int get_max_speed()
	{
		return road::maxSpeed;
	}

	void change_length(int lengthChange)
	{
		road::length +=lengthChange;
	};

	void change_max_speed(int maxSpeedChange)
	{
		road::length +=maxSpeedChange;
	};

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

	double get_min_travel_time()
	{
		return minTravelTime;
	};
};

