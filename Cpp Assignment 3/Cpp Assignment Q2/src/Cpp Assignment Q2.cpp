 #include <iostream>
#include <memory>
using namespace std;


class Texture{
	string name;
	int width;
	int height;

public:

	Texture(string name, int w, int h) : name(name), width(w), height(h){
		cout<<"Texture Loaded.........." << endl;

	}


	~Texture(){
		cout<<"Texture Released..........." << endl;
	}

	void display() const{
		cout<<"Name: " <<name << endl;
		cout<<"Width: " <<width << endl;
		cout<<"Height: " <<height << endl;
	}
};

class Shared{
	string name;
	string type;

public:
	Shared(string name,string type) : name(name),type(type)
	{
		cout<<"Shader compiled" << endl;

	}

	void sharedDisplay(){

		cout<<"Name: " <<name << endl;
		cout<<"Type: " << type << endl;

	}
	int getReferenceCount(const shared_ptr<Shared> &shader){
		int ref = shader.use_count();
		return ref;
	}

	~Shared(){
		cout<<"Shader Destructor" << endl;

	}


};

class  AudioClip{
	string name;
	int duration;

public:
	AudioClip(string n, int d) : name(n), duration(d) {
		cout <<"Default AudioClip Constructor....." << endl;
	}

	~AudioClip(){
		cout <<"Default AudioClip Destructor....." << endl;
	}

	void getName(){
		cout <<"Clip name: "<<name <<endl;
		cout<<"Clip Duration: "<<duration << endl;
	}
};


int main() {

	unique_ptr<Texture> p1 = make_unique<Texture>("player_sprite", 512, 512);

//	auto p2 = p1; //error: in unique_ptr copy p1(ptr) is not allowed, it has only one owner called unique_ptr.
//	p2->display();
//	p1->display();

//you not shared ownership of unique pointer but you can transfer ownership to another pointer using move()
	auto p2 = move(p1);
	p2->display();

	cout << "tex1 is null: " << (p1 == nullptr ? "YES" : "NO") << endl;

	cout <<"==========================================" <<endl;

	//Shared_ptr

	shared_ptr<Shared> shader = make_shared<Shared>("main_vert", "vertex");
	cout << "Ref count: " << shader.use_count() << endl; //1
	{
	auto rendererRef = shader;
	cout << "Ref count: " << shader.use_count() << endl;  // 2

	auto editorRef   = shader;
	cout << "Ref count: " << shader.use_count() << endl;  // 3
	}

	cout << "Ref count: " << shader.use_count() << endl;


	cout <<"Ref count after function call: " <<shader->getReferenceCount(shader) << endl;

	cout <<"==========================================" <<endl;

	//Weak_ptr

	auto audio = make_shared<AudioClip>("explosian" , 3.5);
	weak_ptr<AudioClip> observer = audio;


//		audio.reset(); //destroyed object

	if(auto clip = observer.lock()){ //.lock() checks if the object is still alive
		cout<< "=========Clip alive=========" << endl;
	 	 clip->getName();
	}else{
		cout << "Clip is expired...." << endl;
	}


		audio.reset(); // destroyed object


	if (observer.expired()) //.expired check is object expired or not!
	cout << "Clip already unloaded." << endl;
	else
		cout<<"Still present!!!!!!!!!"<< endl;


	cout <<"==========================================" <<endl;

	return 0;


}
