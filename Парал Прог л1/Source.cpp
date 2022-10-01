#include<iostream>
#include <vector>
#include <fstream>
#include <random> 
#include <chrono>
#define size 100

#define Matrix_1_size_ver size
#define Matrix_1_size_hor size
#define Matrix_2_size_ver size
#define Matrix_2_size_hor size
#define Matrix_res_size_ver size
#define Matrix_res_size_hor size
 
void creat_rendom_files()
{
	std::ofstream data_1("C:\\Users\\matro\\source\\repos\\Паралельная прога лаба1\\Парал Прог л1\\data_1.txt");

	for (int i = 0; i < Matrix_1_size_hor; i++) 
	{
			for (int j = 0; j < Matrix_1_size_ver; j++)
			{
				data_1 << rand() % 50 + 10 << " ";
			}
			data_1<< std::endl;
	}
	data_1.close();

	std::ofstream data_2("C:\\Users\\matro\\source\\repos\\Паралельная прога лаба1\\Парал Прог л1\\data_2.txt");

	for (int i = 0; i < Matrix_2_size_hor; i++)
	{
		for (int j = 0; j < Matrix_2_size_ver; j++)
		{
			data_2 << rand() % 50 + 10 << " ";
		}
		data_2 << std::endl;
	}
	data_2.close();
}

void read_matrixы(std::vector<std::vector<int>>& matrix_1, std::vector<std::vector<int>>& matrix_2)
{
	std::ifstream data_1("C:\\Users\\matro\\source\\repos\\Паралельная прога лаба1\\Парал Прог л1\\data_1.txt");
	for (int i = 0; i < Matrix_1_size_hor; i++)
	{
		for (int j = 0; j < Matrix_1_size_ver; j++)
		{

			data_1 >> matrix_1[i][j];
		}
	}
	data_1.close();

	std::ifstream data_2("C:\\Users\\matro\\source\\repos\\Паралельная прога лаба1\\Парал Прог л1\\data_2.txt");
	for (int i = 0; i < Matrix_2_size_hor; i++)
	{
		for (int j = 0; j < Matrix_2_size_ver; j++)
		{

			data_2 >> matrix_2[i][j];
		}

	}
	data_2.close();
}

void write_stat(std::chrono::duration<double, std::milli> stat, std::vector<std::vector<int>>& matrix_res)
{
	std::ofstream data_res("C:\\Users\\matro\\source\\repos\\Паралельная прога лаба1\\Парал Прог л1\\data_res.txt");
	for (int i = 0; i < Matrix_res_size_hor; i++)
	{
		for (int j = 0; j < Matrix_res_size_ver; j++)
		{
			data_res << matrix_res[i][j] << " ";
		}
		data_res << std::endl;
	}
	data_res.close();

	std::ofstream stat_f("C:\\Users\\matro\\source\\repos\\Паралельная прога лаба1\\Парал Прог л1\\stat.txt", std::ios::app);
	stat_f << "Время затраченное на переменожение матриц: " << stat.count() << "mc" << std::endl;
	stat_f << "Размерность матриц:" << std::endl
		<< "Первая матрица " << Matrix_1_size_ver << " на " << Matrix_1_size_hor << std::endl
		<< "Вторая матрица " << Matrix_2_size_ver << " на " << Matrix_2_size_hor << std::endl << std::endl << std::endl;
	stat_f.close();
}

void mul_mat(std::vector<std::vector<int>>& matrix_1, std::vector<std::vector<int>>& matrix_2, std::vector<std::vector<int>>& matrix_res)
{
	auto start = std::chrono::steady_clock::now();
	for (int i = 0; i < Matrix_1_size_hor; i++)
	{
		for (int j = 0; j < Matrix_2_size_ver; j++)
		{
			matrix_res[i][j] = 0;
			for (int k = 0; k < Matrix_1_size_ver; k++)
			{
				matrix_res[i][j] += matrix_1[i][k] * matrix_2[k][j];
			}
		}
	}
	auto end = std::chrono::steady_clock::now();
	std::chrono::duration<double, std::milli> time = end - start;
	write_stat(time, matrix_res);
}

int main()
{
	std::vector<std::vector<int>> matrix_1 (Matrix_1_size_hor, std::vector<int>(Matrix_1_size_ver));
	std::vector<std::vector<int>> matrix_2(Matrix_2_size_hor, std::vector<int>(Matrix_2_size_ver));
	std::vector<std::vector<int>> matrix_res(Matrix_res_size_hor, std::vector<int>(Matrix_res_size_ver));
	creat_rendom_files();
	read_matrixы(matrix_1, matrix_2);
	mul_mat(matrix_1, matrix_2, matrix_res);
	


	std::cout<<std::endl;
	return 0;
}

