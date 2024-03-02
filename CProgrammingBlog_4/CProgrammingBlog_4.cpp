//#include <stdio.h>
//
//int main()
//{
//	int n = 10;
//	int* p = &n;
//	const int* cp = &n;
//
//	*p = 20;
//	//*cp = 30;
//	// 읽기 전용이라 수정 불가
//}

//#include <stdio.h>
//#include <string.h>
//
//int main()
//{
//	const char* s1 = "ABC";
//	char s2[20];
//
//	//s2 = s1;
//	//s1, s2는 주소
//	//주소를 주소에 넣어서 오류
//
//	s2[0] = s1[0];
//	s2[1] = s1[1];
//	s2[2] = s1[2];
//	s2[3] = s1[3];
//	printf("%s %s\n", s1, s2);
//
//	char s3[20];
//	strcpy_s(s3, strlen(s1) + 1, s1); // #include <string.h>
//	printf("%s %s\n", s1, s3);
//}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	bool run = true;
	char* dataArr[1000] = { 0 };
	int dataCount = 0;

	while (run)
	{
		char buf[500];
		printf("문자를 입력하세요(프로그램 종료는 \"exit\"입력) : ");
		gets_s(buf, 500);

		if (strcmp("exit", buf) == 0)
			run = false;
		else
		{
			char* data = (char*)malloc(strlen(buf) + 1);
			strcpy_s(data, strlen(buf) + 1, buf);
			dataArr[dataCount++] = data;
		}
	}

	for (int i = 0; i < dataCount; i++)
		printf("dataArr[%d] : %s\n", i, dataArr[i]);
	for (int i = 0; i < dataCount; i++)
		free(dataArr[i]);
}