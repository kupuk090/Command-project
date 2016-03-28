#define _USE_MATH_DEFINES

#include <stdlib.h>
#include <math.h>
#include <iostream>

using namespace std;

#ifndef WE_ARE_COMMAND_H
#define WE_ARE_COMMAND_H

class n_angle
{
private:
	double radius, x = 0, y = 0;
	int n;

public:
	//���������� ������ ��������� ����������
	double get_radius();
	//���������� x ���������� ������
	double get_x();
	//���������� y ���������� ������
	double get_y();
	//���������� n
	int get_n();

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
	bool operator== (n_angle n);
	
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
};

class ellipse
{
private:
	double major_axis, minor_axis, x = 0, y = 0;

public:
	//���������� major_axis
	double get_major_axis();
	//���������� minor_axis
	double get_minor_axis();
	//���������� x ���������� ������
	double get_x();
	//���������� y ���������� ������
	double get_y();

	//�������� ������� �������
	double get_area();
	//�������� �������� �������
	double get_perimeter();
	

	//����������� ����� � ����� ����������
	void move(double x_, double y_);

	//��������� �������� �� �����-���� �������� (�.�. +- �����-�� �����)
	void resizing(double x, double y = 0);

	//���������� ��������� ��������� ���� ��������
	bool operator== (ellipse second);

	//����������� ����������� ���� ��������
	bool crossing(ellipse second);

	//����������� ��������� ������� second � ��� ������
	bool accessory(ellipse second);

	//���������� ���� ��
	bool is_it_circle();


	//����������� ������
	ellipse(double a, double b, double x_ = 0, double y_ = 0);

	//����� ����������
	void return_parameters();




	//���������� �� ������� ��� n-�������� � ������
	friend bool operator== (n_angle n, ellipse el);
	friend bool operator== (ellipse el, n_angle n);
	//����������� ����������� ������� � n-���������
	friend bool crossing(n_angle n, ellipse el);
	friend bool crossing(ellipse el, n_angle n);
	//����������� ��������� ������� � n-��������
	friend bool accessory(n_angle n, ellipse el);
	friend bool accessory(ellipse el, n_angle n);

	//����������� �������������� ����� 
	bool beloning_el(ellipse second, double x, double y);
	bool beloning_n(n_angle second, double x, double y);
};

int Sign(double x);

#endif