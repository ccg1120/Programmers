#include <iostream>
#include <vector>
#include <string>

using namespace std;




long GetDecimal(long );
int GetSigma(int );
int GetkeyByValue(vector<char> , char );
vector<int> solution1211(vector<int>);
string solution(vector<string> , vector<string> );
int solution1210(int , int );

vector<int> solution1212(vector<int> , vector<vector<int>> );
vector<int> solution1212_3(vector<int>);


vector<int> solution1217_1(vector<int>, int);
long long solution1217_2(int , int );
vector<string> solution1217_3(vector<string> , int );

bool solution1218_1(string );
string solution1218_2(string s);
bool solution1218_3(string s);
string solution1218_4(vector<string> seoul);

int solution1217_Company_001(int );
int solution1217_Company_004(vector<int> , vector<int> );

string solution_1227_1(string s, int n);
int main(void)
{

	//solution1218_1("pPoooyY");

	//solution1218_2("AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA");

	//solution1218_3("012345");

	/*vector<string> kk;
	kk.push_back("Jane");
	kk.push_back("Kim");
	solution1218_4(kk);*/

	
	solution_1227_1(" ZzZz",25);

	return 0;
}

#pragma region Solve

long GetDecimal(long input)
{

	vector<bool> vec(input + 1, true);
	vec[0] = false;
	vec[1] = false;
	for (size_t i = 2; i*i <= input; i++)
	{
		if (vec[i])
		{
			for (size_t j = i * i; j <= input; j += i)
			{
				vec[j] = false;

			}
		}
	}

	long answer = 0;
	for (size_t i = 0; i < input + 1; i++)
	{
		if (vec[i])
		{
			answer += i;
		}
	}

	return answer;
}

string solution(vector<string> participant, vector<string> completion) {
	string answer = "";

	vector<char> key;
	vector<vector<int>> value;
	vector<char> key2;
	vector<vector<int>> value2;

	if (participant.size() > 100000)
	{
		return answer;
	}
	if (participant.size() == 1)
	{
		return answer;
	}

	for (size_t i = 0; i < participant.size(); i++)
	{
		int keyindex = GetkeyByValue(key, participant[i].front());
		if (keyindex == -1)
		{
			key.push_back(participant[i].front());
			vector<int> count;
			count.push_back(i);
			value.push_back(count);
		}
		else
		{
			value[keyindex].push_back(i);
		}
	}

	for (size_t i = 0; i < completion.size(); i++)
	{
		int keyindex = GetkeyByValue(key2, completion[i].front());
		if (keyindex == -1)
		{
			key2.push_back(completion[i].front());
			vector<int> count;
			count.push_back(i);
			value2.push_back(count);
		}
		else
		{
			value2[keyindex].push_back(i);
		}
	}

	int findvalueindex = -1;
	int value2mapindex = -1;

	for (size_t i = 0; i < key.size(); i++)
	{
		int temp2 = GetkeyByValue(key2, key[i]);
		findvalueindex = i;
		if (temp2 == -1)
		{
			return participant[value[findvalueindex][0]];
		}
		else if (value[i].size() != value2[temp2].size())
		{
			value2mapindex = temp2;
			break;
		}
	}


	vector<bool> checerbool(value2[value2mapindex].size(), true);

	for (size_t i = 0; i < value[findvalueindex].size(); i++)
	{
		int valueindex = value[findvalueindex][i];
		bool check = true;

		for (size_t j = 0; j < value2[value2mapindex].size(); j++)
		{
			int valueindex2 = value2[value2mapindex][j];
			if (checerbool[j])
			{
				if (completion[valueindex2] == participant[valueindex])
				{
					check = false;
					checerbool[j] = false;
					break;
				}
			}
		}
		if (check)
		{
			return participant[valueindex];
		}

	}
	return answer;
}

string solution2(vector<string> participant, vector<string> completion)
{
	//문제는 통과 효율성 미통과
	string answer = "";
	if (participant.size() > 100000)
	{
		return answer;
	}
	if (participant.size() == 1)
	{
		return answer;
	}
	int sizei = participant.size();
	int sizej = completion.size();


	vector<bool> checker(sizej, true);
	int hap = 0;
	int comhap = 0;
	for (size_t i = 0; i < sizei; i++)
	{
		for (size_t j = 0; j < sizej; j++)
		{
			if (checker[j])
			{
				if (participant[i].front() == completion[j].front())
				{
					checker[j] = false;
					comhap += i;
					break;
				}
			}
		}
		hap = hap + i;
	}

	answer = participant[hap - comhap];
	return answer;
}


int GetSigma(int num)
{
	int hap = 0;
	for (size_t i = 0; i < num; i++)
	{
		hap = hap + i;
	}
	return hap;
}


