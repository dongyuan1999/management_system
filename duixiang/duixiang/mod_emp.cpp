#include"workerManager.h"

//修改职工
void WorkerManager::Mod_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空！" << endl;
	}
	else
	{
		cout << "请输入要修改的职工编号：" << endl;
		int id = 0;
		cin >> id;
		int index = IsExist(id);
		if (index != -1)
		{
			delete this->m_EmpArray[index];
			m_EmpArray[index]=NULL;

			int newId;
			string name;
			int dId;

			cout << "查到： " << id << "号职工，请输入新职工号： " << endl;
			cin >> newId;
			
			//判断newId是否已经存在（不包括与被删除id的比较）
			int ret = -1;
			for (int i = 0; i < index; i++)
			{
				if (this->m_EmpArray[i]->m_Id == newId)
				{
					ret = i;
				}
			}
			for (int i = index+1; i < this->m_EmpNum; i++)
			{
				if (this->m_EmpArray[i]->m_Id == newId)
				{
					ret = i;
				}
			}
			if (ret !=- 1)
			{
				cout << "该编号已经存在" << endl;
				while (1)
				{
					cout << "请重新输入新职工编号" << endl;
					cin >> newId;

					ret = -1;
					//判断输入id是否存在（不包括与被删除id的比较）
					for (int i = 0; i < index; i++)
					{
						if (this->m_EmpArray[i]->m_Id == newId)
						{
							ret = i;
						}
					}
					for (int i = index + 1; i < this->m_EmpNum; i++)
					{
						if (this->m_EmpArray[i]->m_Id == newId)
						{
							ret = i;
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
			}

			cout << "请输入要修改姓名" << endl;
			cin >> name;

			Worker* worker = NULL;

			while (1)
			{
				cout << "请选择该职工的岗位：" << endl;
				cout << "1、普通职工" << endl;
				cout << "2、经理" << endl;
				cout << "3、老板" << endl;
				cin >> dId;
				bool flag = true;
				switch (dId)
				{
				case 1://普通员工
					worker = new Employee(newId, name, dId);
					break;
				case 2://经理
					worker = new Manager(newId, name, dId);
					break;
				case 3://老板
					worker = new Boss(newId, name, dId);
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
			this->m_EmpArray[index] = worker;
			cout << "修改成功！" << endl;
			//保存到文件中
			this->save();

		}
		else
		{
			cout << "修改失败，未找到该职工" << endl;
		}
	}
	system("pause");
	system("cls");

}