#ifndef ARRAY
#define ARRAY

#define MAX 10
class Array
{
	private:
		int a[MAX];
		int n;
	public:
		Array();
		~Array();
		//void printArr();
		//void scanArr();
		void printArr(int k);
		void inputArr(int k);
		//void quantityOfArr();
		void invertArr();
};
#endif //!ARRAY

