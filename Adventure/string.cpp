//--------------------------------------------------------------------------------//
//																				  //
//																				  //
// this is where to put your string class										  //
//																				  //
//																				  //
//--------------------------------------------------------------------------------//

#include "string.h"
#include "window.h"
#include <iostream>
#include <cctype>
#include <iomanip>

// read a line from the console, ending with ENTER, this is needed for the adventure game
void String::ReadFromConsole()
{
	char a_str[50];

	//std::cin.getline(a_str, 50);
	//limet the amount of characters read from the console to 40
	std::cin >> std::setw(40) >> a_str;

	//Delete m_string if it has been previously allocated
	if (m_str != nullptr) {
		delete[] m_str;
	}

	m_capacity = 0;
	m_size = 0;

	//Count the new string and resize capacity for it
	for (int i = 0; a_str[i] != '\0'; i++) {
		m_size++;
	}
	//set capacity
	m_capacity = m_size + 1;

	//Allocate new memory for string
	m_str = new char[m_capacity];

	//Copy the new string into char array
	for (int i = 0; a_str[i] != '\0'; i++) {
		m_str[i] = a_str[i];
	}

	//Set the null terminator
	m_str[m_size] = '\0';

	toLower();
}

// write to the console, used by room
void String::WriteToConsole()
{
	std::cout << m_str << std::endl;
}

// constructor default
String::String()
{
	m_str = nullptr;
	m_capacity = 0;
	m_size = 0;
}

// constructor creat a char array from a char array
String::String(char * a_str) {
	//set m_Str to NULL
	m_str = nullptr;
	//set m_str to a_str
	setString(a_str);
}
//copy constructor
String::String(String &a_other) {
	//set m_size4 and m_capacity
	this->m_size = a_other.m_size;
	this->m_capacity = a_other.m_capacity;

	//check if a_other.m_str is not null
	if (a_other.m_str != nullptr) {
		//creat m_str
		this->m_str = new char[this->m_capacity];
		//set m_str to a_other.m_str
		for (int i = 0; i <= m_size; i++)
			this->m_str[i] = a_other.m_str[i];

		//set end to '\0'
		//this->m_str[m_size] = '\0';
	}
	else
		//if the a_other.m_str is null set m_str to null
		this->m_str = nullptr;
}


// decontructor
String::~String()
{
	if (m_str != nullptr) {
		delete[] m_str;
	}
}

// put the remainder of your string functions here ... if they are named in a defferent way then there will be some repair needed
// needed for compilation, please replace
// ===========================================================================
//char * String::cStr()
//{
//	return nullptr;
//}
// ===========================================================================

int String::GetcStrLen(char a_str[]) {
	for (int i = 0;; i++) {
		if (a_str[i] == '\0')
			return i;
	}
	return 0;
}
void String::SetCapacity(char a_string[]) {
	//get the size of a_string
	int a_strSize = GetcStrLen(a_string);
	//checks if the array has  the free space to store the 2 strings
	if (a_strSize + m_size >= m_capacity)
		//resets the size of the array
		m_capacity = m_size + a_strSize + 10;

	//sets the length of the str
	m_size = m_size + a_strSize;
}
int String::FindSubString(int a_start, String& a_str) {
	if (a_str.m_str == nullptr)
		return -1;

	if (a_start >= m_size)
		return -1;

	if (a_start < 0)
		return -1;

	//loop through the sting starting from a_start
	for (int i = a_start; i < m_size; i++) {
		//check if m_star index i is = to the start of a_str
		if (m_str[i] == a_str.m_str[0]) {
			//to keep going from where i was
			int k = i;
			for (int j = 0; j <= a_str.m_size; j++, k++) {
				//check if at the end of a_str
				if (a_str.m_str[j] == '\0')
					//return the start postion of the sub string
					return k - a_str.m_size;
				if (a_str.m_str[j] != m_str[k])
					break;
			}
		}
	}
	return -1;
}

