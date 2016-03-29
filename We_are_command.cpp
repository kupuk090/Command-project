	#include "We_are_command.h"
	
    //возвращаем радиус описанной окружности
	double n_angle:: get_radius() const
	{
		return radius;
	}
	
	//возвращаем x координату центра
	double n_angle:: get_x() const
	{
		return x;
	}
	
	//возвращаем y координату центра
	double n_angle:: get_y() const
	{
		return y;
	}
	
	//возвращаем n
	int n_angle:: get_n() const
	{
		return n;
	}

	//получаем величину стороны n-угольника
	double n_angle :: get_side() const
	{
		return 2 * radius * sin(M_PI / n);
	}

	//получаем площадь n-угольника
	double n_angle::get_area() const
	{
		return (n / 2)*pow(radius,2)*sin(2 * M_PI / n);
	}
	
	//получаем периметр n-угольника
	double n_angle::get_perimeter() const
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
	void n_angle:: move(const double x_, const double y_)
	{
		x = x_;
		y = y_;
	}
	
	//изменение размеров на какую-либо величину 
	void n_angle:: resizing_by_side(const double a)
	{
		radius = (get_side() + a) / 2 / sin(M_PI / n);
	}
	
	void n_angle:: resizing_by_rad(const double a)
	{
		radius = radius + a;
	}
	
	//перегрузка оператора сравнения двух n-угольников
	bool n_angle::operator== (const n_angle& n)
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
	bool n_angle :: crossing(const n_angle& second)
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
	bool n_angle :: accessory(const n_angle& second)
	{
		double l;
		l = sqrt(pow((this->x - second.x), 2) + pow((this->y - second.y), 2));
		if (this->crossing(second))
		{
			if ((this->radius - second.radius) >= l)
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
	
	n_angle:: n_angle(const double rad, const int n_, const double x_, const double y_ )
	{
		radius = rad;
		n = n_;
		x = x_;
		y = y_;
	}
	
	
	//функция знака
	int Sign(double x)
	{
		return x < 0 ? -1 : ((x == 0) ? 0 : 1);
	}
	
	
    //возвращаем major_axis
	double ellipse:: get_major_axis() const
	{
		return major_axis;
	}
	
	//возвращаем minor_axis
	double ellipse:: get_minor_axis() const
	{
		return minor_axis;
	}
	
	//возвращаем x координату центра
	double ellipse:: get_x() const
	{
		return x;
	}
	
	//возвращаем y координату центра
	double ellipse:: get_y() const
	{
		return y;
	}

	 //получаем площадь эллипса
	 double ellipse::get_area() const
	 {
		 return major_axis*minor_axis*M_PI;	 
	 }
	 
	 //получаем периметр эллипса
	 double ellipse::get_perimeter() const
	 {
		 return (4 * (major_axis*minor_axis*M_PI + pow((major_axis - minor_axis), 2)) / (major_axis + minor_axis));
	 
	 }
	 
	 //перемещение ценра в новые координаты
	 void ellipse::move(const double x_, const double y_)
	 {
		 x = x_;
		 y = y_;
	 }

	 //изменение размеров на какую-либо величину 
	 void ellipse:: resizing(const double x, const double y )
	 {
		 major_axis += x;
		 minor_axis += y;
	 }

	 //перегрузка оператора сравнения двух эллипсов
	 bool ellipse::operator== (const ellipse& second)
	 {
		 if (this->get_major_axis() != second.major_axis)
		 {
			 if (abs((this->get_major_axis() - second.minor_axis) <0.0001) && (abs(this->get_minor_axis() - second.major_axis) < 0.0001))
				 return true;
			 else 
				 return false;
		 }
		 else
		 {
			 if (abs(this->get_minor_axis() - second.minor_axis) < 0.0001)
				 return true;
			 else 
				 return false;
		 }
			
		 }
	
	 //определение пересечения двух эллипсов
	 bool ellipse::crossing(const ellipse& second)
	 {
		 double a = this->get_major_axis();
		 double b = this->get_minor_axis();
		 double c = second.major_axis;
		 double d = second.minor_axis;
		 double x0 = this->get_x() - second.x;
		 double y0 = this->get_y() - second.y;
		 double t = 0;
		 double f = pow((a*cos(t) + x0), 2) / (c*c) + pow(b*sin(t) + y0, 2) / (d*d) - 1;
		 double tmp = 0;

		 while (t < 6.28)
		 {
			 tmp = f;
			 t = t + 0.001;
			 f = pow((a*cos(t) + x0), 2) / (c*c) + pow((b*sin(t) + y0), 2) / (d*d) - 1;
			 if (Sign(tmp) != Sign(f))
				 return true;
		 }
		 return false;
 }
	
	 //определение принадлежности точек 
	 bool ellipse::beloning_el(const ellipse& second, const double x, const double y) const
	 {
		 double a = this->get_major_axis();
		 double b = this->get_minor_axis();
		 double c = second.major_axis;
		 double d = second.minor_axis;
		 double x01 = this->get_x();
		 double y01 = this->get_y();
		 double x02 = second.x;
		 double y02 = second.y;
		 double f1 = pow(x - x01, 2) / (a*a) + pow(y - y01, 2) / (b*b) - 1;
		 double f2 = pow(x - x02, 2) / (c*c) + pow(y - y02, 2) / (d*d) - 1;

		 if ((f1 <= 0) && (f2 <= 0))
			 return true;
		 else
			 return false;
	 }
	 
	 //определения вхождение эллипса second в наш эллипс
	 bool  ellipse::accessory(const ellipse& second)
	 {
		 double c = second.major_axis;
		 double d = second.minor_axis;
		 double x02 = second.x;
		 double y02 = second.y;


		 if ((this->beloning_el(second, x02, y02 + d)) && (this->beloning_el(second, x02, y02 - d)) && (this->beloning_el(second, x02 + c, y02)) && (this->beloning_el(second, x02 - c, y02)))
			 return true;

		 else
			 return false;
	  }
	 
	 //определяем круг ли
	 bool ellipse::is_it_circle()
	 {
		 if (abs(major_axis - minor_axis) < 0.000000001)
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
	 ellipse::ellipse(const double a, const double b, const double x_, const double y_)
	 {
		 major_axis = a;
		 minor_axis = b;
		 x = x_;
		 y = y_;
	 }
	 
	 //сравниваем по площади наш n-угольник и эллипс
	 bool operator== (const n_angle& n, const ellipse& el)
	 {
		 if (el == n ) 
			 return true;
		 else 
			 return false;
	 }

	 bool operator== (const ellipse& el, const n_angle& n)
	 {
		 double dif = n.get_area() - el.get_area();
		 if (dif<0)
			 dif = -dif;
		 if (dif<0.0000001)
			 return true;
		 else
			 return false;
	 }

	 //определение пересечения эллипса и n-угольника
	 bool crossing(const n_angle& n, const ellipse& el)
	 {
		 double a = el.get_major_axis();
		 double b = el.get_minor_axis();
		 double c = n.get_radius();
		 double d = n.get_radius();
		 double x0 = el.get_x() - n.get_x();
		 double y0 = el.get_y() - n.get_y();
		 double t = 0;
		 double f = pow((a*cos(t) + x0), 2) / (c*c) + pow(b*sin(t) + y0, 2) / (d*d) - 1;
		 double tmp = 0;

		 while (t < 6.28)
		 {
			 tmp = f;
			 t = t + 0.001;
			 f = pow((a*cos(t) + x0), 2) / (c*c) + pow((b*sin(t) + y0), 2) / (d*d) - 1;
			 if (Sign(tmp) != Sign(f))
				 return true;
		 }
		 return false;
}

	 bool crossing(const ellipse& el, const n_angle& n)
	 {
		 if (crossing(n, el))
			 return true;
		 else
			 return false;
	 }

	 //определение принадлежности точек 
	 bool ellipse::beloning_n(const n_angle& second, const double x, const double y) const
	 {
		 double a = this->get_major_axis();
		 double b = this->get_minor_axis();
		 double c = second.get_radius();
		 double d = second.get_radius();
		 double x01 = this->get_x();
		 double y01 = this->get_y();
		 double x02 = second.get_x();
		 double y02 = second.get_y();
		 double f1 = pow(x - x01, 2) / (a*a) + pow(y - y01, 2) / (b*b) - 1;
		 double f2 = pow(x - x02, 2) / (c*c) + pow(y - y02, 2) / (d*d) - 1;

		 if ((f1 <= 0) && (f2 <= 0))
			 return true;
		 else
			 return false;
	 }
	 
	 //определение вхождения эллипса в n-угольник
	 bool accessory(const ellipse& el, const n_angle& n)
	 {
		 double a = el.get_major_axis();
		 double b = el.get_minor_axis();
		 double x01 = el.get_x();
		 double y01 = el.get_y();

		 if ((el.beloning_n(n, x01, y01 + b)) && (el.beloning_n(n, x01, y01 - b)) && (el.beloning_n(n, x01 + a, y01)) && (el.beloning_n(n, x01 - a, y01)))
			 return true;
		 else
			 return false;
	 }

	 bool accessory(const n_angle& n, const ellipse& el)
	 {
		 double c = n.get_radius();
		 double d = n.get_radius();
		 double x02 = n.get_x();
		 double y02 = n.get_y();


		 if ((el.beloning_n(n, x02, y02 + d)) && (el.beloning_n(n, x02, y02 - d)) && (el.beloning_n(n, x02 + c, y02)) && (el.beloning_n(n, x02 - c, y02)))
			 return true;

		 else
			 return false;
	 }
	 
	 
	 
	 
	 
	 
	 
	
	
 
	
	 
	