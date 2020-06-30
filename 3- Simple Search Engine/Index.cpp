/*
	
	@author: 152120151005- Yusuf Furkan Yucesoy

*/
#include "Index.h"
#include <map> 
#include <iostream>
#include <fstream>
#include <sstream> 
#include <set>

struct index_struct {
	string fileName;
	int lineNumber;
};
map<string, vector<index_struct>> index; // word -> [file+lineNumber]

vector<string> indexFiles; // word -> [file+lineNumber]
string to_lower(string str) {
	string ret = "";
	for (char c : str) {
		ret += ::tolower(c);
	}
	return ret;
}
///-------------------------------------------------------
/// Given a list of file names, read each file line by line
/// and create an index.
///
void CreateIndex(vector<string>& files) {   
	for (int i = 0; i < files.size(); i++) {
		string fileName = files.at(i);
		indexFiles.push_back(fileName);
		string word;
		ifstream file;
		file.open(fileName);

		std::string line;
		int lineNumber = 1;
		while (std::getline(file, line)) {
			vector<string> wordVector;
			string word = "";
			for (char x : line) {
			
				if (isalpha(x) == false) {
					if(word.size()>=3){
						wordVector.push_back(word); 
						word = "";
					}
					else {
						word = "";
					}
					
				}
				else {
					word = word + x;
					
				}
			}
			if (!word.empty() && word.size() >= 3) {
				wordVector.push_back(word);
			}

			for (string w : wordVector) {
				w = to_lower(w);
				index_struct is;
				is.fileName = fileName;
				is.lineNumber = lineNumber;
				vector<index_struct> isVector;
				map<string, vector<index_struct>>::iterator it = index.find(w);
				if (it != index.end()) {
					isVector = it->second;
					index.erase(w);
				}
				isVector.push_back(is);
				index.insert(make_pair(w, isVector));
			}
			lineNumber++;
		}
	}
} // end-CreateIndex

///----------------------------------------------
/// Given a list of keywords, searches the index 
/// and prints the name of all document that contain ALL keywords
/// Also print the lines where any of the keywords exists in the document
///
string gotoline(std::ifstream& infile, unsigned int num) {
	string st;
	infile.seekg(ios::beg);
	for (int n = 0; n < num - 1; ++n) {
		infile.ignore(std::numeric_limits<streamsize>::max(), '\n');
	}
	getline(infile, st);
	return st;
}
void Search(vector<string>& keywords) {
	for (string indexFile : indexFiles) {
		bool allFound = true;
		set<int> lines;
		for (string keyword : keywords) {
			keyword = to_lower(keyword);
			map<string, vector<index_struct>>::iterator it = index.find(keyword);
			if (it == index.end()) {
				break;
			}
			vector<index_struct> fileLineVector = it->second;
			bool found = false;
			for (index_struct is : fileLineVector) {
				if (indexFile.compare(is.fileName) == 0) {
					found = true;
					lines.insert(is.lineNumber);
				}
			}
			if (found == false) {
				allFound = false;
				break;
			}
		}
		
		ifstream myfile;
		myfile.open(indexFile);
		

		if (allFound) {
			cout << indexFile << endl;
			for (int line : lines) {
				cout<<"\tLine "<<line<<":"<< gotoline(myfile, line)<<endl;
			}
		}
	}
	
} // end-Search