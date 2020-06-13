#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

int close_files(ifstream &Ubuntu_dls, ifstream &raspi_dls){
    Ubuntu_dls.close();
    raspi_dls.close();
    return 0;
}
int create_file(string filename){
    string param = "touch " + filename;
    system(param.c_str());
    return 0;   //supposed to have error checking here but wtv
}

int main_function(){
    return 0;
}
int main(){
    // ofstream myfile;
    string Ubuntu_dls_filename = "ls_Ubuntu_dls.txt";
    string raspi_dls_filename = "ls_raspi_dls.txt";

    string raspi_dls_loc = "/run/user/1000/gvfs/smb-share:server=raspberrypi.local,share=pi%20share/shared_Downloads";
    string raspi_system_ls_param = "ls " + raspi_dls_loc + "-lt > " + raspi_dls_filename;
    
    // string Ubuntu_system_touch_param = "touch " + Ubuntu_dls_filename;
    // string Windows_dls_filename = "ls_Windows_dls.txt";

    ifstream Ubuntu_dls(Ubuntu_dls_filename.c_str());
    ifstream raspi_dls(raspi_dls_filename.c_str());
    // ifstream Windows_dls(Windows_dls_filename);
    
    
    string line;
    if(Ubuntu_dls.is_open()){
         //execute ls, sorts new (top) to old (bottom)
        system("ls ~/Downloads -lt > ls_Ubuntu_dls.txt");
        // system(raspi_system_ls_param.c_str());
        // cout << myfile.rdbuf() << endl;


        while(getline(Ubuntu_dls, line)){
            cout << line << '\n';
        }        

        // myfile.close();
        close_files(Ubuntu_dls, raspi_dls);
    }
    else{
        // cout << "error opening file" << endl;
        create_file(Ubuntu_dls_filename);
        create_file(raspi_dls_filename);

    }

   
    return 0;
}