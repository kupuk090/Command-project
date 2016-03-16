#define _USE_MATH_DEFINES

#include <stdlib.h>
#include <math.h>

class n_angle
{
private:
	double radius, x = 0, y = 0;
	double angle = 0;
	int n;

public:
	//���������� ������ ��������� ����������
	double get_radius()
	{
		return radius;
	}
	//���������� x ���������� ������
	double get_x()
	{
		return x;
	}
	//���������� y ���������� ������
	double get_y()
	{
		return y;
	}
	//���������� n
	int get_n()
	{
		return n;
	}
	//���������� ���� �������� ������ ������� ������������ ��� ��
	double get_angle()
	{
		return angle;
	}

	//�������� �������� ������� n-���������
	double get_side();
	
	//�������� ������� n-���������
	double get_area();
	//�������� �������� n-���������
	double get_perimeter();


	//����������� ����� � ����� ����������
	void move(double x_, double y_);
	
	//��������� �������� �� �����-���� �������� (�.�. +- �����-�� �����)
	void resizing_by_side(double x);
	void resizing_by_rad(double x);
	
	//���������� ��������� ��������� ���� n-����������
	n_angle operator== (n_angle n);
	
	//����������� ����������� ���� n-����������
	bool crossing(n_angle second);
	
	//����������� ��������� n-��������� second � ��� n-��������
	bool accessory(n_angle second);

	//���������� ������� ��
	bool is_it_square();
	

	//����������� ������
	n_angle(double rad, int n_, double x_ = 0, double y_ = 0);

	//����� ����������
	void return_parameters();



	//���������� �� ������� ��� n-�������� � ������
	friend n_angle operator== (n_angle n, ellipse el);
	friend n_angle operator== (ellipse el, n_angle n);
	//����������� ����������� ������� � n-���������
	friend crossing(n_angle n, ellipse el);
	friend crossing(ellipse el, n_angle n);
	//����������� ��������� ������� � n-��������
	friend accessory(n_angle n, ellipse el);
	friend crossing(ellipse el, n_angle n);
};

class ellipse
{
private:
	double major_axis, minor_axis, x = 0, y = 0;
	double angle = 0;

public:
	//���������� major_axis
	double get_major_axis()
	{
		return major_axis;
	}
	//���������� minor_axis
	double get_minor_axis()
	{
		return minor_axis;
	}
	//���������� x ���������� ������
	double get_x()
	{
		return x;
	}
	//���������� y ���������� ������
	double get_y()
	{
		return y;
	}
	//���������� ���� �������� major_axis ������������ ��� ��
	double get_angle()
	{
		return angle;
	}

	//�������� ������� �������
	double get_area();
	//�������� �������� �������
	double get_perimeter();
	//�������� ������ �������
	double get_radius();


	//����������� ����� � ����� ����������
	void move(double x_, double y_);

	//��������� �������� �� �����-���� �������� (�.�. +- �����-�� �����)
	void resizing(double x, double y = 0)
	{
		major_axis += x;
		minor_axis += y;
	}

	//���������� ��������� ��������� ���� ��������
	ellipse operator== (ellipse second);

	//����������� ����������� ���� ��������
	bool crossing(ellipse second);

	//����������� ��������� ������� second � ��� ������
	bool accessory(ellipse second);

	//���������� ���� ��
	bool is_it_circle();


	//����������� ������
	ellipse(double a, double b, double x_ = 0, double y_ = 0)
	{
		major_axis = a;
		minor_axis = b;
		x = x_;
		y = y_;
	}

	//����� ����������
	void return_parameters();
};

//�� ���� ���������, � ��� � ���-�� �� ������

n_angle operator== (n_angle n, ellipse el)
{
	if (n.get_area() == el.get_area()) return true;
	else return false;
}
ellipse operator== (ellipse el, n_angle n)
{
	if (n.get_area() == el.get_area()) return true;
	else return false;
}

