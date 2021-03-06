#ifndef __BASE_64_H_
#define __BASE_64_H_
  

#include <string>  

using namespace std;  

class CBase64  
{  
private:  
	CBase64(void);  
public:  
	~CBase64(void);  

	static string Encode(const unsigned char* Data,int DataByte);  
	static string Decode(const char* Data,int DataByte,int& OutByte);  
};  

#endif