int GetkeyByValue(vector<char> key, char input)
{
	int result = -1;
	for (size_t i = 0; i < key.size(); i++)
	{
		if (key[i] == input)
		{
			result = i;
			break;
		}
	}
	return result;
}

int solution1210(int N, int number) {
	int answer = 0;

	return answer;
}

//모의고사
vector<int> solution1211(vector<int> answers) {
	vector<int> answer;
	// 0점일때 처리 필요, 
	// 통과3개 됨 다시 확인 필요

	int maxproblem = 10000;
	int answersMaxLenght = answers.size();


	int case1[] = { 1, 2, 3, 4, 5 };
	int case2[] = { 2, 1, 2, 3, 2, 4, 2, 5, };
	int case3[] = { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 };

	int case1maxlenght = sizeof(case1) / sizeof(case1[0]);
	int case2maxlenght = sizeof(case2) / sizeof(case2[0]);
	int case3maxlenght = sizeof(case3) / sizeof(case3[0]);

	vector<int> casePassCount(3, 0);

	for (size_t i = 0; i < answersMaxLenght; i++)
	{
		//int answersindex = (i % answersMaxLenght);
		int case1index = (i % case1maxlenght);
		int case2index = (i % case2maxlenght);
		int case3index = (i % case3maxlenght);

		if (case1[case1index] == answers[i])
		{
			casePassCount[0]++;
		}
		if (case2[case2index] == answers[i])
		{
			casePassCount[1]++;
		}
		if (case3[case3index] == answers[i])
		{
			casePassCount[2]++;
		}
	}
	vector<int> tempanswer;
	tempanswer.push_back(1);
	tempanswer.push_back(2);
	tempanswer.push_back(3);

	for (size_t i = 0; i < casePassCount.size() - 1; i++)
	{
		for (size_t j = i + 1; j < casePassCount.size(); j++)
		{
			if (casePassCount[i] < casePassCount[j])
			{
				int temp = casePassCount[j];
				casePassCount[i] = casePassCount[j];
				casePassCount[j] = temp;

				int temp2 = tempanswer[j];
				tempanswer[i] = tempanswer[j];
				tempanswer[j] = temp2;
			}
		}
	}

	for (size_t i = 0; i < tempanswer.size(); i++)
	{
		if (casePassCount[i] > 0)
		{
			answer.push_back(tempanswer[i]);
		}
	}

	return answer;
}



//K번째 수
vector<int> solution1212(vector<int> array, vector<vector<int>> commands) {
	vector<int> answer;

	for (size_t i = 0; i < commands.size(); i++)
	{
		int startindex = commands[i][0] - 1;
		int indexlenght = commands[i][1] - startindex;
		vector<int> tempvec;
		for (size_t j = 0; j < indexlenght; j++)
		{
			tempvec.push_back(array[startindex + j]);
		}

		for (size_t k = 0; k < tempvec.size() - 1; k++)
		{
			for (size_t kk = k + 1; kk < tempvec.size(); kk++)
			{
				if (tempvec[k] > tempvec[kk])
				{
					int temp = tempvec[k];
					tempvec[k] = tempvec[kk];
					tempvec[kk] = temp;
				}
			}
		}
		answer.push_back(tempvec[(commands[i][2] - 1)]);
	}


	return answer;
}

string solution1212_2(string s) {
	string answer = "";

	int lenght = s.length();
	int div = lenght / 2;

	if (lenght % 2 == 0)
	{
		answer = s.substr(div - 1, 2);
	}
	else
	{
		answer = s.substr(div, 1);
	}

	return answer;
}

vector<int> solution1212_3(vector<int> arr)
{
	vector<int> answer;

	// [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
	cout << "Hello Cpp" << endl;

	int temp = -1;
	for (size_t i = 0; i < arr.size(); i++)
	{
		if (arr[i] != temp)
		{
			answer.push_back(arr[i]);
			temp = arr[i];
		}
	}
	return answer;
}

//나누어 떨어지는 숫자 배열
vector<int> solution1217_1(vector<int> arr, int divisor) {
	vector<int> answer;

	for (size_t i = 0; i < arr.size(); i++)
	{

		if (arr[i] % divisor == 0)
		{
			answer.push_back(arr[i]);
		}
	}

	if (answer.size() == 0)
	{
		answer.push_back(-1);
	}
	else
	{
		for (size_t i = 0; i < answer.size() - 1; i++)
		{
			for (size_t j = i; j < answer.size(); j++)
			{
				if (answer[i] > answer[j])
				{
					int temp = answer[j];
					answer[j] = answer[i];
					answer[i] = temp;
				}
			}
		}
	}
	return answer;
}

