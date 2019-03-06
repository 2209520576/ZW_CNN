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
	//��˹��ʼ���ķ���Ĭ��Ϊ1.0
	float GaussSigma = 1.0;
	//��˹��ʼ���ľ�ֵĬ��Ϊ0
	float GaussMean = 0;
	//openmp�߳���, Ĭ��Ϊ1
	int openmp_num_threads = 1;
	//���������
	string activation_func = "sigmoid";
	//��ʧ��������
	string loss_type = "L1";
	//������ʧ������ֵ
	float loss;
	//�����ǩMat
	Mat label;
	//ǰ�򴫲������һ�����������򴫲������
	Mat output_error;
	//��ʧ���������в������ݶ�
	vector <Mat> delta;
	//����ȥ��ȡ���ݶȺ�ѧϰ�ʲ�������
	void UpdateParameters();
	//���򴫲�����
	void backward();
	//ѧϰ��
	float learning_rate;
public:
	Net() {};
	~Net() {};
	//��ʼ������
	void initNet(vector <int> layer_neuron_num_);
	//������ͨ�������
	float *random_uniform(int length);
	//������˹�ֲ������
	float *random_gaussian(int length);
	//��ʼ��Ȩ��
	void initWeights();
	//��ʼ��ƫ��
	void initBiases();
	//�����������е��߳���
	void SetThreads(int num);
	//��ʼ��ÿ��Layer���������
	void SetActivation(string input);
	//ǰ�򴫲�
	void forward();
	//���򴫲����ݶȣ���ʽ����
	void getGrad();
};