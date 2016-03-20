#include "We_are_command.h"
#include <iostream>

using namespace std;

	//���������� ������ ��������� ����������
	
    double n_angle:: get_radius()
	{
		return radius;
	}
	
	//���������� x ���������� ������
	double n_angle:: get_x()
	{
		return x;
	}
	
	//���������� y ���������� ������
	double n_angle:: get_y()
	{
		return y;
	}
	
	//���������� n
	int n_angle:: get_n()
	{
		return n;
	}

	//�������� �������� ������� n-���������
	double n_angle :: get_side()
	{
		return 2 * radius * sin(M_PI / n);
	}

	//�������� ������� n-���������
	double n_angle::get_area()
	{
		return (n / 2)*pow(radius, 2)*sin(2 * M_PI / n);
	}
	
	//�������� �������� n-���������
	double n_angle::get_perimeter()
	{
		return get_side()*n;
	}
	
	//�������� ��������� n-���������
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
	
	//����������� ����� � ����� ����������
	void n_angle:: move(double x_, double y_)
	{
		x = x_;
		y = y_;
	}
	
	//��������� �������� �� �����-���� �������� 
	void n_angle:: resizing_by_side(double a)
	{
		radius = (get_side() + a) / 2 / sin(M_PI / n);
	}
	
	void n_angle:: resizing_by_rad(double a)
	{
		radius = radius + a;
	}
	
	//���������� ��������� ��������� ���� n-����������
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
	
	//����������� ����������� ���� n-����������
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
	
	//����������� ��������� n-��������� second � n-�������� first
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
	
	//���������� ������� ��
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
	
	
	
	
	
	
	//����������� ����������� ������� � n-���������
	bool crossing(n_angle n, ellipse el)
	{
		return 0;
	}
	
	bool crossing(ellipse el, n_angle n)
	{
		if (crossing(n, el)) return true;
		else return false;
	}
	
	//����������� ��������� ������� � n-��������
	bool accessory(n_angle n, ellipse el)
	{
		return 0;
	}
	
	bool accessory(ellipse el, n_angle n)
	{
		return 0;
	}





	
	
	//���������� major_axis
	double ellipse:: get_major_axis()
	{
		return major_axis;
	}
	
	//���������� minor_axis
	double ellipse:: get_minor_axis()
	{
		return minor_axis;
	}
	
	//���������� x ���������� ������
	double ellipse:: get_x()
	{
		return x;
	}
	
	//���������� y ���������� ������
	double ellipse:: get_y()
	{
		return y;
	}

	 //�������� ������� �������
	 double ellipse::get_area()
	 {
		 return major_axis*minor_axis*M_PI;	 
	 }
	 
	 //�������� �������� �������
	 double ellipse::get_perimeter()
	 {
		 return (4 * (major_axis*minor_axis*M_PI + pow((major_axis - minor_axis), 2)) / (major_axis + minor_axis));
	 
	 }
	 
	 //����������� ����� � ����� ����������
	 void ellipse::move(double x_, double y_)
	 {
		 x = x_;
		 y = y_;
	 }

	 //��������� �������� �� �����-���� �������� 
	 void ellipse:: resizing(double x, double y)
	 {
		 major_axis += x;
		 minor_axis += y;
	 }

	 //���������� ��������� ��������� ���� ��������
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



	 //�������� ������ �������
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

	 //����������� ����������� ���� ��������
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

	 //����������� ��������� ������� second � ��� ������
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

	 //���������� ���� ��
	 bool ellipse::is_it_circle()
	 {
		 if (major_axis = minor_axis)
			 return true;
		 else
			 return false;
	 }

	 //����� ����������
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
	 
	 

	 //����������� ������
	 ellipse::ellipse(double a, double b, double x_, double y_)
	 {
		 major_axis = a;
		 minor_axis = b;
		 x = x_;
		 y = y_;
	 }
	 
	 //���������� �� ������� ��� n-�������� � ������
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
