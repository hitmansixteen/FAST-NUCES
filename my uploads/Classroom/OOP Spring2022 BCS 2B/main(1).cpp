#include<iostream>
#include<string.h>
#include<ctime>
using namespace std;

int myTokenizer(char* data, char**& list_tokens, char delimeter){
    int data_len = strlen(data) + 1;
    int *token_len;
    int count = 0;
    for(int i = 0;i<data_len;i++)
        if(data[i] == delimeter)
        count++;
    int size = count +1;
    list_tokens = new char*[size];
    token_len = new int[size];
    int x =0;
    count=0;
    for(int i=0;i<data_len;i++){
        if (data[i] != delimeter && data[i] != '\0')
			count++;
		else{
			token_len[x] = count + 1;
			list_tokens[x] = new char[count + 1];
			count = 0;
			x++;
		}
    }
    x=0;
    int j;
    for(int i=0;i<size;i++){
        j=0;
        for(;j<token_len[i]-1;j++){
            list_tokens[i][j]= data[x];
            x++;
        }
        list_tokens[i][j]='\0';
        x++;
    }
    delete[] token_len;
    return size;
}

class date{
    time_t now;
    tm *ltm;
public:
    date(){
        now = time(0);
        ltm = localtime(&now);
    }
    void setdate(){
        now = time(0);
        ltm = localtime(&now);
    }
    friend ostream& operator<<(ostream&out, date& d){
        cout << d.ltm->tm_mday << "/"<< 1 + d.ltm->tm_mon<< "/"<<1900 + d.ltm->tm_year;
        cout << " "<< d.ltm->tm_hour << ":"<< d.ltm->tm_min << ":"<< d.ltm->tm_sec << endl;
        return out;
    }
};

class file{
    char* name;
    char* content;
    char* link;
    date creation_date;
    date last_accessed;
public:
    file(){
        name=nullptr;
        content=nullptr;
        link=nullptr;
        creation_date.setdate();
        last_accessed.setdate();
    }

    file(char* n,char* c,char* l){
        int len_n = strlen(n)+1;
        name = new char[len_n];
        strcpy(name,n);
        int len_c = strlen(c)+1;
        content = new char[len_c];
        strcpy(content,c);
        int len_l = strlen(l)+1;
        link = new char[len_l];
        strcpy(link,l);
        creation_date.setdate();
        last_accessed.setdate();
    }

    file(file& f){
        name = new char[strlen(f.name) + 1];
		strcpy(name, f.name);

		link = new char[strlen(f.link) + 1];
		strcpy(link, f.link);

		content = new char[strlen(f.content) + 1];
		strcpy(content, f.content);

		creation_date = f.creation_date;
		last_accessed = f.last_accessed;
    }

    void set_name(char* n){
        if (name != nullptr)
		    delete[] name;
        int len_n = strlen(n)+1;
        name = new char[len_n];
        strcpy(name,n);
    }
	void set_link(char* l){
	    if (link != nullptr)
		    delete[] link;
	    link = new char[strlen(l) + 1];
	    strcpy(link, l);
    }
	void set_content(char* c){
        if (content != nullptr)
		    delete[] content;
	    content = new char[strlen(c) + 1];
	    strcpy(content, c);
    }

	char* get_name(){return name;}

    ~file(){
        if (name != nullptr)
			delete[] name;
		if (content != nullptr)
			delete[] content;
		if (link != nullptr)
			delete[] link;
    }
};

class folder{
    char* name;
    char* link;
    date creation_date;
    date last_accessed;
    int no_of_files;
    int no_of_subfolders;
    int array_file;
    int array_subfolder;
    file* files;
    folder* subfolders;
public:
    folder(){
        name=nullptr;
        link=nullptr;
        creation_date.setdate();
        last_accessed.setdate();
        no_of_files = no_of_subfolders = array_subfolder = 0;
        array_file=2;
        files = new file[array_file];
        subfolders = new folder[array_subfolder];
    }
    folder(char* n,char* l){
        strcpy(name,n);
        strcpy(link,l);
        creation_date.setdate();
        last_accessed.setdate();
    }
    void set_name(char* n){
        if (name != nullptr)
		    delete[] name;
        int len_n = strlen(n)+1;
        name = new char[len_n];
        strcpy(name,n);
    }
    void setdate(){
        creation_date.setdate();
        last_accessed.setdate();
    }
    ~folder(){
        if (name != nullptr)
			delete[] name;
		if (link != nullptr)
			delete[] link;
		if (files != nullptr)
			delete[] files;
		if (subfolders != nullptr)
			delete[] subfolders;
    }
};

class filesystem{
    folder root;
public:
    filesystem(){
        char n[] = "root";
        root.set_name(n);
        root.setdate();
    }
    void createfile(){
        char* n,*l;
        char ** paths;
        cout<<"Enter path in which you want to create the file: ";
        cin>>l;      
        cout<<"Enter name of the file: ";
        cin>>n;
        int slashes = myTokenizer(l,paths ,'/');
        if(slashes==1);


     
    }
    void createfolder();
    void readfile();
    void listfolder();
    void removefile();
    void removefolder();
};


int main()
{
    system("cls");
   
    

    

    return 0;
}