#include "vector.h"
#include <list>
USING_NS_STD;
USING_NS_ELLOOP;
TEST(VectorTest, DeleteItem) {
	vector<int> vi{ 1, 2, 3, 4 };
	auto del = find(vi.begin(), vi.end(), 3);
	print_container(vi);
	psln(vi.size());
	if (del != vi.end()) {
		vi.erase(del);
	}
	print_container(vi);

	list<int> li{ 5, 6, 7, 8, 9 };
	print_container(li);
	vi.assign(li.begin(), li.end());
	print_container(vi);

	// question:
	// can i do vector.assign() directly without deleting content first(such as swap())?



}

TEST(OtherTest, UnInitialClassMember) {
	UnInitial ui;
	psln(ui.i_);
	cout << boolalpha << ui.b_ << endl;
	cout << noboolalpha << ui.b_ << endl;
	cout << noboolalpha << ui.c_ << endl;
	cout << noboolalpha << ui.d_ << endl;
}