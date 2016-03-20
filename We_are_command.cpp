#include "We_are_command.h"
#include <iostream>

using namespace std;

	//возвращаем радиус описанной окружности
    	double n_angle:: get_radius()
	{
		return radius;
	}
	
	//возвращаем x координату центра
	double n_angle:: get_x()
	{
		return x;
	}
	
	//возвращаем y координату центра
	double n_angle:: get_y()
	{
		return y;
	}
	
	//возвращаем n
	int n_angle:: get_n()
	{
		return n;
	}

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
	double n_angle::get_perimeter()
	{
		return get_side()*n;
	}
	
	//получаем параметры n-угольника
	void n_angle :: return_parameters()
	{
		cout << "parametrs of n-angle:\n";
		cout << "perimetr of n_angle:\n"
			 << get_perimeter();
		cout << "\narea of n_angle:\n" 
			 << get_area();
		cout << "\nside of n_angle:\n" 
			 << get_side();
		cout << "\nradius of circumcircle:\n" 
			 << get_radius();
		cout << "\namount of sides:\n" 
			 << get_n();
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
	bool n_angle::operator== (n_angle n)
	{
		if ((this->radius == n.radius) && (this->n == n.n))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	
	//определение пересечения двух n-угольников
	bool n_angle :: crossing(n_angle second)
	{
		double l;
		l = sqrt(pow((this->get_x() - second.get_x()), 2) + pow((this->get_y() - second.get_y()), 2));
		if ((this->get_radius()+ second.get_radius()) >= l)
		{
			return true;
		}
		else
		{
			return false;
		}

	}
	
	//определения вхождения n-угольника second в n-угольник first
	bool n_angle :: accessory(n_angle second)
	{
		double l;
		l = sqrt(pow((this->x - second.x), 2) + pow((this->y - second.y), 2));
		if (this->crossing(second))
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
	
	n_angle:: n_angle(double rad, int n_, double x_, double y_)
	{
		radius = rad;
		n = n_;
		x = x_;
		y = y_;
	}
	
	
	
	
	
	
	//определение пересечения эллипса и n-угольника
	bool crossing(n_angle n, ellipse el)
	{
		return 0;
	}
	
	bool crossing(ellipse el, n_angle n)
	{
		if (crossing(n, el)) return true;
		else return false;
	}
	
	//определение вхождения эллипса в n-угольник
	bool accessory(n_angle n, ellipse el)
	{
		return 0;
	}
	
	bool accessory(ellipse el, n_angle n)
	{
		return 0;
	}





	
	
	//возвращаем major_axis
	double ellipse:: get_major_axis()
	{
		return major_axis;
	}
	
	//возвращаем minor_axis
	double ellipse:: get_minor_axis()
	{
		return minor_axis;
	}
	
	//возвращаем x координату центра
	double ellipse:: get_x()
	{
		return x;
	}
	
	//возвращаем y координату центра
	double ellipse:: get_y()
	{
		return y;
	}

	 //получаем площадь эллипса
	 double ellipse::get_area()
	 {
		 return major_axis*minor_axis*M_PI;	 
	 }
	 
	 //получаем периметр эллипса
	 double ellipse::get_perimeter()
	 {
		 return (4 * (major_axis*minor_axis*M_PI + pow((major_axis - minor_axis), 2)) / (major_axis + minor_axis));
	 
	 }
	 
	 //перемещение ценра в новые координаты
	 void ellipse::move(double x_, double y_)
	 {
		 x = x_;
		 y = y_;
	 }

	 //изменение размеров на какую-либо величину 
	 void ellipse:: resizing(double x, double y)
	 {
		 major_axis += x;
		 minor_axis += y;
	 }

	 //перегрузка оператора сравнения двух эллипсов
	 bool ellipse::operator== (ellipse second)
	 {
		 if (this->get_major_axis() != second.get_major_axis())
		 {
			 if (abs((this->get_major_axis() - second.get_minor_axis()) < 0.000000001) && abs((this->get_minor_axis() - second.get_major_axis()) < 0.000000001))
				 return true;
			 else 
				 return false;
		 }
		 else
		 {
			 if (abs(this->get_minor_axis() - second.get_minor_axis()) < 0.000000001)
				 return true;
			 else 
				 return false;
		 }
	}



	//получаем радиус эллипса к точке лежащей на прямой, соединяющей центры рассматриваемого эллипса и другой фигуры
	 double ellipse::get_radius(double a, double b, double x1, double y1, double x2, double y2)
	 {
		 double dx = x2 - x1;
		 double dy = y2 - y1;

		 if (dx == 0)
			 return b;
		 else
		 {
			 return a*b / sqrt((b*b*dx*dx / (dx*dx + dy*dy)) + (a*a*dy*dy / (dx*dx + dy*dy)));
		 }
	 }

	 //определение пересечения двух эллипсов
	 bool ellipse::crossing(ellipse second)
	 {
		 double l;
		 l = sqrt(pow((this->get_x() - second.get_x()), 2) + pow((this->get_y() - second.get_y()), 2));
		 if ((get_radius(this->get_major_axis(), this->get_minor_axis(), this->get_x(), this->get_y(), second.get_x(), second.get_y()) + get_radius(second.get_major_axis(), second.get_minor_axis(), second.get_x(), second.get_y(), this->get_x(), this->get_y())) >= l)
		 {
			 return true;
		 }
		 else
		 {
			 return false;
		 }
	 }

	 //определения вхождение эллипса second в наш эллипс
	 bool  ellipse::accessory(ellipse second)
	 {
		 double l;
		 l = sqrt(pow((this->get_x() - second.get_x()), 2) + pow((this->get_y() - second.get_y()), 2));
		 if (this->crossing(second))
		 {
			 if (abs(get_radius(this->get_major_axis(), this->get_minor_axis(), this->get_x(), this->get_y(), second.get_x(), second.get_y()) - get_radius(second.get_major_axis(), second.get_minor_axis(), second.get_x(), second.get_y(), this->get_x(), this->get_y())) >= l)
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

	 //определяем круг ли
	 bool ellipse::is_it_circle()
	 {
		 if (major_axis = minor_axis)
			 return true;
		 else
			 return false;
	 }

	 //вывод параметров
	 void ellipse :: return_parameters()
	 {
		 cout << "parametrs of n-angle:\n";
		 cout << "ellipse of major_axis:\n"
			 << get_major_axis();
		 cout << "\nellipse of minor_axis:\n"
			 << get_minor_axis();
		 cout << "\nperimetr of n_angle:\n"
			  << get_perimeter();
		 cout << "\narea of n_angle:\n"
			  << get_area();
		
	 }
	 
	 

	 //конструктор класса
	 ellipse::ellipse(double a, double b, double x_, double y_)
	 {
		 major_axis = a;
		 minor_axis = b;
		 x = x_;
		 y = y_;
	 }
	 
	 //сравниваем по площади наш n-угольник и эллипс
	 bool operator== (ellipse el, n_angle n)
	 {
		 if (abs(n.get_area() - el.get_area()) < 0.000000001)
			 return true;
		 else
			 return false;
	 }

	 bool operator== (n_angle n, ellipse el)
	 {
		 if (n == el) return true;
		 else return false;
	 }
