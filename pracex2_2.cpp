#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

void sort(float x[], int N){
	for(int i = 1; i < N; i++){
		for(int j = i; j > 0; j--){
			if(x[j] > x[j-1]){
				float temp = x[j];
				x[j] = x[j-1];
				x[j-1] = temp;
			}else{
				break;
			} 
		}
	}
}

int main(){
	//Write your code here
	float score[20] = {};
	string s;
	int count = 0;
	ifstream source;
	ofstream of;
	source.open("score3.txt");
	of.open("result.txt");
	while(getline(source,s)){
		score[count] = atof(s.c_str());
		count++;
	}
	sort(score,20);
	count = 1;
	for(int i = 0 ; i < 20 ; i++){
		if(score[i] == score[i-1]){
			of << count+1 << ":";
		}else{
			of << i+1 << ":";
			count = i;
		}
		of << score[i] << endl;
	}
	
	return 0;
}

