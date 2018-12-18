#include <iostream>
#include <vector>


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

int solution1217_Company_001(int );

int solution1217_Company_004(vector<int> , vector<int> );
int main(void)
{
	/*int hap = GetSigma(100000);
	int hap2 = GetSigma(99999);

	cout << hap << endl;
	vector<string> test1;
	test1.push_back("mislav");
	test1.push_back("stanko");
	test1.push_back("mislav");
	test1.push_back("ana");
	
	

	vector<string> test2;
	test2.push_back("stanko");
	test2.push_back("ana");
	test2.push_back("mislav");
	
	
	

	
	string value = solution(test1,test2);*/

	//vector<int> temp;
	//temp.push_back(1);
	//temp.push_back(3);
	//temp.push_back(2);
	//temp.push_back(4);
	//temp.push_back(2);
	//temp.push_back(1);
	//temp.push_back(2);
	//temp.push_back(3);
	//temp.push_back(4);
	//temp.push_back(5);


	//solution1211(temp);


	//vector<int>temp1212;
	//temp1212.push_back(1);
	//temp1212.push_back(5);
	//temp1212.push_back(2);
	//temp1212.push_back(6);
	//temp1212.push_back(3);
	//temp1212.push_back(7);
	//temp1212.push_back(4);
	//vector<vector<int>> temp2_1212;
	//
	//vector<int> temptemp;
	//temptemp.push_back(2);
	//temptemp.push_back(5);
	//temptemp.push_back(3);
	//temp2_1212.push_back(temptemp);

	//vector<int> temptemp2;
	//temptemp2.push_back(4);
	//temptemp2.push_back(4);
	//temptemp2.push_back(1);
	//temp2_1212.push_back(temptemp2);

	//vector<int> temptemp3;
	//temptemp3.push_back(1);
	//temptemp3.push_back(7);
	//temptemp3.push_back(3);
	//temp2_1212.push_back(temptemp3);

	////solution1212(temp1212, temp2_1212);

	//vector<int> temp1212_3;
	//temp1212_3.push_back(1);
	//temp1212_3.push_back(1);
	//temp1212_3.push_back(3);
	//temp1212_3.push_back(3);
	//temp1212_3.push_back(0);
	//temp1212_3.push_back(1);
	//temp1212_3.push_back(1);
	//solution1212_3(temp1212_3);
	


	//vector<int> temp1217_1;
	//temp1217_1.push_back(5);
	//temp1217_1.push_back(9);
	//temp1217_1.push_back(7);
	//temp1217_1.push_back(10);
	//solution1217_1(temp1217_1,5);

	//solution1217_2(-100, 3);

	//vector<string> temp1217_3;
	//temp1217_3.push_back("sun");
	//temp1217_3.push_back("bed");
	//temp1217_3.push_back("car");
	//
	//solution1217_3(temp1217_3,1);


	//solution1217_Company_001(123);

	vector<int>temp1;
	temp1.push_back(5);
	temp1.push_back(1);
	temp1.push_back(3);
	temp1.push_back(7);

	vector<int>temp2;
	temp2.push_back(2);
	temp2.push_back(2);
	temp2.push_back(6);
	temp2.push_back(8);

	solution1217_Company_004(temp1, temp2);

	return 0;
}

long GetDecimal(long input)
{
	
	vector<bool> vec(input+1, true);
	vec[0] = false;
	vec[1] = false;
	for (size_t i = 2; i*i <= input; i++)
	{
		if (vec[i])
		{
			for (size_t j = i*i; j <= input; j+=i)
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
	//������ ��� ȿ���� �����
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

//���ǰ��
vector<int> solution1211(vector<int> answers) {
	vector<int> answer;
	// 0���϶� ó�� �ʿ�, 
	// ���3�� �� �ٽ� Ȯ�� �ʿ�

	int maxproblem = 10000;
	int answersMaxLenght = answers.size();


	int case1[] = { 1, 2, 3, 4, 5 };
	int case2[] = { 2, 1, 2, 3, 2, 4, 2, 5, };
	int case3[] = { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 };

	int case1maxlenght = sizeof(case1) / sizeof(case1[0]);
	int case2maxlenght = sizeof(case2) / sizeof(case2[0]);
	int case3maxlenght = sizeof(case3) / sizeof(case3[0]);

	vector<int> casePassCount(3,0);
	
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

	for (size_t i = 0; i < casePassCount.size()-1; i++)
	{
		for (size_t j = i+1; j < casePassCount.size(); j++)
		{
			if(casePassCount[i] < casePassCount[j])
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



//K��° ��
vector<int> solution1212(vector<int> array, vector<vector<int>> commands) {
	vector<int> answer;

	for (size_t i = 0; i < commands.size(); i++)
	{		
		int startindex = commands[i][0] - 1;
		int indexlenght = commands[i][1] - startindex;
		vector<int> tempvec;
		for (size_t j = 0; j < indexlenght; j++)
		{
			tempvec.push_back(array[startindex+j]);
		}

		for (size_t k = 0; k < tempvec.size()-1; k++)
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
		answer = s.substr(div-1, 2);
	}
	else
	{
		answer = s.substr(div,1);
	}

	return answer;
}

vector<int> solution1212_3(vector<int> arr)
{
	vector<int> answer;

	// [����] ��ư�� ������ ��� ���� �� �� �ֽ��ϴ�.
	cout << "Hello Cpp" << endl;
	
	int temp= -1; 
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

//������ �������� ���� �迭
vector<int> solution1217_1(vector<int> arr, int divisor) {
	vector<int> answer;

	for (size_t i = 0; i < arr.size(); i++)
	{

		if (arr[i]%divisor == 0)
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
		for (size_t i = 0; i < answer.size()-1; i++)
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

//�� ���� ������ ��
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

//���ڿ� �� ������� �����ϱ�
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
			tempvectorindex.push_back(tempvectorchar.size()-1);

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
		for (size_t j = 0; j < tempvector[i].size()-1; j++)
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

	for (size_t i = 0; i < tempvectorchar.size()-1; i++)
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

    // [����] ��ư�� ������ ��� ���� �� �� �ֽ��ϴ�.
    cout << "Hello Cpp" << endl;

    return answer;
}

//ȸ�� �ڵ��׽�Ʈ
int solution1217_Company_001(int n)
{
	int answer = 0;
	int maxvalue = 100000000;
	// [����] ��ư�� ������ ��� ���� �� �� �ֽ��ϴ�.
	cout << "Hello Cpp" << endl;

	for (size_t i = maxvalue; i > 0; i/=10)
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