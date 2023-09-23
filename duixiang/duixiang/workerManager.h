#pragma once
#include <iostream>
using namespace std;
#include"Worker.h"
#include"Employee.h"
#include"Manager.h"
#include"Boss.h"
#include"fstream"
#include"string.h"
#define FILENAME "empFile.txt"

class WorkerManager
{
public:

	//构造函数
	WorkerManager();

	//统计文件中人数
	int get_EmpNum();

	//初始化员工
	void init_Emp();

	//保存文件
	void save();

	//按照职工编号判断职工是否存在，返回编号或-1
	int IsExist(int id);

	//显示菜单
	void Show_Menu();

	//退出系统
	void ExitSystem();

	//添加职工
	void Add_Emp();

	//显示职工
	void Show_Emp();

	//删除职工
	void Del_Emp();

	//修改职工
	void Mod_Emp();

	//查找职工
	void Find_Emp();
	
	//职工排序
	void Sort_Emp();
	
	//清空职工
	void Clean_File();

	//析构函数
	~WorkerManager();

	int m_EmpNum;
	Worker** m_EmpArray;//指针指向指针数组
	//判断文件是否为空 标志
	bool m_FileIsEmpty;
};