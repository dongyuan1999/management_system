#include"workerManager.h"

//ɾ��ְ��
void WorkerManager::Del_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
	}
	else
	{
		//����ְ�����ɾ��
		cout << "��������Ҫɾ����ְ�����" << endl;
		int id = 0;
		cin >> id;
		int index = this->IsExist(id);
		if ((index != -1))//ְ�����ڣ�����Ҫɾ����λ���ϵ�ְ��
		{
			//����ǰ��
			delete m_EmpArray[index];
			m_EmpArray[index] = NULL;

			for (int i = index; i < this->m_EmpNum - 1; i++)
			{
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}

			this->m_EmpNum--;//���������м�¼��Ա����
			//����ͬ�����µ��ļ���
			if (this->m_EmpNum == 0)
			{
				this->m_FileIsEmpty = true;
			}
			this->save();
			cout << "ɾ���ɹ�" << endl;


		}
		else
		{
			cout << "ɾ��ʧ�ܣ�δ�ҵ���ְ��" << endl;
		}

	}
	system("pause");
	system("cls");
}