//두 정수 사이의 합
long long solution1217_2(int a, int b) {
	long long answer = 0;
	if (a == b)
	{
		answer = a;
		return answer;
	}
	int max = a > b ? a : b;
	std::cout << max;
	int min = a < b ? a : b;
	std::cout << min;

	for (int i = min; i <= max; i++)
	{
		answer += i;
	}
	return answer;
}

//문자열 내 마음대로 정렬하기
vector<string> solution1217_3(vector<string> strings, int n) {
	vector<string> answer;
	int stringindex = n;

	vector<char> tempvectorchar;
	vector<int> tempvectorindex;
	vector<vector<string>> tempvector;

	for (size_t i = 0; i < strings.size(); i++)
	{
		int index = -1;
		for (size_t j = 0; j < tempvectorchar.size(); j++)
		{
			if (strings[i].at(n) == tempvectorchar[j])
			{
				index = j;
				break;
			}
		}

		if (index == -1)
		{
			tempvectorchar.push_back(strings[i].at(n));
			tempvectorindex.push_back(tempvectorchar.size() - 1);

			vector<string> temp;
			temp.push_back(strings[i]);
			tempvector.push_back(temp);
		}
		else
		{
			tempvector[index].push_back(strings[i]);
		}
	}

	for (size_t i = 0; i < tempvector.size(); i++)
	{
		for (size_t j = 0; j < tempvector[i].size() - 1; j++)
		{
			for (size_t k = j; k < tempvector[i].size(); k++)
			{
				if (tempvector[i][j] > tempvector[i][k])
				{
					string temp = tempvector[i][k];
					tempvector[i][k] = tempvector[i][j];
					tempvector[i][j] = temp;
				}
			}
		}
	}

	for (size_t i = 0; i < tempvectorchar.size() - 1; i++)
	{
		for (size_t j = i; j < tempvectorchar.size(); j++)
		{
			if (tempvectorchar[i] > tempvectorchar[j])
			{
				char tempchar = tempvectorchar[j];
				tempvectorchar[j] = tempvectorchar[i];
				tempvectorchar[i] = tempchar;

				int tempindex = tempvectorindex[j];
				tempvectorindex[j] = tempvectorindex[i];
				tempvectorindex[i] = tempindex;
			}
		}
	}

	for (size_t i = 0; i < tempvectorindex.size(); i++)
	{
		for (size_t k = 0; k < tempvector[tempvectorindex[i]].size(); k++)
		{
			answer.push_back(tempvector[tempvectorindex[i]][k]);
		}
	}
	return answer;
}

bool solution1217_4(string s)
{
	bool answer = true;

	// [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
	cout << "Hello Cpp" << endl;

	return answer;
}

//문자열 내 p와 y의 개수
bool solution1218_1(string s)
{
	bool answer = true;
	size_t slenght = s.length();

	int countp = 0;
	int county = 0;

	cout << 'p' << endl;
	cout << 'P' << endl;
	for (size_t i = 0; i < slenght; i++)
	{
		if (s.at(i) == 'p' || s.at(i) == 'P')
		{
			countp++;
		}
		else if (s.at(i) == 'y' || s.at(i) == 'Y')
		{
			county++;
		}
	}
	if (countp != county)
	{
		answer = false;
	}

	// [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
	cout << "Hello Cpp" << endl;

	return answer;
}

//문자열 내림차순으로 배치하기
string solution1218_2(string s) {
	string answer = "";

	vector<char> schar;
	vector<char> bchar;

	//65~90 대문자

	for (size_t i = 0; i < s.length(); i++)
	{
		if (s[i] <= 90 && s[i] >= 65)
		{
			bchar.push_back(s[i]);
		}
		else
		{
			schar.push_back(s[i]);
		}
	}

	if (schar.size() > 0)
	{
		for (int i = 0; i < schar.size() - 1; i++)
		{
			for (int j = i; j < schar.size(); j++)
			{
				if (schar[i] < schar[j])
				{
					char temp = schar[i];
					schar[i] = schar[j];
					schar[j] = temp;
				}
			}
		}
		for (size_t i = 0; i < schar.size(); i++)
		{
			answer += schar[i];
		}
	}

	if (bchar.size() > 0)
	{
		for (int i = 0; i < bchar.size() - 1; i++)
		{
			for (int j = i; j < bchar.size(); j++)
			{
				if (bchar[i] < bchar[j])
				{
					char temp = bchar[i];
					bchar[i] = bchar[j];
					bchar[j] = temp;
				}
			}
		}
		for (size_t i = 0; i < bchar.size(); i++)
		{
			answer += bchar[i];
		}
	}

	return answer;
}

