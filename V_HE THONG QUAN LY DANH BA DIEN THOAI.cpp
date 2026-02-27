/* HỆ THỐNG QUẢN LÝ DANH BẠ ĐIỆN THOẠI
🎯 Chức năng:
1. Menu
2. Thêm liên hệ
3. Hiển thị
4. Tìm kiếm
5. Sắp xếp
6. Xóa */

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <cctype>
#include <algorithm>
using namespace std;

void displayChoose();
void Running_Program(); // Ham chinh de chay chuong trinh
void deleteWhiteSpace(string& str); // Xoa khoang trang o dau va cuoi chuoi

void displayContacts(vector<string>& name_contacts, vector<string>& phone_contacts); // 1. Hien thi tat ca lien he
void addContacts(vector<string>& name_contacts, vector<string>& phone_contacts); // 2. Them mot lien he
void lookforContacts(vector<string>& name_contacts, vector<string>& phone_contacts); // 3. Tim kiem lien he
void sortContacts(vector<string>& name_contacts, vector<string>& phone_contacts); // 4. Sap xep lien he
void deleteContacts(vector<string>& name_contacts, vector<string>& phone_contacts); // 5. Xoa lien he
bool exitProgram(); // 6. Thoat

int main()       /* ------------------------------- HAM CHINH ------------------------------- */
{
	Running_Program();
	return 0;
}

void displayChoose()
{
	cout << "\n=== HE THONG QUAN LY DANH BA DIEN THOAI ===\n"
		<< setfill('-') << setw(22) << "MENU" << setfill('-') << setw(22) << "\n"
		<< "1. Hien thi tat ca lien he" << "\n"
		<< "2. Them mot lien he" << "\n"
		<< "3. Tim kiem lien he" << "\n"
		<< "4. Sap xep lien he" << "\n"
		<< "5. Xoa lien he" << "\n"
		<< "6. Thoat" << "\n"
		<< "============================================" << "\n"
		<< "\nVui long chon chuc nang (1-6): ";
}
void deleteWhiteSpace(string& str) // Xoa khoang trang o dau va cuoi chuoi
{
	while (str[0] == ' ')
	{
		str.erase(0, 1);
	}
	while (str[str.length() - 1] == ' ')
	{
		str.erase(str.length() - 1, 1);
	}
}

