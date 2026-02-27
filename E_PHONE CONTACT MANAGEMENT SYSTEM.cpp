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
void Running_Program(); // Main function to run program
void deleteWhiteSpace(string& str); // Remove spaces at beginning and end of string

void displayContacts(vector<string>& name_contacts, vector<string>& phone_contacts); // 1. Display all contacts
void addContacts(vector<string>& name_contacts, vector<string>& phone_contacts); // 2. Add a contact
void lookforContacts(vector<string>& name_contacts, vector<string>& phone_contacts); // 3. Search for a contact
void sortContacts(vector<string>& name_contacts, vector<string>& phone_contacts); // 4. Sort contacts
void deleteContacts(vector<string>& name_contacts, vector<string>& phone_contacts); // 5. Delete a contact
bool exitProgram(); // 6. Exit 

int main()       /* ------------------------------- MAIN FUNCTION ------------------------------- */
{
	Running_Program();
	return 0;
}

void displayChoose()
{
	cout << "\n=== PHONE CONTACT MANAGEMENT SYSTEM ===\n"
		<< setfill('-') << setw(22) << "MENU" << setfill('-') << setw(22) << "\n"
		<< "1. Display all contacts" << "\n"
		<< "2. Add a contact" << "\n"
		<< "3. Search for a contact" << "\n"
		<< "4. Sort contacts" << "\n"
		<< "5. Delete a contact" << "\n"
		<< "6. Exit" << "\n"
		<< "============================================" << "\n"
		<< "\nPlease choose a function (1-6): ";
}
void deleteWhiteSpace(string& str) // Remove spaces at beginning and end of string
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

