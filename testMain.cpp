#include <iostream> 
#include <fstream> 
#include <sstream> 
#include <cstdlib>

using namespace std;

int main() {
    int row = 0, col = 0, numrows = 0, numcols = 0;
    int max = 0;
    int min = 0;
    ifstream myfile;
    stringstream ss;
    myfile.open("Sample.pgm", ios::binary);
    //ifstream myfile("Sample.pgm");
    string text;
    getline(myfile, text, '\n');
    cout << text << endl;

    if (text == "P5") {
        getline(myfile, text, '\n');
        cout << text << endl;
        getline(myfile, text, '\n');
        cout << text << endl;
        getline(myfile, text, ' ');
        row = atoi(text.c_str());
        cout<<"Row = "<<row;
        getline(myfile, text, '\n');
        col = atoi(text.c_str());
        cout<<"Col = "<<col;
        getline(myfile, text, '\n');
        max = atoi(text.c_str());
        ss << myfile.rdbuf();
    }

    int array[row][col];
    long long sum = 0;

    for (row = 0; row < numrows; ++row) {
        for (col = 0; col < numcols; ++col) {
            unsigned char temp;
            ss >> temp;
            array[row][col] = temp;
            //array[row][col];
            if (array[row][col] > max) {
                max = array[row][col];
            }
            if (array[row][col] < min) {
                min = array[row][col];
            }
            sum = sum + array[row][col];
        }
    }

    double avg = (double) sum / (double) (row * col);

    cout << "Statistics of the image:" << endl;
    cout << "Width: " << row << endl;
    cout << "Height: " << col << endl;
    //cout << "Min-Intensity: " << min << endl;
    cout << "Max-Intensity: " << max << endl;
  //  cout << "Ave-Intensity: " << avg << endl;

    myfile.close();
}