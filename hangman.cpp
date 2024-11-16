#include <iostream>
#include <string>
using namespace std;

void suggestion(string hint) {
    cout << "Suggestion: ";
    cin.ignore();
    getline(cin, hint);
    return ;
}

char giveAnswer(char ans) {
    cout << "Enter the word: ";
    cin >> ans;
    return ans;
}

bool hangmanGame(int lifelines, char arr[], string hint, char ans, string word) {
    suggestion(hint);
    int size = word.size();
    while (lifelines > 0) {
        for (int j=0; j<word.size(); j++) {
            cout << arr[j] << " ";
        } cout << endl;
        char wordAns = giveAnswer(ans);
        for (int k=0; k<word.size(); k++) {
            if (wordAns == word[k]) {
                arr[k] = wordAns;
                word[k] = ' ';
                size--;
                break;
            }
            if ((k == word.size() - 1) && (wordAns != word[word.size()-1])) {
                lifelines--;
                if (lifelines == 0) {
                    return 0;
                }
                cout << "You guesses wrong word: " << endl;
                cout << "You left with only " << lifelines << " life" << endl;
                suggestion(hint);
            }
        }
        if (size == 0) {
            return 1;
            break;
        }
    }
}

int main() {
    string word;
    cout << "Enter the word to be guessed: ";
    cin >> word;
    char wordArray[30] = {};
    for (int i=0; i<word.size(); i++) {
        wordArray[i] = '_';
    }
    string hint;
    char ans;
    int gaming = hangmanGame(3, wordArray, hint, ans, word);
    
    if (gaming == 1) {
        cout << "YOU GUESSED IT WRITE" << endl;
        cout << endl;
        cout << "WINNER" << endl;
    }
    else {
        cout << "OUT OF LIFES" << endl;
        cout << endl;
        cout << "LOSER" << endl;
    }

}