#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> remplireMatrice(int lines, int rows);
vector<vector<int>> produitMatriciel(const vector<vector<int>>& matrice1, const vector<vector<int>>& matrice2);
void afficheMatrice(const vector<vector<int>>& matrice);

int main(){
	
	vector<vector<int>>matrice1;
	vector<vector<int>>matrice2;
	vector<vector<int>>produitMatrice;

	cout << "Entrez les éléments du premier matrice" << endl;
	matrice1 = remplireMatrice(5, 3);
	
	cout << endl;
	
	cout <<"Entrez les éléments du second matrice" << endl;
	matrice2 = remplireMatrice(3, 2);
	/*	Les blocs try{}catch(exception){} sont deja expliqués dans la fonction vector<vector<int>> produitMatriciel
	 * Pour ce qui est du fonction .what():
	 * 	elle prend la valeur pris dans throw et les rassemble dans erreur.what() pour fournir un message d'erreur pérsonnaliser
	 * */
	try{
		produitMatrice = produitMatriciel(matrice1, matrice2);
		cout << "Somme des deux matrices" << endl;
		afficheMatrice(produitMatrice);
	}catch(const exception& erreur){
		cout << "Erreur " << erreur.what()<<endl;
	}
	
	return 0;
}

vector<vector<int>> remplireMatrice(int lines, int rows){
	
	vector<vector<int>>matrice;
	
	for(int i = 0; i < lines; i++){
		vector<int>tmp;
		
		for(int j = 0; j < rows; j++){
			int value;
			cout<<"lines("<<i+1<<")colonnes("<<j+1<<")  ";
			cin >> value;
			tmp.push_back(value);
		}
		matrice.push_back(tmp);
	}
	
	return matrice;
}

vector<vector<int>> produitMatriciel(const vector<vector<int>>& matrice1, const vector<vector<int>>& matrice2){
	int lines1 = matrice1.size(), rows1 = matrice1[0].size();
	int lines2 = matrice2.size(), rows2 = matrice2[0].size();

	/*	Au cas ou:
	 * le nombre de colonne du premier du premier matrice ne correspend pas au nombre de lignes du second matrice
	 * L'opérateur throw est utilisé pour gerer les erreurs lors d'une code (ou programme),
	 * pour générer une exception, il est utilisé en conjonction avec les mécanismes de gestion des exceptions
	 * Dans le bloc try{} se trouve une instance de "vector<vector<int>> produitMatriciel"
	 * Ces exceptions sont rattrapés par la fonction catch(){}
	 * */	
	if(rows1 != lines2)
		throw runtime_error("la produit ne peut pas être fait");

	vector<vector<int>>result(lines1, vector<int>(rows2));
	
	for(int i = 0; i < lines1; i++){
		for(int j = 0; j < rows2; j++){
			int produit = 0;
			for(int k = 0; k < rows1; k++){
				produit += matrice1[i][k]*matrice2[k][j];
			}
			result[i][j] = produit;
		}
	}
	
	return result;
}

void afficheMatrice(const vector<vector<int>>& matrice){
	for(const auto& num : matrice){
		for(const auto& element : num){
			cout<< element << " ";
		}
		cout << endl;
	}
}
