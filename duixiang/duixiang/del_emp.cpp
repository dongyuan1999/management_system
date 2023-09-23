#include"workerManager.h"

//删除职工
void WorkerManager::Del_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空" << endl;
	}
	else
	{
		//按照职工编号删除
		cout << "请输入想要删除的职工编号" << endl;
		int id = 0;
		cin >> id;
		int index = this->IsExist(id);
		if ((index != -1))//职工存在，并且要删除该位置上的职工
		{
			//数据前移
			delete m_EmpArray[index];
			m_EmpArray[index] = NULL;

			for (int i = index; i < this->m_EmpNum - 1; i++)
			{
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}

			this->m_EmpNum--;//更新数组中记录人员个数
			//数据同步更新到文件中
			if (this->m_EmpNum == 0)
			{
				this->m_FileIsEmpty = true;
			}
			this->save();
			cout << "删除成功" << endl;


		}
		else
		{
			cout << "删除失败，未找到该职工" << endl;
		}

	}
	system("pause");
	system("cls");
}
