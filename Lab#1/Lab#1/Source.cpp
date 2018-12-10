#include <iostream>
#include <windows.h>
#include <math.h>

#include "MyList.h"
#include "MyCircleList.h"
#include "MyFigure.h"

using namespace std;

int main()
{
	MyList<int> intList;
	MyList<double> DoubleList;
	MyList<MyFigure> FigureList;

	MyCircleList<int> intCList;
	MyCircleList<double> DoubleCList;
	MyCircleList<MyFigure> FigureCList;


	int menu = 0, StructType = 0, DataType = 0;

	while (menu != -1)
	{
		if (menu == 0)
		{
			system("cls");
			cout << "Choose data struct :\n 1.List\n 2.Circle List\n 3.Exit\n > ";
			cin >> StructType;

			menu = 1;

			if (StructType == 3)
				menu = -1;
		}
		else if (menu == 1)
		{
			system("cls");
			cout << "Choose data type :\n 1.Int\n 2.Double\n 3.Figure\n 4.Back\n > ";
			cin >> DataType;
			menu = 2;

			if (DataType == 4)
				menu = 0;

		}
		else if (menu == 2)
		{
			system("cls");
			if (StructType == 1)
			{
				if (DataType == 1)
				{
					int choose = 0;
					cout << "Your list: ";
					for (int i = 0; i < intList.getSize(); i++)
					{
						cout << intList.GetElementByIndex(i) << " ";
					}
					cout << "\n\nMenu:\n1.Add\n2.Delete\n3.Find by index\n4.Find by value\n0.Back\n > ";
					cin >> choose;

					if (choose == 1)
					{
						int buffer;
						cout << "Input number > ";
						cin >> buffer;
						intList.AddNew(buffer);
					}
					else if (choose == 2)
					{
						double buffer;
						cout << "Input number > ";
						cin >> buffer;
						intList.Delete(buffer);
					}
					else if (choose == 3)
					{
						int buffer;
						cout << "Input index > ";
						cin >> buffer;
						if (buffer < intList.getSize() && buffer >= 0)
						{
							cout << "Result: " << intList.GetElementByIndex(buffer) << endl;
						}
						else
							cout << "Cant find it!\n";
						system("pause");
					}
					else if (choose == 4)
					{
						int buffer;
						cout << "Input number > ";
						cin >> buffer;
						int ind = intList.FindByValue(buffer);
						if (ind != -1)
							cout << "Result: " << ind << endl;
						else
							cout << "Cant do it!\n";
						system("pause");
					}
					else
					{
						menu = 1;
					}
				}
				else if (DataType == 2)
				{
					int choose = 0;
					cout << "Your list: ";
					for (int i = 0; i < DoubleList.getSize(); i++)
					{
						cout << DoubleList.GetElementByIndex(i) << " ";
					}
					cout << "\n\nMenu:\n1.Add\n2.Delete\n3.Find by index\n4.Find by value\n0.Back\n > ";
					cin >> choose;

					if (choose == 1)
					{
						double buffer;
						cout << "Input number > ";
						cin >> buffer;
						DoubleList.AddNew(buffer);
					}
					else if (choose == 2)
					{
						int buffer;
						cout << "Input number > ";
						cin >> buffer;
						DoubleList.Delete(buffer);
					}
					else if (choose == 3)
					{
						int buffer;
						cout << "Input index > ";
						cin >> buffer;
						if (buffer < DoubleList.getSize() && buffer >= 0)
						{
							cout << "Result: " << DoubleList.GetElementByIndex(buffer) << endl;
						}
						else
							cout << "Cant find it!\n";
						system("pause");
					}
					else if (choose == 4)
					{
						double buffer;
						int ind;
						cout << "Input number > ";
						cin >> buffer;
						ind = DoubleList.FindByValue(buffer);
						if (ind != -1)
							cout << "Result: " << ind << endl;
						else
							cout << "Cant find!\n";
						system("pause");
					}
					else
					{
						menu = 1;
					}
				}
				else if (DataType == 3)
				{
					int choose = 0;
					cout << "Your list: ";
					for (int i = 0; i < FigureList.getSize(); i++)
					{
						MyFigure buff;
						buff = FigureList.GetElementByIndex(i);
						cout << i + 1 << ". ";
						for (int j = 0; j < buff.get_count_of_angles(); j++)
						{
							cout << buff.GetSideLengthByIndex(j) << " ";
						}
						cout << "P = " << buff.get_perimetr() << " S = " << buff.ploshad();
						cout << endl;
					}
					cout << "\n\nMenu:\n1.Add\n2.Delete\n3.Find by index\n4.Find by value\n0.Back\n > ";
					cin >> choose;

					if (choose == 1)
					{
						int angels = 0;
						cout << "Input count of angles > ";
						while (angels < 3 || angels > 5)
						{
							cin >> angels;
							if (angels < 3 || angels > 5)
							{
								cout << "Error! (3-5) > ";
							}
						}

						MyFigure buff(angels);
						for (int i = 0; i < buff.get_count_of_angles(); i++)
						{
							float val;
							cout << i + 1 << " > ";
							cin >> val;
							buff.SetLengthByIndex(val, i);
						}

						FigureList.AddNew(buff);
						system("pause");
					}
					else if (choose == 2)
					{
						int buffer;
						cout << "Input number > ";
						cin >> buffer;
						FigureList.Delete(buffer);
					}
					else if (choose == 3)
					{
						int buffer;
						cout << "Input index > ";
						cin >> buffer;
						if (buffer < FigureList.getSize() && buffer >= 0)
						{
							MyFigure obj(FigureList.GetElementByIndex(buffer));
							cout << "Result: ";
							for (int i = 0; i < obj.get_count_of_angles(); i++)
								cout << obj.GetSideLengthByIndex(i);
							cout << endl << endl;
						}
						else
							cout << "Cant find it!\n";
						system("pause");
					}
					else if (choose == 4)
					{
						cout << "Count of angles > ";
						int angles;
						cin >> angles;
						MyFigure buff(angles);
						for (int i = 0; i < buff.get_count_of_angles(); i++)
						{
							float val;
							cout << i + 1 << " > ";
							cin >> val;
							buff.SetLengthByIndex(val, i);
						}

						int res = FigureList.FindByValue(buff);
						if (res != -1)
						{
							cout << "Result: " << res << endl;
						}
						else
							cout << "Cant find it!";

					}
					else
					{
						menu = 1;
					}
				}
			}
			else
			{
				if (DataType == 1)
				{
					int choose = 0;
					cout << "Your list: ";
					for (int i = 0; i < intCList.getSize(); i++)
					{
						cout << intCList.GetElementByIndex(i) << " ";
					}
					cout << "\n\nMenu:\n1.Add\n2.Delete\n3.Find by index\n4.Find by value\n0.Back\n > ";
					cin >> choose;

					if (choose == 1)
					{
						int buffer;
						cout << "Input number > ";
						cin >> buffer;
						intCList.AddNew(buffer);
					}
					else if (choose == 2)
					{
						double buffer;
						cout << "Input number > ";
						cin >> buffer;
						intCList.Delete(buffer);
					}
					else if (choose == 3)
					{
						int buffer;
						cout << "Input index > ";
						cin >> buffer;
						if (buffer < intCList.getSize() && buffer >= 0)
						{
							cout << "Result: " << intCList.GetElementByIndex(buffer) << endl;
						}
						else
							cout << "Cant find it!\n";
						system("pause");
					}
					else if (choose == 4)
					{
						int buffer;
						cout << "Input number > ";
						cin >> buffer;
						int ind = intCList.FindByValue(buffer);
						if (ind != -1)
							cout << "Result: " << ind << endl;
						else
							cout << "Cant do it!\n";
						system("pause");
					}
					else
					{
						menu = 1;
					}
				}
				else if (DataType == 2)
				{
					int choose = 0;
					cout << "Your list: ";
					for (int i = 0; i < DoubleCList.getSize(); i++)
					{
						cout << DoubleCList.GetElementByIndex(i) << " ";
					}
					cout << "\n\nMenu:\n1.Add\n2.Delete\n3.Find by index\n4.Find by value\n0.Back\n > ";
					cin >> choose;

					if (choose == 1)
					{
						double buffer;
						cout << "Input number > ";
						cin >> buffer;
						DoubleCList.AddNew(buffer);
					}
					else if (choose == 2)
					{
						double buffer;
						cout << "Input number > ";
						cin >> buffer;
						DoubleCList.Delete(buffer);
					}
					else if (choose == 3)
					{
						int buffer;
						cout << "Input index > ";
						cin >> buffer;
						if (buffer < DoubleCList.getSize() && buffer >= 0)
						{
							cout << "Result: " << DoubleCList.GetElementByIndex(buffer) << endl;
						}
						else
							cout << "Cant find it!\n";
						system("pause");
					}
					else if (choose == 4)
					{
						double buffer;
						int ind;
						cout << "Input number > ";
						cin >> buffer;
						ind = DoubleCList.FindByValue(buffer);
						if (ind != -1)
							cout << "Result: " << ind << endl;
						else
							cout << "Cant find!\n";
						system("pause");
					}
					else
					{
						menu = 1;
					}
				}
				else if (DataType == 3)
				{
					int choose = 0;
					cout << "Your list: ";
					for (int i = 0; i < FigureCList.getSize(); i++)
					{
						MyFigure buff;
						buff = FigureCList.GetElementByIndex(i);
						cout << i + 1 << ". ";
						for (int j = 0; j < buff.get_count_of_angles(); j++)
						{
							cout << buff.GetSideLengthByIndex(j) << " ";
						}
						cout << "P = " << buff.get_perimetr() << " S = " << buff.ploshad();
						cout << endl;
					}
					cout << "\n\nMenu:\n1.Add\n2.Delete\n3.Find by index\n4.Find by value\n0.Back\n > ";
					cin >> choose;

					if (choose == 1)
					{
						int angels = 0;
						cout << "Input count of angles > ";
						while (angels < 3 || angels > 5)
						{
							cin >> angels;
							if (angels < 3 || angels > 5)
							{
								cout << "Error! (3-5) > ";
							}
						}

						MyFigure buff(angels);
						for (int i = 0; i < buff.get_count_of_angles(); i++)
						{
							float val;
							cout << i + 1 << " > ";
							cin >> val;
							buff.SetLengthByIndex(val, i);
						}

						FigureCList.AddNew(buff);
						system("pause");
					}
					else if (choose == 2)
					{
						int buffer;
						cout << "Input number > ";
						cin >> buffer;
						FigureCList.Delete(buffer);
					}
					else if (choose == 3)
					{
						int buffer;
						cout << "Input index > ";
						cin >> buffer;
						if (buffer < FigureCList.getSize() && buffer >= 0)
						{
							MyFigure obj(FigureCList.GetElementByIndex(buffer));
							cout << "Result: ";
							for (int i = 0; i < obj.get_count_of_angles(); i++)
								cout << obj.GetSideLengthByIndex(i);
							cout << endl << endl;
						}
						else
							cout << "Cant find it!\n";
						system("pause");
					}
					else if (choose == 4)
					{
						cout << "Count of angles > ";
						int angles;
						cin >> angles;
						MyFigure buff(angles);
						for (int i = 0; i < buff.get_count_of_angles(); i++)
						{
							float val;
							cout << i + 1 << " > ";
							cin >> val;
							buff.SetLengthByIndex(val, i);
						}

						int res = FigureCList.FindByValue(buff);
						if (res != -1)
						{
							cout << "Result: " << res << endl;
						}
						else
							cout << "Cant find it!";

					}
					else
					{
						menu = 1;
					}
				}
			}
		}
		else
		{
			menu = -1;
		}
	}

	return 0;
}
