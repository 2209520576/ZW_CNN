#pragma once
#include <iostream>
#include <opencv2\opencv.hpp>
using namespace std;
using namespace cv;

class Net
{
public:
	//ÿһ�����Ԫ��Ŀ
	vector <int> layer_neuron_num;
	//�㣬ʹ��Opencv��Mat
	vector <Mat> layer;
	//Ȩֵ����
	vector <Mat> weights;
	//ƫ�þ���
	vector <Mat> biases;
public:
	Net() {};
	~Net() {};
	void initNet(vector <int> layer_neuron_num_);

};
