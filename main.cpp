//Name: Noor Al-Ali IDNum: 1732975

#include <iostream>
#include <dirent.h>
#include <sys/types.h>
#include <string>
#include <bits/stdc++.h>
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <cstddef>
using namespace std;

void case1(string key, string extension){
    string files[1000];
    int counter;

   //open the current direcory
   DIR *dr;
   struct dirent *en;
   dr = opendir("."); 
   if (dr) {
      while ((en = readdir(dr)) != NULL) {

          string file=en->d_name;

          //check if the file is with the given extension
        if(file.substr(file.find_last_of(".") + 1) == extension){

            files[counter]=file;
            counter++;
            //concatenate the openssl command 
            string c1="openssl enc -in "+ file + " -out "+ file+".enc " +  "-aes-256-cbc -kfile " + key;

            //convert the command to char
            int n1= c1.length();
            char command1[n1+1];
            strcpy(command1, c1.c_str());

            //execute the openssl command
            system(command1);

            // conatenate the rm command to delete the origin file
            string c2="rm "+ file;

            //convert the command to char
            int n2= c2.length();
            char command2[n2+1];
            strcpy(command2, c2.c_str());

             //execute the openssl command
            system(command2);
        }
      }
      closedir(dr); //close all directory
   }

    cout<<"\n"<<"****************************************\n";
    cout <<endl;
    cout<<"Summary of encrypted file names:"<<endl;
    for (int i = 0; i < counter; i++)
        cout << files[i] << "\n";
    cout<<endl;

}

void case2 (string key){
     string files[1000];
    int counter;
    
   DIR *dr;
   struct dirent *en;
   dr = opendir("."); 
   if (dr) {
      while ((en = readdir(dr)) != NULL) {

          string file=en->d_name;
           files[counter]=file;
            counter++;

          //check if the file is enc files
        if(file.substr(file.find_last_of(".") + 1) == "enc"){
            
            size_t lastindex = file.find_last_of("."); 
            string rawname = file.substr(0, lastindex);

            //concatenate the openssl command 
            string c1="openssl enc -d -in "+ file + " -out "+ rawname +  " -aes-256-cbc -kfile " + key;

            //convert the command to char
            int n1= c1.length();
            char command1[n1+1];
            strcpy(command1, c1.c_str());

            //execute the openssl command
            system(command1);

            // conatenate the rm command to delete the origin file
            string c2="rm "+ file;

            //convert the command to char
            int n2= c2.length();
            char command2[n2+1];
            strcpy(command2, c2.c_str());

             //execute the openssl command
            system(command2);
        }
      }
      closedir(dr); //close all directory
   }
    
     cout<<"\n"<<"****************************************\n";
    cout <<endl;
    cout<<"Summary of all file names:"<<endl;
    for (int i = 0; i < counter; i++){
        if (files[i]!="." && files[i]!="..")
        {   if(files[i].substr(files[i].find_last_of(".") + 1) != "enc")
            cout << files[i] << "\n";
            if (files[i].substr(files[i].find_last_of(".") + 1) == "enc"){
            size_t lastindex = files[i].find_last_of("."); 
            string rawname = files[i].substr(0, lastindex);
            cout<<rawname<<endl;
            }
        }
    }
        
    cout<<endl;
}

int main(int argc, char** argv) {

    //to detarmine the case
    int theCase = atoi(argv[1]);

    // wrong input
    if (argc <3 ) cout << "very low arguments"<<endl;
    else if (argc <4 && theCase==1) cout << "very low arguments"<<endl;
    else if (argc > 4) cout<< "too much arguments"<<endl;
    else if (argc >3 && theCase==2) cout<< "too much arguments"<<endl;

    //case 1
    else if (theCase==1 && argc ==4) case1(argv[2], argv[3]);

    //case 2
    else if (theCase==2 && argc ==3) case2(argv[2]);
   return(0);
}
