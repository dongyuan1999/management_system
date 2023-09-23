#include"workerManager.h"

//增加职工数量
void WorkerManager::Add_Emp()
{
	cout << "请输入增加职工数量：" << endl;

	int addNum = 0;
	cin >> addNum;

	if (addNum > 0)
	{
		//计算新空间大小
		int newSize = this->m_EmpNum + addNum;

		//开辟新空间
		Worker** newSpace = new Worker * [newSize];

		//将原空间下内容存放到新空间下
		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				newSpace[i] = this->m_EmpArray[i];
			}
		}
		//输入新数据
		for (int i = 0; i < addNum; i++)
		{
			int id;
			string name;
			int dId;

			while (1)
			{
				cout << "请输入第" << i + 1 << "个新职工编号" << endl;
				cin >> id;
				//判断输入id是否存在(包括与之前存在的id和刚刚输入的id的比较）
				int ret = -1;
				for (int j = 0; j < this->m_EmpNum+i; j++)
				{
					if (newSpace[j]->m_Id == id)
					{
						ret = 1;
						break;
					}
				}
				if (ret == -1)
				{
					break;
				}
				else
				{
					cout << "该编号已经存在" << endl;
				}

			}

			cout << "请输入第" << i + 1 << "个新职工姓名" << endl;
			cin >> name;


			Worker* worker = NULL;
			while (1) {
				cout << "请选择该职工的岗位：" << endl;
				cout << "1、普通职工" << endl;
				cout << "2、经理" << endl;
				cout << "3、老板" << endl;
				cin >> dId;
				bool flag = true;
				switch (dId)
				{
				case 1://普通员工
					worker = new Employee(id, name, dId);
					break;
				case 2://经理
					worker = new Manager(id, name, dId);
					break;
				case 3://老板
					worker = new Boss(id, name, dId);
					break;
				default:
					flag = false;
					cout << "输入有误" << endl;
					break;
				}
				if (flag)
				{
					break;
				}
			}
			newSpace[this->m_EmpNum + i] = worker;
		}

		//释放原有空间
		delete[]this->m_EmpArray;
		//更改新空间的指向
		this->m_EmpArray = newSpace;
		//更新新的个数
		this->m_EmpNum = newSize;
		//提示信息
		cout << "成功添加" << addNum << "名新职工" << endl;
		//增加成员后文件不为空
		this->m_FileIsEmpty = false;
		//保存数据到文件中
		this->save();
	}
	else
	{
		cout << "输入有误" << endl;
	}
	system("pause");
	system("cls");
}