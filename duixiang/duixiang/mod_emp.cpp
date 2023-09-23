#include"workerManager.h"

//�޸�ְ��
void WorkerManager::Mod_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
	}
	else
	{
		cout << "������Ҫ�޸ĵ�ְ����ţ�" << endl;
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

			cout << "�鵽�� " << id << "��ְ������������ְ���ţ� " << endl;
			cin >> newId;
			
			//�ж�newId�Ƿ��Ѿ����ڣ��������뱻ɾ��id�ıȽϣ�
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
				cout << "�ñ���Ѿ�����" << endl;
				while (1)
				{
					cout << "������������ְ�����" << endl;
					cin >> newId;

					ret = -1;
					//�ж�����id�Ƿ���ڣ��������뱻ɾ��id�ıȽϣ�
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
						cout << "�ñ���Ѿ�����" << endl;
					}
				}
			}

			cout << "������Ҫ�޸�����" << endl;
			cin >> name;

			Worker* worker = NULL;

			while (1)
			{
				cout << "��ѡ���ְ���ĸ�λ��" << endl;
				cout << "1����ְͨ��" << endl;
				cout << "2������" << endl;
				cout << "3���ϰ�" << endl;
				cin >> dId;
				bool flag = true;
				switch (dId)
				{
				case 1://��ͨԱ��
					worker = new Employee(newId, name, dId);
					break;
				case 2://����
					worker = new Manager(newId, name, dId);
					break;
				case 3://�ϰ�
					worker = new Boss(newId, name, dId);
					break;
				default:
					flag = false;
					cout << "��������" << endl;
					break;
				}
				if (flag)
				{
					break;
				}
			}
			this->m_EmpArray[index] = worker;
			cout << "�޸ĳɹ���" << endl;
			//���浽�ļ���
			this->save();

		}
		else
		{
			cout << "�޸�ʧ�ܣ�δ�ҵ���ְ��" << endl;
		}
	}
	system("pause");
	system("cls");

}