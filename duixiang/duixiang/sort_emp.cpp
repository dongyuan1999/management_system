#include"workerManager.h"

//职工排序
void WorkerManager::Sort_Emp()
{
	if (m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空" << endl;
	}
	else
	{
		cout << "请输入排序方式：" << endl;
		cout << "1：升序" << endl;
		cout << "2：降序" << endl;
		int choose = 0;
		cin >> choose;
		if (choose == 1)
			//升序排列
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				for (int j = 0; j < this->m_EmpNum - i - 1; j++)
				{
					if (this->m_EmpArray[j]->m_Id > this->m_EmpArray[j + 1]->m_Id)
					{
						Worker* temp = NULL;
						temp = this->m_EmpArray[j];
						this->m_EmpArray[j] = this->m_EmpArray[j + 1];
						this->m_EmpArray[j + 1] = temp;
					}
				}
			}
			this->save();
		}
		else if (choose == 2)
			//降序排列
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				for (int j = 0; j < this->m_EmpNum - i - 1; j++)
				{
					if (this->m_EmpArray[j]->m_Id < this->m_EmpArray[j + 1]->m_Id)
					{
						Worker* temp = NULL;
						temp = this->m_EmpArray[j];
						this->m_EmpArray[j] = this->m_EmpArray[j + 1];
						this->m_EmpArray[j + 1] = temp;
					}
				}
			}
			this->save();
		}
		else
		{
			cout << "输入有误" << endl;
		}
	}
	system("pause");
	system("cls");
}