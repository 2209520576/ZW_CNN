#pragma once
#include <iostream>
#include <ctime>
#include <random>
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
	//��ʼ������
	//0��ʾ[-1��1]�����ʼ��
	//1��ʾ��ֵΪGaussMean����ΪGaussSigma�ĸ�˹��ʼ��
	int InitType = 0;
	float GaussSigma = 1.0;
	float GaussMean = 0;
public:
	Net() {};
	~Net() {};
	void initNet(vector <int> layer_neuron_num_);
	float *random_uniform(int length);
	float *random_gaussian(int length);
	void initWeights();
	void initBiases();

};
