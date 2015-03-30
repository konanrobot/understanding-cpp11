#include "vector.h"
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

	// question:
	// can i do vector.assign() directly without deleting content first(such as swap())?

}