//문자열 다루기 기본
bool solution1218_3(string s) {
	bool answer = true;
	if (s.length() != 4 && s.length() != 6)
	{
		answer = false;
		return answer;
	}

	for (size_t i = 0; i < s.length(); i++)
	{
		if (s[i] < '1')
		{
			answer = false;
			break;
		}
		else if (s[i] > '9')
		{
			answer = false;
			break;
		}
	}

	return answer;
}

//서울에서 김서방 찾기
string solution1218_4(vector<string> seoul) {
	string answer = "김서방은 ";
	int num = 0;
	string answer2 = "에 있다.";

	for (size_t i = 0; i < seoul.size(); i++)
	{
		if (seoul[i].at(0) == 'K')
		{
			if (seoul[i] == "Kim")
			{
				num = i;
				break;
			}
		}
	}

	answer += to_string(num);
	answer += answer2;

	return answer;
}

//수박수박수박수박수박수?
string solution1219_1(int n) {
	string answer = "";
	string b = "수";
	string a = "박";
	for (int i = 1; i <= n; i++)
	{

		if ((i % 2) == 0)
		{
			answer += a;
		}
		else
		{
			answer += b;

		}
	}

	return answer;
}

//문자열을 정수로 바꾸기
int solution1219_2(string s) {
	int answer = 0;
	bool signal = true;
	//1의 자리
	int length = s.length();
	int add = 0;
	if (s.at(0) == '-')
	{
		signal = false;
		add++;
	}
	else if (s.at(0) == '+')
	{
		add++;
	}
	int maxvalue = 10 * length;
	for (size_t i = 0 + add; i < length; i++)
	{
		int num = s[i] - '0';
		//answer += (num*)
	}

	//to int는 식상하니까 다르게 



	return answer;
}


//회사 코딩테스트
int solution1217_Company_001(int n)
{
	int answer = 0;
	int maxvalue = 100000000;
	// [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
	cout << "Hello Cpp" << endl;

	for (size_t i = maxvalue; i > 0; i /= 10)
	{
		int div = (int)(n / i);
		int val = i * div;
		answer += div;
		n = n - val;
	}

	return answer;
}

int solution1217_Company_002(vector<vector<int> > maps)
{
	int answer = 0;
	int startpoint = 0;

	int mapwidth = maps[0].size();
	int mapheight = maps.size();


	return answer;
}

int solution1217_Company_004(vector<int> A, vector<int> B) {
	int answer = 0;

	for (size_t i = 0; i < B.size(); i++)
	{
		int score = 0;
		for (size_t k = 0; k < A.size(); k++)
		{
			if (B[i] > A[k])
			{
				score++;
			}
		}
	}

	return answer;
}


//시저 암호
string solution_1227_1(string s, int n) {
	string answer = "";

	cout << s << endl;
	for (size_t i = 0; i < s.length(); i++)
	{
		int temp = s.at(i) + n;
		if (s.at(i) == ' ')
		{
			temp = ' ';
		}
		else if (s.at(i) <= 'Z')
		{
			if (temp > 'Z')
			{
				temp = ('A' - 1) + (temp - 'Z');
			}
		}
		else if (s.at(i) <= 'z')
		{
			if (temp > 'z')
			{
				temp = ('a' - 1) + (temp - 'z');
			}
		}
		answer += (char)temp;
	}

	cout << answer << endl;

	//공백 32
	//A ~ 65 Z 90
	//A ~ 97 Z 122


	return answer;
}

vector<int> solution_1230_1(long long n) {
	vector<int> answer;

	string temp = to_string(n);

	int lenght = temp.length();

	//size_t -도 안됨
	for (int i = lenght - 1; i >= 0; i--)
	{
		int intresult = (temp.at(i) - '1') + 1;
		answer.push_back(intresult);
	}


	/*while (n > 0) {
		answer.push_back(n % 10);
		n /= 10;
	}*/
	return answer;
}

//평균 구하기
double solution_0102(vector<int> arr) {
	double answer = 0;

	int len = arr.size();
	int hap = 0;

	for (size_t i = 0; i < len; i++)
	{
		hap += arr[i];
	}
	answer = hap / (double)len;
	return answer;
}

//핸드폰 번호 가리기
string solution_0001(string phone_number) {
	string answer = "";

	int max = 4;

	int lenght = phone_number.length();
	for (size_t i = 0; i < lenght - 4; i++)
	{
		phone_number.at(i) = '*';
	}
	answer = phone_number;
	return answer;
}
#pragma endregion

//자릿수 더하기
int solution_0108(int n)
{
	int answer = 0;

	// [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
	cout << "Hello Cpp" << endl;
	int temp = n;

	while (temp != 0 )
	{
		answer += temp % 10;
		temp = temp / 10;
	}

	return answer;
}