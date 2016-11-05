#ifndef _STRING_H_
#define _STRING_H_

#include "window.h"

// you have to put your version in the cpp file
class String
{
public:
	String();
	String(char* a_str);														// e.g. String thisStr("Hello World");
	String(String& a_other);													// e.g. String otherStr("Hi There"); String thisStr(otherString);
	~String();

	void ReadFromConsole();														// allows input to a String class
	void WriteToConsole();														// allows string to be placed in console
	int length();														// The ability to query the string�s length, returning an integer
	char characterAt(int index);										// The ability to access a character at a certain index within the string class
	bool equalTo(String& a_str);										// The ability to compare if the string is the same as another string class
	void append(char* a_string);												// The ability to append one string to another
	void prepend(char* a_string);												// The ability to prepend one string to another
	char* cStr();																// The ability to return the string as a basic constant C-style string (const char*)																			// The ability to return the string as a basic constant C-style string (const char*)
	void toLower();															// The ability to convert the string to a duplicate containing all lowercase letters
	void toUpper();															// The ability to convert the string to a duplicate containing all uppercase letters
	int find(String a_FindString);											// The ability to find a sub-string within the string class
	int find(int a_Index, String a_FindString);								// The ability to find a sub-string within the string class, starting from a certain index within the string
	void replace(String a_FindString, char* a_ReplaceString);					// The ability to replace a sub-string found within the string with a different sub-string
	void setString(char* a_string);											// The ability to set the string to an input C-style string
private:
	char* m_str;
	int	m_capacity;
	int	m_size;
	int GetcStrLen(char a_string[]);
	void SetCapacity(char a_string[]);
	int FindSubString(int a_start, String& a_str);

};

#endif
