#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class file{
	public:
		ifstream fIn;
		ofstream fOut;

		file();
		~file();
};

file::file(){
	fIn.open("C:\\bledne.txt");
	fOut.open("C:\\wynik3.txt");
}

file::~file(){
	fIn.close();
	fOut.close();
}

class ciagi{
	
	private:
		file f;
		vector <int> ciag;
		vector <int> r;
		vector <int> wrong;
		
	public:
		void load();
		void write();

};

void ciagi::load(){
	int lenght, num, correct_r;
	
	while(!f.fIn.eof()){
		
		f.fIn>>lenght;
		for(int i = 0;i<lenght;i++){
			f.fIn>>num;
			ciag.push_back(num);
			
		}
		for(int i = 0;i<4;i++){
			r.push_back(ciag[i+1]-ciag[i]);
		}
		if(r[0]==r[1]){
			correct_r = r[0];
		} else if(r[1]==r[2]){
			correct_r = r[1];
		} else if(r[2]==r[3]){
			correct_r = r[2];
		} else if(r[3]==r[0]){
			correct_r = r[3];
		}

		for(int i = 0;i<lenght;i++){
			if(ciag[i] + correct_r != ciag[i+1]){
				wrong.push_back(ciag[i+1]);
				break;
			}
		}
		ciag.clear();
		r.clear();
	}
	
	
}

void ciagi::write(){
	for(int i = 0;i<wrong.size()-1;i++){
		f.fOut<<i+1<<": "<<wrong[i]<<endl;
	}
}

int main(int argc, char** argv) {
	ciagi c;
	c.load();
	c.write();
	
	return 0;
}
