

#include "stdafx.h"

	//получаем величину стороны n-угольника
	double n_angle :: get_side()
	{
		return 2 * radius * sin(M_PI / n);
	}

	//получаем площадь n-угольника
	double n_angle::get_area()
	{
		return (n / 2)*pow(radius, 2)*sin(2 * M_PI / n);
	}
	//получаем периметр n-угольника
	double n_angle::get_P()
	{
		return get_side()*n;
	}
	//получаем параметры n-угольника
	void n_angle :: get_parametrs()
	{
		cout << "parametrs of n-angle:\n";
		cout << "perimetr of n_angle:\n"
			<< get_P();
		cout << "\narea of n_angle:\n" 
			<< get_area();
		cout << "\nside of n_angle:\n" 
			<< get_side();
		cout << "\nradius of circumcircle:\n" 
			<< radius;
		cout << "\namount of sides:\n" 
			<< n;
	}

	//перемещение ценра в новые координаты
	void n_angle:: move(double x_, double y_)
	{
		x = x_;
		y = y_;
	}

	//изменение размеров на какую-либо величину 
	void n_angle:: resizing_by_side(double a)
	{
		radius = (get_side() + a) / 2 / sin(M_PI / n);
	}
	void n_angle:: resizing_by_rad(double a)
	{
		radius = radius + a;
	}
	//перегрузка оператора сравнения двух n-угольников
	bool n_angle::operator== (n_angle f)
	{
		if (this->radius == f.radius)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	
	//определение пересечения двух n-угольников
	bool n_angle :: crossing(n_angle obj)
	{
		double l;
		l = sqrt(pow((this->x - obj.x), 2) + pow((this->y - obj.y), 2));
		if ((this->radius + obj.radius) >= l)
		{
			return true;
		}
		else
		{
			return false;
		}

	}
	//определения вхождения n-угольника second в n-угольник first
	bool n_angle :: accessory(n_angle obj)
	{
		double l;
		l = sqrt(pow((this->x - obj.x), 2) + pow((this->y - obj.y), 2));
		if (this->crossing(obj))
		{
			if (abs(this->radius - radius) >= l)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}

		
	}
	
	//определяем квадрат ли
	bool n_angle:: is_it_square()
	{
		if (n == 4) 
		{ 
			return true; 
		}
		else 
		{ 
			return false; 
		}
	}
	
	 n_angle:: n_angle(double rad, int n_, double x_, double y_ )
	{
		radius = rad;
		n = n_;
		x = x_;
		y = y_;
	}
	