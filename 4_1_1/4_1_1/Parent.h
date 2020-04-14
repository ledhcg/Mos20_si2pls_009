
#ifndef PARENT
#define PARENT
#define MAX 25
#define MAX_ID 100
class parent
{
public:
	parent() {
		id_parent = 0;
	};
	parent(char nameInput[]) {
		name = nameInput;
		id_parent = 0;
	};
	~parent();

private:
	
	char name[MAX];
	int* id_parent;
	int* id[MAX_ID];
};
#endif // !PARENT