void displayContacts(vector<string>& name_contacts, vector<string>& phone_contacts) // 1. Hien thi tat ca lien he
{
	if (name_contacts.empty() && phone_contacts.empty())
	{
		cout << "\n"
     	<< setfill('-') << setw(8) << "" 
     	<< " Danh sach lien he trong... "
     	<< setw(8) << "" << endl;
		return;
	}
	cout << "\n"
	 	 << setfill('-') << setw(20) << "" 
	 	 << " Tat ca lien he "
	 	 << setw(20) << "" << endl;
	for (int i = 0; i < name_contacts.size(); i++)
	{
		cout << "[" << (i + 1) << "]: " << name_contacts[i] << " - " << phone_contacts[i] << endl;
	}
	cout << setfill('-') << setw(57) << "" << endl;
}
void addContacts(vector<string>& name_contacts, vector<string>& phone_contacts) // 2. Them mot lien he
{
	string __name_contacts, __phone_contacts; // Bien tam de luu ten va so dien thoai lien he
	string num_add;

	cout << "\n"
     	<< setfill('-') << setw(20) << "" 
     	<< " Luu y: "
     	<< setw(20) << "" << "\n"
         << " - Ten lien he chi duoc chua chu cai va khoang trang.\n"
         << " - So dien thoai phai co 7-15 chu so.\n"
		 << " - Nhan (n/N) de quay lai menu.\n"
		 << " - Nhan (y/Y) de xem tat ca lien he.\n"
		 << setfill('-') << setw(50) << "" << endl;
    do // Nhap so luong lien he can them
    {
		cout << "Nhap so luong lien he can them: ";
		getline(cin, num_add);
		deleteWhiteSpace(num_add);
		
		if (num_add == "n" || num_add == "N")
		{
            num_add.clear();
			return;
		}
		if (num_add == "y" || num_add == "Y")
		{
			displayContacts(name_contacts, phone_contacts);
			num_add.clear();
			return;
		}
        for (int i = 0; i < num_add.length(); i++)
		{
            if (!isdigit(num_add[i]))
            {
                cout << "Ban phai nhap mot so nguyen duong hoac nhan (n/N) de quay lai menu!" << "\n";
                num_add.clear();
                break;
            } 
        	if (stoi(num_add) <= 0 || stoi(num_add) > 5)
			{
				cout << "Ban co the them toi da 5 va toi thieu 1 lien he. Nhan (n/N) de quay lai menu!" << "\n";
				num_add.clear();
				break;
			}
		}
    } while (num_add.empty());

	for (int i = 0; i < stoi(num_add); i++) // Vong lap de them lien he
	{
		do // Nhap ten lien he
		{
			cout << "Nhap ten lien he " << (i + 1) << ": ";
			getline(cin, __name_contacts);
			deleteWhiteSpace(__name_contacts);

			// Xoa cac khoang trang trung lap lien tiep
			for (int i = 0; i < __name_contacts.length(); i++)
			{
				if (__name_contacts[i] == ' ' && __name_contacts[i + 1] == ' ')
				{
					__name_contacts.erase(i, 1);
					i--;
				}
			}
			if (__name_contacts == "n" || __name_contacts == "N")
			{
				return;
			}
			for (char& character : __name_contacts)
			{
				if (character == ' ')
				{
					continue;
				}
				else if (isalpha(character))
				{
					character = tolower(character);
				}
				else if (!isalpha(character))
				{
					cout << "Ten lien he chi duoc chua chu cai va khoang trang. Nhan (n/N) de quay lai!" << endl;
					__name_contacts.clear();
					break;
				}
			}
			__name_contacts[0] = toupper(__name_contacts[0]);

			// Viet hoa chu cai dau sau moi khoang trang
			for (int i = 0; i < __name_contacts.length(); i++)
			{
				if (__name_contacts[i] == tolower(__name_contacts[i]) && __name_contacts[i - 1] == ' ')
				{
					__name_contacts[i] = toupper(__name_contacts[i]);
				}
			}
		} while (__name_contacts.empty());

		name_contacts.push_back(__name_contacts);

		do // Nhap so dien thoai
		{
			cout << "Nhap so dien thoai cho " << __name_contacts << ": ";
			getline(cin, __phone_contacts);
			deleteWhiteSpace(__phone_contacts);

            if (__phone_contacts == "n" || __phone_contacts == "N")
            {
                name_contacts.pop_back();
				__name_contacts.clear();
				__phone_contacts.clear();
                return;
            }
            for (char& character : __phone_contacts)
            {
                if (!isdigit(character))
                {
                    cout << "So dien thoai chi duoc chua chu so. Nhan (n/N) de quay lai!" << endl;
                    __phone_contacts.clear();
                    break;
                } else if (__phone_contacts.length() < 7 || __phone_contacts.length() > 15)
                {
                    cout << "So dien thoai phai co 7-15 chu so. Nhan (n/N) de quay lai!" << endl;
                    __phone_contacts.clear();
                    break;
                }
            }
		} while (__phone_contacts.empty());
		
		phone_contacts.push_back(__phone_contacts);
	}
}
void lookforContacts(vector<string>& name_contacts, vector<string>& phone_contacts) // 3. Tim kiem lien he
{
	string search_input;
	string substring; // Bien tam de luu chuoi con tu input
	vector<string> show_name_contacts, show_phone_contacts; // Bien tam de luu ket qua tim kiem
	vector<string> compare_results; // Bien tam de luu ket qua khop sau khi tach chuoi

	if (name_contacts.empty() && phone_contacts.empty())
		{
			cout << "\n"
				<< setfill('-') << setw(8) << "" 
				<< " Danh sach lien he trong... "
				<< setw(8) << "" << endl;
			return;
		}
    while (true)
	{
		cout << "\n"
			<< setfill('-') << setw(20) << "" 
			<< " Luu y: "
			<< setw(20) << "" << "\n"
			<< " - Ten lien he chi duoc chua chu cai va khoang trang.\n"
			<< " - Tim kiem bang so dien thoai 1-15 chu so.\n"
			<< " - Nhan (n/N) de quay lai menu.\n"
			<< " - Nhan (y/Y) de xem tat ca lien he.\n"
			<< setfill('-') << setw(50) << "" << "\n";

		do // Vong lap xu ly nhap lieu
		{
			cout << "Nhap ten hoac so dien thoai de tim lien he tuong tu: ";
			getline(cin, search_input);
			deleteWhiteSpace(search_input);

			string display_search = search_input; // Luu input goc de hien thi sau khi tach chuoi
			
			// Xoa cac khoang trang trung lap lien tiep
			for (int i = 0; i < search_input.length(); i++)
			{
				if (search_input[i] == ' ' && search_input[i + 1] == ' ')
				{
					search_input.erase(i, 1);
					i--;
				}
			}
			if (search_input == "n" || search_input == "N")
			{
				search_input.clear();
				return;
			}
			if (search_input == "y" || search_input == "Y")
			{
				displayContacts(name_contacts, phone_contacts);
				search_input.clear();
				continue;
			}

            if (isalpha(search_input[0])) // Truong hop nhap ten lien he
            {
				for (int i = 0; i < search_input.length(); i++)
                {
                    if (!isalpha(search_input[i]) && search_input[i] != ' ')
                    {
                        cout << "Chi duoc nhap ten lien he hoac so dien thoai, hoac nhan (n/N) de quay lai!" << "\n";
                        search_input.clear();
                        break;
                    }
                }
				if (search_input.empty()) continue; // Ten khong hop le, yeu cau nhap lai

				for (char& character : search_input)
				{
					if (character == ' ')
					{
						continue;
					}
					else if (isalpha(character))
					{
						character = tolower(character);
					}
				}
				search_input[0] = toupper(search_input[0]);
				
				// Viet hoa chu cai dau sau moi khoang trang
				for (int i = 0; i < search_input.length(); i++)
				{
					if (search_input[i] == tolower(search_input[i]) && search_input[i - 1] == ' ')
					{
						search_input[i] = toupper(search_input[i]);
					}
				}
                
				// Tach input thanh tung tu rieng va tim moi tu nhu chuoi con trong ten lien he.
				// Bat ky lien he nao co ten chua it nhat mot tu khop se duoc them vao ket qua.

				search_input += ' '; // Them khoang trang vao cuoi de tach tu cuoi cung
				for (int i = 0; i < search_input.length(); i++)
				{
					if (search_input[i] == ' ')
					{
						for (int j = 0; j < i; j++)
						{
							substring += search_input[j];
						}
						compare_results.push_back(substring);
						search_input.erase(0, i + 1);
						substring.clear();
						i = -1; // Dat lai vi tri do i++ trong vong lap
					}
				}
				for (int i = 0; i < name_contacts.size(); i++)
				{
					for (int j = 0; j < compare_results.size(); j++)
					{
						if (name_contacts[i].find(compare_results[j]) != string::npos)
						{
							show_name_contacts.push_back(name_contacts[i]);
							show_phone_contacts.push_back(phone_contacts[i]);
								break; // Tim thay ket qua, khong can tiep tuc trong lien he nay
						}
					}
				}
				if (show_name_contacts.empty() && show_phone_contacts.empty()) // Khong tim thay ket qua
				{
					cout << "Khong tim thay ket qua cho '" << display_search << "' trong danh sach lien he!" << endl;
					search_input.clear();
					display_search.clear();
					compare_results.clear();
					continue;
				}
				cout << "\n"
					 << setfill('-') << setw(50) << "\n"
					 << " Ket qua tim kiem cho: " << display_search << endl;

				for (int i = 0; i < show_name_contacts.size(); i++)
				{
					cout << "["<< i + 1 << "] " << show_name_contacts[i] << " - " << show_phone_contacts[i] << endl;
				}
				cout << setfill('-') << setw(50) << "\n";

				show_name_contacts.clear();
				show_phone_contacts.clear();
				compare_results.clear();
				continue;
            }
			
			if (isdigit(search_input[0])) // Truong hop nhap so dien thoai
			{
				for (int i = 0; i < search_input.length(); i++)
				{
					if (!isdigit(search_input[i]))
					{
						cout << "Nhap ten lien he hoac so dien thoai hoac nhan (n/N) de quay lai!" << "\n";
						search_input.clear();
						break;
					}
				}
				if (search_input.empty()) continue; // So dien thoai khong hop le, yeu cau nhap lai

				if (search_input.length() < 1 || search_input.length() > 15)
                {
                    cout << "So dien thoai phai co 1-15 chu so. Nhan (n/N) de quay lai!" << endl;
                    search_input.clear();
					display_search.clear();
                    continue;
                }
				
				// Tim input nhu chuoi con trong tung so dien thoai da luu
				for (int i = 0; i < phone_contacts.size(); i++)
				{
					if (phone_contacts[i].find(search_input) != string::npos)
					{
						show_name_contacts.push_back(name_contacts[i]);
						show_phone_contacts.push_back(phone_contacts[i]);
					}
				}
				if (show_name_contacts.empty() && show_phone_contacts.empty()) // Khong tim thay ket qua
				{
					cout << "Khong tim thay ket qua cho '" << display_search << "' trong danh sach lien he!" << endl;
					search_input.clear();
					display_search.clear();
					continue;
				}
				cout << "\n"
					 << setfill('-') << setw(50) << "\n"
					 << " Ket qua tim kiem cho: " << display_search << endl;

				for (int i = 0; i < show_name_contacts.size(); i++)
				{
					cout << "["<< i + 1 << "] " << show_name_contacts[i] << " - " << show_phone_contacts[i] << endl;
				}
				cout << setfill('-') << setw(50) << "\n";

				show_name_contacts.clear();
				show_phone_contacts.clear();
				search_input.clear();
				display_search.clear();
			}
		} while (search_input.empty());
	}
}
void sortContacts(vector<string>& name_contacts, vector<string>& phone_contacts) // 4. Sap xep lien he
{
    string sort_func;
    string position;
    string new_position;

    if (name_contacts.empty() && phone_contacts.empty())
	{
		cout << "\n"
     	<< setfill('-') << setw(8) << "" 
     	<< " Danh sach lien he trong... "
     	<< setw(8) << "" << endl;
		return;
	}
    while (true)
    {
        cout << "\n"
                << setfill('-') << setw(20) << "" 
                << " Luu y: "
                << setw(20) << "" << "\n"
                << " - Nhan (n/N) de quay lai menu.\n"
                << " - Nhan (y/Y) de xem tat ca lien he.\n"
                << setfill('-') << setw(50) << "" << "\n";
        do // Vong lap chon chuc nang sap xep
        {
            cout << " 1. Sap xep ten tu A den Z.\n"
                 << " 2. Sap xep ten tu Z den A.\n"
                 << " 3. Di chuyen lien he sang vi tri khac.\n"
                 << " 4. Hoan doi vi tri 2 lien he.\n"
                 << setfill('-') << setw(50) << "" << "\n"
                 << " Vui long chon chuc nang: "; 
            getline(cin, sort_func);
            deleteWhiteSpace(sort_func);

            if (sort_func == "n" || sort_func == "N")
			{
				sort_func.clear();
				return;
			}
			if (sort_func == "y" || sort_func == "Y")
			{
				displayContacts(name_contacts, phone_contacts);
				sort_func.clear();
				continue;
			}
            for (int i = 0; i < sort_func.length(); i++)
            {
                if (!isdigit(sort_func[i]))
                {
                    cout << "Chon lua chon 1-4 hoac nhan (n/N) de quay lai!" << "\n";
                    sort_func.clear();
                    break;
                }
				if (stoi(sort_func) > 4 || stoi(sort_func) <=0)
            	{
            	    cout << "Chon lua chon 1-4 hoac nhan (n/N) de quay lai!" << "\n";
            	    sort_func.clear();
					break;
            	}
            }
        } while (sort_func.empty());

        if (sort_func == "1") // Sap xep noi bot: A den Z
        { 
            for (int i = 0; i < name_contacts.size(); i++)
            {
                for (int j = 0; j < name_contacts.size() - 1; j++)
                {
                    if (name_contacts[j + 1][0] < name_contacts[j][0])
                    {
                        swap(name_contacts[j], name_contacts[j + 1]);
                        swap(phone_contacts[j], phone_contacts[j + 1]);
                    }
                }
            }
            cout << " Da sap xep lien he tu A den Z!" << "\n";
            return;
        } else if (sort_func == "2") // Sap xep noi bot: Z den A
        {
            for (int i = 0; i < name_contacts.size(); i++)
            {
                for (int j = 0; j < name_contacts.size() - 1; j++)
                {
                    if (name_contacts[j + 1][0] > name_contacts[j][0])
                    {
                        swap(name_contacts[j], name_contacts[j + 1]);
                        swap(phone_contacts[j], phone_contacts[j + 1]);
                    }
                }
            }
            cout << " Da sap xep lien he tu Z den A!" << "\n";
            return;
        } else if (sort_func == "3") // Di chuyen lien he sang vi tri khac
        {
            // Su dung insert-then-erase de di chuyen phan tu trong vector.
            // Chen vao new_position truoc, sau do xoa o chi so goc
            // (lech 1 don vi neu new_position <= position do viec chen lam dich chi so).
            cout << "\n"
                 << setfill('-') << setw(10) << "" 
                 << "Nhan (n/N) de quay lai, (y/Y) de xem tat ca lien he!"
                 << setfill('-') << setw(10) << "" << "\n";
            do // Nhap vi tri hien tai
            {
                cout << " Nhap vi tri lien he can di chuyen: ";
                getline(cin, position);
                deleteWhiteSpace(position);

                if (position == "n" || position == "N")
                {
                    position.clear();
                    return;
                }
                if (position == "y" || position == "Y")
                {
                    displayContacts(name_contacts, phone_contacts);
                    position.clear();
                    continue;
                }
                for (int i = 0; i < position.length(); i++)
                {
                    if (!isdigit(position[i]))
                    {
                        cout << "Nhap vi tri tu 1 den " << name_contacts.size() << " hoac nhan (n/N) de quay lai!" << "\n";
                        position.clear();
                        break;
                    }
                    if (stoi(position) > name_contacts.size() || stoi(position) <= 0)
                    {
                        cout << "Nhap vi tri tu 1 den " << name_contacts.size() << " hoac nhan (n/N) de quay lai!" << "\n";
                        position.clear();
                        break;
                    }
                }
            } while (position.empty());

            cout << "\n"
                 << setfill('-') << setw(10) << "" 
                 << "Nhan (n/N) de quay lai, (y/Y) de xem tat ca lien he!"
                 << setfill('-') << setw(10) << "" << "\n";

            do // Nhap vi tri moi
            {
                cout << " Nhap vi tri moi cho lien he: ";
                getline(cin, new_position);
                deleteWhiteSpace(new_position);

                if (new_position == "n" || new_position == "N")
                {
                    new_position.clear();
                    return;
                }
                if (new_position == "y" || new_position == "Y")
                {
                    displayContacts(name_contacts, phone_contacts);
                    new_position.clear();
                    continue;
                }
                if (new_position == position)
                {
                    cout << "Vi tri moi phai khac vi tri hien tai!" << "\n";
                    new_position.clear();
                    continue;
                }
                for (int i = 0; i < new_position.length(); i++)
                {
                    if (!isdigit(new_position[i]))
                    {
                        cout << "Nhap vi tri tu 1 den " << name_contacts.size() << " hoac nhan (n/N) de quay lai!" << "\n";
                        new_position.clear();
                        break;
                    }
                    if (stoi(new_position) > name_contacts.size() || stoi(new_position) <= 0)
                    {
                        cout << "Nhap vi tri tu 1 den " << name_contacts.size() << " hoac nhan (n/N) de quay lai!" << "\n";
                        new_position.clear();
                        break;
                    }
                }
            } while (new_position.empty());

            name_contacts.insert(name_contacts.begin() + stoi(new_position) - 1, name_contacts[stoi(position) - 1]);
            name_contacts.erase(name_contacts.begin() + stoi(position));
            phone_contacts.insert(phone_contacts.begin() + stoi(new_position) - 1, phone_contacts[stoi(position) - 1]);
            phone_contacts.erase(phone_contacts.begin() + stoi(position));
            
            cout << setfill('-') << setw(50) << "" << "\n"
                 << "Lien he tai vi tri " << position << " da duoc di chuyen den vi tri " << new_position << "!" << "\n"
                 << setfill('-') << setw(50) << "" << "\n"; 
            return;
        } else if (sort_func == "4") // Hoan doi vi tri 2 lien he
        {
            do // Nhap vi tri thu nhat
            {
                cout << "\n"
                     << setfill('-') << setw(10) << "" 
                     << "Nhan (n/N) de quay lai, (y/Y) de xem tat ca lien he!"
                     << setfill('-') << setw(10) << "" << "\n"
                     << " Nhap vi tri lien he thu nhat can hoan doi: ";
                getline(cin, position);
                deleteWhiteSpace(position);

                if (position == "n" || position == "N")
                {
                    position.clear();
                    return;
                }
                if (position == "y" || position == "Y")
                {
                    displayContacts(name_contacts, phone_contacts);
                    position.clear();
                    continue;
                } 
                for (int i = 0; i < position.length(); i++)
                {
                    if (!isdigit(position[i]))
                    {
                        cout << setfill('-') << setw(50) << "" << "\n"
                             << "Nhap vi tri tu 1 den " << name_contacts.size() << " hoac nhan (n/N) de quay lai!" << "\n";
                        position.clear();
                        break;
                    }
                    if (stoi(position) > name_contacts.size() || stoi(position) <= 0)
                    {
                        cout << setfill('-') << setw(50) << "" << "\n"
                             << "Nhap vi tri tu 1 den " << name_contacts.size() << " hoac nhan (n/N) de quay lai!" << "\n";
                        position.clear();
                        break;
                    }
                }
            } while (position.empty());

            do // Nhap vi tri thu hai
            {
                cout << setfill('-') << setw(50) << "" << "\n"
                     << " Nhap vi tri lien he thu hai can hoan doi voi vi tri " << position << ": ";

                getline(cin, new_position);
                deleteWhiteSpace(new_position);

                if (new_position == "n" || new_position == "N")
                {
                    new_position.clear();
                    return;
                }
                if (new_position == "y" || new_position == "Y")
                {
                    displayContacts(name_contacts, phone_contacts);
                    new_position.clear();
                    continue;
                }
                if (new_position == position)
                {
                    cout << setfill('-') << setw(50) << "" << "\n"
                         << "Vi tri moi phai khac vi tri hien tai!" << "\n"
                         << setfill('-') << setw(50) << "" << "\n";
                    new_position.clear();
                    continue;
                }
                for (int i = 0; i < new_position.length(); i++)
                {
                    if (!isdigit(new_position[i]))
                    {
                        cout << "Nhap vi tri tu 1 den " << name_contacts.size() << " hoac nhan (n/N) de quay lai!" << "\n";
                        new_position.clear();
                        break;
                    }
                    if (stoi(new_position) > name_contacts.size() || stoi(new_position) <= 0)
                    {
                        cout << "Nhap vi tri tu 1 den " << name_contacts.size() << " hoac nhan (n/N) de quay lai!" << "\n";
                        new_position.clear();
                        break;
                    }
                }
            } while (new_position.empty());

            swap(name_contacts[stoi(position) - 1], name_contacts[stoi(new_position) - 1]);
            swap(phone_contacts[stoi(position) - 1], phone_contacts[stoi(new_position) - 1]);

            cout << setfill('-') << setw(50) << "" << "\n"
                 << "Lien he tai vi tri " << position << " da duoc hoan doi voi lien he tai vi tri " << new_position << "!" << "\n"
                 << setfill('-') << setw(50) << "" << "\n";
            return;
        }
    }
}
void deleteContacts(vector<string>& name_contacts, vector<string>& phone_contacts) // 5. Xoa lien he
{
    string index_delete; // Bien tam de luu chi so lien he can xoa
    string num_delete;
    string YoN; // Bien tam de luu xac nhan (co/khong)
    
	if (name_contacts.empty() && phone_contacts.empty())
	{
		cout << "\n"
     	<< setfill('-') << setw(8) << "" 
     	<< " Danh sach lien he trong... "
     	<< setw(8) << "" << endl;
		return;
	}
    while (true)
    {
        cout << "\n"
             << setfill('-') << setw(20) << "" 
             << " Luu y: "
             << setw(20) << "" << "\n"
             << " - Ban co the xoa mot hoac nhieu lien he cung luc.\n"
             << " - Nhan (n/N) de quay lai menu.\n"
             << " - Nhan (y/Y) de xem tat ca lien he.\n"
             << setfill('-') << setw(50) << "" << "\n";
        do // Vong lap xu ly nhap lieu
		{
			cout << "Nhap so luong lien he can xoa: ";
			getline(cin, num_delete);
			deleteWhiteSpace(num_delete);
			
			if (num_delete == "n" || num_delete == "N")
			{
				num_delete.clear();
				return;
			}
			if (num_delete == "y" || num_delete == "Y")
			{
				displayContacts(name_contacts, phone_contacts);
				num_delete.clear();
				continue;
			}
            for (int i = 0; i < num_delete.length(); i++)
            {
                if (!isdigit(num_delete[i]))
                {
                    cout << "Ban phai nhap mot so nguyen duong hoac nhan (n/N) de quay lai menu!" << "\n";
                    num_delete.clear();
                    break;
                }
				if (stoi(num_delete) > name_contacts.size())
            	{
            	    cout << "Ban co the xoa toi da " << name_contacts.size() << " lien he hoac nhan (n/N) de quay lai!" << "\n";
            	    num_delete.clear();
					break;
            	}
            }
		} while (num_delete.empty());
		
		if (stoi(num_delete) == name_contacts.size())
		{
			do // Xac nhan xoa tat ca lien he
            {
				cout << setfill('-') << setw(60) << "" << "\n"
			 		 << "!! BAN CO CHAC MUON XOA TAT CA LIEN HE? (y/n): ";
                getline (cin, YoN);
                deleteWhiteSpace(YoN);
            
                if (YoN == "n" || YoN == "N")
                {
                    YoN.clear();
                    return;
                }
                if (YoN == "y" || YoN == "Y")
                {
					name_contacts.clear();
					phone_contacts.clear();
                    YoN.clear();
                    index_delete.clear();
					cout << "\n" << setfill('-') << setw(12) << ""
					 << " Da xoa tat ca lien he thanh cong! "
						 << setfill('-') << setw(12) << "" << "\n";
                    return;
                }
            } while (YoN != "y" && YoN != "Y" && YoN != "n" && YoN != "N");
		}

        for (int i = 0; i < stoi(num_delete); i++) // Vong lap nhap chi so cac lien he can xoa
        {
            cout << "Nhap chi so lien he thu " << i + 1 << " can xoa: ";
			getline(cin, index_delete);
			deleteWhiteSpace(index_delete);
			
			if (index_delete == "n" || index_delete == "N")
			{
				index_delete.clear();
				return;
			}
			if (index_delete == "y" || index_delete == "Y")
			{
				displayContacts(name_contacts, phone_contacts);
				index_delete.clear();
				i--;
				continue;
			}
            for (int j = 0; j < index_delete.length(); j++)
            {
                if (!isdigit(index_delete[j])) 
                {
                    cout << "Ban phai nhap mot so nguyen duong hoac nhan (n/N) de quay lai menu!" << "\n";
                    index_delete.clear();
                    i--;
                    break;
                }
                if (stoi(index_delete) <= 0 || stoi(index_delete) > name_contacts.size())
                {
                    cout << "Vi tri phai nam trong khoang 1 den " << name_contacts.size() << " hoac nhan (n/N) de quay lai!" << "\n";
                    index_delete.clear();
                    i--;
                    break;
                }
            }

            do // Xac nhan xoa lien he
            {
                cout << "Ban co chac muon xoa: " << name_contacts[stoi(index_delete) - 1] << " - " 
                                                              << phone_contacts[stoi(index_delete) - 1] << " ? (y/n): ";
                getline (cin, YoN);
                deleteWhiteSpace(YoN);
            
                if (YoN == "n" || YoN == "N")
                {
                    YoN.clear();
                    return;
                }
                if (YoN == "y" || YoN == "Y")
                {
                    name_contacts.erase(name_contacts.begin() + stoi(index_delete) - 1);
                    phone_contacts.erase(phone_contacts.begin() + stoi(index_delete) - 1);

                    cout << setfill('-') << setw(5) << ""
                            << " Da xoa lien he tai vi tri [" << index_delete << "] thanh cong! "
                            << setfill('-') << setw(5) << "" << "\n";
                    YoN.clear();
                    index_delete.clear();
                    break;
                }
            } while (YoN != "y" && YoN != "Y" && YoN != "n" && YoN != "N");
        }
	}
}
bool exitProgram() // 6. Thoat
{
	string exit_confirm;

	cout << "\n"
     	<< setfill('-') << setw(20) << "" 
     	<< " Luu y: "
     	<< setw(20) << "" << "\n"
         << "Thoat chuong trinh se xoa tat ca du lieu da nhap!\n"
		 << setfill('-') << setw(50) << "" << "\n"
		 << "Ban co chac muon thoat? (y/n): ";

	while (true)
	{
		getline(cin, exit_confirm);
		deleteWhiteSpace(exit_confirm);

		if (exit_confirm == "y" || exit_confirm == "Y")
		{
			cout << "\n"
				<< setfill('-') << setw(4) << "" 
				<< " Da thoat chuong trinh. Cam on ban da su dung! "
				<< setw(4) << "" << endl;
			return true;
		}
		else if (exit_confirm == "n" || exit_confirm == "N")
		{
			cout << "\n"
     		<< setfill('-') << setw(10) << "" 
     		<< " Tiep tuc chuong trinh... "
     		<< setw(10) << "" << endl;
			return false;
		}
		else
		{
			cout << "Lua chon khong hop le. Nhap (y/n): ";
		}
	} 
}

