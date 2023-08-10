#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> remplireMatrice( int lines, int rows);
vector<vector<int>> somme_Matrice(const vector<vector<int>>&matrice1, const vector<vector<int>>&matrice2);
void afficheMatrice(const vector<vector<int>>& matrice);

/*
 * */
int main(){
	vector<vector<int>>matrice1;
	vector<vector<int>>matrice2;
	vector<vector<int>>sommeMatrice;

	cout << "Entrez les éléments du premier matrice" << endl;
	matrice1 = remplireMatrice(3, 3);
	
	cout << endl;
	
	cout <<"Entrez les éléments du second matrice" << endl;
	matrice2 = remplireMatrice(3, 3);
	
	try{
		sommeMatrice = somme_Matrice(matrice1, matrice2);
		cout << "Somme des deux matrices" << endl;
		afficheMatrice(sommeMatrice);
	}catch(const exception& erreur){
		cout << "Erreur" << erreur.what()<<endl;
	}
	
	return 0;
}

/*
 * */
vector<vector<int>> remplireMatrice( int lines, int rows){
	vector<vector<int>>matrice;
	
	for(int i = 0; i < lines; i++){
		vector<int>tmp;
		for(int j = 0; j < rows; j++){
			int value;
			cout<<"lines("<<i+1<<") colonne("<<j+1<<") ";
			cin>>value;
			tmp.push_back(value);
		}
		matrice.push_back(tmp);
	}
	
	return matrice;
}

/*
 * */
vector<vector<int>> somme_Matrice(const vector<vector<int>>&matrice1, const vector<vector<int>>&matrice2){
	int rows = matrice1.size();
	int lines = matrice1[0].size();
	vector<vector<int>> sommeMatrice(rows, vector<int>(lines));
	
	if(rows != matrice2.size() || lines != matrice2[0].size()){
		throw runtime_error("Les dimesions des matrices ne correspondent pas.");
	}
	
	for(int i = 0; i < rows; i++){
		for(int j = 0; j < lines; j++){
			sommeMatrice[i][j] = matrice1[i][j] + matrice2[i][j];
		}
	}
	
	return sommeMatrice;
}

/*
 * */
void afficheMatrice(const vector<vector<int>>& matrice){
	for(const auto& num : matrice){
		for(const auto& element : num){
			cout<< element << " ";
		}
		cout << endl;
	}
}
