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

	//���캯��
	WorkerManager();

	//ͳ���ļ�������
	int get_EmpNum();

	//��ʼ��Ա��
	void init_Emp();

	//�����ļ�
	void save();

	//����ְ������ж�ְ���Ƿ���ڣ����ر�Ż�-1
	int IsExist(int id);

	//��ʾ�˵�
	void Show_Menu();

	//�˳�ϵͳ
	void ExitSystem();

	//���ְ��
	void Add_Emp();

	//��ʾְ��
	void Show_Emp();

	//ɾ��ְ��
	void Del_Emp();

	//�޸�ְ��
	void Mod_Emp();

	//����ְ��
	void Find_Emp();
	
	//ְ������
	void Sort_Emp();
	
	//���ְ��
	void Clean_File();

	//��������
	~WorkerManager();

	int m_EmpNum;
	Worker** m_EmpArray;//ָ��ָ��ָ������
	//�ж��ļ��Ƿ�Ϊ�� ��־
	bool m_FileIsEmpty;
};