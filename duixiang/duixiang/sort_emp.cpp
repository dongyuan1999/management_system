#include"workerManager.h"

//ְ������
void WorkerManager::Sort_Emp()
{
	if (m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
	}
	else
	{
		cout << "����������ʽ��" << endl;
		cout << "1������" << endl;
		cout << "2������" << endl;
		int choose = 0;
		cin >> choose;
		if (choose == 1)
			//��������
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
			//��������
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
			cout << "��������" << endl;
		}
	}
	system("pause");
	system("cls");
}