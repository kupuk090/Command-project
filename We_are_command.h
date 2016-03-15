#define _USE_MATH_DEFINES

#include <stdlib.h>
#include <math.h>

class n_angle
{
private:
	double radius, x = 0, y = 0;
	int n;

public:
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

public:
	//�������� ������� �������
	double get_area();
	//�������� �������� �������
	double get_perimeter();


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


	/*
	//���������� �� ������� ��� ������ � n-��������
	friend ellipse operator== (ellipse el, n_angle n);
	//����������� ����������� ������� � n-���������
	friend crossing(ellipse el, n_angle n);
	//����������� ��������� n-��������� � ������
	friend accessory(ellipse el, n_angle n);
	*/
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