int String::length() {
	return m_size;
}
char String::characterAt(int index) {
	return m_str[index];
}
bool String::equalTo(String & a_str) {
	//check if both strings are null
	if (m_str == nullptr && a_str.m_str == nullptr)
		return true;

	//check if onley 1 is null
	if (m_str == nullptr || a_str.m_str == nullptr)
		return false;

	if (m_size != a_str.length())
		return false;

	for (int i = 0; i < m_size; i++) {
		if (m_str[i] != a_str.characterAt(i))
			return false;
	}
	return true;
}
void String::append(char * a_string) {
	if (a_string == nullptr) {
		setString(a_string);
		return;
	}
	
	//gets the size the array needs to be
	SetCapacity(a_string);

	//makes a new temp array 
	char *tmp = new char[m_capacity];

	int i = 0;
	//add the first array to the temp str
	if (m_str != nullptr) {
		for (; ; i++) {
			if (m_str[i] == '\0')
				break;

			tmp[i] = m_str[i];
		}
	}
	//adds the 2 str to the temp str
	for (int j = 0; ; i++, j++) {
		if (a_string[j] == '\0')
			break;

		tmp[i] = a_string[j];
	}
	//set end to '\0'
	tmp[m_size] = '\0';
	if (m_str != nullptr)
		delete[] m_str;

	m_str = tmp;
}
void String::prepend(char * a_string) {
	if (a_string == nullptr)
		return;

	//gets the size the array needs to be
	SetCapacity(a_string);

	//makes a new temp array 
	char *tmp = new char[m_capacity];

	int i = 0;
	//add the first array to the temp str
	for (; ; i++) {
		if (a_string[i] == '\0')
			break;

		tmp[i] = a_string[i];
	}
	if (m_str != nullptr) {
		//adds the 2 str to the temp str
		for (int j = 0; ; i++, j++) {
			if (m_str[j] == '\0')
				break;

			tmp[i] = m_str[j];
		}
	}
	//set end to '\0'
	tmp[m_size] = '\0';
	if (m_str != nullptr)
		delete[] m_str;

	m_str = tmp;
}
char * String::cStr() {
	return m_str;
}
void String::toLower() {
	for (int i = 0; i < m_size; i++)
		m_str[i] = tolower(m_str[i]);
}
void String::toUpper() {
	for (int i = 0; i < m_size; i++)
		m_str[i] = toupper(m_str[i]);
}
int String::find(String a_FindString) {
	return FindSubString(0, a_FindString);
}
int String::find(int a_Index, String a_FindString) {
	return FindSubString(a_Index, a_FindString);
}
void String::replace(String a_FindString, char * a_ReplaceString) {
	//check if m_str a_FindString.m_str and a_ReplaceString == null if they do return
	if (m_str == nullptr || a_FindString.m_str == nullptr || a_ReplaceString == nullptr)
		return;

	//check if the string your searching for is biger then the string your searching in
	if (a_FindString.length() > m_size)
		return;

	int searchPos = 0;
	int replacesFound = 0;
	int replaceLength = GetcStrLen(a_ReplaceString);

	//finds how many strings to replace
	while (find(searchPos, a_FindString) != -1) {
		searchPos = find(searchPos, a_FindString) + a_FindString.length();
		replacesFound++;
	}

	//return if there are no words to replace
	if (replacesFound == 0)
		return;
	//find the new size of the array
	int tmpSize = ((m_size - a_FindString.length() * replacesFound) + replaceLength * replacesFound);
	//checks current array has enuf space
	if (tmpSize >= m_capacity) {
		// set the new capacity
		m_capacity = tmpSize + 10;
	}
	//a new temp char array to hold the new replaced string
	char* buffer = new char[m_capacity];
	//to loop through the new char array
	int newCount = 0;
	//to loop through the old char array
	int oldCount = 0;
	//resets the search pos to look from ther start agen
	searchPos = 0;
	//looks for the first place the find string shows 
	searchPos = find(searchPos, a_FindString);

	//loop thorough the array
	do {
		//check if its at the place to start replacing the string
		if (oldCount < searchPos) {
			buffer[newCount] = m_str[oldCount];
			oldCount++;
			newCount++;
		}
		else {
			//replace the old sub string witn the new string
			for (int i = 0; i < replaceLength; i++, newCount++)
				buffer[newCount] = a_ReplaceString[i];
			//set old count past the word you just replaced
			oldCount += a_FindString.length();
			//fing the next sub string to replae
			searchPos = find(searchPos + a_FindString.length(), a_FindString);
		}
	} while (find(searchPos, a_FindString) != -1);
	//copey the end of the string
	for (; newCount < tmpSize; newCount++, oldCount++)
		buffer[newCount] = m_str[oldCount];

	delete[] m_str;
	m_str = buffer;
	//set end to '\0'
	m_size = tmpSize;
	m_str[m_size] = '\0';
}
void String::setString(char* a_string) {
	if (a_string == nullptr)
		return;

	//find length of a_str
	for (int i = 0; ; i++) {
		if (a_string[i] == '\0') {
			m_size = i;
			break;
		}
	}

	//delets the str if it not = to null
	if (m_str != nullptr)
		delete[] m_str;

	//make a char array to hold a_str
	m_capacity = m_size + 10;
	m_str = new char[m_capacity];

	//set m_str to a_str
	for (int i = 0; i < m_size; i++)
		m_str[i] = a_string[i];

	//set end to '\0'
	m_str[m_size] = '\0';
}