void displayContacts(vector<string>& name_contacts, vector<string>& phone_contacts) // 1. Display all contacts
{
	if (name_contacts.empty() && phone_contacts.empty())
	{
		cout << "\n"
     	<< setfill('-') << setw(8) << "" 
     	<< " Contact list is empty... "
     	<< setw(8) << "" << endl;
		return;
	}
	cout << "\n"
	 	 << setfill('-') << setw(20) << "" 
	 	 << " All Contacts "
	 	 << setw(20) << "" << endl;
	for (int i = 0; i < name_contacts.size(); i++)
	{
		cout << "[" << (i + 1) << "]: " << name_contacts[i] << " - " << phone_contacts[i] << endl;
	}
	cout << setfill('-') << setw(57) << "" << endl;
}
void addContacts(vector<string>& name_contacts, vector<string>& phone_contacts) // 2. Add a contact
{
	string __name_contacts, __phone_contacts; // Temporary variables to store contact name and phone number
	string num_add;

	cout << "\n"
     	<< setfill('-') << setw(20) << "" 
     	<< " Notes: "
     	<< setw(20) << "" << "\n"
         << " - Contact name can only contain letters and spaces.\n"
         << " - Phone number must be 7-15 digits.\n"
		 << " - Press (n/N) to go back to menu.\n"
		 << " - Press (y/Y) to view all contacts.\n"
		 << setfill('-') << setw(50) << "" << endl;
    do // Input number of contacts to add
    {
		cout << "Enter number of contacts to add: ";
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
                cout << "You must enter a positive integer or press (n/N) to go back to menu!" << "\n";
                num_add.clear();
                break;
            } 
        	if (stoi(num_add) <= 0 || stoi(num_add) > 5)
			{
				cout << "You can add maximum 5 contacts or minimum 1. Press (n/N) to go back to menu!" << "\n";
				num_add.clear();
				break;
			}
		}
    } while (num_add.empty());

	for (int i = 0; i < stoi(num_add); i++) // Loop to add contacts
	{
		do // Input contact name
		{
			cout << "Enter name for contact " << (i + 1) << ": ";
			getline(cin, __name_contacts);
			deleteWhiteSpace(__name_contacts);

			// Remove consecutive duplicate spaces
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
					cout << "Contact name can only contain letters and spaces. Press (n/N) to go back!" << endl;
					__name_contacts.clear();
					break;
				}
			}
			__name_contacts[0] = toupper(__name_contacts[0]);

			// Capitalize first letter after each space
			for (int i = 0; i < __name_contacts.length(); i++)
			{
				if (__name_contacts[i] == tolower(__name_contacts[i]) && __name_contacts[i - 1] == ' ')
				{
					__name_contacts[i] = toupper(__name_contacts[i]);
				}
			}
		} while (__name_contacts.empty());

		name_contacts.push_back(__name_contacts);

		do // Input phone number
		{
			cout << "Enter phone number for " << __name_contacts << ": ";
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
                    cout << "Phone number can only contain digits. Press (n/N) to go back!" << endl;
                    __phone_contacts.clear();
                    break;
                } else if (__phone_contacts.length() < 7 || __phone_contacts.length() > 15)
                {
                    cout << "Phone number must be 7-15 digits. Press (n/N) to go back!" << endl;
                    __phone_contacts.clear();
                    break;
                }
            }
		} while (__phone_contacts.empty());
		
		phone_contacts.push_back(__phone_contacts);
	}
}
void lookforContacts(vector<string>& name_contacts, vector<string>& phone_contacts) // 3. Search for a contact
{
	string search_input;
	string substring; // Temporary variable to store substring from input
	vector<string> show_name_contacts, show_phone_contacts; // Temporary variables to store search results
	vector<string> compare_results; // Temporary variables to store matching results after parsing

	if (name_contacts.empty() && phone_contacts.empty())
		{
			cout << "\n"
				<< setfill('-') << setw(8) << "" 
				<< " Contact list is empty... "
				<< setw(8) << "" << endl;
			return;
		}
    while (true)
	{
		cout << "\n"
			<< setfill('-') << setw(20) << "" 
			<< " Notes: "
			<< setw(20) << "" << "\n"
			<< " - Contact name can only contain letters and spaces.\n"
			<< " - Search by 1-15 digit phone number.\n"
			<< " - Press (n/N) to go back to menu.\n"
			<< " - Press (y/Y) to view all contacts.\n"
			<< setfill('-') << setw(50) << "" << "\n";

		do // Input processing loop
		{
			cout << "Enter contact name or phone number to find matching contacts: ";
			getline(cin, search_input);
			deleteWhiteSpace(search_input);

			string display_search = search_input; // Preserve original input for display after parsing
			
			// Remove consecutive duplicate spaces
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

            if (isalpha(search_input[0])) // Case when input is a contact name
            {
				for (int i = 0; i < search_input.length(); i++)
                {
                    if (!isalpha(search_input[i]) && search_input[i] != ' ')
                    {
                        cout << "You can only enter a contact name or phone number, or press (n/N) to go back!" << "\n";
                        search_input.clear();
                        break;
                    }
                }
				if (search_input.empty()) continue; // Invalid name, request re-entry

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
				
				// Capitalize first letter after each space
				for (int i = 0; i < search_input.length(); i++)
				{
					if (search_input[i] == tolower(search_input[i]) && search_input[i - 1] == ' ')
					{
						search_input[i] = toupper(search_input[i]);
					}
				}
                
				// Parse input into individual words and search each word as a substring in contact names.
				// Any contact whose name contains at least one matching word is added to results.

				search_input += ' '; // Add space at end to parse last word
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
						i = -1; // Reset for next iteration due to i++ in loop
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
								break; // Found match, no need to continue searching in this contact
						}
					}
				}
				if (show_name_contacts.empty() && show_phone_contacts.empty()) // No matching results found
				{
					cout << "No match found for '" << display_search << "' in contact list!" << endl;
					search_input.clear();
					display_search.clear();
					compare_results.clear();
					continue;
				}
				cout << "\n"
					 << setfill('-') << setw(50) << "\n"
					 << " Search results for: " << display_search << endl;

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
			
			if (isdigit(search_input[0])) // Case when input is a phone number
			{
				for (int i = 0; i < search_input.length(); i++)
				{
					if (!isdigit(search_input[i]))
					{
						cout << "Enter contact name or phone number or press (n/N) to go back!" << "\n";
						search_input.clear();
						break;
					}
				}
				if (search_input.empty()) continue; // Invalid phone number, request re-entry

				if (search_input.length() < 1 || search_input.length() > 15)
                {
                    cout << "Phone number must be 1-15 digits. Press (n/N) to go back!" << endl;
                    search_input.clear();
					display_search.clear();
                    continue;
                }
				
				// Search for the input as a substring within each stored phone number
				for (int i = 0; i < phone_contacts.size(); i++)
				{
					if (phone_contacts[i].find(search_input) != string::npos)
					{
						show_name_contacts.push_back(name_contacts[i]);
						show_phone_contacts.push_back(phone_contacts[i]);
					}
				}
				if (show_name_contacts.empty() && show_phone_contacts.empty()) // No matching results found
				{
					cout << "No match found for '" << display_search << "' in contact list!" << endl;
					search_input.clear();
					display_search.clear();
					continue;
				}
				cout << "\n"
					 << setfill('-') << setw(50) << "\n"
					 << " Search results for: " << display_search << endl;

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
void sortContacts(vector<string>& name_contacts, vector<string>& phone_contacts) // 4. Sort contacts
{
    string sort_func;
    string position;
    string new_position;

    if (name_contacts.empty() && phone_contacts.empty())
	{
		cout << "\n"
     	<< setfill('-') << setw(8) << "" 
     	<< " Contact list is empty... "
     	<< setw(8) << "" << endl;
		return;
	}
    while (true)
    {
        cout << "\n"
                << setfill('-') << setw(20) << "" 
                << " Notes: "
                << setw(20) << "" << "\n"
                << " - Press (n/N) to go back to menu.\n"
                << " - Press (y/Y) to view all contacts.\n"
                << setfill('-') << setw(50) << "" << "\n";
        do // Sort function selection loop
        {
            cout << " 1. Sort names from A to Z.\n"
                 << " 2. Sort names from Z to A.\n"
                 << " 3. Move contact to another position.\n"
                 << " 4. Swap positions of 2 contacts.\n"
                 << setfill('-') << setw(50) << "" << "\n"
                 << " Please choose a function: "; 
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
                    cout << "Choose option 1-4 or press (n/N) to go back!" << "\n";
                    sort_func.clear();
                    break;
                }
				if (stoi(sort_func) > 4 || stoi(sort_func) <=0)
            	{
            	    cout << "Choose option 1-4 or press (n/N) to go back!" << "\n";
            	    sort_func.clear();
					break;
            	}
            }
        } while (sort_func.empty());

        if (sort_func == "1") // Bubble sort: A to Z
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
            cout << " Contacts sorted from A to Z!" << "\n";
            return;
        } else if (sort_func == "2") // Bubble sort: Z to A
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
            cout << " Contacts sorted from Z to A!" << "\n";
            return;
        } else if (sort_func == "3") // Move contact to another position
        {
            // Uses insert-then-erase to relocate an element within the vector.
            // Insert at new_position first, then erase from the original index
            // (offset by 1 if new_position <= position due to the insertion shifting indices).
            cout << "\n"
                 << setfill('-') << setw(10) << "" 
                 << "Press (n/N) to go back, (y/Y) to view all contacts!"
                 << setfill('-') << setw(10) << "" << "\n";
            do // Input current position
            {
                cout << " Enter position of contact to move: ";
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
                        cout << "Enter position 1 to " << name_contacts.size() << " or press (n/N) to go back!" << "\n";
                        position.clear();
                        break;
                    }
                    if (stoi(position) > name_contacts.size() || stoi(position) <= 0)
                    {
                        cout << "Enter position 1 to " << name_contacts.size() << " or press (n/N) to go back!" << "\n";
                        position.clear();
                        break;
                    }
                }
            } while (position.empty());

            cout << "\n"
                 << setfill('-') << setw(10) << "" 
                 << "Press (n/N) to go back, (y/Y) to view all contacts!"
                 << setfill('-') << setw(10) << "" << "\n";

            do // Input new position
            {
                cout << " Enter new position for contact: ";
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
                    cout << "New position must be different from current position!" << "\n";
                    new_position.clear();
                    continue;
                }
                for (int i = 0; i < new_position.length(); i++)
                {
                    if (!isdigit(new_position[i]))
                    {
                        cout << "Enter position 1 to " << name_contacts.size() << " or press (n/N) to go back!" << "\n";
                        new_position.clear();
                        break;
                    }
                    if (stoi(new_position) > name_contacts.size() || stoi(new_position) <= 0)
                    {
                        cout << "Enter position 1 to " << name_contacts.size() << " or press (n/N) to go back!" << "\n";
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
                 << "Contact at position " << position << " moved to position " << new_position << "!" << "\n"
                 << setfill('-') << setw(50) << "" << "\n"; 
            return;
        } else if (sort_func == "4") // Swap positions of 2 contacts
        {
            do // Input first position
            {
                cout << "\n"
                     << setfill('-') << setw(10) << "" 
                     << "Press (n/N) to go back, (y/Y) to view all contacts!"
                     << setfill('-') << setw(10) << "" << "\n"
                     << " Enter position of first contact to swap: ";
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
                             << "Enter position 1 to " << name_contacts.size() << " or press (n/N) to go back!" << "\n";
                        position.clear();
                        break;
                    }
                    if (stoi(position) > name_contacts.size() || stoi(position) <= 0)
                    {
                        cout << setfill('-') << setw(50) << "" << "\n"
                             << "Enter position 1 to " << name_contacts.size() << " or press (n/N) to go back!" << "\n";
                        position.clear();
                        break;
                    }
                }
            } while (position.empty());

            do // Input second position
            {
                cout << setfill('-') << setw(50) << "" << "\n"
                     << " Enter position of second contact to swap with " << position << ": ";

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
                         << "New position must be different from current position!" << "\n"
                         << setfill('-') << setw(50) << "" << "\n";
                    new_position.clear();
                    continue;
                }
                for (int i = 0; i < new_position.length(); i++)
                {
                    if (!isdigit(new_position[i]))
                    {
                        cout << "Enter position 1 to " << name_contacts.size() << " or press (n/N) to go back!" << "\n";
                        new_position.clear();
                        break;
                    }
                    if (stoi(new_position) > name_contacts.size() || stoi(new_position) <= 0)
                    {
                        cout << "Enter position 1 to " << name_contacts.size() << " or press (n/N) to go back!" << "\n";
                        new_position.clear();
                        break;
                    }
                }
            } while (new_position.empty());

            swap(name_contacts[stoi(position) - 1], name_contacts[stoi(new_position) - 1]);
            swap(phone_contacts[stoi(position) - 1], phone_contacts[stoi(new_position) - 1]);

            cout << setfill('-') << setw(50) << "" << "\n"
                 << "Contact at position " << position << " swapped with contact at position " << new_position << "!" << "\n"
                 << setfill('-') << setw(50) << "" << "\n";
            return;
        }
    }
}
void deleteContacts(vector<string>& name_contacts, vector<string>& phone_contacts) // 5. Delete a contact
{
    string index_delete; // Temporary variable to store index of contact to delete
    string num_delete;
    string YoN; // Temporary variable to store confirmation (yes/no)
    
	if (name_contacts.empty() && phone_contacts.empty())
	{
		cout << "\n"
     	<< setfill('-') << setw(8) << "" 
     	<< " Contact list is empty... "
     	<< setw(8) << "" << endl;
		return;
	}
    while (true)
    {
        cout << "\n"
             << setfill('-') << setw(20) << "" 
             << " Notes: "
             << setw(20) << "" << "\n"
             << " - You can delete one or multiple contacts at once.\n"
             << " - Press (n/N) to go back to menu.\n"
             << " - Press (y/Y) to view all contacts.\n"
             << setfill('-') << setw(50) << "" << "\n";
        do // Input processing loop
		{
			cout << "Enter number of contacts to delete: ";
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
                    cout << "You must enter a positive integer or press (n/N) to go back to menu!" << "\n";
                    num_delete.clear();
                    break;
                }
				if (stoi(num_delete) > name_contacts.size())
            	{
            	    cout << "You can delete maximum " << name_contacts.size() << " contacts or press (n/N) to go back!" << "\n";
            	    num_delete.clear();
					break;
            	}
            }
		} while (num_delete.empty());
		
		if (stoi(num_delete) == name_contacts.size())
		{
			do // Confirm delete all contacts
            {
				cout << setfill('-') << setw(60) << "" << "\n"
			 		 << "!! ARE YOU SURE YOU WANT TO DELETE ALL CONTACTS? (y/n): ";
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
					 << " Successfully deleted all contacts! "
						 << setfill('-') << setw(12) << "" << "\n";
                    return;
                }
            } while (YoN != "y" && YoN != "Y" && YoN != "n" && YoN != "N");
		}

        for (int i = 0; i < stoi(num_delete); i++) // Loop to input indices of contacts to delete
        {
            cout << "Enter index of contact " << i + 1 << " to delete: ";
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
                    cout << "You must enter a positive integer or press (n/N) to go back to menu!" << "\n";
                    index_delete.clear();
                    i--;
                    break;
                }
                if (stoi(index_delete) <= 0 || stoi(index_delete) > name_contacts.size())
                {
                    cout << "Position must be between 1 and " << name_contacts.size() << " or press (n/N) to go back!" << "\n";
                    index_delete.clear();
                    i--;
                    break;
                }
            }

            do // Confirm delete contact
            {
                cout << "Are you sure you want to delete: " << name_contacts[stoi(index_delete) - 1] << " - " 
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
                            << " Successfully deleted contact at position [" << index_delete << "]! "
                            << setfill('-') << setw(5) << "" << "\n";
                    YoN.clear();
                    index_delete.clear();
                    break;
                }
            } while (YoN != "y" && YoN != "Y" && YoN != "n" && YoN != "N");
        }
	}
}
bool exitProgram() // 6. Exit
{
	string exit_confirm;

	cout << "\n"
     	<< setfill('-') << setw(20) << "" 
     	<< " Note: "
     	<< setw(20) << "" << "\n"
         << "Exiting the program will delete all entered data!\n"
		 << setfill('-') << setw(50) << "" << "\n"
		 << "Are you sure you want to exit? (y/n): ";

	while (true)
	{
		getline(cin, exit_confirm);
		deleteWhiteSpace(exit_confirm);

		if (exit_confirm == "y" || exit_confirm == "Y")
		{
			cout << "\n"
				<< setfill('-') << setw(4) << "" 
				<< " Exited program. Thank you for using! "
				<< setw(4) << "" << endl;
			return true;
		}
		else if (exit_confirm == "n" || exit_confirm == "N")
		{
			cout << "\n"
     		<< setfill('-') << setw(10) << "" 
     		<< " Continuing program... "
     		<< setw(10) << "" << endl;
			return false;
		}
		else
		{
			cout << "Invalid option. Enter (y/n): ";
		}
	} 
}