void Running_Program()
{
	vector<string> name_contacts, phone_contacts;
	string choice;
	bool shouldExit = false; // Bien kiem tra nguoi dung co muon thoat khong

	do
	{
		displayChoose(); // Hien thi menu chon chuc nang
		do // Nhap lua chon
    	{
			getline(cin, choice);
        	deleteWhiteSpace(choice);

        	for (int i = 0; i < choice.length(); i++)
        	{
            		if (!isdigit(choice[i]))
            		{
            	    	cout << "Nhap so tu 1 den 6. Vui long chon lai!" << "\n";
            	    choice.clear();
					displayChoose();
            	    break;
        	    } 
        	}
    } while (choice.empty());

		switch (stoi(choice))
		{
		case 1:
			displayContacts(name_contacts, phone_contacts); // Hien thi tat ca lien he
			break;
		case 2:
			addContacts(name_contacts, phone_contacts); // Them lien he
			break;
		case 3:
			lookforContacts(name_contacts, phone_contacts); // Tim kiem lien he
			break;
		case 4:
			sortContacts(name_contacts, phone_contacts); // Sap xep lien he
			break;
		case 5:
			deleteContacts(name_contacts, phone_contacts); // Xoa lien he
			break;
		case 6:
			shouldExit = exitProgram(); // Thoat
			break;
		default:
			cout << "Chon so tu 1 den 6. Vui long thu lai!" << endl; // Lua chon khong hop le
			break;
		}
	} while (!shouldExit);
}
