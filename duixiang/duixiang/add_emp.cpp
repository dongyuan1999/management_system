#include"workerManager.h"

//����ְ������
void WorkerManager::Add_Emp()
{
	cout << "����������ְ��������" << endl;

	int addNum = 0;
	cin >> addNum;

	if (addNum > 0)
	{
		//�����¿ռ��С
		int newSize = this->m_EmpNum + addNum;

		//�����¿ռ�
		Worker** newSpace = new Worker * [newSize];

		//��ԭ�ռ������ݴ�ŵ��¿ռ���
		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				newSpace[i] = this->m_EmpArray[i];
			}
		}
		//����������
		for (int i = 0; i < addNum; i++)
		{
			int id;
			string name;
			int dId;

			while (1)
			{
				cout << "�������" << i + 1 << "����ְ�����" << endl;
				cin >> id;
				//�ж�����id�Ƿ����(������֮ǰ���ڵ�id�͸ո������id�ıȽϣ�
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
					cout << "�ñ���Ѿ�����" << endl;
				}

			}

			cout << "�������" << i + 1 << "����ְ������" << endl;
			cin >> name;


			Worker* worker = NULL;
			while (1) {
				cout << "��ѡ���ְ���ĸ�λ��" << endl;
				cout << "1����ְͨ��" << endl;
				cout << "2������" << endl;
				cout << "3���ϰ�" << endl;
				cin >> dId;
				bool flag = true;
				switch (dId)
				{
				case 1://��ͨԱ��
					worker = new Employee(id, name, dId);
					break;
				case 2://����
					worker = new Manager(id, name, dId);
					break;
				case 3://�ϰ�
					worker = new Boss(id, name, dId);
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
			newSpace[this->m_EmpNum + i] = worker;
		}

		//�ͷ�ԭ�пռ�
		delete[]this->m_EmpArray;
		//�����¿ռ��ָ��
		this->m_EmpArray = newSpace;
		//�����µĸ���
		this->m_EmpNum = newSize;
		//��ʾ��Ϣ
		cout << "�ɹ����" << addNum << "����ְ��" << endl;
		//���ӳ�Ա���ļ���Ϊ��
		this->m_FileIsEmpty = false;
		//�������ݵ��ļ���
		this->save();
	}
	else
	{
		cout << "��������" << endl;
	}
	system("pause");
	system("cls");
}