void Running_Program()
{
	vector<string> name_contacts, phone_contacts;
	string choice;
	bool shouldExit = false; // Variable to check if user wants to exit

	do
	{
		displayChoose(); // Display choice menu
		do // Input selection
    	{
			getline(cin, choice);
        	deleteWhiteSpace(choice);

        	for (int i = 0; i < choice.length(); i++)
        	{
            		if (!isdigit(choice[i]))
            		{
            	    	cout << "Enter a number from 1 to 6. Please choose again!" << "\n";
            	    choice.clear();
					displayChoose();
            	    break;
        	    } 
        	}
    } while (choice.empty());

		switch (stoi(choice))
		{
		case 1:
			displayContacts(name_contacts, phone_contacts); // Display all contacts
			break;
		case 2:
			addContacts(name_contacts, phone_contacts); // Add contact
			break;
		case 3:
			lookforContacts(name_contacts, phone_contacts); // Search for contact
			break;
		case 4:
			sortContacts(name_contacts, phone_contacts); // Sort contacts
			break;
		case 5:
			deleteContacts(name_contacts, phone_contacts); // Delete contact
			break;
		case 6:
			shouldExit = exitProgram(); // Exit
			break;
		default:
			cout << "Choose a number from 1 to 6. Please try again!" << endl; // Invalid choice
			break;
		}
	} while (!shouldExit);
}
