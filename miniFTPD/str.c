#include "str.h"
#include "common.h"

void str_trim_crlf(char *str)	//去除\r\n
{
	char *p = &str[strlen(str) - 1];
	while(*p == '\r' || *p == '\n')
	{
		*p-- = '\0';
	}
}


void str_split(const char *str, char *left, char *right, char c)
{
	char *p = strchr(str, c);	//查找字符c所在的第一个位置
	if(p == NULL)	//未找到要查找的字符
	{
		strcpy(left, str);
	}
	else
	{
		strncpy(left,str,p-str);
		strcpy(right, p+1);
	}
}


int str_all_space(const char *str)	//判断是否全是空格
{	
	while(*str)
	{
		if(!isspace(*str))
			return 0;
		str++;
	}
	return 1;
}


void str_upper(char *str)	//将字符串转换为大写
{
	while(*str)
	{
		*str = toupper(*str);
		str++;
	}
}


long long str_to_longlong(const char *str)	//将字符串转为 long long
{
	//return atoll(str);
	long long result = 0;
	long long mult = 1;
	unsigned int len = strlen(str);
	int i;

	if(len > 15)
		return 0;

	for(i = len-1 ; i >= 0 ; i--)
	{
		char ch = str[i];
		long long val;
		if(ch < '0' || ch >'9')
			return 0;
		
		val = ch - '0';
		val *= mult;
		result += val;
		mult *= 10;
	}

	return result;
}


unsigned int str_octal_to_uint(const char *str)	//将八进制转为整数
{
	unsigned int result = 0;
	int seen_non_zero_digit = 0;

	while(*str)
	{
		int digit = *str;
		if(!isdigit(digit) || digit > '7')
			break;

		if(digit != '0')
			seen_non_zero_digit = 1;

		if(seen_non_zero_digit)
		{
			result = result << 3;
			result += (digit - '0');

		}
		str++;
	}
	return result;
}