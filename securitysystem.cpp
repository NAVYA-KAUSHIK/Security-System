#include<iostream>
#include<fstream> //header file used for file hndling operatios
#include<sstream> //header files provides templates that enable inter operations between string buffer and string objects
#include<string>

using namespace std;

int main()
{
    int a,i=0;
    string text,old,password1,password2,password0,pass,name,age,user,word,word1;
    string credentials[2], cp[2];

    //Menu

    cout<<"      Security System "<<endl;
    cout<<"_________________________________"<<endl<<endl;
    cout<<"|          1.Register           |"<<endl;
    cout<<"|          2.Login              |"<<endl;
    cout<<"|          3.Change Password    |"<<endl;
    cout<<"|          4.End program        |"<<endl;
    cout<<"|_______________________________|"<<endl<<endl;
    //ask the user to enter choice
    do{
        cout<<endl<<endl;
        cout<<"Enter your choice: ";
        cin>>a;
        switch(a)
        {
            case 1:{

                cout<<"_________________________"<<endl<<endl;
                cout<<"|-------REGISTER--------|"<<endl;
                cout<<"|_______________________|"<<endl;
                cout<<"Please enter username:     "<<endl;
                cin>>name;
                cout<<"Please enter the password: "<<endl;
                cin>>password0;
                cout<<"Please enter your age:     "<<endl;
                cin>>age;

                //class to use file handling operations
                ofstream of1;
                of1.open("file.txt");
                if(of1.is_open())
                {
                    of1<<name<<"\n";
                    of1<<password0;
                    cout<<"Registration successful"<<endl;
                }




                break;
            }
            case 2:{
                i=0;

                cout<<"__________________________________"<<endl<<endl;
                cout<<"|--------------LOGIN--------------|"<<endl;
                cout<<"|_________________________________|"<<endl;

                //class to read objects

                ifstream of2;
                of2.open("file.txt");
                cout<<"Please enter your username: "<<endl;
                cin>>user;
                cout<<"Please enter your password: "<<endl;
                cin>>pass;

                if(of2.is_open())
                {
                    while(!of2.eof())
                    {    
                        //get line function is used to read the file line by line
                        // istringstream is used to stream the string and store in the extraction operator
                        while(getline(of2,text)){
                            istringstream iss(text);
                            iss>>word; //it stores the string
                            credentials[i]=word;
                            i++;}
                            if(user==credentials[0]&& pass==credentials[1])
                            {
                                cout<<"------LOGIN SUCCESSFULL------"<<endl;
                                cout<<endl;
                                cout<<"Details: "<<endl;
                                cout<<"Username: "+name<<endl;
                                cout<<"Password: "+pass<<endl;
                                cout<<"Age:      "+age<<endl;
                            }
                            else
                            {
                                cout<<endl<<endl;
                                cout<<"OOPS! Incorrect Credentials"<<endl;
                                cout<<"|       1.Press 2 to Login                  |"<<endl;
                                cout<<"|       2.Press 3 to change password        |"<<endl;
                                break;
                            }
                        }
                    }
                    break;

                }



            
            case 3: {
                i=0;
                cout<<"-------------CHANGE PASSWORD-----------"<<endl;

                ifstream of0;
                of0.open("file.txt");
                cout<<"Enter the old password:  "<<endl;
                cin>>old;
                if(of0.is_open())
                {
                    while(!of0.eof()) //eof is end of file
                    {
                        while(getline(of0,text)){
                            istringstream iss(text);
                            iss>>word1; //storing data in wordd1
                            cp[1]=word;
                            i++;
                        }
                        if(old==cp[1])
                        {
                            of0.close();

                            ofstream of1;
                            of1.open("file.txt");
                            if(of1.is_open())
                            {
                                cout<<"Enter your new Password:  "<<endl;
                                cin>>password1;
                                cout<<"Confirm the new password: "<<endl;
                                cin>>password2;

                                if(password1==password2)
                                {
                                    of1<<cp[0]<<"\n";
                                    of1<<password1;
                                    cout<<"Password changed succcessfully"<<endl;
                                }
                                else{
                                    of1<<cp[0]<<"\n";
                                    of1<<old;
                                    cout<<"Password do not match"<<endl;

                                }
                            }
                        }
                        else{
                         cout<<"Please enter a valid password"<<endl;
                         break;
                         }
                    }


                }
                break;
            }
            case 4:{
                cout<<"----------THANKYOU!----------"<<endl;
                break;
            }
            default:
            cout<<"Enter a valid choice"<<endl;

              
        }
    }
    while(a!=4);


    return 0;



}
 